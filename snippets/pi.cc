#include <iostream>
#include <cstdlib>
#include <random>
#include <omp.h>
#include <vector>
#include <numeric>

#include "argagg.hpp"
#include "fmt/format.h"

template <typename Rng>
double compute_pi(Rng &gen, unsigned long N)
{
    unsigned long M = 0;
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (unsigned long i = 0; i < N; ++i) {
        double x = dist(gen);
        double y = dist(gen);
        if (x*x + y*y < 1.0) ++M;
    }

    return 4.0 * static_cast<double>(M) / N;
}

template <typename V>
auto mean(V const &vec)
{
    return std::accumulate(
        std::begin(vec),
        std::end(vec),
        (decltype(vec[0]))(0)) / std::size(vec);
}

int main(int argc, char **argv)
{
    unsigned n_threads = omp_get_max_threads();
    argagg::parser argparser {{
        { "help", {"-h", "--help"},
          "shows this help message", 0 },
        { "threads", {"-j", "--threads"},
          fmt::format("number of threads ({})", n_threads),
          1 },
        { "repeat", {"-r", "--repeat"},
          "repeat experiment n times (1)", 1 },
        { "sample", {"-s", "--sample"},
          "number of samples (1e6)", 1 },
    }};

    argagg::parser_results args;
    try {
        args = argparser.parse(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    if (args["help"]) {
        std::cerr << "Usage: pi [-h] [-j<i>] [-r<i>] [-n<f>]" << std::endl
                  << argparser;
        return EXIT_SUCCESS;
    }

    n_threads = args["threads"].as<unsigned>(n_threads);
    auto n_repeats = args["repeat"].as<unsigned>(1);
    double n_samples = args["sample"].as<double>(1e6);

    std::random_device dev_random;
    std::vector<std::mt19937> generators;
    for (unsigned i = 0; i < n_threads; ++i) {
        generators.emplace_back(dev_random());
    }

    std::vector<double> pies(n_repeats);
    #pragma omp parallel for num_threads(n_threads)
    for (double &pi : pies) {
        auto &gen = generators[omp_get_thread_num()];
        pi = compute_pi(gen, n_samples);
    }

    std::cout << fmt::format("Value of pi: {}", mean(pies))
              << std::endl;
    return EXIT_SUCCESS;
}


#include <iostream>
#include <cstdlib>
#include <random>
#include <omp.h>
#include <vector>
#include <numeric>

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

int main(int argc, char **argv) 
{
        std::random_device dev_random;
        std::vector<std::mt19937> generators;
        for (int i = 0, N = omp_get_max_threads(); i < N; ++i) {
                generators.emplace_back(dev_random());
        }

        std::vector<double> pies(100);
        #pragma omp parallel for
        for (unsigned i = 0; i < 100; ++i) {
                auto &gen = generators[omp_get_thread_num()];
                pies[i] = compute_pi(gen, 10000000);
        }

        double pi = std::accumulate(
                pies.begin(), pies.end(), 0.0) / pies.size();
        std::cout << pi << std::endl;
        return EXIT_SUCCESS;
}



import numpy as np

def compute_pi(N):
    pts = np.random.uniform(0, 1, (2, N))
    M = np.count_nonzero((pts**2).sum(axis=0) < 1)
    return 4 * M / N

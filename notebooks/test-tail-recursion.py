import numpy
import noodles
import time
from copy import copy

@noodles.schedule(call_by_ref=['gobble'])
def factorial_tr(x, acc=1, gobble=None):
    time.sleep(0.1)
    if x == 0:
        return acc
    else:
        return factorial_tr(x - 1, acc * x, copy(gobble))

gobble_size = 10000000
gobble = numpy.zeros(gobble_size)
result = noodles.run_single(factorial_tr(10, gobble=gobble))

import numpy
import noodles
import time
from copy import copy

@noodles.schedule(call_by_ref=['gobble'])
def mul(x, y, gobble):
    return x*y

@noodles.schedule(call_by_ref=['gobble'])
def factorial(x, gobble):
    time.sleep(0.1)
    if numpy.all(x == 0):
        return numpy.ones_like(x)
    else:
        return mul(factorial(x - 1, copy(gobble)), x, gobble)

gobble_size = 10000000
gobble = numpy.zeros(gobble_size)
result = noodles.run_single(factorial(10, gobble))

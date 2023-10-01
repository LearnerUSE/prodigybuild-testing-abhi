"""
## Modified Contents:

"""
"""Newton's Method."""

# Newton's Method - https://en.wikipedia.org/wiki/Newton%27s_method
from collections.abc import Callable

RealFunc = Callable[[float], float]  # type alias for a real -> real function


# function is the f(x) and derivative is the f'(x)
def newton(
    function: RealFunc,
    derivative: RealFunc,
    starting_int: int,
) -> float:
    """
     """
    prev_guess = float(starting_int)
    while True:
        try:
            next_guess = prev_guess - function(prev_guess) / derivative(prev_guess)
        except ZeroDivisionError:
            raise ZeroDivisionError("Could not find root") from None
        if abs(prev_guess - next_guess) < 10**-5:
            return next_guess
        prev_guess = next_guess


def f(x: float) -> float:
    return (x**3) - (2 * x) - 5


def f1(x: float) -> float:
    return 3 * (x**2) - 2

"""
## Test Content
"""

import unittest
import math

class TestNewton(unittest.TestCase):
    def test_newton_method(self):
        self.assertAlmostEqual(newton(lambda x: x ** 3 - 2 * x - 5, lambda x: 3 * x ** 2 - 2, 3), 2.0945514815423474)
        self.assertAlmostEqual(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -2), 1.0)
        self.assertAlmostEqual(newton(lambda x: x ** 3 - 1, lambda x: 3 * x ** 2, -4), 1.0000000000000102)
        self.assertAlmostEqual(newton(math.sin, math.cos, 1), 0.0)
        self.assertAlmostEqual(newton(math.sin, math.cos, 2), 3.141592653589793)
        self.assertAlmostEqual(newton(math.cos, lambda x: -math.sin(x), 2), 1.5707963267948966)
        with self.assertRaises(ZeroDivisionError): newton(math.cos, lambda x: -math.sin(x), 0) 

if __name__ == "__main__":
    unittest.main()
    print(newton(f, f1, 3))
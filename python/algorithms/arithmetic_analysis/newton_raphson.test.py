from decimal import Decimal
from math import sin, log, exp

from sympy import diff


def newton_raphson(
    func: str, a: float | Decimal, precision: float = 10**-10
) -> float:
    """Finds root from the point 'a' onwards by Newton-Raphson method
    >>> newton_raphson("sin(x)", 2)
    3.1415926536808043
    >>> newton_raphson("x**2 - 5*x +2", 0.4)
    0.4384471871911695
    >>> newton_raphson("x**2 - 5", 0.1)
    2.23606797749979
    >>> newton_raphson("log(x)- 1", 2)
    2.718281828458938
    """
    x = a
    while True:
        x = Decimal(x) - (Decimal(eval(func)) / Decimal(eval(str(diff(func)))))
        # This number dictates the accuracy of the answer
        if abs(eval(func)) < precision:
            return float(x)
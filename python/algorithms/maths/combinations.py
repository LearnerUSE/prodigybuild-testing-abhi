import unittest
from math import factorial


def combinations(n: int, k: int) -> int:
    """
    Returns the number of different combinations of k length which can
    be made from n values, where n >= k.

    Examples:
    >>> combinations(10,5)
    252

    >>> combinations(6,3)
    20

    >>> combinations(20,5)
    15504

    >>> combinations(52, 5)
    2598960

    >>> combinations(0, 0)
    1

    >>> combinations(-4, -5)
    ...
    Traceback (most recent call last):
    ValueError: Please enter positive integers for n and k where n >= k
    """

    # If either of the conditions are true, the function is being asked
    # to calculate a factorial of a negative number, which is not possible
    if n < k or k < 0:
        raise ValueError("Please enter positive integers for n and k where n >= k")
    return factorial(n) // (factorial(k) * factorial(n - k))


class TestCombinations(unittest.TestCase):
    def test_combinations(self):
        self.assertEqual(combinations(10, 5), 252)
        self.assertEqual(combinations(6, 3), 20)
        self.assertEqual(combinations(20, 5), 15504)
        self.assertEqual(combinations(52, 5), 2598960)
        self.assertEqual(combinations(0, 0), 1)
        with self.assertRaises(ValueError):
            combinations(-4, -5)


if __name__ == "__main__":
    unittest.main()
import unittest

def minimum_waiting_time(queries: list[int]) -> int:
    n = len(queries)
    if n in (0, 1):
        return 0
    return sum(query * (n - i - 1) for i, query in enumerate(sorted(queries)))

class TestMinimumWaitingTime(unittest.TestCase):
    def test_minimum_waiting_time(self):
        self.assertEqual(minimum_waiting_time([3, 2, 1, 2, 6]), 17)
        self.assertEqual(minimum_waiting_time([3, 2, 1]), 4)
        self.assertEqual(minimum_waiting_time([1, 2, 3, 4]), 10)
        self.assertEqual(minimum_waiting_time([5, 5, 5, 5]), 30)
        self.assertEqual(minimum_waiting_time([]), 0)

if __name__ == "__main__":
    unittest.main()
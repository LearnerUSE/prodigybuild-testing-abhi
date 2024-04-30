import unittest

def binary_search(a_list: list[int], item: int) -> bool:
    if len(a_list) == 0:
        return False
    left = 0
    right = len(a_list) - 1
    while left <= right:
        midpoint = (left + right) // 2
        if a_list[midpoint] == item:
            return True
        elif item < a_list[midpoint]:
            right = midpoint - 1
        else:
            left = midpoint + 1
    return False

class TestBinarySearch(unittest.TestCase):
    def test_binary_search(self):
        test_list = [0, 1, 2, 8, 13, 17, 19, 32, 42]
        self.assertFalse(binary_search(test_list, 3))
        self.assertTrue(binary_search(test_list, 13))
        self.assertTrue(binary_search([4, 4, 5, 6, 7], 4))
        self.assertFalse(binary_search([4, 4, 5, 6, 7], -10))
        self.assertTrue(binary_search([-18, 2], -18))
        self.assertTrue(binary_search([5], 5))
        self.assertTrue(binary_search(['a', 'c', 'd'], 'c'))
        self.assertFalse(binary_search(['a', 'c', 'd'], 'f'))
        self.assertFalse(binary_search([], 1))
        self.assertTrue(binary_search([-.1, .1 , .8], .1))
        self.assertTrue(binary_search(range(-5000, 5000, 10), 80))
        self.assertFalse(binary_search(range(-5000, 5000, 10), 1255))
        self.assertFalse(binary_search(range(0, 10000, 5), 2))

if __name__ == "__main__":
    unittest.main()
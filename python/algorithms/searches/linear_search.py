import unittest

class LinearSearchTest(unittest.TestCase):
    def test_linear_search(self):
        self.assertEqual(linear_search([0, 5, 7, 10, 15], 0), 0)
        self.assertEqual(linear_search([0, 5, 7, 10, 15], 15), 4)
        self.assertEqual(linear_search([0, 5, 7, 10, 15], 5), 1)
        self.assertEqual(linear_search([0, 5, 7, 10, 15], 6), -1)

    def test_rec_linear_search(self):
        self.assertEqual(rec_linear_search([0, 30, 500, 100, 700], 0, 4, 0), 0)
        self.assertEqual(rec_linear_search([0, 30, 500, 100, 700], 0, 4, 700), 4)
        self.assertEqual(rec_linear_search([0, 30, 500, 100, 700], 0, 4, 30), 1)
        self.assertEqual(rec_linear_search([0, 30, 500, 100, 700], 0, 4, -6), -1)

if __name__ == "__main__":
    unittest.main()
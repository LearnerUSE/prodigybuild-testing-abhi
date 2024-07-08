import unittest
from unittest.mock import MagicMock

class TestContributingGuidelines(unittest.TestCase):
    def test_rule_1(self):
        issue = "There is a bug in the algorithm"
        self.assertTrue(issue, "Issue must detail what exactly is the problem")

    def test_rule_2(self):
        code = """
        # This is a comment
        def add(a, b):
            return a + b
        """
        self.assertNotIn("#", code, "Code must be clean, no excessive use of comments")

    def test_rule_3(self):
        code = """
        # This is a comment
        def add(a, b):
            return a + b
        """
        self.assertIn("C", code, "All algorithms must be programmed in C")

    def test_advice_1(self):
        issue = "The algorithm is not working as expected"
        self.assertGreater(len(issue), 10, "The more helpful an issue is, the more likely it will be fixed")

    def test_advice_2(self):
        code = """
        def add(a, b):
            return a + b
        """
        result = add(2, 3)
        self.assertEqual(result, 5, "Test your code before running it")

    def test_advice_3(self):
        code = """
        def add(a, b):
            return a + b
        """
        self.assertLess(len(code), 100, "Using too much indentation is hard to read")

if __name__ == '__main__':
    unittest.main()
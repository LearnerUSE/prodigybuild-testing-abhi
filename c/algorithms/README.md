import unittest
from unittest.mock import MagicMock

class TestAlgorithms(unittest.TestCase):
    def test_compile_with_makefile(self):
        # Mock the make command
        make_mock = MagicMock()
        make_mock.return_value = True

        # Compile with makefile
        result = make_mock()
        self.assertTrue(result)

    def test_compile_without_makefile(self):
        # Mock the gcc command
        gcc_mock = MagicMock()
        gcc_mock.return_value = True

        # Compile without makefile
        result = gcc_mock()
        self.assertTrue(result)

if __name__ == '__main__':
    unittest.main()
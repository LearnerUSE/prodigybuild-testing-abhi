import unittest

class TestOpticalFlow(unittest.TestCase):
    def test_warp(self):
        image = np.array([[0, 1, 2], [0, 3, 0], [2, 2, 2]])
        horizontal_flow = np.array([[0, 1, -1], [-1, 0, 0], [1, 1, 1]])
        vertical_flow = np.array([[0, 0, 0], [0, 1, 0], [0, 0, 1]])
        expected_output = np.array([[0, 0, 0], [3, 1, 0], [0, 2, 3]])
        self.assertTrue(np.array_equal(warp(image, horizontal_flow, vertical_flow), expected_output))

    def test_horn_schunck(self):
        image0 = np.array([[0, 0, 2], [0, 0, 2]])
        image1 = np.array([[0, 2, 0], [0, 2, 0]])
        alpha = 0.1
        num_iter = 110
        expected_output = np.array([[[0, -1, -1], [0, -1, -1]], [[0, 0, 0], [0, 0, 0]]], dtype=np.int32)
        self.assertTrue(np.array_equal(np.round(horn_schunck(image0, image1, num_iter, alpha)).astype(np.int32), expected_output))

unittest.main()
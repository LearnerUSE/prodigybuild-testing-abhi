import unittest
import math


class SegmentTree:
    def __init__(self, a):
        self.A = a
        self.N = len(a)
        self.st = [0] * (
            4 * self.N
        )  # approximate the overall size of segment tree with array N
        self.build(1, 0, self.N - 1)

    def left(self, idx):
        return idx * 2

    def right(self, idx):
        return idx * 2 + 1

    def build(self, idx, l, r):  # noqa: E741
        if l == r:
            self.st[idx] = self.A[l]
        else:
            mid = (l + r) // 2
            self.build(self.left(idx), l, mid)
            self.build(self.right(idx), mid + 1, r)
            self.st[idx] = max(self.st[self.left(idx)], self.st[self.right(idx)])

    def update(self, a, b, val):
        return self.update_recursive(1, 0, self.N - 1, a - 1, b - 1, val)

    def update_recursive(self, idx, l, r, a, b, val):  # noqa: E741
        """
        update(1, 1, N, a, b, v) for update val v to [a,b]
        """
        if r < a or l > b:
            return True
        if l == r:
            self.st[idx] = val
            return True
        mid = (l + r) // 2
        self.update_recursive(self.left(idx), l, mid, a, b, val)
        self.update_recursive(self.right(idx), mid + 1, r, a, b, val)
        self.st[idx] = max(self.st[self.left(idx)], self.st[self.right(idx)])
        return True

    def query(self, a, b):
        return self.query_recursive(1, 0, self.N - 1, a - 1, b - 1)

    def query_recursive(self, idx, l, r, a, b):  # noqa: E741
        """
        query(1, 1, N, a, b) for query max of [a,b]
        """
        if r < a or l > b:
            return -math.inf
        if l >= a and r <= b:
            return self.st[idx]
        mid = (l + r) // 2
        q1 = self.query_recursive(self.left(idx), l, mid, a, b)
        q2 = self.query_recursive(self.right(idx), mid + 1, r, a, b)
        return max(q1, q2)

    def show_data(self):
        show_list = []
        for i in range(1, self.N + 1):
            show_list += [self.query(i, i)]
        return show_list


class TestSegmentTree(unittest.TestCase):

    def test_query(self):
        A = [1, 2, -4, 7, 3, -5, 6, 11, -20, 9, 14, 15, 5, 2, -8]
        segt = SegmentTree(A)
        self.assertEqual(segt.query(4, 6), 7)
        self.assertEqual(segt.query(7, 11), 11)
        self.assertEqual(segt.query(7, 12), 14)
    
    def test_update_and_query(self):
        A = [1, 2, -4, 7, 3, -5, 6, 11, -20, 9, 14, 15, 5, 2, -8]
        segt = SegmentTree(A)
        segt.update(1, 3, 111)
        self.assertEqual(segt.query(1, 15), 111)
        segt.update(7, 8, 235)
        self.assertEqual(segt.query(1, 15), 235)

    def test_show_data(self):
        A = [1, 2, -4, 7, 3, -5, 6, 11, -20, 9, 14, 15, 5, 2, -8]
        segt = SegmentTree(A)
        self.assertListEqual(segt.show_data(), [1, 2, 111, 7, 3, 6, 235, 235, 9, 14, 14, 15, 5, 2, -8])


if __name__ == "__main__":
    unittest.main()
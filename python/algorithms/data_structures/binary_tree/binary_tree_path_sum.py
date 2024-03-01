```python
from typing import Optional

class Node:
    def __init__(self, value: int) -> None:
        self.value = value
        self.left: Optional[Node] = None
        self.right: Optional[Node] = None

class BinaryTreePathSum:
    def __init__(self) -> None:
        self.paths = 0

    def depth_first_search(self, node: Optional[Node], path_sum: int) -> None:
        if node is None:
            return

        if path_sum == self.target:
            self.paths += 1

        if node.left:
            self.depth_first_search(node.left, path_sum + node.left.value)
        if node.right:
            self.depth_first_search(node.right, path_sum + node.right.value)

    def path_sum(self, node: Optional[Node], target: int) -> int:
        if node is None:
            return 0

        self.target = target
        self.depth_first_search(node, node.value)
        self.path_sum(node.left, target)
        self.path_sum(node.right, target)

        return self.paths
```
class Queue:
    def __init__(self):
        self.entries = []
        self.length = 0
        self.front = 0

    def __str__(self):
        printed = "<" + str(self.entries)[1:-1] + ">"
        return printed

    def put(self, item):
        self.entries.append(item)
        self.length = self.length + 1

    def get(self):
        if self.length > 0:
            self.length = self.length - 1
            dequeued = self.entries[self.front]
            self.entries = self.entries[1:]
            return dequeued
        else:
            raise IndexError("Queue is empty")

    def rotate(self, rotation):
        for _ in range(rotation):
            self.put(self.get())

    def get_front(self):
        if self.length > 0:
            return self.entries[0]
        else:
            raise IndexError("Queue is empty")

    def size(self):
        return self.length
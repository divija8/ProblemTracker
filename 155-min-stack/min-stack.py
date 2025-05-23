class MinStack:

    def __init__(self):
        self.mini = float('inf')
        self.stack = []

    def push(self, val: int) -> None:
        if not self.stack:
            self.stack.append(val)
            self.mini = val
        elif val >= self.mini:
            self.stack.append(val)
        else:
            self.stack.append(2 * val - self.mini)
            self.mini = val

    def pop(self) -> None:
        if not self.stack:
            return
        x = self.stack.pop()
        if x < self.mini:
            self.mini = 2 * self.mini - x

    def top(self) -> int:
        if not self.stack:
            return
        x = self.stack[-1]  
        if x >= self.mini:
            return x
        else:
            return self.mini  

    def getMin(self) -> int:
        return self.mini
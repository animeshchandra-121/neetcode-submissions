class FreqStack:

    def __init__(self):
        self.group_stack = {}
        self.freq = {}
        self.max_val = 0

    def push(self, val: int) -> None:
        self.freq[val] = self.freq.get(val, 0) + 1
        self.group_stack.setdefault(self.freq[val], []).append(val)

        self.max_val = max(self.max_val, self.freq[val])

    def pop(self) -> int:
        val = self.group_stack[self.max_val].pop()
        self.freq[val] -= 1

        if not self.group_stack[self.max_val]:
            self.max_val -= 1

        return val
        


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
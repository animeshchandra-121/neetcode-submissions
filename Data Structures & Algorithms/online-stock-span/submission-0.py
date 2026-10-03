class StockSpanner:

    def __init__(self):
        self.monotonic_stack = []

    def next(self, pick: int) -> int:
        span = 1
        while self.monotonic_stack and self.monotonic_stack[-1][0] <= pick:
            span += self.monotonic_stack[-1][1]
            self.monotonic_stack.pop()
        self.monotonic_stack.append((pick, span))    
        return span

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
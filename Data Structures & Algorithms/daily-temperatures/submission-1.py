class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack= []
        n = len(temperatures)
        result = [0]*n
        for i in range(n - 1, -1, -1):
            while stack and temperatures[stack[-1]] <= temperatures[i]:
                stack.pop()
            if stack and temperatures[i] < temperatures[stack[-1]]:
                result[i] = abs(i - stack[-1])
            stack.append(i)
        return result


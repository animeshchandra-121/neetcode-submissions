class Solution:
    def decodeString(self, s: str) -> str:
        n = len(s)
        stack= []
        for ch in s:
            if ch == ']':
                ch1 = ""
                while stack and stack[-1] != '[':
                    ch1 = stack.pop() + ch1
                stack.pop()
                num = ""
                while stack and stack[-1].isdigit():
                    num = stack.pop() + num
                stack.append(int(num) * ch1)
            else:
                stack.append(ch)
        return "".join(stack)
                
            

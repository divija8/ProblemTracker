class Solution:
    def robotWithString(self, s: str) -> str:
        freq = Counter(s)
        min_char = 'a'
        stack = []
        result = []

        for ch in s:
            stack.append(ch)
            freq[ch] -= 1

            while min_char <= 'z' and freq[min_char] == 0:
                min_char = chr(ord(min_char) + 1)

            while stack and stack[-1] <= min_char:
                result.append(stack.pop())
            
        
        return ''.join(result)
        
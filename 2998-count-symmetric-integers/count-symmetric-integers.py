class Solution:
    def is_symmetric(self, val: int) -> bool:
        s = str(val)
        if len(s) % 2 != 0:
            return False
        mid = len(s) // 2
        left = sum(int(d) for d in s[:mid])
        right = sum(int(d) for d in s[mid:])
        return left == right

    def countSymmetricIntegers(self, low: int, high: int) -> int:
        count = 0
        for i in range(low, high + 1):
            if self.is_symmetric(i):
                count += 1
        return count
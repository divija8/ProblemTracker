class Solution:
    def triangleType(self, nums: List[int]) -> str:
        l = len(set(nums))
        a, b, c = nums[0], nums[1], nums[2]

        if a + b > c and b + c > a and c + a > b:
            if l == 1 :
                return "equilateral"
            elif l == 2 :
                return "isosceles"
            elif l == 3:
                return "scalene"
        else:
            return "none"
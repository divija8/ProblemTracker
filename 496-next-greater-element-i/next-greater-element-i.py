class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nge_ele = {}
        stack = []
        
        for num in nums2:
            while stack and num > stack[-1]:
                prev = stack.pop()
                nge_ele[prev] = num
        
            stack.append(num)

        while stack:
                nge_ele[stack.pop()] = -1

        return [nge_ele[num] for num in nums1]
        
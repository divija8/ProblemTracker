class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        lmax = height[l]
        rmax = height[r]
        ans = 0
        while l <= r:
            if height[l] < height[r]:
                if min(lmax, rmax) >= height[l]:
                    ans += min(lmax, rmax) - height[l]
                l += 1
                if height[l] > lmax:
                    lmax = height[l]
                
            else:
                if min(lmax, rmax) >= height[r]:
                    ans += min(lmax, rmax) - height[r]
                r -= 1
                if height[r] > rmax:
                    rmax = height[r]
                
        return ans
        
        
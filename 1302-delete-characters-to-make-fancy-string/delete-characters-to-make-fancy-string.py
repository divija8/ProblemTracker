class Solution:
    def makeFancyString(self, s: str) -> str:
        ans = []
        ele = s[0]
        ans.append(ele)
        count = 1

        for i in range(1, len(s)):
            if s[i] == ele:
                count += 1
                if count < 3:
                    ans.append(s[i])
            else:
                ele = s[i]
                count = 1
                ans.append(s[i])
        return "".join(ans)
        
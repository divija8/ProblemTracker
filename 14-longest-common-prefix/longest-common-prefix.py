class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        pref = strs[0]

        for i in range(1, len(strs)):
            while strs[i].find(pref) != 0:
                pref = pref[0 : len(pref)-1]

                if pref == "":
                    return ""
        return pref

        
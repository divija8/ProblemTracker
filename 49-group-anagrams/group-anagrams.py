class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)

        for s1 in strs:
            count = [0] * 26
            for ch in s1:
                count[ord(ch) - ord('a')] += 1
            res[tuple(count)].append(s1)
        
        return list(res.values())
        
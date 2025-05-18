from typing import List

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        l, r = 0, len(products) - 1
        prefix = ""
        res = []

        for i in range(len(searchWord)):
            prefix += searchWord[i]

            while l <= r and (len(products[l]) < len(prefix) or not products[l].startswith(prefix)):
                l += 1

            while l <= r and (len(products[r]) < len(prefix) or not products[r].startswith(prefix)):
                r -= 1

            res.append([])
            for j in range(l, min(l + 3, r + 1)):
                res[-1].append(products[j])

        return res
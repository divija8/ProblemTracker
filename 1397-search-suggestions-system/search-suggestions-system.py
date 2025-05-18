class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        l, r = 0, len(products) - 1
        res = []
        for i in range(len(searchWord)):
            prefix = searchWord[i]
            while l <= r and (len(products[l]) <= i or products[l][i] != prefix):
                l += 1

            while l <= r and (len(products[r]) <= i or products[r][i] != prefix):
                r -= 1

            current = []
            for j in range(3):
                if l + j <= r :
                    current.append(products[l + j])
            res.append(current)
        return res
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        idx = word.find(ch)
        if(idx == -1):
            return word
        reversed_part = word[:idx+1][::-1]
        result  = reversed_part + word[idx+1:]
    
        return result
        

        
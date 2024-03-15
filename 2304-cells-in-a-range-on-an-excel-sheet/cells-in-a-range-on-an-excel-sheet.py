class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        ans = []
        start,end = s.split(":")
        start_let,start_num = start[0],start[1]
        end_let,end_num = end[0],end[1]
        for i in range(ord(start_let),ord(end_let)+1):
            for j in range(int(start_num),int(end_num)+1):
                ans.append(chr(i)+str(j))
        return ans
        
        
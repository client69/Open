class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        i = 1
        count = 0
        last = 0
        while(count != k):
            if i not in arr:
                count+=1
                last = i
            i+=1
        return last
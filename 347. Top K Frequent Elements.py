class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for i in nums:
            count[i] = 1+count.get(i, 0)
        
        array = []
        for i, cnt in count.items():
            array.append([cnt, i])
        array.sort()

        ans = []
        while len(ans) < k:
            ans.append(array.pop()[1])
        return ans


# Time Complexity: O(n log n)
# Space Complexity: O(n)
class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        counts = Counter(nums)
        pq = []
        for i, f in counts.items():
            heapq.heappush(pq, (f, i))
            if len(pq) > k:
                heapq.heappop(pq)
        ans = []
        while pq:
            f, i = heapq.heappop(pq)
            ans.append(i)
        return ans
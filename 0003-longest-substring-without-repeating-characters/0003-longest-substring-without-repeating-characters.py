class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = defaultdict(lambda: -1)
        l, ln = 0, 0
        for r in range(len(s)):
            if seen[s[r]] >= l:
                l = seen[s[r]] + 1
            seen[s[r]] = r
            ln = max(r - l + 1, ln)
        return ln
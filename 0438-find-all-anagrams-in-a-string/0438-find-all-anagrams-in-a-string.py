class Solution:
    def findAnagrams(self, s: str, p: str) -> list[int]:
        k = len(p)
        counts = Counter(p)
        ret = []

        for i in range(len(s) - k + 1):
            if counts == Counter(s[i:i+k]):
                ret.append(i)

        return ret
# O(n*k)
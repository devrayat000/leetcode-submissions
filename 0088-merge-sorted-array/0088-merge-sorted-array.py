class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        r1 = m - 1
        r2 = n - 1
        p = m + n - 1
        while r2 > -1:
            if r1 > -1 and nums1[r1] > nums2[r2]:
                nums1[p] = nums1[r1]
                r1 -= 1
            else:
                nums1[p] = nums2[r2]
                r2 -= 1
            p -= 1
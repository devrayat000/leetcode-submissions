class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums = sorted(nums1 + nums2)
        size = len(nums)
        if size % 2 == 0:
            i = size/2
            return float(nums[i]+nums[i-1]) / 2
        else:
            return nums[(size-1)/2]
        
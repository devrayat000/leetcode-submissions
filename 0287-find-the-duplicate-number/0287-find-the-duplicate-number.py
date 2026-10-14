class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        slow, fast = nums[0], nums[0]

        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        back = nums[0]
        while slow != back:
            slow = nums[slow]
            back = nums[back]
        return slow
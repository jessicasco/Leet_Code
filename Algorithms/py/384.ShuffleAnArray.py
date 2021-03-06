class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.orig = nums
        self.cur = nums[:]

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        self.cur = self.orig[:]
        return self.cur
    
    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        import random
        random.shuffle(self.cur)
        return self.cur


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()

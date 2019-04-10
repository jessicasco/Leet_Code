class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        count = 0
        diamond = set(J)
        for s in S:
            if s in diamond:
                count += 1
        return count

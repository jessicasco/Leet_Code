class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n != 0 and n&(n-1) == 0

    def isPowerOfTwo_1(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        while n != 1:
            if n % 2 == 0:
                n /= 2
            else:
                return False
        return True
class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        for c in set(s):
            if s.count(c) < k:
                return max(self.longestSubstring(ss, k) for ss in s.split(c))
        return len(s)

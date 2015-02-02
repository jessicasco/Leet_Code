class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return an integer
    def strStr(self, haystack, needle):
        i = 0
        while True:
            j = 0
            while True:
                if j == len(needle):
                    return i
                if i + j == len(haystack):
                    return -1
                if needle[j] != haystack[i+j]:
                    break
                j += 1
            i += 1


#include "leetcode.h"
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0;
        int high = n-1;
        while (low < high) {
            int middle = low + (high-low)/2;
            if (A[middle] == target) {
                return middle;
            } else if (A[middle] < target) {
                low = middle+1;
            } else {
                high = middle;
            }
        }
        return (A[low] < target) ? low + 1 : low;
    }
};
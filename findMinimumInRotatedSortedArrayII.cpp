#include "leetcode.h"
class Solution {
    public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size()-1);
    }
    private:
    int findMin(vector<int> &num, int start, int end) {
        if (start == end)
            return num[start];
        if (num[start] < num[end])
            return num[start];
        int mid = start + (end - start) / 2;
        if (num[start] == num[end])
            return findMin(num, start+1, end);
        if (num[mid] >= num[start])
            return findMin(num, mid+1, end);
        return findMin(num, start, mid);
    }
};

int main() {
    Solution s;
    //int nums[] = {4, 5, 6, 7, 1, 1, 1, 2};
    int nums[] = {1, 2};
    vector<int> num(nums, nums + sizeof(nums)/sizeof(nums[0]));
    cout << s.findMin(num) << endl;
    return 0;
}

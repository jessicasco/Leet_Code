class Solution {
public:
    int findMin(vector<int> &num) {
        int start = 0, end = num.size()-1;
        while (start < end && num[start] > num[end]) {
            int mid = start + (end - start)/2;
            if (num[mid] > num[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return num[start];
    }
    /*
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
        if (num[mid] >= num[start])
            return findMin(num, mid+1, end);
        return findMin(num, start, mid);
    }
    */
};

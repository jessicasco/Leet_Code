class Solution {
public:
    bool canJump(int A[], int n) {
        int maxIndex = 0;
        for (int i=0; i < n && i <= maxIndex; i++) {
            if (i+A[i] < maxIndex) {
                continue;
            }
            maxIndex = i + A[i];
            if (maxIndex >= n-1) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    int n = 25003;
    int A[25003];
    for (int i=0; i < 25000; i++) {
        A[i] = 25000-i;
    }
    A[25000] = 1;
    A[25001] = 0;
    A[25002] = 0;
    Solution s;
   // cout << s.canJump(A, n) << endl;
    A[0] = 0;
    A[1] = 1;
    cout << s.canJump(A, 2) << endl;
    return 0;
}


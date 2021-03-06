public class Solution {
    public boolean canJump(int[] A) {
        int n = A.length;
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
}

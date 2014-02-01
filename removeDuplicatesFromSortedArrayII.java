public class Solution {
    public int removeDuplicates(int[] A) {
        int n = A.length;
        if (n <= 2) {
            return n;
        }
        int j = 1;
        for (int i=2; i < n; i++) {
            if (A[i] != A[j-1]) {
                A[++j] = A[i];
            }
        }
        return j+1;
    }
}

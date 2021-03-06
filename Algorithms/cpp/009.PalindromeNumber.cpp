class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long i = 1;
        while (i*10 <= x) {
            i *= 10;
        }
        while (x > 0) {
            if (x/i == x%10) {
                x = x % i;
                x /= 10;
                i /= 100;
            }
            else {
                return false;
            }
        }
        return true;
    }
};


#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        string largestNumber(vector<int> &num) {
            std::sort(num.begin(), num.end(), cmp);
            if (num[0] == 0)
                return "0";
            string result = "";
            for (int i = 0; i < num.size(); i++) {
                result += std::to_string(num[i]);
            }
            return result;
        }
    private:
        bool static cmp(long x, long y) {
            long i = 10;
            while (i <= y) {
                i *= 10;
            }
            long xx = x*i + y;
            i = 10;
            while (i <= x) {
                i *= 10;
            }
            long yy = y * i + x;
            if (xx <= yy)
                return false;
            return true;
        }
};

int main() {
    int a[] = {5041,7233,8441,8543,6385,3510,7485,8082,2331,4285,1741,6090,5940,9375,1881,2398,8853,4536,5570,2602,670,3797,877,485,5293,2977,9745,6911,7724,6942,1018,5538,5975,814,8040,3729,8109,6632,7401,6251,9316,1160,3350,6454,169,9043,9985,9739,6648,8383,310,6228,9760,1091,2377,4596,4072,5725,5711,236,9743,9579,1136,707,4622,2247,230,6623,4310,1516,7388,1595,2204,1331,3109,4307,5117,6790,9996,3248,2877,7770,7156,6088,3034,3229,9354,6063,9388,2030,6176,3521,9438,3329,2533,2184,1247,7002,844,3161};
    int c[] = {41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55};
    int d[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> b(d , d+100);
    Solution s;
    cout << s.largestNumber(b) << endl;
    return 0;
}
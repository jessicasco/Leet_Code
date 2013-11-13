#include "leetcode.h"
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector< pair<double,ii> > vdii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = S.size();
        int m = T.size();
        int result[m+1][n+1];
        result[0][0] = 1;
        for (int i=1; i <= m; ++i) {
            result[i][0] = 0;
        }
        for (int j=1; j <= n; ++j) {
            result[0][j] = 1;
        }
        for (int i=1; i <= m; ++i) {
            for (int j=1; j <= n; ++j) {
                result[i][j] = result[i][j-1];
                if (S[j-1] == T[i-1]) {
                    result[i][j] += result[i-1][j-1];
                }
            }
        }
        return result[m][n];
    }
};
int main() {
    Solution s;
    string S = "rabbbit";
    string T = "rabbit";
    cout << s.numDistinct(S, T) << endl;
    return 0;
}


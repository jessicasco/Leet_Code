#include "leetcode.h"
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        set<vector<int> > result2;
        vector<int> path;
        DFS(result2, path, candidates, target, 0, 0);
        for (set<vector<int> >::iterator it=result2.begin(); it != result2.end(); it ++) {
            result.push_back(*it);
        }
        return result;
    }
    void DFS(set<vector<int> > &result, vector<int> path, 
            vector<int> &candidates, int target, int level, int sum) {
        if (sum == target) {
            result.insert(path);
            return;
        }
        if (sum > target) return;
        for (int i = level; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            DFS(result, path, candidates, target, i+1, sum + candidates[i]);
            path.pop_back();
        }
    }
    /*
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        set<vector<int> > temp;
        sort(candidates.begin(), candidates.end());
        //for (int i = 0; i < candidates.size(); i++) {
        //    cout << candidates[i] << (i == candidates.size()-1 ? "" : " ");
        //}
        //cout << endl;
        int index[target+2];
        index[0] = candidates.size();
        solve(target, candidates, index, 0, temp);
        for (set<vector<int> >::iterator it=temp.begin(); it != temp.end(); it ++) {
            result.push_back(*it);
        }
        return result;
    }
    
    void solve(int target, vector<int> &candidates, int index[], 
            int n, set<vector<int> > &result) {
        if (target < 0)
            return ;
        if (target == 0) {
            vector<int> v;
            for (int i = n; i >= 1; i--) {
                v.push_back(candidates[index[i]]);
            }
            result.insert(v);
        }
    
        for (int i = index[n]-1; i >= 0; i--) {
            index[n+1] = i;
            solve(target-candidates[i], candidates, index, n+1, result);
        }
    }
    */
    /*
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        int index[target];
        index[0] = 0;
        solve(target, 0, candidates, index, 0, result);
        return result;
    }
    
    void solve(int target, int sum, vector<int> &candidates, int index[], 
            int n, vector<vector<int> > &result) {
        if (sum > target)
            return;
        if (sum == target) {
            vector<int> v;
            for (int i=1; i <= n; i++) {
                v.push_back(candidates[index[i]]);
            }
            result.push_back(v);
        }
    
        for (int i = index[n]; i < candidates.size(); i++) {
            index[n+1] = i;
            solve(target, sum + candidates[i], candidates, index, n+1, result);
        }
    }
     for further thoughts on
     http://leetcode.com/2010/09/print-all-combinations-of-number-as-sum.html
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        int index[target];
        index[0] = -1;
        solve(target, 0, candidates, index, 0, result);
        return result;
    }
    
    void solve(int target, int sum, vector<int> &candidates, int index[], 
            int n, vector<vector<int> > &result) {
        if (sum > target)
            return;
        if (sum == target) {
            vector<int> v;
            for (int i=1; i <= n; i++) {
                v.push_back(candidates[index[i]]);
            }
            result.push_back(v);
        }
    
        for (int i = index[n]+1; i < candidates.size(); i++) {
            index[n+1] = i+1;
            solve(target, sum + candidates[i+1], candidates, index, n+1, result);
        }
    }
    */
};
int main() {
    Solution s;
    vector<int> candidates;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);
    vector<vector<int> > v = s.combinationSum2(candidates, 8);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ((j == v[i].size()-1)?"":" ");
        }
        cout << endl;
    }
    return 0;
}

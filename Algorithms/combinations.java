import java.util.*;
public class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();
        DFS(result, path, n, k, 1);
        return result;
    }
    private void DFS(List<List<Integer>> result,
            ArrayList<Integer> path,
            int n, int k, int min) {
        if (path.size() == k) {
            result.add((List<Integer>)path.clone());
            return;
        }
        for (int i = min; i <= n; i++) {
            path.add(i);
            DFS(result, path, n, k, i+1);
            path.remove(path.size()-1);
        }
    }
    /*
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();
        combine(n, k, 1, path, result);
        return result;
    }
    void combine(int n, int k, int min, ArrayList<Integer> path, 
            ArrayList<ArrayList<Integer>> result) {
        ArrayList<Integer> clone_path = (ArrayList<Integer>)path.clone();
        if (clone_path.size() == k) {
            result.add(clone_path);
            return;
        }
        if (min > n) {
            return;
        }
        combine(n, k, min+1, clone_path, result);
        clone_path.add(min);
        combine(n, k, min+1, clone_path, result);
    }
    */
    /*
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        
        ArrayList<ArrayList<Integer> > result = new ArrayList<ArrayList<Integer>>();
        for (int i=0; i < Math.pow(2, n); i++) {
            ArrayList<Integer> v = new ArrayList<Integer>();
            int j = i;
            int p = 1;
            int q = 0;
            while (j != 0) {
                if ((j & 0x01) != 0) {
                    v.add(p);
                    q ++;
                }
                p ++;
                j >>= 1;
            }
            if (k == q) {
                result.add(v);
            }
        }
        return result;
    }
    */
}

import java.util.*;
public class Solution {
    public ArrayList<Integer> grayCode(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<Integer> v = new ArrayList<Integer>();
        for (int i=0; i < (1<<n); i++) {
            v.add((i >> 1) ^ i);
        }
        return v;
    }
}

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int prev = 0, total = 0;
        for (int i = 0; i < s.size(); i++) {
            int curr = map[s[i]];
            total += (curr > prev) ? (curr - 2 * prev) : curr;
            prev = curr;
        }
        return total;
    }
};

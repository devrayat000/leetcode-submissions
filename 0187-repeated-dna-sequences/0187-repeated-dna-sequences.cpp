class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string, int> cache;
        vector<string> comb;

        for (int i = 0, j = 10; j <= n; i++, j++) {
            string sub = s.substr(i, 10);
            if (cache[sub] == 1) {
                comb.push_back(sub);
            }
            cache[sub]++;
        }

        return comb;
    }
};
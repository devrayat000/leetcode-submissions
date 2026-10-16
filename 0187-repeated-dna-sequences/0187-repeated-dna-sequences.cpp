class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string, int> cache;

        for (int i = 0, j = 10; j <= n; i++, j++) {
            string sub = s.substr(i, 10);
            cache[sub]++;
        }

        vector<string> comb;
        for (auto [key, freq] : cache) {
            if (freq > 1) {
                comb.push_back(key);
            }
        }

        return comb;
    }
};
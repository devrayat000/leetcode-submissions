class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto str : strs) {
            vector<int> freq(26, 0);
            for (const char& c : str) {
                freq[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < freq.size(); i++) {
                if (freq[i] > 0) {
                    key += to_string(i) + "(" + to_string(freq[i]) + ")";
                }
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> values;

        // Optimize memory allocation upfront
        values.reserve(mp.size());

        // [key, val] unpacks the map pair; we only push 'val'
        for (const auto& [key, val] : mp) {
            values.push_back(move(val));
        }

        return values;
    }
};

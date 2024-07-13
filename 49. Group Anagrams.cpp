class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;

        for(auto& s : strs){
            string str = s;
            sort(str.begin(), str.end());
            anagram[str].push_back(s);
        }

        vector<vector<string>> result;
        for(auto[x,y] : anagram){
            result.push_back(y);
        }
        return result;
    }
};

// Time complexity: O(n * m * log m)
// Space complexity: O(n)
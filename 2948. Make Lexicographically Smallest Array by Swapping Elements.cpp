// Date: 01/25/2025
// 2948. Make Lexicographically Smallest Array by Swapping Elements
// C++ Solution
// Sorting and Greedy Technique

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>>a;
        int n = nums.size();

        for(int i=0; i<n; i++){
            a.push_back({nums[i], i});
        }
        sort(a.begin(), a.end());

        vector<vector<pair<int, int>>>pair;
        pair.push_back({a[0]});

        for(int i=1; i<n; i++){
            if(a[i].first - a[i-1].first <= limit){
                pair.back().push_back(a[i]);
            }
            else{
                pair.push_back({a[i]});
            }
        }

        for(const auto& x : pair){
            vector<int>y;
            for(const auto& [value, index] : x){
                y.push_back(index);
            }
            sort(y.begin(), y.end());

            for (size_t i=0; i<y.size(); ++i){
                nums[y[i]] = x[i].first;
            }
        }
        return nums;
    }
};


// Time Complexity: O(nlogn)
// Space Complexity: O(n)
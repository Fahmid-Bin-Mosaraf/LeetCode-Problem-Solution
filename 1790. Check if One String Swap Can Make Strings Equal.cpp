// Date: 05/02/2025
// 1790. Check if One String Swap Can Make Strings Equal
// C++ Solution
// Greedy

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>a;
        for(int i=0; i< s1.size(); i++){
            if(s1[i] != s2[i]){
                a.push_back(i);
            }
        }
        
        if(a.size() == 0){
            return true;
        }
        if(a.size() != 2){
            return false;
        }
        return s1[a[0]] == s2[a[1]] && s1[a[1]] == s2[a[0]];
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size();
        vector<int>a(26, 0);

        for(int i=0; i<right; i++){
            a[s[i] - 'a']++;
        }

        for(int i=0; i<26; i++){
            int x = a[i];
            if(x % 2 != 0){
                left += x - 1;
            }
            else if (x != 0){
                left += x - 2;
            }
        }
        return right - left;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)
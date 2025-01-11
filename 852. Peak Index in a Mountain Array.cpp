// Binary Search

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        int k = arr.size()-1;

        while(i != k){
            int j = i+(k-i)/2;
            if(arr[j] < arr[j+1]){
                i = j+1;
            }
            else{
                k = j;
            }
        }
        return i;
    }
};


// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        for (int i = 0; i < n; i++) {
            a.push_back(nums[i]);
        }
        sort(a.begin(), a.end());
        int x = -1;
        int y = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != a[i]) {
                y = i;
                if (x == -1) {
                    x = i;
                }
            }
        }
        if (x != y) {
            return y - x + 1;    
        } else {
            return 0;
        }
        
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
        set<vector<int>> st;
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] + nums[i] > 0)
                    right--;
                else if (nums[left] + nums[right] + nums[i] < 0)
                    left++;

                else
                {
                    st.insert(st.end(), {nums[i], nums[left], nums[right]});
                    right--;
                    left++;
                }
            }
        }

        vector<vector<int>> master(st.begin(), st.end());

        return master;
        
    }
};
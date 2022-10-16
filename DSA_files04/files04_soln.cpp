class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
         vector<vector<int>> res;
         int len = nums.size();

        if (len < 4)
            return res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 1; i++)
        {

            long target1 = target - nums[i];

            for (int j = i + 1; j < len; j++)
            {

             long int target2 = target1 - nums[j];

                int left = j + 1;

                int right = len - 1;

                while (left < right)
                {

                    int two_sum = nums[left] + nums[right];

                    if (two_sum < target2)
                        left++;

                    else if (two_sum > target2)
                        right--;

                    else
                    {

                        vector<int> temp(4, 0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[left];
                        temp[3] = nums[right];
                        res.push_back(temp);

                       
                        while (left < right && nums[left] == temp[2])
                            ++left;

                        while (left < right && nums[right] == temp[3])
                            --right;
                    }
                }

           
                while (j + 1 < len && nums[j + 1] == nums[j])
                    ++j;
            }

       
            while (i + 1 < len && nums[i + 1] == nums[i])
                ++i;
        }

        return res;
    }
};

        
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
 
    // for couting of number of suitable subarray
    int count = 0;
    map<int, int> mp;
    // key -> remainder
    // value -> frequeny

    // initial condition
    int sum = 0;
    int rdr = 0;

    // remainder 0 has freq of 1
    mp[0] = 1;

    for (auto x : nums)
    {
        sum = sum + x;
        rdr = sum % k;

        if (rdr < 0)
        {
            rdr = rdr + k;
        }
        
        if (mp.find(rdr) != mp.end())
            count = count + mp[rdr];

        mp[rdr]++;

        // find sum and find remainder
        // if remainder add 7
    }
return count;
        
    }
};
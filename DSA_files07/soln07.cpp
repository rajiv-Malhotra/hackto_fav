#include<bits/stdc++.h>
using namespace std;

// This is soln to question 07

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;

		map<map<char,int>, vector<string>> m;

		int n = strs.size();

		for(int i = 0; i < n; i++){
			map<char,int> m1;

			string temp = strs[i];

			for(int j = 0; j< temp.size();j++){
				m1[temp[j]]++;
			}

			m[m1].push_back(strs[i]);
		}

	   for(auto i : m) ans.push_back(i.second);

		return ans;


        
    }
};
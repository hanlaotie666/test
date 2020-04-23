#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0) return false;
		if (k == 0) {
			for (int i = 1; i < n; i++)
				if (nums[i - 1] == nums[i] && nums[i] == 0) return true;
			return false;
		}
		vector<int> preSum(n,0);
		unordered_map<int, vector<int>> MyMap;//key 表示preSum[i] % k,value 表示下标的vector
		preSum[0] = nums[0];
		MyMap[preSum[0] % k].push_back(0);
		MyMap[0].push_back(-1);				//当余数为0时，特殊处理
		for (int i = 1; i < n; i++)
		{
			preSum[i] = preSum[i - 1] + nums[i];
			MyMap[preSum[i] % k].push_back(i);
		}
		unordered_map<int, vector<int>>::iterator it = MyMap.begin();
		for (; it != MyMap.end(); it++)
		{
			if (it->second.size() == 1) continue;
			else if (it->second.size() >= 3) return true;
			else
			{
				int temp1 = (it->second)[1];
				int temp2 = (it->second)[0];
				if (temp1 - temp2 > 1) return true;
				else continue;
			}
		}
		return false;
	}
};
int main()
{
	vector<int> nums{23,2,6,4,7};
	int k = 6;
	Solution sol;
	cout<<sol.checkSubarraySum(nums,k)<<endl;
	return 0;
}

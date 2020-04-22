using namespace std;
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int n;
	long long int money;
	vector<long long int> w;
	vector<vector<long long int>> dp;
	int getMin(long long int a, long long int b)
	{
		return a > b ? b : a;
	}
	int search(int idx, long long int m)
	{
		
		if (idx >= n) return 999999;
		if (m == money) return 0;
		if (dp[idx][m] < 99999) return dp[idx][m];

		if ((long long)(m + w[idx]) > money ) 
			dp[idx][m]=search(idx + 1, m);
		else
			dp[idx][m] = getMin(search(idx, m + w[idx]) + 1, search(idx + 1, m));
		return dp[idx][m];

	}
	int coinChange(vector<int>& coins, int amount) {
		money = amount;
		n = coins.size();
		for (int i = 0; i < n; i++) w.push_back(coins[i]);
		vector<vector<long long int>> f(n, vector<long long int>(money, 999999));
		dp = f;
		int res = search(0, 0);
		return res>9999 ? -1 : res;
	}
};
int main()
{
	vector<int> coins{ 1,2147483647 };
	int amount = 2;
	Solution sol;
	cout<<sol.coinChange(coins, 2)<<endl;
	return 0;
}

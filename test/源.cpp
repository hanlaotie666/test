#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int res;
vector<vector<int>> dp(3000, vector<int>(3000, -1));
int search(int n, int m)
{
	if (dp[n][m] >= 0) return dp[n][m];
	int temp;
	if (n < m) temp = 0;
	else if (m == 0) temp=1;
	else if (m == n) temp = 1;
	else
		temp= search(n - 1, m - 1) + search(n - 1, m);
	temp = temp % (1000000000 + 7);
	dp[n][m] = temp;
	return temp;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int temp = search(n - i + m - 1-1, n - i);
		temp = temp % (1000000000 + 7);
		res = (res + temp)%(1000000000 + 7);
	}
	cout << res << endl;
}
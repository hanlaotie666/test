#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int res;
vector<int> ans;
int n, m;
void search(int idx, int remained)
{
	if (idx > n) return;
	if (idx == n)
	{
		if (remained == 0)
		{
			res++;
			res = res % (1000000000 + 7);
			return;
		}
		else return;
	}
	for (int i = 0; i <= remained; i++)
	{
		ans.push_back(i);
		search(idx + 1, remained - i);
		ans.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	int temp;
	temp = m; m = n; n = temp;
	n = n - 1;
	for(int i=1;i<=m;i++)
		search(0, m-i);
	cout << res << endl;

}

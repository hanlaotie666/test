#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}
int main()
{
	int M, N;
	cin >> M >> N;
	vector<int> host(M,0);
	for (int i = 0; i < M; i++) cin >> host[i];
	sort(host.begin(), host.end());
	int tempmax = host[M-1];
	vector<pair<int, int>> req;
	for (int i = 0; i < N; i++)
	{
		int temp1, temp2; cin >> temp1 >> temp2;
		if (temp1 <= tempmax) {
			pair<int, int> pa;
			pa.first = temp1; pa.second=temp2;
			req.push_back(pa);
		}			
	}
	sort(req.begin(), req.end(), cmp);
	int res = 0;
	for (int i = 0; i < req.size(); i++)
	{
		int tempj=lower_bound(host.begin(), host.end(), req[i].first) - host.begin();
		if (tempj != host.size())
		{
			res += req[i].second;
			host.erase(host.begin() + tempj);
		}

	}
	cout << res << endl;
	return 0;
}
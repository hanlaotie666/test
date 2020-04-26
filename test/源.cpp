#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int main()
{
	int T;
	cin >> T;
	vector<int> res;
	for (int i = 0; i < T; i++)
	{
		int Q;
		cin >> Q;
		queue<int> myque;
		for (int i = 0; i < Q; i++)
		{
			string s;
			cin >> s;
			int a;
			if (s[0] == 'P'&& s[1]=='U') {
				cin >> a;
			}
	
			if (s[0] == 'P'&& s[1] == 'U') {
				myque.push(a);
			}
			if (s.compare("TOP") == 0) 
			{ 
				if (!myque.empty()) 
					res.push_back(myque.front());
				else res.push_back(-1);
			}
			if (s.compare("SIZE") == 0)
			{
				res.push_back(myque.size());
			}
			if (s.compare("POP") == 0)
			{
				if (!myque.empty())
					myque.pop();
				else res.push_back(-1);
				
			}
				
			if (s.compare("CLEAR") == 0)
			{
				while (!myque.empty()) myque.pop();
			}

		}
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int Exist(int len, string s)
	{
		for (int i = 0; i + len <= s.size(); i++)
		{
			string s_temp(s.begin() + i, s.begin() + i + len);
			string s_temp2(s_temp);
			reverse(s_temp2.begin(), s_temp2.end());
			if (s_temp.compare(s_temp2) == 0) return i;
		}
		return -1;
	}
	string longestPalindrome(string s) {
		int len = s.size();
		for (; len >= 1; len--)
			if (Exist(len, s) != -1) break;
		int  i = Exist(len, s);
		string res(s.begin()+i,s.begin()+i+len);
		return res;
	}
};
int main()
{
	string s;
	cin >> s;
	Solution sol;
	cout << sol.longestPalindrome(s) << endl;
}
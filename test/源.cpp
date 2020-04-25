//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//	bool IsHuiwen(string s)
//	{
//		string s1(s);
//		reverse(s1.begin(), s1.end());
//		if (s1.compare(s) == 0) return true;
//		return false;
//	}
//	int search(int idx,string s)
//	{
//		if (idx == s.size()-1) return 1;
//		int num = 0;
//		for (int len = 1; idx + len <= s.size(); len++)
//		{
//			string temp(s.begin() + idx, s.begin() + idx+ len);
//			if (IsHuiwen(temp)) num += 1;
//		}
//		return search(idx + 1, s)+num;
//	}
//	int countSubstrings(string s) {
//		return search(0,s);
//	}
//};
//
//
//int main()
//{
//	Solution sol;
//	cout << sol.countSubstrings("aaa") << endl;
//}
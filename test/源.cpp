#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
using namespace std;
double getMinDis(vector<pair<int, int>> A, vector<pair<int, int>> B)
{
	double mindis = 99999999;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			int A_x = A[i].first, A_y = A[i].second;
			int B_x = B[j].first, B_y = B[j].second;
			if (sqrt((A_x - B_x)*(A_x - B_x) + (A_y - B_y)*(A_y - B_y)) < mindis)
				mindis = sqrt((A_x - B_x)*(A_x - B_x) + (A_y - B_y)*(A_y - B_y));
		}
	}
	return mindis;
}
int main()
{
	int T;
	cin >> T;
	vector<double> res;
	for (int i = 0; i < T; i++)
	{
		vector<pair<int, int>> A, B;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			pair<int, int> temp;
			cin >> temp.first >> temp.second;
			A.push_back(temp);
		}
		for (int j = 0; j < n; j++)
		{
			pair<int, int> temp;
			cin >> temp.first >> temp.second;
			B.push_back(temp);
		}
		res.push_back(getMinDis(A, B));

	}
	for (int i = 0; i < res.size(); i++)
		printf("%.3lf\n", res[i]);
	return 0;
}
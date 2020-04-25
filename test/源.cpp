#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	queue<pair<pair<int,int>,int>> myque; //存储 第 i 层  j 操作  a当前的值
	myque.push(pair<pair<int,int>,int>(pair<int,int>(0,0),a+1)); 
	myque.push(pair<pair<int, int>, int>(pair<int, int>(0, 1), a-1));
	myque.push(pair<pair<int, int>, int>(pair<int, int>(0, 2), a*2));
	int res = 0;
	while (!myque.empty())
	{
		pair<pair<int, int>, int> opera = myque.front();
		myque.pop();
		int now_a = opera.second;
		if (now_a == b) { res = opera.first.first + 1; break; }
		for (int i = 0; i < 3; i++)
			if(i==0) myque.push(pair<pair<int, int>, int>(pair<int,int>(opera.first.first + 1, i), now_a+1));
			else if(i==1) myque.push(pair<pair<int, int>, int>(pair<int, int>(opera.first.first + 1, i), now_a-1));
			else myque.push(pair<pair<int, int>, int>(pair<int, int>(opera.first.first + 1, i), now_a*2));
	}
	cout << res << endl;
	return 0;
}
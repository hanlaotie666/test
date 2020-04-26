#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#define MAXSIZE 10000 
#define Infinity 65535 
using namespace std;
typedef struct
{
	double x;
	double y;
	int flag;
} point;
point s1[MAXSIZE], s2[MAXSIZE], s[MAXSIZE], t[MAXSIZE];
double cp(int low, int high);
double distance(const point u, const point v)
{
	if (u.flag != v.flag)
		return sqrt((u.x - v.x)*(u.x - v.x) + (u.y - v.y)*(u.y - v.y));
	else
		return (double)Infinity;
}

void fast_sort_X_Y(point *s, int begin, int end, bool flag)
{
	if (!flag)
	{
		if (begin<end)
		{
			int i, j;
			i = begin; j = end;
			point temp = s[begin];
			while (i<j)
			{
				while (i<j&&s[j].x >= temp.x)
					j--;
				s[i] = s[j];
				while (i<j&&s[i].x <= temp.x)
					i++;
				s[j] = s[i];
			}
			s[i] = temp;
			fast_sort_X_Y(s, begin, i - 1, flag);
			fast_sort_X_Y(s, i + 1, end, flag);
		}
	}
	else 
	{
		if (begin<end)
		{
			int i, j;
			i = begin; j = end;
			point temp = s[begin];
			while (i<j)
			{
				while (i<j&&s[j].y >= temp.y)
					j--;
				s[i] = s[j];
				while (i<j&&s[i].y <= temp.y)
					i++;
				s[j] = s[i];
			}
			s[i] = temp;
			fast_sort_X_Y(s, begin, i - 1, flag);
			fast_sort_X_Y(s, i + 1, end, flag);
		}
	}
}
double distance_Of_Three_Or_Less(point *s, int low, int high)
{
	double temp1, temp2, temp3;
	if ((high - low)<1)
	{
		cout << "少于两个点，出错！" << endl;
		return Infinity;
	}
	else if ((high - low) == 1) 
	{
		return distance(s[low], s[high]);
	}
	else
	{
		temp1 = distance(s[low],s[low + 1]);
		temp2 = distance(s[low],s[high]);
		temp3 = distance(s[low + 1],s[high]);
		double temp = temp1<temp2 ? temp1 : temp2;
		return temp<temp3 ? temp : temp3;
	}
}
double cp(point *s, int low, int high)
{
	int mid, k, i, j;
	double x0, dl, dr, d, d1;
	if ((high - low)<3)
	{
		return distance_Of_Three_Or_Less(s, low, high);
	}
	else
	{
		mid = (low + high) / 2;
		x0 = s[mid].x;
		dl = cp(s,low,mid);
		dr = cp(s,(mid + 1),high);
		d = (dl>dr) ? dr : dl;
		k = -1;
		for (i = low; i <= high; i++)
		{
			if (fabs(s[i].x - x0) <= d)
			{
				k++;
				t[k] = s[i];
			}
		}
		fast_sort_X_Y(t,0,k,1);
		d1 = 2 * d;
		k++;//k为t数组元素的个数

		for (i = 0; i<k - 1; i++)
		{
			for (j = (i + 1); j<(((i + 7)<k) ? (i + 7) : k); j++)
				if (distance(t[i],t[j]) < d1)
					d1 = distance(t[i],t[j]);
		}
		if (d1<d)
			d = d1;
		}
		return d;
}
void main()
{
	int T;
	cin >> T;
	vector<double> res;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		int n1, n2;
		n1 = n; n2 = n;
		for (int j = 0; j<n1; ++j)
		{
			cin >> s1[j].x >> s1[j].y;
			s1[j].flag = 1;
			s[j] = s1[j];
		}
		for (int j = 0; j<n2; ++j)
		{
			cin >> s2[j].x >> s2[j].y;
			s2[j].flag = 2;
			s[n1 + j] = s2[j];
		}
		fast_sort_X_Y(s, 0, n1 + n2 - 1, 0);
		res.push_back(cp(s, 0, n1 + n2 - 1));		
	}
	for (int i = 0; i < res.size(); i++)
		printf("%.3lf\n", res[i]);

}
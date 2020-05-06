#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
using namespace std;
vector<vector<int>> allpaths;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
int res=-99999999;
TreeNode* Build(string str)
{
	TreeNode* root = new TreeNode(-99999999);
	//判断有无括号
	int tempi = -1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') { tempi = i; break; }
	}
	if (tempi != -1)//有'('
	{
		string stemp = str.substr(0, tempi);
		int a = atoi(stemp.c_str());
		root->val = a;
		while ((tempi--) >= 0) str.erase(str.begin());
		str.erase(str.end() - 1);
		//找','号
		string::size_type  mypos = str.find(",");
		if (str.find(",") != str.npos)
		{
			string str1 = str.substr(0, mypos);
			string str2 = str.substr(mypos+1);
			root->left = Build(str1);
			root->right = Build(str2);
			return root;
		}
		else
		{
			int a = atoi(str.c_str());
			root->val = a;
			return root;
		}

	}
	else
	{
		string::size_type  mypos = str.find(",");
		if (str.find(",") != str.npos)
		{
			string str1 = str.substr(0, mypos + 1);
			string str2 = str.substr(mypos);
			root->left = Build(str1);
			root->right = Build(str2);
			return root;
		}
		else
		{
			int a = atoi(str.c_str());
			root->val = a;
			return root;
		}
	}
	return NULL;
}
vector<vector<int> > allPath;
//找到所有路径
void findAllPath(TreeNode* pRoot, vector<int>&path) {
	if (pRoot == NULL)
	{
		return;
	}
	path.push_back(pRoot->val);
	if (pRoot->left == NULL&&pRoot->right == NULL) //达到了叶子节点
	{
		allPath.push_back(path);//保存路径
	}
	if (pRoot->left != NULL)//左子树
	{
		findAllPath(pRoot->left, path);
	}
	if (pRoot->right != NULL)//右子树
	{
		findAllPath(pRoot->right, path);
	}
	path.pop_back();//在返回到父节点之前，在路径上删除当前节点
}
int maxSubArray(vector<int>& nums) {
	int ans = 0;
	int max = -2147483647;
	for (int i = 0; i<nums.size(); i++)
	{
		if (ans<0) ans = 0;
		ans = ans + nums[i];
		if (ans>max)
			max = ans;
	}
	return max;
}

int main()
{
	string temp;
	cin >> temp;
	TreeNode* root =Build(temp);
	vector<int> path;
	findAllPath(root,path);
	for (int i = 0; i < allPath.size(); i++)
	{
		int temp = maxSubArray(allPath[i]);
		res = res > temp ? res : temp;
	}
	cout << res << endl;
	return 0;
}
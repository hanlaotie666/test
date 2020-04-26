#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxjiedian;
TreeNode *root;
vector<TreeNode *> now_root;
TreeNode* Build_Tree(int val)
{
	if (val > maxjiedian) return NULL;
	TreeNode* root = new TreeNode(val);
	root->left = Build_Tree(2*val);
	root->right = Build_Tree(2 * val + 1);
	return root;	
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL)
		return NULL;
	if (root == p || root == q)
		return root;

	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);

	if (left == NULL)
		return right;
	if (right == NULL)
		return left;
	if (left && right) 
		return root;
	return NULL; 
}

void GetNodePath(TreeNode* root, int node, vector<int> &v, bool& flag)
{
	if (root == NULL || flag == true)
		return;
	GetNodePath(root->left, node, v, flag);
	GetNodePath(root->right, node, v, flag);
	if (root->val == node || flag == true)
	{
		v.push_back(root->val);
		now_root.push_back(root);
		flag = true;
	}
}
vector<int> getPath(int a, int b)
{
	vector<int> hah;
	bool flag = false;
	now_root.clear();
	GetNodePath(root, a, hah, flag);
	TreeNode* temp_a = now_root[0];
	flag = false;
	now_root.clear();
	GetNodePath(root, b, hah, flag);
	TreeNode* temp_b = now_root[0];
	TreeNode* gonggong = lowestCommonAncestor(root, temp_a, temp_b);
	vector<int> haha1,haha2;
	flag = false;
	GetNodePath(gonggong, a, haha1, flag);
	flag = false;
	GetNodePath(gonggong, b, haha2, flag);
	reverse(haha2.begin(), haha2.end());
	for (int i = 1; i < haha2.size(); i++)
		haha1.push_back(haha2[i]);
	return haha1;
}
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> ml;
	int maxu = 0, maxv = 0;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp; int temp1;
		cin >> temp1; temp.push_back(temp1);
		int len = 0;
		if (temp1 == 1) len = 3; else len = 2;
		for (int i = 0; i < len; i++) { cin >> temp1; temp.push_back(temp1); }
		ml.push_back(temp);
		if (temp[1] > maxu) maxu = temp[1];
		if (temp[2] > maxv) maxv = temp[2];
	}

	maxjiedian = maxu > maxv ? maxu : maxv;
	root = Build_Tree(1);
	vector<pair<vector<int>,int>> zongpath;
	vector<int> res;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp = ml[i];
		vector<int> path_temp;
		if (temp[0] == 1)
		{
			path_temp = getPath(temp[1], temp[2]);
			pair<vector<int>, int> hhhh;
			hhhh.first = path_temp; hhhh.second = temp[3];
			zongpath.push_back(hhhh);
		}
		if (temp[0] == 2)
		{
			vector<int> new_path= getPath(temp[1], temp[2]);
			int res_temp = 0;
			for (int j = 0; j < new_path.size() - 1; j++)
			{
				for (int k = 0; k < zongpath.size(); k++)
				{
					vector<int> zongtemp = zongpath[k].first;
					for (int m = 0; m < zongtemp.size() - 1; m++)
					{
						if (zongtemp[m] == new_path[j] && zongtemp[m + 1] == new_path[j + 1])
							res_temp += zongpath[k].second;
						if (zongtemp[m+1] == new_path[j] && zongtemp[m] == new_path[j + 1])
							res_temp += zongpath[k].second;
					}
				}
			}
			res.push_back(res_temp);
		}
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}
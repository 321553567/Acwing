#include<iostream>
#include<vector>
using namespace std;
// 题目链接：https://sim.csp.thusaac.com/contest/32/problem/0
// 仓库规划问题，已经AC，三层for循环暴力求解
int main()
{
	int n, m; // n是仓库个数，m是位置编码的维数
	cin >> n >> m;
	// 仓库二维数组
	vector<vector<int>> warehouse(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> warehouse[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		// 上级仓库
		vector<vector<int>> smallest(2, vector<int>(m));
		int up = 0;//最小的上级仓库的编号
		// 对每个仓库进行判断
		int num = 0;// num用来判断当前上家仓库有几个
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue; // 跳过自身
			// 对仓库中的每一个位置编码进行判断
			int temp = 0; // temp用来判断是否是上级仓库
			for (int t = 0; t < m; t++)
			{
				if (warehouse[j][t] <= warehouse[i][t])	temp++;
			}
			if (temp == 0) // 也就是说确认warehouse[j]是一个上级仓库
			{
				// 如果有多个仓库都是上级仓库，要判断的是编号更小，而不是里面的编码更小，服了，调代码调了一个多小时，做梦都没想到是这出了问题
				if (up == 0 || j < up)
				{
					up = j + 1;
				}
			}
		}
		cout << up << endl;
	}
	return 0;
}
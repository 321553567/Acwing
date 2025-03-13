#include<iostream>
#include<vector>
using namespace std;
// ��Ŀ���ӣ�https://sim.csp.thusaac.com/contest/32/problem/0
// �ֿ�滮���⣬�Ѿ�AC������forѭ���������
int main()
{
	int n, m; // n�ǲֿ������m��λ�ñ����ά��
	cin >> n >> m;
	// �ֿ��ά����
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
		// �ϼ��ֿ�
		vector<vector<int>> smallest(2, vector<int>(m));
		int up = 0;//��С���ϼ��ֿ�ı��
		// ��ÿ���ֿ�����ж�
		int num = 0;// num�����жϵ�ǰ�ϼҲֿ��м���
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue; // ��������
			// �Բֿ��е�ÿһ��λ�ñ�������ж�
			int temp = 0; // temp�����ж��Ƿ����ϼ��ֿ�
			for (int t = 0; t < m; t++)
			{
				if (warehouse[j][t] <= warehouse[i][t])	temp++;
			}
			if (temp == 0) // Ҳ����˵ȷ��warehouse[j]��һ���ϼ��ֿ�
			{
				// ����ж���ֿⶼ���ϼ��ֿ⣬Ҫ�жϵ��Ǳ�Ÿ�С������������ı����С�����ˣ����������һ����Сʱ�����ζ�û�뵽�����������
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
# include<iostream>

using namespace std;
// 快速排序
const int N = 1e7+10;

int n;// 第一行输入，表示输入多少个数
int q[N];// 存储用的数组
// 通过双指针求解，左指针为l，右指针为r
void quick_sort(int q[], int l, int r)
{
	// 数组内只有一个元素或者元素为空的情况
	if (l >= r) return;
	// 选择一个分界值，将数组分成左右两部分，这里选择中间元素
	int x = q[(l + r) / 2];
	// 设置i和j为我们的双指针，但不要直接设置成l和r，因为接下来我们要进行do while
	int i = l - 1, j = r + 1;
	while (i < j)
	{
		// i从左到右移动，直到找到一个大于等于基准值x的元素
		// i从右到左移动，直到找到一个小于等于基准值x的元素
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		// 交换两数
		if (i < j) swap(q[i], q[j]);
	}
	// 对剩下部分进行操作

	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}
int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &q[i]);
	}
	quick_sort(q, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", q[i]);
	}
	return 0;
}
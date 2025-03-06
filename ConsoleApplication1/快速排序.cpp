# include<iostream>

using namespace std;
// ��������
const int N = 1e7+10;

int n;// ��һ�����룬��ʾ������ٸ���
int q[N];// �洢�õ�����
// ͨ��˫ָ����⣬��ָ��Ϊl����ָ��Ϊr
void quick_sort(int q[], int l, int r)
{
	// ������ֻ��һ��Ԫ�ػ���Ԫ��Ϊ�յ����
	if (l >= r) return;
	// ѡ��һ���ֽ�ֵ��������ֳ����������֣�����ѡ���м�Ԫ��
	int x = q[(l + r) / 2];
	// ����i��jΪ���ǵ�˫ָ�룬����Ҫֱ�����ó�l��r����Ϊ����������Ҫ����do while
	int i = l - 1, j = r + 1;
	while (i < j)
	{
		// i�������ƶ���ֱ���ҵ�һ�����ڵ��ڻ�׼ֵx��Ԫ��
		// i���ҵ����ƶ���ֱ���ҵ�һ��С�ڵ��ڻ�׼ֵx��Ԫ��
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		// ��������
		if (i < j) swap(q[i], q[j]);
	}
	// ��ʣ�²��ֽ��в���

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
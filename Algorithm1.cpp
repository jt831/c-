#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
int sum = 0;
int test(int a)
{
	
	if (a == 1)
	{
		return 1;
	}
	return a + test(a - 1);
}
void QuickSort(int* A, int left, int right) //��������
{
    if (left >= right) return;
    int x = A[(left + right) >> 1], low = left, high = right;
    while (low < high)
    {
        while (A[low] < x)
            low++;
        while (A[high] > x)
            high--;
        if (low <= high)
        {
            int Temp = A[low];
            A[low] = A[high];
            A[high] = Temp;
            low++;
            high--;
        }
    }
    QuickSort(A, left, high);
    QuickSort(A, low, right);
}
long long SolveStepUpdate(int nStair) //n�����ӣ�һ�ο�����1��n�������м��ַ���
{
	if (nStair <= 0)
		return 0;
	else if (nStair == 1)
		return 1;
	else
	{
		long long step = 0;
		long long fstep = 1;
		for (int i = 2; i <= nStair; ++i)
		{
			step = 2 * fstep;
			fstep = step;
		}
		return step;
	}
}
long long SolveStepUpdate1(int nStair) //����ĵݹ�ʵ��
{
	if (nStair <= 0)
		return 0;
	else if (nStair == 1)
		return nStair;
	else
		return 2*SolveStepUpdate1(nStair - 1);
}

int cmp(const void* a, const void* b) //c�Դ�qsort�е��βΡ���cmp����ʵ��
{
	return(*(int*)a - *(int*)b);  //���� 
	//return(*(int *)b-*(int *)a); //���� 
}
int main()
{
	int a[] = {15,48,55,0,44,20,11};
	//qsort(a,7,sizeof(a[0]),cmp);
    /*QuickSort(a, 0, 55);
	for (auto i : a)
	{
		cout << i<<" ";
	}*/
	cout << SolveStepUpdate(5);
	return 0;
}
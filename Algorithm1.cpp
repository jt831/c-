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
void QuickSort(int* A, int left, int right) //快速排序
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
long long SolveStepUpdate(int nStair) //n级梯子，一次可以跳1—n级，问有几种方法
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
long long SolveStepUpdate1(int nStair) //上面的递归实现
{
	if (nStair <= 0)
		return 0;
	else if (nStair == 1)
		return nStair;
	else
		return 2*SolveStepUpdate1(nStair - 1);
}

int cmp(const void* a, const void* b) //c自带qsort中的形参——cmp函数实现
{
	return(*(int*)a - *(int*)b);  //升序 
	//return(*(int *)b-*(int *)a); //降序 
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
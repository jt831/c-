#include <iostream>
using namespace std;

#define COL 3
#define LIST 3
struct Matrix {
	int m[COL][LIST];

};
Matrix MatrixMul(Matrix a, Matrix b)
{
	Matrix c= {
		{
			{ 0, 0 ,0},
			{ 0, 0,0 },
		{0,0,0}
		}
	};
	int k=0,l=0;
	
	while (l<LIST) 
	{
		while (k < COL)
		{
			int i = k, j = l;
			for (; i < COL && j < LIST; i++, j++)
			{
				c.m[k][l] += a.m[k][j] * b.m[i][l];
			}
			k++;
		}
		l++,k=0;
	}
	return c;


}

int main() {
	Matrix c = 
	{
		{
			{ 8, 0 ,8}, 
		    { 0, 8 ,8},
			{ 5, 4 ,8}
		} 
	};
	Matrix k=MatrixMul(c, c);
	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < LIST; j++) {
			cout << k.m[i][j] << " ";
		}
		cout << endl;
	}
	
	



	return 0;
}
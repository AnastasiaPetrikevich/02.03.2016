#include <iostream>
using namespace std;
void QuickSort(int*, int);
void QuickSort(int*, int, int);
void DisplayArray(int*, int);
int* AllocArray(int );

int main()
{
	int n;
	while (true)
	{
		cout << "Enter size of array: " << endl;
		cin >> n;
		if (n > 0) break;
		cout << "Error!";
	}
	system("cls");
	int* a = AllocArray(n);
	cout << "Source array: " << endl;
	DisplayArray(a, n);
	QuickSort(a, n);
	cout << endl << "Array after sort: " << endl;
	DisplayArray(a, n);
	system("pause");
	system("cls");
	return 0;
}

int* AllocArray(int n)
{
	int  *a = new int[n];
	for (int* p = a; p < a + n; p++)
		*p = rand() %100;
	return a;
}

void QuickSort(int* a, int n)
{
	QuickSort(a, 0, n - 1);
}

void QuickSort(int* a, int left, int right)
{
	int i = left, j = right;
	int t;
	int point = a[(left + right) / 2];

	while (i <= j)
	{
		while (a[i] < point)
			i++;
		while (a[j] > point)
			j--;
		if (i <= j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	};

	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);

}

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
}

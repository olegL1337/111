#include <iostream>
#include <cstdlib>
#include <time.h>
//КОМЕНТАР
//коМЕНТАР
using namespace std;
void merge(int *arr, int l, int m, int r, int &c, int &m_p);
void mergeSort(int *arr, int l, int r, int &c_p, int &m_p);
int main() {
	setlocale(LC_ALL, "ukr");
	int n;
	cout << "vveditb rosmir";
	cin >> n;
	//srand(time(0));
	int *arr = new int[n];
	for (int i = 0; i < n; arr[i] = rand() % 100 + 1, i++)
		;

	for (int i = 0; i < n; cout << arr[i] << " ", i++)
		;
	int c_p = 0, m_p = 0;
	int a = clock();
	mergeSort(arr, 0, n - 1, c_p, m_p);
	for (int i = 0; i < n; cout << arr[i] << " ", i++)
		;
	cout << endl << "m= " << m_p << " c= " << c_p;
	cout << endl;
	cout << "час";
	cout << clock() - a << endl;
	return 0;
}
void merge(int *arr, int l, int m, int r, int &c, int &m_p) {
	int i, j, k;
	int const n1 = m - l + 1;
	int const n2 = r - m;

	int *L = new int[n1];
	int *R = new int[n2];
	for (i = 0; i < n1; L[i] = arr[l + i], i++)
		;
	for (j = 0; j < n2; R[j] = arr[m + 1 + j], j++)
		;
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			m++;
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		c++;
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int *arr, int l, int r, int &c_p, int &m_p) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m, c_p, m_p);
		mergeSort(arr, m + 1, r, c_p, m_p);
		merge(arr, l, m, r, c_p, m_p);
	}
}

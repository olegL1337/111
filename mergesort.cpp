#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
void QuickSort(int *arr, unsigned int N, int L, int R, int &c_p, int &m_p);
void merge(int *arr, int l, int m, int r, int &c, int &m_p);
void mergeSort(int *arr, int l, int r, int &c_p, int &m_p);
void heapify(int *arr, int n, int i, int &c_p, int &m_p);
void HeapSort(int *arr, int n, int &c_p, int &m_p);
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
	cout << endl;
	cout << "1: швидке " << endl;
	cout << "2: злиттям" << endl;
	cout << "3: пiрамiдальне" << endl;
	int k;
	cout << "k:";
	cin >> k;
	int c_p = 0, m_p = 0;
	int a = clock();
	if (k > 0 && k <= 7) {
		switch (k) {
		case 1:
			QuickSort(arr, n, 0, n - 1, c_p, m_p);
			break;
		case 2:
			mergeSort(arr, 0, n - 1, c_p, m_p);
			break;
		case 3:
			HeapSort(arr, n, c_p, m_p);
			break;
		}
	}
	for (int i = 0; i < n; cout << arr[i] << " ", i++)
		;
	cout << endl << "m= " << m_p << " c= " << c_p;
	cout << endl;
	cout << "час";
	cout << clock() - a << endl;
	return 0;
}
void QuickSort(int *arr, unsigned int N, int L, int R, int &c_p, int &m_p) {
	int i = L, j = R;
	int x = arr[(R + L) / 2];
	do {
		while (arr[i] < x) {
			i++;
			m_p++;
		}
		while (x < arr[j]) {
			j--;
			m_p++;
		}
		if (i <= j) {
			swap(arr[i++], arr[j--]);
			c_p++;
			m_p++;
		}
	} while (i < j);
	if (L < j)
		QuickSort(arr, N, L, j, c_p, m_p);
	if (i < R)
		QuickSort(arr, N, i, R, c_p, m_p);
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

void heapify(int *arr, int n, int i, int &c_p, int &m_p) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest]) {
		largest = l;
		m_p++;
	}
	if (r < n && arr[r] > arr[largest]) {
		largest = r;
		m_p++;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]);
		c_p++;
		heapify(arr, n, largest, c_p, m_p);
	}
}

void HeapSort(int *arr, int n, int &c_p, int &m_p) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, c_p, m_p);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		c_p++;
		heapify(arr, i, 0, c_p, m_p);
	}
}

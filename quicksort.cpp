#include <iostream>
#include <ctime>
using namespace std;
void out(int *mass, int n)
{
	for (int i = 0; i<n; cout << mass[i] << ends, i++);
	cout << endl;
}
void quicksort(int *mass, int start, int end)
{
	int i = start, j = end;
	int tmp;
	int pivot = mass[(start + end) / 2];

	while (i <= j) {
		while (mass[i] < pivot)
			i++;
		while (mass[j] > pivot)
			j--;
		if (i <= j) {
			tmp = mass[i];
			mass[i] = mass[j];
			mass[j] = tmp;
			i++;
			j--;
		}
	};
	if (start < j)
		quicksort(mass, start, j);
	if (i < end)
		quicksort(mass, i, end);
}
int main()
{
	srand(time(NULL));
	int n, vybir = 1;
	clock_t t;
	double T;
	cout << "n="; cin >> n;
	int *mass = new int[n];

	cout << "Input: " << endl;
	for (int i = 0; i<n; cin >> mass[i], i++);
	//for(int i=0; i<n; mass[i]=-10+rand()%1000, i++);
	out(mass, n);

	t = clock();
	quicksort(mass, 0, n - 1);
	t = clock() - t;
	T = (float)t / CLOCKS_PER_SEC;
	cout << "Result:" << endl;
	out(mass, n);
	cout << "Time:  " << T << "c" << endl << endl;
	delete[] mass;
	system("pause");
}
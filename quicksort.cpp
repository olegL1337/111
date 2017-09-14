#include <iostream>
#include <ctime>
using namespace std;
void out(int *mass, int n)
{
	for (int i = 0; i<n; cout << mass[i] << ends, i++);
	cout << endl;
}
int parsition(int *mass, int start, int end)
{
	int pivot = mass[end / 2];
	int pindex = start;
	for (int i = start; i<end; i++)
	{
		if (mass[i] <= pivot)
		{
			swap(mass[i], mass[pindex]);
			pindex++;
		}
	}
	swap(mass[pindex], mass[end]);
	return pindex;
}
void quicksort(int *mass, int start, int end)
{
	if (start<end)
	{
		int pindex = parsition(mass, start, end);
		quicksort(mass, start, pindex - 1);
		quicksort(mass, pindex + 1, end);
	}

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
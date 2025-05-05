#include <iostream>
using namespace std;

static int podzial(int tab[], int start, int koniec) {
	int pivot = tab[koniec];
	int i = start - 1;

	for (int j = start; j <= koniec;j++) {
		if (tab[j] < pivot) {
			i++;
			int temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
	}
	i++;
	int temp = tab[i];
	tab[i] = tab[koniec];
	tab[koniec] = temp;

	return i;
}

static void sortowanie(int tab[], int start, int koniec) {
	if (koniec <= start) return;

	int pivot = podzial(tab, start, koniec);
	sortowanie(tab, start, pivot - 1);
	sortowanie(tab, pivot + 1, koniec);
}

int main() {
	int tab[] = {3,2,1,4,5,9,8,7,6,10,11,12,13,14,15,18,17,16,19};
	int size = sizeof(tab) / sizeof(tab[0]);

	sortowanie(tab, 0, size - 1);

	//wypisanie
	for (int i = 0; i < size; i++) {
		cout << tab[i] << " ";
	}
}
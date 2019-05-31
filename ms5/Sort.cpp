/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

namespace sict {

	template<typename T>
	void Sort(T SortArray[], int n) {
		for (int i = 0; i < n; i++) {
			int idk = i;
			for (int cnt = i + 1; cnt < n; cnt++) {
				if (SortArray[cnt] < SortArray[idk]) {
					idk = cnt;
				}
				if (idk != i) {
					int temp = SortArray[i];
					SortArray[i] = SortArray[idk];
					SortArray[idk] = SortArray[temp];
				}
			}
		}
	}
}

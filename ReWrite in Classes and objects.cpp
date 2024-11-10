#include <iostream>

void Create(int num);
void SortMassive(int* mas, int num);
void RESULT(int* mas, int num);

void Create(int num) {
	int* mas = new int[num];
	for (int i = 0; i < num; i++) {
		std::cin >> mas[i];
	}
	SortMassive(mas, num);
}

void SortMassive(int* mas, int num) {
	for (int i = 0; i < num ; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (mas[j] < mas[j + 1]) {
				int temp = 0;
				temp = mas[j+1];
				mas[j + 1] = mas[j];
				mas[j] = temp;
			}
		}
	}
	RESULT(mas, num);
}
void RESULT(int* mas, int num) {
	for (int i = 0; i < num; i++) {
		std::cout << mas[i] << " ";
	}
}


int main()
{
	int N;
	std::cin >> N;
	Create(N);
	return 0;
}





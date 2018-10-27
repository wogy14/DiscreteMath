#include <stdio.h>
#include <locale.h>
void print_matrix(int parr[20][20], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", parr[i][j]);
		}
		printf("\n");
	}
}
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
/*
Returns if asym 0
		else if antisym 1
		else if sym 2
*/
int is_symetric(int arr[20][20], int m, int n) {
	int count = 0;
	if (m != n) return 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && arr[i][j] == arr[j][i]) {
				count++;
			}
		}
	}
	if (count == m * n - min(m, n)) {
		return 2;
	}
	else if (count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
/*
Returns if  reflex 1
			antireflex 2
			no reflex 0
*/
int is_reflex(int arr[20][20], int m, int n) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j && arr[i][j] == 1) {
				count++;
			}
		}
	}
	if (count == min(m, n)) {
		return 1;
	}
	else if (count == 0) {
		return 2;
	}
	else {
		return 0;
	}
}
/*
Returns if  tranz 1
			antitranz 2
			no tranz 0
*/
int is_tranz(int arr[20][20], int m, int n) {
	int checked = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[i][j] == arr[j][k]) {
					if (arr[i][k] != checked) {
						return 0;
					}
					if (arr[i][k] == 1) {
						checked = 1;
					}
					else {
						checked = 0;
					}
				}
				else {
					return 0;
				}
			}
		}
	}
	if (checked == 1) return 1;
	return 2;
}
int main() {
	setlocale(LC_ALL, "Ukrainian");
	int A[20], B[20], matrix[20][20], cA, cB;
	printf("Put count of array A:");
	scanf_s("%d", &cA);
	printf("Put elements of A\n");
	for (int i = 0; i < cA; i++) {
		printf("%d. ", i + 1);
		scanf_s("%d", &A[i]);
	}
	printf("Put count of array B:");
	scanf_s("%d", &cB);
	printf("Put elements of B\n");
	for (int i = 0; i < cB; i++) {
		printf("%d. ", i + 1);
		scanf_s("%d", &B[i]);
	}
	for (int i = 0; i < cA; i++) {
		for (int j = 0; j < cB; j++) {
			if (A[i] > B[j]) matrix[i][j] = 1;
			else matrix[i][j] = 0;
		}
	}
	print_matrix(matrix, cA, cB);
	switch (is_symetric(matrix, cA, cB)) {
	case 2:
		printf("Симетрична");
		break;
	case 1:
		printf("Антисиметрична");
		break;
	case 0:
		printf("Асиметрична");
		break;
	}
	printf("\n");
	switch (is_reflex(matrix, cA, cB)) {
	case 1:
		printf("Рефлексивна");
		break;
	case 2:
		printf("Антирефлексивна");
		break;
	case 0:
		printf("Не рефлексивна");
		break;
	}
	printf("\n");
	switch (is_tranz(matrix, cA, cB)) {
	case 1:
		printf("Транзитивна");
		break;
	case 2:
		printf("Антитранзитивна");
		break;
	case 0:
		printf("Не транзитивна");
		break;
	}
	printf("\n");
	system("pause");
	return 0;
}
/*All rights reserved by Oleksii Havryshkiv*/

#include <iostream>
using namespace std;

void arr_print(int values[100], int n) { // Виведення заданого масиву
	cout << "{";
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cout << ", ";
		}
		cout << values[i];
	}
	cout << "}\n";
}
int clean(int values[100], int n) { // Ощищення множини від одинакових елементів! Повертає потужність
	int count = 0;
	for (int i = 0; i < n; i++) {
		int b = 1;
		for (int j = 0; j < i; j++) {
			if (values[i] == values[j]) {
				count++;
				b = 0;
				break;
			}
		}
		if (b) {
			values[i - count] = values[i];
		}

	}
	return (n - count);
}
int intersection(int arr1[100], int arr2[100], int arr3[100], int count1, int count2) {// Перетин двох множин arr1 i arr2
	count1 = clean(arr1, count1);
	count2 = clean(arr2, count2);
	int index = 0;
	for (int i = 0; i < count1; i++) {
		for (int j = 0; j < count2; j++) {
			if (arr1[i] == arr2[j]) {
				arr3[index] = arr1[i];
				index++;
				break;
			}
		}
	}
	return index;
}
int merger(int arr1[100], int arr2[100], int arr3[100], int count1, int count2) {// Об'єднання двох множин arr1 i arr2
	count1 = clean(arr1, count1);
	count2 = clean(arr2, count2);
	int count3 = count1 + count2;
	for (int i = 0; i < count1; i++) {
		arr3[i] = arr1[i];
	}
	for (int i = count1; i < count3; i++) {
		arr3[i] = arr2[i - count1];
	}
	count3 = clean(arr3, count3);
	return count3;
}
int rizn(int arr1[100], int arr2[100], int arr3[100], int count1, int count2) {// Різниця двох множин
	int is,count = 0;
	count1 = clean(arr1, count1);
	count2 = clean(arr2, count2);
	for (int i = 0; i < count1;i++) {
		is = 0;
		for (int j = 0;j < count2;j++) {
			if (arr1[i] == arr2[j]) {
				is = 1;
				count++;
				break;
			}
		}
		if (!is) {
			arr3[i - count] = arr1[i];
		}
	}
	return (count1 - count);
}
int sym_rizn(int arr1[100], int arr2[100], int arr3[100], int count1, int count2) {// Симетрична різниця
	int arr_merge[100], arr_intersection[100];
	count1 = clean(arr1, count1);
	count2 = clean(arr2, count2);
	return rizn(arr_merge,arr_intersection,arr3,merger(arr1,arr2,arr_merge,count1,count2), intersection(arr1,arr2,arr_intersection,count1,count2));
}
int main() {
	setlocale(LC_ALL, "Ukrainian");
	int A[100], B[100],AwithB[100],cA, cB,pot;
	cout << "Введiть к-сть елементiв множини A: ";
	cin >> cA;
	cout << "Введiть елементи множини А\n";
	for (int i = 0; i < cA; i++) {
		cout << i + 1 << ". ";
		cin >> A[i];
	}
	cout << "Введiть к-сть елементiв множини B: ";
	cin >> cB;
	cout << "Введiть елементи множини B\n";
	for (int i = 0; i < cB; i++) {
		cout << i + 1 << ". ";
		cin >> B[i];
	}	
	cout << "Об'єднання: ";
	pot = merger(A, B, AwithB, cA, cB);
	arr_print(AwithB,pot);
	cout << "Потужнiсть: " << pot << endl;
	cout << "Симетрична рiзниця: ";
	pot = sym_rizn(A, B, AwithB, cA, cB);
	arr_print(AwithB, pot);
	cout << "Потужнiсть: " << pot << endl;
	system("pause");
	return 0;
}
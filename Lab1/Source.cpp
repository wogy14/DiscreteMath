#include <iostream>
using namespace std;

void main() {
	int x, y, z,res;

	setlocale(LC_ALL,"Ukrainian");	

	cout << "Введiть наступнi значення(0/1):\nX:";
	cin >> x;
	cout << "Y:";
	cin >> y;
	cout << "Z:";
	cin >> z;

	if ((y && !z) == true && (x || (y == z)) == false) {
		if ((x || !y) == true) {
			res = 0;
		}
		else {
			res = 1;
		}
	}
	else {
		res = 1;
	}

	cout << "-------------------------------------------------------------------------------------------\n";	
	cout << "| x | y | z | x v ¬y | y ^ ¬z | x v (y <-> z) | (x v ¬y) -> ((y ^ ¬z) -> (x v (y <-> z))) |\n";
	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "| " << x << " | "  << y << " | "  << z << " |   " << (int)(x || !y) << "    |   " << (int)(y && !z) << "    |       " << (int)(x || (y == z)) << "       |                     " << res << "                     |\n";	
	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "Result: " << res << endl << endl;
	system("pause");
}
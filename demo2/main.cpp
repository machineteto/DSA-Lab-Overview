#include <iostream>

using namespace std;
//BAI 1;
void a1() {
	int	a[5] = { 10, 20, 30, 40, 50 };
	int* p = a + 1, * q = &a[4];
	//pointer p chua dia chi a[1], pointer q chua dia chi a[4]

	*p += 5; //*p = *p + 5; pointer p dang chua dia chi a[1] + 5;
	//pointer p thay doi mang a[1] -> 25;
	//array hien tai: a[5] = { 10, 25, 30, 40, 50 }

	*(q - 1) = *p * 2;
	//lui pointer q tu a[4] xuong a[3] va gan cho no pointer *p * 2
	//array hien tai la a[5] = { 10, 25, 30, 50, 50 };

	p++;
	//pointer p tien len dia chi a[3];

	printf("%d	%d	%d\n", *p, (int)(q - p), a[3]);
	//dia chi q - dia chia p 4 - 2
}

void timMinMax(int* a, int	n, int* min, int* max) {
	if (n <= 0) return;

	*min = *a;
	*max = *a;
	for (int* p = a + 1; p < a + n; p++) {
		if (*p < *min) {
			*min = *p;
		}
		
		if (*p > *max) {
			*max = *p;
		}
	}
}

int* daoMang(int* a, int n) {
	int* temp = new int[n];

	for (int i = 0; i < n; i++) {
		temp[i] = a[n - 1 - i];
	}
	return temp;
}

int main() {
	int s;
	cout << "1) bai 1.a\n" << "2) bai 1.b\n" << "3) bai 1.c\n" << endl;
	cout << "nhap: ";
	cin >> s;
	switch (s) {
	case 1: {
		a1();
		break;
	}

	case 2: {
		int a[5] = { 10, 20, 30, 40, 50 };
		int min, max;

		timMinMax(a, 5, &min, &max );
		cout << "min: " << min << endl << "max: " << max;
	}
		break;

	case 3: {
		int a[5] = { 40, 80, 60 , 70, 10 };
		int* b = daoMang(a, 5);

		cout << "mang dao nguoc: ";
		for (int i = 0; i < 5; i++) {
			cout << b[i] << " ";
		} 
		delete[]b;
		b = nullptr;
		break;
	}

	default:
		return 0;
	}
}
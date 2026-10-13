#include<iostream>

using namespace std;

int dem = 0;

int	f(int n) {
	dem++;
	if (n <= 1)	return	1;
	return	f(n - 1) + 2 * f(n - 2);
}

int	tongChan(int* a, int n) {
	if (n == 0)
		return 0;

	if (*(a + n - 1) % 2 == 0) {
		return *(a + n - 1) + tongChan(a, n - 1);
	}
	return tongChan(a, n - 1);
}

int timNhiPhan(int* a, int l, int r, int x) {
	if (l > r)
		return -1;

	int mid = (l + r) / 2;

	if (a[mid] == x)
		return mid;

	if (a[mid] > x)
		return timNhiPhan(a, l, mid + 1, x);

	return timNhiPhan(a, mid - 1, r, x);
}

void inNhiPhan(int n) {
	if (n == 0) {
		return;
	}
	else
		inNhiPhan(n / 2);
	cout << n % 2;
}

int main() {
	int s;
	cin >> s;
	switch (s) {
	case 1: {
		cout << f(4) << endl;
		cout << dem;
		break;
	}
	case 2: {
		int a[] = {10, 60, 70, 80, 90};
		int n = 5;
		cout << timNhiPhan(a, 0, n - 1, 60);
		break;
	}
	case 3: {
		int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		cout << tongChan(a, 10);
		break;
	}
	case 4: {
		int n;
		cin >> n;
		inNhiPhan(n);
		break;
	}
	default:
		return 0;
	}
}
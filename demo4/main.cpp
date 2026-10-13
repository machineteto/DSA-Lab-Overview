#include <iostream>
#include <string>

using namespace std;

struct SinhVien {
	//atribute
private:
	string idSV;
	string nameSV;
	float scoreSV;

public:
	//contructor
	SinhVien(string idSV = "000000000000", string nameSV = "Nguyen Van A", float scoreSV = 0.00)
		: idSV(idSV), nameSV(nameSV), scoreSV(scoreSV) {
	}

	//method
	SinhVien* nhapDS(int& n) {
		cout << "nhap so luong sv: ";
		cin >> n;
		SinhVien* ds = new SinhVien[n];

		for (int i = 0; i < n; i++) {
			cout << i + 1 << ": " << endl;

			cout << "maSV: ";
			cin >> ds[i].idSV;

			cout << "ho ten: ";
			getline(cin >> ws, ds[i].nameSV);

			cout << "diem trung binh: ";
			cin >> ds[i].scoreSV;
		}
		return ds;
	}

	SinhVien* timMax(SinhVien* ds, int	n) {
		if (n <= 0 || ds == nullptr) {
			return nullptr;
		}
		SinhVien* max = &ds[0];

		for (int i = 1; i < n; i++) {
			if (ds[i].scoreSV > max->scoreSV) {
				max = &ds[i];
			}
		}
		return max;
	}

	void sortDS(SinhVien* ds, int n) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {

				if (ds[i].scoreSV < ds[j].scoreSV ||
					(ds[i].scoreSV == ds[j].scoreSV &&
						ds[i].nameSV > ds[j].nameSV)) {

					SinhVien temp = ds[i];
					ds[i] = ds[j];
					ds[j] = temp;
				}
			}
		}
		cout << "\n danh sach sap xep: " << endl;
		for (int i = 0; i < n; i++) {
			cout << "Ma SV: " << ds[i].getID() << endl;
			cout << "Ho ten: " << ds[i].Getname() << endl;
			cout << "Diem TB: " << ds[i].getScore() << endl;
			cout << "--------------------" << endl;
		}
	}


	//getter-setter
	void setID(string i) {
		idSV = i;
	}

	void setName(string n) {
		nameSV = n;
	}

	void setSCore(float s) {
		scoreSV = s;
	}

	string getID() {
		return idSV;
	}

	string Getname() {
		return nameSV;
	}

	float getScore() {
		return scoreSV;
	}
};

int main() {
	SinhVien s1;
	int n;

	SinhVien* ds = s1.nhapDS(n);

	SinhVien* tbMax = s1.timMax(ds, n);
	if (tbMax != nullptr) {
		cout << "\nSinh vien diem cao nhat: \n ";
		cout << tbMax->getID() << endl;
		cout << tbMax->Getname() << endl;
		cout << tbMax->getScore() << endl;
	}

	s1.sortDS(ds, n);

	delete[] ds;
	return 0;
}
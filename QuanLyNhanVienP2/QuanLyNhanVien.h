#pragma once 
#include "NhanVienHopDong.h"
#include "NhanVienBienChe.h"

using namespace std;

static bool TangDan(NhanVien& a, NhanVien& b) {
	return a.LayLuong() > b.LayLuong();
}

static bool GiamDan(NhanVien& a, NhanVien& b) {
	return a.LayLuong() < b.LayLuong();
}

static void HoanDoi(NhanVien& a, NhanVien& b) {
	NhanVien* d = &a;
	a = b;
	b = *d;
}

template <class T>
class QuanLyNhanVien {
	string TenCaNhan;
	NhanVien* Data;
	unsigned int SoLuong;
public:
	// Information: Cac tinh nang cua ham dung va ham huy cua QuanLyNhanVien.
	~QuanLyNhanVien(void);
	QuanLyNhanVien(string TenCaNhan = NULL);
	QuanLyNhanVien(const QuanLyNhanVien&);

	// Information: Cac tinh nang them, xoa du lieu cua QuanLyNhanVien.
	void Them();
	void Xoa(int);

	// Information: Cac tinh nang thay doi du lieu cua QuanLyNhanVien.
	void SapXepTheoLuong(bool (*SortType)(NhanVien&, NhanVien&));
	template <class U>
	friend ostream& operator<<(ostream& cout, QuanLyNhanVien<U>& input);
	void Sua(int);

	// Information: Cac tinh nang truy van du lieu cua QuanLyNhanVien.
	int TimKiemTheoTen(string);
	unsigned int LaySoLuong();
	T operator[] (int i);
};

template <class T>
QuanLyNhanVien<T>::~QuanLyNhanVien(void) {
	if (this->Data != NULL) {
		NhanVien* NextVal = this->Data;
		while (NextVal != NULL) {
			NhanVien* temp = NextVal;
			NextVal = NextVal->Next;
			delete temp;
			temp = NULL;
		}
	}
	this->Data = NULL;
	this->SoLuong = 0;
}

template <class T>
QuanLyNhanVien<T>::QuanLyNhanVien(string TenCaNhan) {
	this->TenCaNhan = TenCaNhan;
	this->Data = NULL;
	this->SoLuong = 0;
}

// Undone: QuanLyNhanVien - Ham dung sao chep.
template <class T>
QuanLyNhanVien<T>::QuanLyNhanVien(const QuanLyNhanVien<T>& input) {
	this->TenCaNhan = input.TenCaNhan;
	// TODO: Ham sao chep QuanLyNhanVien tai day!
	// this->SoLuong = input.SoLuong;
	this->Data = NULL;
	this->SoLuong = 0;
}

template <class T>
void QuanLyNhanVien<T>::Them() {
	NhanVien* currentDS = this->Data;
	NhanVien* importDS = NULL;
	int d = 2;

LoaiNhanVien:
	try {
		cout << endl;
		cout << "Nhap loai nhan vien:" << endl;
		cout << "  1: Nhan vien hop dong" << endl;
		cout << "  2: Nhan vien bien che" << endl;
		cout << "Chon: ";
		cin >> d;
		if ((d == 1) || (d == 2)) {
			goto ThongTinNhanVien;
		}
		else throw string("Ban da nhap sai yeu cau. Vui long thu lai!");
	}
	catch (string ex) {
		cout << ex << endl;
		goto LoaiNhanVien;
	}

ThongTinNhanVien:
	cin.ignore();
	try {
		(d == 1) ? importDS = new NhanVienHD() : importDS = new NhanVienBC();
		cin >> *importDS;
	}
	catch (string ex) {
		cout << ex << endl;
		goto ThongTinNhanVien;
	}
	if (currentDS != NULL) {
		while (currentDS->Next != NULL)
			currentDS = currentDS->Next;
		importDS->Previous = currentDS;
		currentDS->Next = importDS;
	}
	else {
		currentDS = importDS;
		this->Data = currentDS;
	}

	this->SoLuong += 1;
}

template <class T>
void QuanLyNhanVien<T>::Xoa(int index) {
	if (index + 1 > (int)this->SoLuong)
		throw string("Chi so ngoai pham vi cua danh sach!");
	if (index == 0) {
		if (this->SoLuong == 1) delete this->Data;
		else this->Data = this->Data->Next;
	}
	else {
		NhanVien* currentDS = this->Data;
		while (index != 0) {
			currentDS = currentDS->Next;
			index -= 1;
		}

		currentDS->Previous->Next = currentDS->Next;
	}
	this->SoLuong -= 1;
}

template <class T>
int QuanLyNhanVien<T>::TimKiemTheoTen(string input) {
	int i = 0;

	NhanVien* currentDS = this->Data;
	while (currentDS != NULL) {
		if (currentDS->LayTen() == input) {
			cout << "Da tim thay du lieu theo chi so " << i << "!\n";
			return i;
		}
		else {
			i += 1;
			currentDS = currentDS->Next;
		}
	}

	throw string("Khong tim thay du lieu theo yeu cau!");
}

template <class T>
unsigned int QuanLyNhanVien<T>::LaySoLuong() {
	return this->SoLuong;
}

// Undone: QuanLyNhanVien - Sap xep theo luong.
template <class T>
void QuanLyNhanVien<T>::SapXepTheoLuong(bool (*SortType)(NhanVien&, NhanVien&)) {
	if (this->SoLuong == 1)
		return;
	else {
		int i, j;
		for (i = (this->SoLuong - 1); i >= 0; i--) {
			for (j = 1; j <= i; j++) {
				// TODO: Sap xep tai day!
				// TODO: Lay gia tri tai mang.
				//  if (SortType((this[j-1], this[j]))
				//  	HoanDoi(this[j-1], this[j]);
			}
		}
	}
}

template <class T>
ostream& operator<<(ostream& cout, QuanLyNhanVien<T>& input) {
	cout << "Thong tin danh sach nay:" << endl;
	cout << "  Ho ten nguoi quan ly: " << input.TenCaNhan << endl;
	cout << "  So luong nhan vien trong danh sach: " << input.SoLuong << endl << endl;
	NhanVien* exportDS = input.Data;
	while (exportDS != NULL) {
		cout << *exportDS << endl;
		exportDS = exportDS->Next;
	}
	return cout;
}

template <class T>
T QuanLyNhanVien<T>::operator[] (int i) {
	NhanVien* nhanVien = this->Data;
	int index = i;

	while (index != 0) {
		if (nhanVien == NULL)
			throw string("Da vuot qua chi so cho phep cua mang! Vui long su dung 'LaySoLuong()' de tim do dai mang.");
		else {
			nhanVien = nhanVien->Next;
			index -= 1;
		}
	}

	return NhanVien(nhanVien);
}

template <class T>
void QuanLyNhanVien<T>::Sua(int index) {
	try {
		NhanVien* nhanVien = this->Data;
		int i = index;

		while (i != 0) {
			if (nhanVien == NULL)
				throw string("Da vuot qua chi so cho phep cua mang! Vui long su dung 'LaySoLuong()' de tim do dai mang.");
			else {
				nhanVien = nhanVien->Next;
				i -= 1;
			}
		}

		cin.ignore();
		cin >> *nhanVien;
	}
	catch (exception ex) {
		cout << ex.what() << endl;
	}
}

#include "QuanLyNhanVien.h"

QuanLyNhanVien::~QuanLyNhanVien(void) {
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

QuanLyNhanVien::QuanLyNhanVien(string TenCaNhan) {
	this->TenCaNhan = TenCaNhan;
	this->Data = NULL;
	this->SoLuong = 0;
}

// Undone: QuanLyNhanVien - Ham dung sao chep.
QuanLyNhanVien::QuanLyNhanVien(const QuanLyNhanVien& input) {
	this->TenCaNhan = input.TenCaNhan;
	// TODO: Ham sao chep QuanLyNhanVien tai day!
	// this->SoLuong = input.SoLuong;
	this->Data = NULL;
	this->SoLuong = 0;
}

void QuanLyNhanVien::Them() {
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

void QuanLyNhanVien::Xoa(unsigned int index) {
	if (index + 1 > this->SoLuong)
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

NhanVien& QuanLyNhanVien::TimKiemTheoTen(string input) {
	int i = 0;

	NhanVien* currentDS = this->Data;
	while (currentDS != NULL) {
		if (currentDS->LayTen() == input) {
			cout << "Da tim thay du lieu theo chi so " << i << "!\n";
			return *currentDS;
		}
		else {
			i += 1;
			currentDS = currentDS->Next;
		}
	}

	throw string("Khong tim thay du lieu theo yeu cau!");
}

unsigned int QuanLyNhanVien::LaySoLuong() {
	return this->SoLuong;
}

// Undone: QuanLyNhanVien - Sap xep theo luong.
void QuanLyNhanVien::SapXepTheoLuong(bool (*SortType)(NhanVien&, NhanVien&)) {
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

ostream& operator<<(ostream& cout, QuanLyNhanVien& input) {
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

NhanVien& QuanLyNhanVien::operator[] (int i) {
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

	return *nhanVien;
}
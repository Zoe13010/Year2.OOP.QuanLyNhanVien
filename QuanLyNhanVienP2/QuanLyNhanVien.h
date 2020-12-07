#pragma once 
#include "NhanVienHopDong.h"
#include "NhanVienBienChe.h"

using namespace std;

template <class T>
static bool TangDan(T& a, T& b) {
	return a.LayLuong() > b.LayLuong();
}

template <class T>
static bool GiamDan(T& a, T& b) {
	return a.LayLuong() < b.LayLuong();
}

template <class T>
class QuanLyNhanVien {
private:
	string TenCaNhan;
	NhanVien* Data;
	unsigned int SoLuong;
public:
	// Information: Cac tinh nang cua ham dung va ham huy cua QuanLyNhanVien.
	~QuanLyNhanVien(void);
	QuanLyNhanVien(string TenCaNhan = NULL);

	// Information: Cac tinh nang them, xoa du lieu cua QuanLyNhanVien.
	/// <summary>
	/// Nhap du lieu cua mot nhan vien va them vao Quan Ly Nhan Vien.
	/// </summary>
	void Them();

	/// <summary>
	/// Xoa nhan vien theo chi so i cua Quan Ly Nhan Vien.
	/// </summary>
	/// <param name="i">Chi so cua nhan vien can xoa</param>
	void Xoa(int);

	// Information: Cac tinh nang thay doi du lieu cua QuanLyNhanVien.
	template <class U>
	friend ostream& operator<<(ostream& cout, QuanLyNhanVien<U>& input);

	/// <summary>
	/// Sap xep danh sach Quan Ly Nhan Vien. 
	/// </summary>
	/// <param name="SortType">Sap xep theo (TangDan/GiamDan tuong ung voi tang dan/giam dan).</param>
	void SapXepTheoLuong(bool (*SortType)(T&, T&));

	/// <summary>
	/// Sua mot nhan vien theo chi so i cua Quan Ly Nhan Vien.
	/// </summary>
	/// <param name="i">Chi so i cua nhan vien can sua</param>
	void Sua(int);
private:
	/// <summary>
	/// Gan mot nhan vien vao vi tri i cua Quan Ly Nhan Vien.
	/// </summary>
	/// <param name="i">Chi so i cua vi tri can gan</param>
	/// <param name="data">Du lieu nhan vien</param>
	void Gan(int, NhanVien*);

	/// <summary>
	/// Hoan doi 2 vi tri nhan vien.
	/// </summary>
	/// <param name="i">vi tri nguoi dung dau</param>
	/// <param name="j">vi tri nguoi dung sau</param>
	void HoanDoi(int i, int j);

public:
	// Information: Cac tinh nang truy van du lieu cua QuanLyNhanVien.
	T& operator[] (int i);

	/// <summary>
	/// Tim kiem ten dau tien tim duoc trong danh sach Quan Ly Nhan Vien.
	/// </summary>
	/// <param name="input">Ten can tim kiem</param>
	/// <returns>Neu tim duoc, tra ve gia tri la chi so cua nhan vien do. Nguoc lai, thong bao loi.</returns>
	int TimKiemTheoTen(string);

	/// <summary>
	/// Lay so luong nhan vien trong Quan Ly Nhan Vien.
	/// </summary>
	/// <returns></returns>
	unsigned int LaySoLuong();
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
		cout << "  0: Quay lai" << endl;
		cout << "Chon: ";
		cin >> d;
		if ((d == 1) || (d == 2)) {
			goto ThongTinNhanVien;
		}
		else if (d == 0) {
			goto End;
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

End:
	return;
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

		currentDS->Next->Previous = currentDS->Previous;
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
T& QuanLyNhanVien<T>::operator[] (int i) {
	NhanVien* nhanVien = this->Data;
	int index = i;

	if (index + 1 > (int)this->SoLuong)
		throw string("Da vuot qua chi so cho phep cua mang! Vui long su dung 'LaySoLuong()' de tim do dai mang.");

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

template <class T>
void QuanLyNhanVien<T>::Gan(int index, NhanVien* input) {
	if (index == 0) {
		input->Previous = this->Data->Previous;
		input->Next = this->Data->Next;
		input->Next->Previous = input;
		this->Data = input;
	}
	else {
		NhanVien* temp = this->Data;
		while (index != 0) {
			temp = temp->Next;
			index -= 1;
		}
		input->Previous = temp->Previous;
		input->Next = temp->Next;
		input->Previous->Next = input;
		if (input->Next != NULL)
			input->Next->Previous = input;
	}
}

template <class T>
void QuanLyNhanVien<T>::SapXepTheoLuong(bool (*SortType)(T&, T&)) {
	if (this->SoLuong == 1)
		return;
	else {
		int i, j;
		for (i = 0; i < (int)this->SoLuong; i++) {
			for (j = i + 1; j < (int)this->SoLuong; j++) {
				if (SortType(this->operator[](i), this->operator[](j)))
					this->HoanDoi(i, j);
			}
		}
	}
}

template <class T>
void QuanLyNhanVien<T>::HoanDoi(int i, int j) {
	NhanVien* a, * b;
	int ai = i, bi = j;
	
	a = this->Data; while (ai != 0) { a = a->Next; ai -= 1; }
	b = this->Data; while (bi != 0) { b = b->Next; bi -= 1; }
	
	NhanVien* tempA;
	if (a->GetClassType() == "NVHD") {
		NhanVienHD* temp2 = (NhanVienHD*)a;
		tempA = new NhanVienHD(temp2->LayID(),
			temp2->LayTen(),
			temp2->LayNgayVaoViec(),
			temp2->LayGioiTinh(),
			temp2->LayLuongCongNhat());
	}
	else {
		NhanVienBC* temp2 = (NhanVienBC*)a;
		tempA = new NhanVienBC(temp2->LayID(),
			temp2->LayTen(),
			temp2->LayNgayVaoViec(),
			temp2->LayGioiTinh(),
			temp2->LayHeSoLuong());
	}
	
	NhanVien* tempB;
	if (b->GetClassType() == "NVHD") {
		NhanVienHD* temp3 = (NhanVienHD*)b;
		tempB = new NhanVienHD(temp3->LayID(),
			temp3->LayTen(),
			temp3->LayNgayVaoViec(),
			temp3->LayGioiTinh(),
			temp3->LayLuongCongNhat());
	}
	else {
		NhanVienBC* temp3 = (NhanVienBC*)b;
		tempB = new NhanVienBC(temp3->LayID(),
			temp3->LayTen(),
			temp3->LayNgayVaoViec(),
			temp3->LayGioiTinh(),
			temp3->LayHeSoLuong());
	}

	this->Gan(j, tempA);
	this->Gan(i, tempB);
}


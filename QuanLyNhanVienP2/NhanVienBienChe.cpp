#include "NhanVienBienChe.h"

NhanVienBC::~NhanVienBC(void) {

}

NhanVienBC::NhanVienBC(void) {
	this->SuaHeSoLuong(2.34);
}

NhanVienBC::NhanVienBC(string ID, string Ten, Date NgayVaoViec, bool GioiTinh, double HeSoLuong) {
	this->SuaID(ID);
	this->SuaTen(Ten);
	this->SuaNgayVaoViec(NgayVaoViec);
	this->SuaGioiTinh(GioiTinh);
	this->SuaHeSoLuong(HeSoLuong);
}

NhanVienBC::NhanVienBC(const NhanVienBC& input) {
	this->SuaID(ID);
	this->SuaTen(Ten);
	this->SuaNgayVaoViec(NgayVaoViec);
	this->SuaGioiTinh(GioiTinh);
	this->SuaHeSoLuong(HeSoLuong);
}

ostream& NhanVienBC::stdcout(ostream& cout) {
	cout << "Thong tin nhan vien:" << endl;
	cout << "  Ma nhan vien: " << this->ID << endl;
	cout << "  Ten nhan vien: " << this->Ten << endl;
	cout << "  Loai nhan vien: Nhan vien bien che" << endl;
	cout << "  Gioi tinh: " << (GioiTinh ? "Nu" : "Nam") << endl;
	cout << "  Ngay vao viec: " << this->NgayVaoViec << endl;
	cout << "  He so luong: " << this->HeSoLuong << endl;
	cout << "  Tham nien lam viec: " << this->ThamNienLamViec << endl;
	cout << "  Luong: " << this->Luong << endl;
	cout << endl;
	return cout;
}

istream& NhanVienBC::stdcin(istream& cin) {
	string tempString = "";
	double tempDouble = 2;

EnterID:
	try {
		cout << "Nhap ID: ";
		fflush(stdin);
		getline(cin, tempString);
		this->SuaID(tempString);
		goto EnterName;
	}
	catch (string ex) {
		cout << ex << endl;
		goto EnterID;
	}

EnterName:
	try {
		cout << "Nhap ten: ";
		fflush(stdin);
		getline(cin, tempString);
		this->SuaTen(tempString);
		goto EnterDate;
	}
	catch (string ex) {
		cout << ex << endl;
		goto EnterName;
	}

EnterDate:
	cin >> this->NgayVaoViec;
	goto EnterGender;

EnterGender:
	try {
		cout << "Gioi tinh? (1: nu, 0: nam) ";
		cin >> tempDouble;
		if ((tempDouble == 0) || (tempDouble == 1))
			this->GioiTinh = tempDouble == 1 ? true : false;
		else
			throw string("Ban da nhap sai yeu cau!\nHay nhap lai.\n");
		goto EnterLuong;
	}
	catch (string ex) {
		cout << ex << endl;
		goto EnterGender;
	}

EnterLuong:
	tempDouble = -1;
	try {
		cout << "Nhap he so luong: ";
		cin >> tempDouble;
		this->SuaHeSoLuong(tempDouble);
		goto End;
	}
	catch (string ex) {
		cout << ex << endl;
		goto EnterLuong;
	}

End:
	return cin;
}

double NhanVienBC::LayHeSoLuong() {
	return this->HeSoLuong;
}

void NhanVienBC::SuaHeSoLuong(double heSoLuong) {
	if ((heSoLuong < 2.34) || (heSoLuong > 10))
		throw string("He so luong ban da nhap khong nam trong vung 2.34 den 10!");

	this->HeSoLuong = heSoLuong;
	this->CapNhatTienLuong();
}

void NhanVienBC::CapNhatTienLuong() {
	// TODO: Cap nhat tham nien lam viec tai day!
	// TODO: Cap nhat luong tai day!
	this->SuaLuong(0);
}

ostream& operator<<(ostream& cout, NhanVienBC& input) {
	return input.stdcout(cout);
}

istream& operator>>(istream& cin, NhanVienBC& input) {
	return input.stdcin(cin);
}

NhanVienBC& NhanVienBC::operator=(NhanVienBC& input) {
	this->SuaID(input.ID);
	this->SuaTen(input.Ten);
	this->SuaNgayVaoViec(input.NgayVaoViec);
	this->SuaGioiTinh(input.GioiTinh);
	this->SuaHeSoLuong(input.HeSoLuong);
	return *this;
}

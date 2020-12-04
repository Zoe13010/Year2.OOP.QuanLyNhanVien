#include "NhanVien.h"

NhanVien::~NhanVien(void) { }

NhanVien::NhanVien(void) {
	this->ID = "00000000";
	this->Ten = "";
	this->NgayVaoViec = Date();
	this->GioiTinh = false;
	this->Luong = 0;
	this->Previous = NULL;
	this->Next = NULL;
}

NhanVien::NhanVien(string ID, string Ten, Date NgayVaoViec, bool GioiTinh) {
	if (ID.length() != 8)
		throw string("ID phai dung 8 ki tu!");

	this->ID = ID;
	this->Ten = Ten;
	this->NgayVaoViec = NgayVaoViec;
	this->GioiTinh = GioiTinh;
	this->Luong = 0;
	this->Previous = NULL;
	this->Next = NULL;
}

NhanVien::NhanVien(const NhanVien& input) {
	this->ID = ID;
	this->Ten = Ten;
	this->NgayVaoViec = NgayVaoViec;
	this->GioiTinh = GioiTinh;
	this->Luong = 0;
	this->Next = input.Next;
	this->Previous = input.Previous;
}

string NhanVien::LayID() {
	return this->ID;
}

void NhanVien::SuaID(string ID) {
	if (ID.length() != 8)
		throw string("ID phai dung 8 ki tu!");

	this->ID = ID;
}

string NhanVien::LayTen() {
	return this->Ten;
}

void NhanVien::SuaTen(string Ten) {
	this->Ten = Ten;
}

Date NhanVien::LayNgayVaoViec() {
	return this->NgayVaoViec;
}

void NhanVien::SuaNgayVaoViec(Date NgayVaoViec) {
	this->NgayVaoViec = NgayVaoViec;
}

bool NhanVien::LayGioiTinh() {
	return this->GioiTinh;
}

void NhanVien::SuaGioiTinh(bool GioiTinh) {
	this->GioiTinh = GioiTinh;
}

double NhanVien::LayLuong() {
	return this->Luong;
}

void NhanVien::SuaLuong(double Luong) {
	if (Luong < 0)
		throw string("Luong phai lon hon hoac bang 0!");

	this->Luong = Luong;
}

ostream& operator<<(ostream& cout, NhanVien& input) {
	return input.stdcout(cout);
}

istream& operator>>(istream& cin, NhanVien& input) {
	return input.stdcin(cin);
}

NhanVien& NhanVien::operator=(const NhanVien& input) {
	this->ID = input.ID;
	this->Ten = input.Ten;
	this->NgayVaoViec = input.NgayVaoViec;
	this->GioiTinh = input.GioiTinh;
	this->Luong = input.Luong;
	return *this;
}

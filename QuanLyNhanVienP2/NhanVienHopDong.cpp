#include "NhanVienHopDong.h"

NhanVienHD::~NhanVienHD(void) {

}

NhanVienHD::NhanVienHD(void) {
	this->SuaLuongCongNhat(0);
}

NhanVienHD::NhanVienHD(string ID, string Ten, Date NgayVaoViec, bool GioiTinh, double LuongCongNhat) {
	this->SuaID(ID);
	this->SuaTen(Ten);
	this->SuaNgayVaoViec(NgayVaoViec);
	this->SuaGioiTinh(GioiTinh);
	this->SuaLuongCongNhat(LuongCongNhat);
}

NhanVienHD::NhanVienHD(const NhanVienHD& input) {
	this->SuaID(input.ID);
	this->SuaTen(input.Ten);
	this->SuaNgayVaoViec(input.NgayVaoViec);
	this->SuaGioiTinh(input.GioiTinh);
	this->SuaLuongCongNhat(input.LuongCongNhat);
}

ostream& NhanVienHD::stdcout(ostream& cout) {
	cout << "Thong tin nhan vien:" << endl;
	cout << "  Ma nhan vien: " << this->ID << endl;
	cout << "  Ten nhan vien: " << this->Ten << endl;
	cout << "  Loai nhan vien: Nhan vien hop dong" << endl;
	cout << "  Gioi tinh: " << (GioiTinh ? "Nu" : "Nam") << endl;
	cout << "  Ngay vao viec: " << this->NgayVaoViec << endl;
	cout << "  Luong cong nhat: " << this->LuongCongNhat << endl;
	cout << "  Luong: ";
	cout.precision(30);
	cout << this->Luong << endl;
	cout << endl;
	return cout;
}

istream& NhanVienHD::stdcin(istream& cin) {
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
		goto EditLuong;
	}
	catch (string ex) {
		cout << ex << endl;
		goto EnterGender;
	}

EditLuong:
	tempDouble = -1;
	try {
		cout << "Nhap luong cong nhat: ";
		cin >> tempDouble;
		this->SuaLuongCongNhat(tempDouble);
		goto End;
	}
	catch (string ex) {
		cout << ex << endl;
		goto EditLuong;
	}

End:
	return cin;
}

double NhanVienHD::LayLuongCongNhat() {
	return this->LuongCongNhat;
}

void NhanVienHD::SuaLuongCongNhat(double luongCongNhat) {
	if (luongCongNhat < 0)
		throw string("Luong cong nhat phai lon hon hoac bang 0!");
	this->LuongCongNhat = luongCongNhat;
	this->CapNhatTienLuong();
}

void NhanVienHD::CapNhatTienLuong() {
	int TongNgay = (this->NgayVaoViec.DayCountOnMonth[this->NgayVaoViec.LayThang() - 1] / 7) * 5;
	int SoNgayConLai = this->NgayVaoViec.DayCountOnMonth[NgayVaoViec.LayThang()] % 7;
	int ThuHienTai = NgayVaoViec.NgayTrongTuan();

	for (int i = 0; i < SoNgayConLai; i++)
		if (ThuHienTai + i != 7 && ThuHienTai + i != 8)
			TongNgay += 1;

	SuaLuong(this->LuongCongNhat * TongNgay);
}

ostream& operator<<(ostream& cout, NhanVienHD& input) {
	return input.stdcout(cout);
}

istream& operator>>(istream& cin, NhanVienHD& input) {
	return input.stdcin(cin);
}

NhanVienHD& NhanVienHD::operator=(NhanVienHD& input) {
	this->SuaID(input.ID);
	this->SuaTen(input.Ten);
	this->SuaNgayVaoViec(input.NgayVaoViec);
	this->SuaGioiTinh(input.GioiTinh);
	this->SuaLuongCongNhat(input.LuongCongNhat);
	return *this;
}

string NhanVienHD::GetClassType() {
	return "NVHD";
}

#pragma once
#include "Date.h"

using namespace std;

class NhanVien {
protected:
	string ID;
	string Ten;
	Date NgayVaoViec;
	bool GioiTinh;
	double Luong;
	void SuaID(string);
	void SuaLuong(double);
	virtual ostream& stdcout(ostream&) = 0;
	virtual istream& stdcin(istream&) = 0;
public:
	NhanVien* Previous;
	NhanVien* Next;
	~NhanVien(void);
	NhanVien(void);
	NhanVien(string ID, string Ten, Date, bool);
	NhanVien(const NhanVien&);
	string LayID();
	string LayTen();
	void SuaTen(string);
	Date LayNgayVaoViec();
	void SuaNgayVaoViec(Date);
	bool LayGioiTinh();
	void SuaGioiTinh(bool);
	double LayLuong();
	friend ostream& operator<<(ostream&, NhanVien&);
	friend istream& operator>>(istream&, NhanVien&);
	NhanVien& operator=(const NhanVien&);
};

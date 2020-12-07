#pragma once
#include "NhanVien.h"

using namespace std;

class NhanVienHD : public NhanVien {
	double LuongCongNhat;
	void CapNhatTienLuong();
	virtual ostream& stdcout(ostream&);
	virtual istream& stdcin(istream&);
public:
	~NhanVienHD();
	NhanVienHD();
	NhanVienHD(string, string, Date, bool, double);
	NhanVienHD(const NhanVienHD&);
	double LayLuongCongNhat();
	void SuaLuongCongNhat(double);
	virtual string GetClassType();
	friend ostream& operator<<(ostream& cout, NhanVienHD& input);
	friend istream& operator>>(istream& cin, NhanVienHD& input);
	NhanVienHD& operator=(NhanVienHD&);
};

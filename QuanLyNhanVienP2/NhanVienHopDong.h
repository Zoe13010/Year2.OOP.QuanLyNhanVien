#pragma once
#include "NhanVien.h"

using namespace std;

class NhanVienHD : public NhanVien {
	double LuongCongNhat;
	void CapNhatTienLuong();
	ostream& stdcout(ostream&);
	istream& stdcin(istream&);
public:
	~NhanVienHD(void);
	NhanVienHD(void);
	NhanVienHD(string, string, Date, bool, double);
	NhanVienHD(const NhanVienHD&);
	double LayLuongCongNhat();
	void SuaLuongCongNhat(double);
	friend ostream& operator<<(ostream& cout, NhanVienHD& input);
	friend istream& operator>>(istream& cin, NhanVienHD& input);
	NhanVienHD& operator=(NhanVienHD&);
};

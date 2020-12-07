#pragma once
#include "NhanVien.h"

using namespace std;

class NhanVienBC : public NhanVien {
	double HeSoLuong;
	double ThamNienLamViec;
	void CapNhatTienLuong();
	ostream& stdcout(ostream&);
	istream& stdcin(istream&);
public:
	~NhanVienBC(void);
	NhanVienBC(void);
	NhanVienBC(string, string, Date, bool, double);
	NhanVienBC(const NhanVienBC&);
	double LayHeSoLuong();
	void SuaHeSoLuong(double);
	virtual string GetClassType();
	friend ostream& operator<<(ostream& cout, NhanVienBC& input);
	friend istream& operator>>(istream& cin, NhanVienBC& input);
	NhanVienBC& operator=(NhanVienBC&);
};

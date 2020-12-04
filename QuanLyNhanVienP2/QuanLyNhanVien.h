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
	void Xoa(unsigned int);

	// Information: Cac tinh nang thay doi du lieu cua QuanLyNhanVien.
	void SapXepTheoLuong(bool (*SortType)(NhanVien&, NhanVien&));
	friend ostream& operator<<(ostream& cout, QuanLyNhanVien& input);

	// Information: Cac tinh nang truy van du lieu cua QuanLyNhanVien.
	NhanVien& TimKiemTheoTen(string);
	unsigned int LaySoLuong();
	NhanVien& operator[] (int i);
};
	
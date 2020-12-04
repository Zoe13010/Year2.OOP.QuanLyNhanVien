#include "QuanLyNhanVien.h"

template <class T>
void QLNV_Them(QuanLyNhanVien<T>*);

template <class T>
void QLNV_Sua(QuanLyNhanVien<T>*);

template <class T>
void QLNV_Xoa(QuanLyNhanVien<T>*);

template <class T>
void QLNV_HienThiThongTin(QuanLyNhanVien<T>*);

template <class T>
void QLNV_TimKiemTheoTen(QuanLyNhanVien<T>*);

template <class T>
void QLNV_XuatDanhSach(QuanLyNhanVien<T>*);

template <class T>
void QLNV_SapXepTheoLuong(QuanLyNhanVien<T>*);

int main() {
	int mode = -1;
	string tempString;

	cout << "Nhap ten nguoi quan ly: ";
	cin.ignore();
	getline(cin, tempString);
	QuanLyNhanVien<NhanVien>* dbnv = new QuanLyNhanVien<NhanVien>(tempString);

	do {
		cout << endl;
		cout << "============= Quan ly nhan vien =============" << endl;
		cout << "So luong hien tai: " << dbnv->LaySoLuong() << endl << endl;
		cout << "1: Them nhan vien" << endl;
		cout << "2: Sua nhan vien" << endl;
		cout << "3: Xoa nhan vien" << endl;
		cout << "4: Hien thi thong tin nhan vien" << endl;
		cout << "5: Tim kiem nhan vien" << endl;
		cout << "6: Xuat toan bo danh sach" << endl;
		cout << "7: Sap xep danh sach theo tien luong" << endl;
		cout << "0: Thoat chuong trinh" << endl << endl;
		cout << "Chon: ";
		cin >> mode;
		cout << endl;

		switch (mode) {
		default:
			break;
		case 1:
			QLNV_Them(dbnv);
			break;
		case 2:
			QLNV_Sua(dbnv);
			break;
		case 3:
			QLNV_Xoa(dbnv);
			break;
		case 4:
			QLNV_HienThiThongTin(dbnv);
			break;
		case 5:
			QLNV_TimKiemTheoTen(dbnv);
			break;
		case 6:
			QLNV_XuatDanhSach(dbnv);
			break;
		case 7:
			QLNV_SapXepTheoLuong(dbnv);
			break;
		}
	} while (mode != 0);

	delete dbnv;
	return 0;
}

template <class T>
void QLNV_Them(QuanLyNhanVien<T>* input) {
	try {
		input->Them();
	}
	catch (string ex) {
		cout << ex << endl;
	}
}

template <class T>
void QLNV_Sua(QuanLyNhanVien<T>* input) {
	cout << "Vui long chon chi muc cua nhan vien can sua: ";
	int index; cin >> index;
	try {
		// dbnv[index].
		// TODO: Sua tai day!
		input->Sua(index);
	}
	catch (string ex) {
		cout << "Loi khi sua!" << endl;
		cout << "Noi dung thong bao loi: " << endl << ex << endl;
	}
}

template <class T>
void QLNV_Xoa(QuanLyNhanVien<T>* input) {
	cout << "Vui long chon chi muc cua nhan vien can xoa: ";
	int index; cin >> index;
	try {
		input->Xoa(index);
		cout << "Da xoa!" << endl;
	}
	catch (exception ex) {
		cout << "Loi khi xoa!" << endl;
		cout << "Noi dung loi: " << endl << ex.what() << endl;
	}
}

template <class T>
void QLNV_HienThiThongTin(QuanLyNhanVien<T>* input) {
	cout << "Vui long chon chi muc cua nhan vien can hien thi: ";
	int index; cin >> index;
	try {
		// TODO: cout << *dbnv[index];
		// cout << &dbnv[index];
	}
	catch (string ex) {
		cout << ex << endl;
	}
}

template <class T>
void QLNV_TimKiemTheoTen(QuanLyNhanVien<T>* input) {
	cout << "Vui long nhap ten cua nguoi muon tim kiem: ";
	string timKiem; cin >> timKiem;
	try {
		cout << input->TimKiemTheoTen(timKiem);
	}
	catch (string ex) {
		cout << ex << endl;
	}
}

template <class T>
void QLNV_XuatDanhSach(QuanLyNhanVien<T>* input) {
	try {
		cout << *input << endl;
	}
	catch (exception ex) {
		cout << ex.what() << endl;
	}
}

template <class T>
void QLNV_SapXepTheoLuong(QuanLyNhanVien<T>* input) {
	try {
		cout << "Chon cach sap xep:" << endl;
		cout << "  1: Tang dan" << endl;
		cout << "  2: Giam dan" << endl;
		cout << "Chon: ";
		int index; cin >> index;
		if (index == 1)
			input->SapXepTheoLuong(TangDan);
		else if (index == 2)
			input->SapXepTheoLuong(GiamDan);
		else throw string("Ban da nhap sai yeu cau!\nHay vao lai menu va thu lai.\n");
	}
	catch (string ex) {
		cout << ex << endl;
	}
}

#include "Date.h"

Date::~Date(void) {

}

Date::Date(unsigned int d, unsigned int m, unsigned int y) {
	if (y <= 0)
		throw string("Sai dinh dang ngay: Nam phai lon hon hoac bang 0!");
	if ((m <= 0) || (m > 12))
		throw string("Sai dinh dang ngay: Thang phai nam trong khoang 1 -> 12!");
	if ((d <= 0) || ((int)d > (this->DayCountOnMonth[m-1] + ((m == 2) ? (this->NamNhuan() ? 1 : 0) : 0))))
		throw string("Sai dinh dang ngay: Ngay phai nam trong khoang 1 -> " +
			to_string(this->DayCountOnMonth[m-1] + ((m == 2) ? (this->NamNhuan() ? 1 : 0) : 0)) +
			" vi ban da nhap thang " + to_string(m) + "!");

	this->Nam = y;
	this->Thang = m;
	this->Ngay = d;
}

Date::Date(const Date& date) {
	this->Nam = date.Nam;
	this->Thang = date.Thang;
	this->Ngay = date.Ngay;
}

void Date::SuaNgay(unsigned int d) {
	if ((d <= 0) || ((int)d > (this->DayCountOnMonth[this->Thang - 1] + (Thang == 2 ? (this->NamNhuan() ? 1 : 0) : 0))))
		throw string("Sai dinh dang ngay: Ngay phai nam trong khoang 1 -> " +
			to_string(this->DayCountOnMonth[this->Thang-1] + (Thang == 2 ? (this->NamNhuan() ? 1 : 0) : 0)) +
			" vi ban da nhap thang " + to_string(Thang) + "!");
	this->Ngay = d;
}

void Date::SuaThang(unsigned int m) {
	if ((m <= 0) || (m > 12))
		throw string("Sai dinh dang ngay: Thang phai nam trong khoang 1 -> 12!");

	this->Thang = m;
	SuaNgay(this->Ngay);
}

void Date::SuaNam(unsigned int y) {
	if (y <= 0)
		throw string("Sai dinh dang ngay: Nam phai lon hon hoac bang 0!");

	this->Nam = y;
	if ((this->Ngay <= 0) || ((int)this->Ngay > (this->DayCountOnMonth[this->Thang-1] + (Thang == 2 ? (this->NamNhuan() ? 1 : 0) : 0)))) {
		cout << "Ban da nhap nam " << y << ". Ngay se duoc gan lai bang 1!";
		this->Ngay = 1;
	}
}

unsigned int Date::NgayTrongTuan() {
	return (this->Ngay + 2 * this->Thang + (3 * (this->Thang + 1)) / 5 + this->Nam + (this->Nam / 4)) % 7 + 1;
}

bool Date::NamNhuan() {
	return (this->Nam % 400 == 0 || ((this->Nam % 4 == 0) && (this->Nam % 100 != 0)));
}

unsigned int Date::LayNgay() {
	return this->Ngay;
}

unsigned int Date::LayThang() {
	return this->Thang;
}

unsigned int Date::LayNam() {
	return this->Nam;
}

istream& operator>>(istream& cin, Date& input) {
	unsigned int temp;

NhapNam:
	try {
		cout << "Nhap nam: ";
		cin >> temp;
		input.SuaNam(temp);
	}
	catch (string ex) {
		cout << ex << endl;
		goto NhapNam;
	}

NhapThang:
	try {
		cout << "Nhap thang: ";
		cin >> temp;
		input.SuaThang(temp);
	}
	catch (string ex) {
		cout << ex << endl;
		goto NhapThang;
	}

NhapNgay:
	try {
		cout << "Nhap ngay: ";
		cin >> temp;
		input.SuaNgay(temp);
	}
	catch (string ex) {
		cout << ex << endl;
		goto NhapNgay;
	}

	return cin;
}

ostream& operator<<(ostream& cout, Date& input) {
	string result = "";
	result += input.DayOfWeekString[input.NgayTrongTuan() - 1] + " ";
	result += to_string(input.Ngay) + '/';
	result += to_string(input.Thang) + '/';
	result += to_string(input.Nam);
	cout << result;
	return cout;
}

Date& Date::operator=(const Date& input) {
	this->Nam = input.Nam;
	this->Thang = input.Thang;
	this->Ngay = input.Ngay;
	return *this;
}

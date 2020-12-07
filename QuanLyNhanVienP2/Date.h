#pragma once
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Date {
	unsigned int Ngay;
	unsigned int Thang;
	unsigned int Nam;
public:
	int DayCountOnMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string DayOfWeekString[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	~Date(void);
	Date(unsigned int d = 1, unsigned int m = 1, unsigned int y = 1900);
	Date(const Date&);
	unsigned int LayNgay();
	unsigned int LayThang();
	unsigned int LayNam();
	bool NamNhuan();
	void SuaNgay(unsigned int);
	void SuaThang(unsigned int);
	void SuaNam(unsigned int);
	unsigned int NgayTrongTuan();
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, Date&);
	Date& operator=(const Date&);
};

/// <summary>
/// Lay ngay hien tai.
/// </summary>
/// <returns></returns>
Date Now();

int YearBetween2Date(Date date1, Date date2);

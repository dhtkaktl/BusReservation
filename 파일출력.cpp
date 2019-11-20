#include <iostream>
#include "Bus.cpp"
#include <fstream>
#include <string>
using namespace std;
int main() {
	ofstream out("savfo.txt", ios::app); //파일쓰기, append모드

	std::string name, phone;
	//bus *ex1 = new normalbus("9:00");
	//bus *ex2 = new honorsbus("12:00");
	//bus *ex3 = new premiumbus("15:00");

	cout << "이름, 전화번호를 입력해주세요. " << endl;
	cout << "이름: "; cin >> name;
	cout << "전화번호: ";  cin >> phone;
	out << name << " " << phone << endl;// 마지막에 " " 없게 할 것

	out.close();

	cout << "예매되었습니다." << endl;
	system("pause");

	return 0;
}
#include <iostream>
#include "Bus.cpp"
#include <fstream>
#include <string>
using namespace std;
int main() {
	ofstream out("savfo.txt", ios::app); //���Ͼ���, append���

	std::string name, phone;
	//bus *ex1 = new normalbus("9:00");
	//bus *ex2 = new honorsbus("12:00");
	//bus *ex3 = new premiumbus("15:00");

	cout << "�̸�, ��ȭ��ȣ�� �Է����ּ���. " << endl;
	cout << "�̸�: "; cin >> name;
	cout << "��ȭ��ȣ: ";  cin >> phone;
	out << name << " " << phone << endl;// �������� " " ���� �� ��

	out.close();

	cout << "���ŵǾ����ϴ�." << endl;
	system("pause");

	return 0;
}
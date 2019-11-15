#include<string>
#include<iostream>
using namespace std;
class Bus{

protected:
	string dep,arr;//��߽ð� �����ð�
	string grade;
	int seatCount;
public:
	Bus(string dep){
		this->dep = dep;
	}
	void decrease();
	void increase();
	void showSeat();
};
class NormalBus:public Bus {
	bool seatList[40] = { 0 }; //0 �� ���ڸ� �¼� ���� x, 1�� ���ڸ�
public:
	NormalBus(string dep):Bus(dep){
		grade = "�Ϲݰ��";
		seatCount = 40;
	}
	void decrease(){
		if (seatCount == 0) {
			std::cout << "�ڸ��� �����ϴ�." << std::endl;
			return;
		}
		seatCount--;
	}// 1�� ���� �ּ� 0
	void increase(){
		if (seatCount == 40) {
			std::cout << "�ִ� �¼��� �ʰ�" << std::endl;
			return;
		}
		seatCount++;
	}// 1�� ���� �ִ� 40  
	void showSeat(){
		system("cls");
		std::cout << "�Ϲ� ���� �ڸ�" << std::endl;
		for (int i = 0; i < 40; i = i + 4) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << " -" << (i + 4) / 10 << (i + 4) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << "| " << seatList[i + 3] << "|" << std::endl;
			std::cout << " -------------------" << std::endl << std::endl;

		}
	}// �ε��������� �� ���� index%4==0�̸� �ٹٲ�

	//seat����
	/*-19- -20- -21-
	  | 0| | 1| | 0|
	  ---- ---- ----

  	  -22- -23- -24-
	  | 0| | 1| | 0|
	  ---- ---- ----*/
};
class HonorsBus :public Bus {
	bool seatList[30] = { 0 }; //0 �� ���ڸ� �¼� ���� x, 1�� ���ڸ�
public:
	HonorsBus(string dep) :Bus(dep) {
		grade = "�����";
		seatCount = 30;
	}
	void decrease() {
		if (seatCount == 0) {
			std::cout << "�ڸ��� �����ϴ�." << std::endl;
			return;
		}
		seatCount--;
	}// 1�� ���� �ּ� 0
	void increase() {
		if (seatCount == 30) {
			std::cout << "�ִ� �¼��� �ʰ�" << std::endl;
			return;
		}
		seatCount++;
	};// 1�� ���� �ִ� 40  
	void showSeat() {
		system("cls");
		std::cout << "�Ϲ� ���� �ڸ�" << std::endl;
		for (int i = 0; i < 30; i = i + 3) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << std::endl;
			std::cout << " --------------" << std::endl << std::endl;

		}
	}// �ε��������� �� ���� index%3==0�̸� �ٹٲ�
};
class PremiumBus :public Bus {
	bool seatList[21] = { 0 }; //0 �� ���ڸ� �¼� ���� x, 1�� ���ڸ�
public:
	PremiumBus(string dep) :Bus(dep) {
		grade = "�����̾�";
		seatCount = 21;
	}
	void decrease() {
		if (seatCount == 0) {
			std::cout << "�ڸ��� �����ϴ�." << std::endl;
			return;
		}
		seatCount--;
	}// 1�� ���� �ּ� 0
	void increase() {
		if (seatCount == 21) {
			std::cout << "�ִ� �¼��� �ʰ�" << std::endl;
			return;
		}
		seatCount++;
	}// 1�� ���� �ִ� 40  
	void showSeat() {
		system("cls");
		std::cout << "�Ϲ� ���� �ڸ�" << std::endl;
		for (int i = 0; i < 21; i = i + 3) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << std::endl;
			std::cout << " --------------" << std::endl << std::endl;

		}
	}// �ε��������� �� ���� index%4==0�̸� �ٹٲ�
};
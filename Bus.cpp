#include<string> // 2019-11-22 �� ���� 11:30 LINK ���� �ذ� ����
#include<iostream>

using namespace std;

class Bus {
protected:
	string dep, arr;// ��߽ð�, �����ð�
	string grade;	// ���
	string date;	// ��¥
	int seatCount;	// �ܿ���
	int totalSeats;	// �� �¼� ��
public:
	Bus(string dep) {
		this->dep = dep;
	}
	Bus(string dep, string date) {
		this->dep = dep;
		this->date = date;
	}
	virtual void decrease() {}	// decrease�� increase�� ���� ���� ���� (reserveSeat���� ���)
	virtual void increase() {}
	virtual int showSeat() { return 0; }	// �¼� ����Լ� - ���� ������ �ڽ� Ŭ��������
	int getSeatCount() { return seatCount; }	// �ܿ��� ������
	int getTotalSeats() { return totalSeats; }	// �� �¼� �� ������
	string getDep() { return dep; }
	string getArr() { return arr; }
	string getGrade() { return grade; }
	virtual bool reserveSeat(int x) { return 0; } // �¼����� �Լ� - ���� ������ �ڽ� Ŭ��������
	// �¼���ȣ�� ���ڷ� �޾� �ش� �¼��� ���(0)������ 1�� �ٲٰ� true��, �̹� ������ �ڸ��� false ����
};
class NormalBus :public Bus {
	bool seatList[40] = { 0 }; // 0�� ���ڸ�, 1�� ���ڸ�
public:
	NormalBus(string dep) :Bus(dep) {
		grade = "�Ϲݰ��";
		seatCount = 40;
		totalSeats = 40;
	}
	NormalBus(string dep, string date) :Bus(dep, date) {
		grade = "�Ϲݰ��";
		seatCount = 40;
		totalSeats = 40;
	}
	void decrease() {
		if (seatCount == 0) {
			std::cout << "�ڸ��� �����ϴ�." << std::endl;
			return;
		}
		seatCount--;
	}// 1�� ���� �ּ� 0
	void increase() {
		if (seatCount == 40) {
			std::cout << "�ִ� �¼��� �ʰ�" << std::endl;
			return;
		}
		seatCount++;
	}// 1�� ���� �ִ� 40  
	int showSeat() {
		system("cls");
		std::cout << "�Ϲ� ���� �ڸ�" << std::endl;
		for (int i = 0; i < 40; i = i + 4) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << " -" << (i + 4) / 10 << (i + 4) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << "| " << seatList[i + 3] << "|" << std::endl;
			std::cout << " -------------------" << std::endl << std::endl;

		}
		return 0;
	}
	bool reserveSeat(int seatNum) {
		if (seatList[seatNum] == 0) {	// ���� ������ ���
			seatList[seatNum] = 1;		// �ż��Ǿ��ٴ� ���� 1�� �ٲٰ�
			return true;				// true ����
		}
		else							// �̹� ���ŵ� �ڸ�(1)�̸�
			return false;				// false ����
	}
};
class HonorsBus :public Bus {
	bool seatList[30] = { 0 }; //0 �� ���ڸ� �¼� ���� x, 1�� ���ڸ�
public:
	HonorsBus(string dep) :Bus(dep) {
		grade = "�����";
		seatCount = 30;
		totalSeats = 30;
	}
	HonorsBus(string dep, string date) :Bus(dep, date) {
		grade = "�����";
		seatCount = 30;
		totalSeats = 30;
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
	int showSeat() {
		system("cls");
		std::cout << "�Ϲ� ���� �ڸ�" << std::endl;
		for (int i = 0; i < 30; i = i + 3) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << std::endl;
			std::cout << " --------------" << std::endl << std::endl;

		}
		return 0;
	}// �ε��������� �� ���� index%3==0�̸� �ٹٲ�
	bool reserveSeat(int seatNum) {
		if (seatList[seatNum] == 0) {	// ���� ������ ���
			seatList[seatNum] = 1;		// �ż��Ǿ��ٴ� ���� 1�� �ٲٰ�
			return true;				// true ����
		}
		else							// �̹� ���ŵ� �ڸ�(1)�̸�
			return false;				// false ����
	}
};
class PremiumBus :public Bus {
	bool seatList[21] = { 0 }; //0 �� ���ڸ� �¼� ���� x, 1�� ���ڸ�
public:
	PremiumBus(string dep) :Bus(dep) {
		grade = "�����̾�";
		seatCount = 21;
		totalSeats = 21;
	}
	PremiumBus(string dep, string date) :Bus(dep, date) {
		grade = "�����̾�";
		seatCount = 21;
		totalSeats = 21;
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
	int showSeat() {
		system("cls");
		std::cout << "�Ϲ� ���� �ڸ�" << std::endl;
		for (int i = 0; i < 21; i = i + 3) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << std::endl;
			std::cout << " --------------" << std::endl << std::endl;

		}
		return 0;
	}// �ε��������� �� ���� index%4==0�̸� �ٹٲ�
	bool reserveSeat(int seatNum) {
		if (seatList[seatNum] == 0) {	// ���� ������ ���
			seatList[seatNum] = 1;		// �ż��Ǿ��ٴ� ���� 1�� �ٲٰ�
			return true;				// true ����
		}
		else							// �̹� ���ŵ� �ڸ�(1)�̸�
			return false;				// false ����
	}
};
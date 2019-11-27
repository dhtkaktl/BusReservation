#include<string>
#include<iostream>

// ����� ���� ����� ����(Normal, Honor, Premium)
// increase(), decrease() ����
// showSeat() �Լ� void�� �ٽ� ����(�ѵ��� int���� - ��ũ ���� ����)
// �� �߿�: reserveSeat(�¼���ȣ)�� �� �¼���ȣ�� 1���� ���� (0���� ���۾ƴ�)
//     ��: reserveSeat(1)�ϸ� seatList[0]�� ���ŵ�
// cancelSeat() �Լ� �߰� - reserveSeat�� �ݴ� ���� (���� ����ϰ� �ܿ���++�ϴ� ���)

using namespace std;

class Bus {	// �����, �������� �̱��� // ��� virtual �Լ��� �ڽĿ��� ����
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
	virtual void showSeat() { }	// �¼���ġ�� ���
	int getSeatCount() { return seatCount; }	// �ܿ��� ������
	int getTotalSeats() { return totalSeats; }	// �� �¼� �� ������
	string getDep() { return dep; }
	string getArr() { return arr; }
	string getGrade() { return grade; }
	string getDate() { return date; }
	virtual bool reserveSeat(int x) { return 0; } // �¼� ����
//	�� �¼���ȣ�� ���ڷ� �޾� �ش� �¼��� ���(0)������ 1�� �ٲٰ� true��, �̹� ������ �ڸ��� false ����
	virtual bool cancelSeat(int x) { return 0; } // �¼� �������
};
class NormalBus :public Bus {
	bool seatList[40] = { 0 }; // 0�� ���ڸ�, 1�� ���ڸ�
public:
	NormalBus(string dep) :Bus(dep) {
		grade = "Normal";
		seatCount = 40;
		totalSeats = 40;
	}
	NormalBus(string dep, string date) :Bus(dep, date) {
		grade = "Normal";
		seatCount = 40;
		totalSeats = 40;
	}
	void showSeat() {
		for (int i = 0; i < 40; i = i + 4) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << " -" << (i + 4) / 10 << (i + 4) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << "| " << seatList[i + 3] << "|" << std::endl;
			std::cout << " -------------------" << std::endl << std::endl;
		}
	}
	bool reserveSeat(int seatNum) {
		if (seatList[seatNum-1] == 0) {	// ���� ������ ���
			seatList[seatNum-1] = 1;		// �ż��Ǿ��ٴ� ���� 1�� �ٲٰ�
			seatCount--;
			return true;				// true ����
		}
		else							// �̹� ���ŵ� �ڸ�(1)�̸�
			return false;				// false ����
	}
	bool cancelSeat(int seatNum) {
		if (seatList[seatNum - 1] == 1) {	// ��� �����ϸ�(�ż��� �ڸ���)
			seatList[seatNum - 1] = 0; // ����ϰ�
			seatCount++; // �ܿ��� �ٽ�+1
			return true; // true ����(��� ����)
		}
		else							// �� �ڸ�(0)�ε� ��� �õ��ϴ°Ÿ�
			return false;				// false ����
	}
};
class HonorsBus :public Bus {
	bool seatList[30] = { 0 }; //0 �� ���ڸ� �¼� ���� x, 1�� ���ڸ�
public:
	HonorsBus(string dep) :Bus(dep) {
		grade = "Honor";
		seatCount = 30;
		totalSeats = 30;
	}
	HonorsBus(string dep, string date) :Bus(dep, date) {
		grade = "Honor";
		seatCount = 30;
		totalSeats = 30;
	}
	void showSeat() {
		for (int i = 0; i < 30; i = i + 3) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << std::endl;
			std::cout << " --------------" << std::endl << std::endl;
		}
	}
	bool reserveSeat(int seatNum) {
		if (seatList[seatNum-1] == 0) {	// ���� ������ ���
			seatList[seatNum-1] = 1;		// �ż��Ǿ��ٴ� ���� 1�� �ٲٰ�
			seatCount--;
			return true;				// true ����
		}
		else							// �̹� ���ŵ� �ڸ�(1)�̸�
			return false;				// false ����
	}
	bool cancelSeat(int seatNum) {
		if (seatList[seatNum - 1] == 1) {	// ��� �����ϸ�(�ż��� �ڸ���)
			seatList[seatNum - 1] = 0; // ����ϰ�
			seatCount++; // �ܿ��� �ٽ�+1
			return true; // true ����(��� ����)
		}
		else							// �� �ڸ�(0)�ε� ��� �õ��ϴ°Ÿ�
			return false;				// false ����
	}
};
class PremiumBus :public Bus {
	bool seatList[21] = { 0 }; //0 �� ���ڸ� �¼� ���� x, 1�� ���ڸ�
public:
	PremiumBus(string dep) :Bus(dep) {
		grade = "Premium";
		seatCount = 21;
		totalSeats = 21;
	}
	PremiumBus(string dep, string date) :Bus(dep, date) {
		grade = "Premium";
		seatCount = 21;
		totalSeats = 21;
	}
	void showSeat() {
		for (int i = 0; i < 21; i = i + 3) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << std::endl;
			std::cout << " --------------" << std::endl << std::endl;
		}
	}
	bool reserveSeat(int seatNum) {
		if (seatList[seatNum-1] == 0) {	// ���� ������ ���
			seatList[seatNum-1] = 1;		// �ż��Ǿ��ٴ� ���� 1�� �ٲٰ�
			seatCount--;
			return true;				// true ����
		}
		else							// �̹� ���ŵ� �ڸ�(1)�̸�
			return false;				// false ����
	}
	bool cancelSeat(int seatNum) {
		if (seatList[seatNum - 1] == 1) {	// ��� �����ϸ�(�ż��� �ڸ���)
			seatList[seatNum - 1] = 0; // ����ϰ�
			seatCount++; // �ܿ��� �ٽ�+1
			return true; // true ����(��� ����)
		}
		else							// �� �ڸ�(0)�ε� ��� �õ��ϴ°Ÿ�
			return false;				// false ����
	}
};

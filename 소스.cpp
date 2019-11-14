#include<string>
using namespace std;
class Bus{

protected:
	string dep,arr;//��߽ð� �����ð�
	int grade;
	int seatCount;
public:
	Bus(string dep){
		this->dep = dep;
	}
	void decrease(){};
	void increase(){};
	void showSeat(){};
};
class NormalBus:public Bus {
	bool seatList[40] = { 0 }; //0 �� ���ڸ� �¼� ���� x, 1�� ���ڸ�
public:
	NormalBus(string dep):Bus(dep){
		grade = 1;
		seatCount = 40;
	}
	//decrease(){};// 1�� ���� �ּ� 0
	//increase(){};// 1�� ���� �ִ� 40  
	//showSeat(){};// �ε��������� �� ���� index%4==0�̸� �ٹٲ�
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
		grade = 2;
		seatCount = 30;
	}
	//decrease(){};// 1�� ���� �ּ� 0
	//increase(){};// 1�� ���� �ִ� 40  
	//showSeat(){};// �ε��������� �� ���� index%3==0�̸� �ٹٲ�
};
class PremiumBus :public Bus {
	bool seatList[21] = { 0 }; //0 �� ���ڸ� �¼� ���� x, 1�� ���ڸ�
public:
	PremiumBus(string dep) :Bus(dep) {
		grade = 3;
		seatCount = 21;
	}
	//decrease(){};// 1�� ���� �ּ� 0
	//increase(){};// 1�� ���� �ִ� 40  
	//showSeat(){};// �ε��������� �� ���� index%4==0�̸� �ٹٲ�
};
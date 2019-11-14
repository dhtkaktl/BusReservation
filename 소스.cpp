#include<string>
using namespace std;
class Bus{

protected:
	string dep,arr;//출발시간 도착시간
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
	bool seatList[40] = { 0 }; //0 이 빈자리 좌석 예매 x, 1이 찬자리
public:
	NormalBus(string dep):Bus(dep){
		grade = 1;
		seatCount = 40;
	}
	//decrease(){};// 1씩 감소 최소 0
	//increase(){};// 1씩 증가 최대 40  
	//showSeat(){};// 인덱스값으로 줄 구별 index%4==0이면 줄바꿈
	//seat예시
	/*-19- -20- -21-
	  | 0| | 1| | 0|
	  ---- ---- ----

  	  -22- -23- -24-
	  | 0| | 1| | 0|
	  ---- ---- ----*/
};
class HonorsBus :public Bus {
	bool seatList[30] = { 0 }; //0 이 빈자리 좌석 예매 x, 1이 찬자리
public:
	HonorsBus(string dep) :Bus(dep) {
		grade = 2;
		seatCount = 30;
	}
	//decrease(){};// 1씩 감소 최소 0
	//increase(){};// 1씩 증가 최대 40  
	//showSeat(){};// 인덱스값으로 줄 구별 index%3==0이면 줄바꿈
};
class PremiumBus :public Bus {
	bool seatList[21] = { 0 }; //0 이 빈자리 좌석 예매 x, 1이 찬자리
public:
	PremiumBus(string dep) :Bus(dep) {
		grade = 3;
		seatCount = 21;
	}
	//decrease(){};// 1씩 감소 최소 0
	//increase(){};// 1씩 증가 최대 40  
	//showSeat(){};// 인덱스값으로 줄 구별 index%4==0이면 줄바꿈
};
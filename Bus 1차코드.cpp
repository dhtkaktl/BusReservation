#include<string>
#include<iostream>
using namespace std;
class Bus{

protected:
	string dep,arr;//출발시간 도착시간
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
	bool seatList[40] = { 0 }; //0 이 빈자리 좌석 예매 x, 1이 찬자리
public:
	NormalBus(string dep):Bus(dep){
		grade = "일반고속";
		seatCount = 40;
	}
	void decrease(){
		if (seatCount == 0) {
			std::cout << "자리가 없습니다." << std::endl;
			return;
		}
		seatCount--;
	}// 1씩 감소 최소 0
	void increase(){
		if (seatCount == 40) {
			std::cout << "최대 좌석수 초과" << std::endl;
			return;
		}
		seatCount++;
	}// 1씩 증가 최대 40  
	void showSeat(){
		system("cls");
		std::cout << "일반 버스 자리" << std::endl;
		for (int i = 0; i < 40; i = i + 4) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << " -" << (i + 4) / 10 << (i + 4) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << "| " << seatList[i + 3] << "|" << std::endl;
			std::cout << " -------------------" << std::endl << std::endl;

		}
	}// 인덱스값으로 줄 구별 index%4==0이면 줄바꿈

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
		grade = "우등고속";
		seatCount = 30;
	}
	void decrease() {
		if (seatCount == 0) {
			std::cout << "자리가 없습니다." << std::endl;
			return;
		}
		seatCount--;
	}// 1씩 감소 최소 0
	void increase() {
		if (seatCount == 30) {
			std::cout << "최대 좌석수 초과" << std::endl;
			return;
		}
		seatCount++;
	};// 1씩 증가 최대 40  
	void showSeat() {
		system("cls");
		std::cout << "일반 버스 자리" << std::endl;
		for (int i = 0; i < 30; i = i + 3) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << std::endl;
			std::cout << " --------------" << std::endl << std::endl;

		}
	}// 인덱스값으로 줄 구별 index%3==0이면 줄바꿈
};
class PremiumBus :public Bus {
	bool seatList[21] = { 0 }; //0 이 빈자리 좌석 예매 x, 1이 찬자리
public:
	PremiumBus(string dep) :Bus(dep) {
		grade = "프리미엄";
		seatCount = 21;
	}
	void decrease() {
		if (seatCount == 0) {
			std::cout << "자리가 없습니다." << std::endl;
			return;
		}
		seatCount--;
	}// 1씩 감소 최소 0
	void increase() {
		if (seatCount == 21) {
			std::cout << "최대 좌석수 초과" << std::endl;
			return;
		}
		seatCount++;
	}// 1씩 증가 최대 40  
	void showSeat() {
		system("cls");
		std::cout << "일반 버스 자리" << std::endl;
		for (int i = 0; i < 21; i = i + 3) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << std::endl;
			std::cout << " --------------" << std::endl << std::endl;

		}
	}// 인덱스값으로 줄 구별 index%4==0이면 줄바꿈
};
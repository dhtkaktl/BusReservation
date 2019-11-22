#include<string> // 2019-11-22 금 오전 11:30 LINK 오류 해결 버전
#include<iostream>

using namespace std;

class Bus {
protected:
	string dep, arr;// 출발시간, 도착시간
	string grade;	// 등급
	string date;	// 날짜
	int seatCount;	// 잔여석
	int totalSeats;	// 총 좌석 수
public:
	Bus(string dep) {
		this->dep = dep;
	}
	Bus(string dep, string date) {
		this->dep = dep;
		this->date = date;
	}
	virtual void decrease() {}	// decrease와 increase는 추후 삭제 예정 (reserveSeat으로 흡수)
	virtual void increase() {}
	virtual int showSeat() { return 0; }	// 좌석 출력함수 - 실제 구현은 자식 클래스에서
	int getSeatCount() { return seatCount; }	// 잔여석 접근자
	int getTotalSeats() { return totalSeats; }	// 총 좌석 수 접근자
	string getDep() { return dep; }
	string getArr() { return arr; }
	string getGrade() { return grade; }
	virtual bool reserveSeat(int x) { return 0; } // 좌석예매 함수 - 실제 구현은 자식 클래스에서
	// 좌석번호를 인자로 받아 해당 좌석이 비어(0)있으면 1로 바꾸고 true를, 이미 매점된 자리면 false 리턴
};
class NormalBus :public Bus {
	bool seatList[40] = { 0 }; // 0이 빈자리, 1이 찬자리
public:
	NormalBus(string dep) :Bus(dep) {
		grade = "일반고속";
		seatCount = 40;
		totalSeats = 40;
	}
	NormalBus(string dep, string date) :Bus(dep, date) {
		grade = "일반고속";
		seatCount = 40;
		totalSeats = 40;
	}
	void decrease() {
		if (seatCount == 0) {
			std::cout << "자리가 없습니다." << std::endl;
			return;
		}
		seatCount--;
	}// 1씩 감소 최소 0
	void increase() {
		if (seatCount == 40) {
			std::cout << "최대 좌석수 초과" << std::endl;
			return;
		}
		seatCount++;
	}// 1씩 증가 최대 40  
	int showSeat() {
		system("cls");
		std::cout << "일반 버스 자리" << std::endl;
		for (int i = 0; i < 40; i = i + 4) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << " -" << (i + 4) / 10 << (i + 4) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << "| " << seatList[i + 3] << "|" << std::endl;
			std::cout << " -------------------" << std::endl << std::endl;

		}
		return 0;
	}
	bool reserveSeat(int seatNum) {
		if (seatList[seatNum] == 0) {	// 예매 가능할 경우
			seatList[seatNum] = 1;		// 매석되었다는 뜻인 1로 바꾸고
			return true;				// true 리턴
		}
		else							// 이미 예매된 자리(1)이면
			return false;				// false 리턴
	}
};
class HonorsBus :public Bus {
	bool seatList[30] = { 0 }; //0 이 빈자리 좌석 예매 x, 1이 찬자리
public:
	HonorsBus(string dep) :Bus(dep) {
		grade = "우등고속";
		seatCount = 30;
		totalSeats = 30;
	}
	HonorsBus(string dep, string date) :Bus(dep, date) {
		grade = "우등고속";
		seatCount = 30;
		totalSeats = 30;
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
	int showSeat() {
		system("cls");
		std::cout << "일반 버스 자리" << std::endl;
		for (int i = 0; i < 30; i = i + 3) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << std::endl;
			std::cout << " --------------" << std::endl << std::endl;

		}
		return 0;
	}// 인덱스값으로 줄 구별 index%3==0이면 줄바꿈
	bool reserveSeat(int seatNum) {
		if (seatList[seatNum] == 0) {	// 예매 가능할 경우
			seatList[seatNum] = 1;		// 매석되었다는 뜻인 1로 바꾸고
			return true;				// true 리턴
		}
		else							// 이미 예매된 자리(1)이면
			return false;				// false 리턴
	}
};
class PremiumBus :public Bus {
	bool seatList[21] = { 0 }; //0 이 빈자리 좌석 예매 x, 1이 찬자리
public:
	PremiumBus(string dep) :Bus(dep) {
		grade = "프리미엄";
		seatCount = 21;
		totalSeats = 21;
	}
	PremiumBus(string dep, string date) :Bus(dep, date) {
		grade = "프리미엄";
		seatCount = 21;
		totalSeats = 21;
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
	int showSeat() {
		system("cls");
		std::cout << "일반 버스 자리" << std::endl;
		for (int i = 0; i < 21; i = i + 3) {
			std::cout << " -" << (i + 1) / 10 << (i + 1) % 10 << "-" << " -" << (i + 2) / 10 << (i + 2) % 10 << "-" << " -" << (i + 3) / 10 << (i + 3) % 10 << "-" << std::endl;
			std::cout << " | " << seatList[i] << "| " << "| " << seatList[i + 1] << "| " << "| " << seatList[i + 2] << "| " << std::endl;
			std::cout << " --------------" << std::endl << std::endl;

		}
		return 0;
	}// 인덱스값으로 줄 구별 index%4==0이면 줄바꿈
	bool reserveSeat(int seatNum) {
		if (seatList[seatNum] == 0) {	// 예매 가능할 경우
			seatList[seatNum] = 1;		// 매석되었다는 뜻인 1로 바꾸고
			return true;				// true 리턴
		}
		else							// 이미 예매된 자리(1)이면
			return false;				// false 리턴
	}
};
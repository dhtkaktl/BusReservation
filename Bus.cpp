#include<string>
#include<iostream>

// 등급을 전부 영어로 변경(Normal, Honor, Premium)
// increase(), decrease() 삭제
// showSeat() 함수 void로 다시 변경(한동안 int였음 - 링크 에러 관련)
// ※ 중요: reserveSeat(좌석번호)할 때 좌석번호는 1부터 시작 (0부터 시작아님)
//     예: reserveSeat(1)하면 seatList[0]이 예매됨
// cancelSeat() 함수 추가 - reserveSeat의 반대 역할 (예매 취소하고 잔여석++하는 기능)

using namespace std;

class Bus {	// 출발지, 도착지는 미구현 // 모든 virtual 함수는 자식에서 구현
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
	virtual void showSeat() { }	// 좌석배치도 출력
	int getSeatCount() { return seatCount; }	// 잔여석 접근자
	int getTotalSeats() { return totalSeats; }	// 총 좌석 수 접근자
	string getDep() { return dep; }
	string getArr() { return arr; }
	string getGrade() { return grade; }
	string getDate() { return date; }
	virtual bool reserveSeat(int x) { return 0; } // 좌석 예매
//	ㄴ 좌석번호를 인자로 받아 해당 좌석이 비어(0)있으면 1로 바꾸고 true를, 이미 매점된 자리면 false 리턴
	virtual bool cancelSeat(int x) { return 0; } // 좌석 예매취소
};
class NormalBus :public Bus {
	bool seatList[40] = { 0 }; // 0이 빈자리, 1이 찬자리
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
		if (seatList[seatNum-1] == 0) {	// 예매 가능할 경우
			seatList[seatNum-1] = 1;		// 매석되었다는 뜻인 1로 바꾸고
			seatCount--;
			return true;				// true 리턴
		}
		else							// 이미 예매된 자리(1)이면
			return false;				// false 리턴
	}
	bool cancelSeat(int seatNum) {
		if (seatList[seatNum - 1] == 1) {	// 취소 가능하면(매석된 자리면)
			seatList[seatNum - 1] = 0; // 취소하고
			seatCount++; // 잔여석 다시+1
			return true; // true 리턴(취소 성공)
		}
		else							// 빈 자리(0)인데 취소 시도하는거면
			return false;				// false 리턴
	}
};
class HonorsBus :public Bus {
	bool seatList[30] = { 0 }; //0 이 빈자리 좌석 예매 x, 1이 찬자리
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
		if (seatList[seatNum-1] == 0) {	// 예매 가능할 경우
			seatList[seatNum-1] = 1;		// 매석되었다는 뜻인 1로 바꾸고
			seatCount--;
			return true;				// true 리턴
		}
		else							// 이미 예매된 자리(1)이면
			return false;				// false 리턴
	}
	bool cancelSeat(int seatNum) {
		if (seatList[seatNum - 1] == 1) {	// 취소 가능하면(매석된 자리면)
			seatList[seatNum - 1] = 0; // 취소하고
			seatCount++; // 잔여석 다시+1
			return true; // true 리턴(취소 성공)
		}
		else							// 빈 자리(0)인데 취소 시도하는거면
			return false;				// false 리턴
	}
};
class PremiumBus :public Bus {
	bool seatList[21] = { 0 }; //0 이 빈자리 좌석 예매 x, 1이 찬자리
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
		if (seatList[seatNum-1] == 0) {	// 예매 가능할 경우
			seatList[seatNum-1] = 1;		// 매석되었다는 뜻인 1로 바꾸고
			seatCount--;
			return true;				// true 리턴
		}
		else							// 이미 예매된 자리(1)이면
			return false;				// false 리턴
	}
	bool cancelSeat(int seatNum) {
		if (seatList[seatNum - 1] == 1) {	// 취소 가능하면(매석된 자리면)
			seatList[seatNum - 1] = 0; // 취소하고
			seatCount++; // 잔여석 다시+1
			return true; // true 리턴(취소 성공)
		}
		else							// 빈 자리(0)인데 취소 시도하는거면
			return false;				// false 리턴
	}
};

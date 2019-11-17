#include<iostream>
#include "Bus.cpp"
#define MAX 3 // 하루당 총 버스 댓수

using namespace std;

//예매기능(); //확인기능(); //취소기능(); //안내화면출력();

void mainMenu(Bus**); // main 함수의 버스 배열이 포인터의 배열이기 때문에 **

main() {
	Bus* bus[MAX];
	NormalBus n("9:00");
	HonorsBus n1("12:00");
	PremiumBus n2("15:00");
	bus[0] = &n;
	bus[1] = &n1;
	bus[2] = &n2;

	mainMenu(bus);

}

void mainMenu(Bus** bus) {
	while (true) {
		int select;
		switch (select) {
		case 1:
			//변수 4개 선언 출발지, 도착지, 가는날짜, 조회할 등급
			//노선조회(*, *, *, *) 호출 // 위에서 선언한 네개 변수의 포인터를 매개변수로

			//조회등급변수에 따른 버스목록 출력(){
			//선택한 조회등급에 따라서 해당 등급버스만 출력
			//for문으로 bus[i]->grade == "해당등급" 버스의 시간, 등급, 잔여석 출력
			//}

			////////////////////////////////////////////////////////////////////////

			// 버스 선택 및 좌석배치 출력			
			cout << "버스 번호 입력:";
			int busSelect;
			while (true) {
				cin >> busSelect;
				if (0 <= busSelect && busSelect < MAX)
					break;
				cout << "잘못된 입력입니다. 다시 입력해주세요:";
			}
			bus[busSelect]->showSeat();

			// 좌석번호 선택 및 매석 단계 
			while (true) {
				cout << "좌석 번호 선택:";
				int seatSelect;
				while (true) {
					cin >> seatSelect;
					if (1 <= seatSelect && seatSelect <= bus[busSelect]->getTotalSeats);
					break;
					cout << "잘못된 입력입니다. 다시 입력해주세요:";
				}

				if (bus[busSelect]->reserveSeat(seatSelect)) { // 입력받은 좌석번호로 예매 시도
					cout << "예매되었습니다.";
					break;
				}
				else
					cout << "이미 예매된 좌석입니다." << endl;
			}

			// 버스 비회원등록(이름 전화번호 저장, 변수선언 및 저장)
			// 결제되었습니다. 출력

		case 2:
			//이름 전화번호 선언후에 입력받음
			//버스 확인화면 출력함수( 이름 전화번호 포인터로 입력받음);

		case 3:
			//버스 취소화면출력
			//버스 취소기능

		case 4:
			//버스 안내 화면 출력
			//버스 도착안내 출력기능

		case 5:
			//종료
		}
	}
}
//버스 노선조회화면출력(출발지선택, 도착지 선택, 가는날짜 선택, 조회등급선택 포인터로){ 
//
//
// }
//예매기능(){} 구현
//확인기능(){} 구현
//취소기능(){} 구현
//안내화면출력(){} 구현
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>
#include "Bus.cpp"
#define MAX 8 // 하루당 총 버스 댓수
#define FILENAME "Info.txt" // 예매 정보가 저장되는 텍스트 파일 이름(경로)
// ㄴ주의: 테스트용 텍스트 파일 만들 때 예를 들어 9시 버스는 "9:00"이 아니라 "09:00"으로 할 것

#define EMPTY_CIN cin.clear(); cin.ignore(INT_MAX, '\n'); // cin 버퍼를 비우는 코드(비정상적인 입력 처리용)

using namespace std;

struct info { // 예매취소 정보 저장용 구조체
	string  number, src, dst, date, grade, name, phone, seat, time;
};

void setState(Bus* bus[][MAX]); // 텍스트 파일 읽어 배열 내 버스 객체들 상태 세팅
void mainMenu(Bus* bus_array[][MAX]);
void showTable(Bus* bus_array[][MAX], int date_index, string grade); // 시간표 출력 및 좌석 선택, 예매까지 다 하는.. 함수
void saveInfo(Bus* bus_pointer, int seatNum); // 예매내역 저장 함수(출발지 도착지는 유성-서울로 고정함) 
void checkReservation(); // 예매확인 함수
void RemoveInfo(struct info*); // 텍스트 파일에서 취소할 예매내역을 지우는 함수
vector<string> split(string str, char delimiter); // str을 delimiter를 기준으로 자른 토큰들을 벡터에 저장해 리턴

int main() {

	Bus* bus[7][MAX]; // 1주일 x 일일 총 버스 댓수
	for (int i = 0; i < 7; i++) {
		string date1 = "2019-12-";
		string date2 = to_string(i+6); // 프로젝트 최종 발표일인 12월 6일부터 1주일
		string sumString = date1 + date2;
		bus[i][0] = new NormalBus("08:00", sumString);
		bus[i][1] = new HonorsBus("10:00", sumString);
		bus[i][2] = new PremiumBus("12:00", sumString);
		bus[i][3] = new NormalBus("14:00", sumString);
		bus[i][4] = new HonorsBus("16:00", sumString);
		bus[i][5] = new PremiumBus("18:00", sumString);
		bus[i][6] = new NormalBus("20:00", sumString);
		bus[i][7] = new HonorsBus("22:00", sumString);
	}

	setState(bus); // 버스 객체들의 상태 세팅(버스별 잔여 좌석수, 좌석 현황)
	
	mainMenu(bus); // 주 작동부(메인 메뉴)

}

void setState(Bus* bus[][MAX]) {

	string line;

	ifstream test_in(FILENAME); // 파일 존재 여부 테스트용 입력스트림
	if (!test_in.is_open()) { // 안 열리면(즉 없으면) FILENAME 경로로 공백 파일 생성
		ofstream outFile;
		outFile.open(FILENAME);
		outFile.close();
	}
	test_in.close(); // 테스트용 인풋 스트림 닫음

	ifstream in(FILENAME);

	getline(in, line);
	while (!in.eof()) {	// 텍스트파일 한줄씩 읽어서, ' ' 기준으로 자른 뒤 배열에 저장
		vector<string> line_vector = split(line, ' ');
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < MAX; j++) { // [4]=날짜 [5]=시간 [6]=등급 [7]=좌석번호				
				if ((line_vector[4] == bus[i][j]->getDate()) && (line_vector[5] == bus[i][j]->getDep()) && (line_vector[6] == bus[i][j]->getGrade())) {
					bus[i][j]->reserveSeat(stoi(line_vector[7]));
				}
			}
		}
		// 텍스트파일의 맨 마지막 줄이 '\n'인 경우 처리
		getline(in, line);
		if (line_vector.size() == 0)
			break;
	}

}

void mainMenu(Bus* bus[][MAX]) {
	while (true) {
		system("cls");
		cout << "1. 버스 예매" << endl;
		cout << "2. 예매 확인" << endl;
		cout << "3. 예매 취소" << endl;
		cout << "4. 프로그램 종료" << endl;

		string inputGrade; // 버스예매시 등급 선택할 때 사용
		int select;	// 다양한 선택에서 쓰이는 변수
		int dateIndex; // 날짜 선택내역을 저장할 변수
		
		while (true) {
			cout << "\n메뉴 번호 입력: "; cin >> select;
			if (1 <= select && select <= 4)	break;
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
			EMPTY_CIN
		} EMPTY_CIN

		system("cls");
		switch (select) {
		
		case 1: // 1. 버스예매
			cout << "<출발지 선택>" << endl;
			cout << "1. 유성" << endl;
			while (true) {
				cout << "\n입력: "; cin >> select;
				if (select == 1) break;
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
				EMPTY_CIN
			} EMPTY_CIN

			cout << "\n<도착지 선택>" << endl;
			cout << "1. 서울" << endl;
			while (true) {
				cout << "\n입력: "; cin >> select;
				if (select == 1) break;
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
				EMPTY_CIN
			} EMPTY_CIN

			cout << "\n<날짜 선택>" << endl;
			cout << "1. 2019. 12. 6. 금" << endl;
			cout << "2. 2019. 12. 7. 토" << endl;
			cout << "3. 2019. 12. 8. 일" << endl;
			cout << "4. 2019. 12. 9. 월" << endl;
			cout << "5. 2019. 12. 10. 화" << endl;
			cout << "6. 2019. 12. 11. 수" << endl;
			cout << "7. 2019. 12. 12. 목" << endl;
			while (true) {
				cout << "\n입력: "; cin >> select;
				if (1 <= select && select <= 7)	break;
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
				EMPTY_CIN
			} EMPTY_CIN
			dateIndex = select - 1; // 인덱스는 0부터 시작하므로

			cout << "\n<등급 선택>" << endl;
			cout << "1. 전체" << endl;
			cout << "2. 프리미엄" << endl;
			cout << "3. 우등" << endl;
			cout << "4. 일반" << endl;
			while (true) {
				cout << "\n조회하기: "; cin >> select;
				if (1 <= select && select <= 4)	break;
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
				EMPTY_CIN
			} EMPTY_CIN

			switch (select) {
			case 1:	inputGrade = "전체"; break;
			case 2:	inputGrade = "Premium"; break;
			case 3:	inputGrade = "Honor"; break;
			case 4:	inputGrade = "Normal"; break;
			}
			
			showTable(bus, dateIndex, inputGrade); // 위에서 선택한 조건들로 배차 조회부터 예매까지 진행
			
			system("pause");
			break;

		case 2:	// 2. 예매확인
			checkReservation();

			system("pause");
			break;

		case 3: {// 3. 예매취소 // case문 안에서 변수 선언하려면 블록 처리
			struct info cancelInfo;
			RemoveInfo(&cancelInfo);

			for (int i = 0; i < 7; i++)
				for (int j = 0; j < MAX; j++)
					if ((bus[i][j]->getDate() == cancelInfo.date) &&
						(bus[i][j]->getDep() == cancelInfo.time) &&
						(bus[i][j]->getGrade() == cancelInfo.grade)) {
							bus[i][j]->cancelSeat(stoi(cancelInfo.seat)); // stoi: string to int
					}
			
			system("pause");
			break;
		}

		case 4: // 4. 종료
			cout << "-- 프로그램이 종료되었습니다 --" << endl;
			return;
		}
	}
}

void showTable(Bus* bus[][MAX], int date_index, string grade) { // 원래는 bus와 grade 2개
	Bus* selectBus[MAX]; // 선택한 등급의 버스들(의 포인터)만을 저장할 배열
	int count = 0; // 선택된 버스들의 댓수 저장

	system("cls");
	cout << "<배차 조회>" << endl;

	if (grade == "전체") {
		for (int i = 0; i < MAX; i++) {
			selectBus[count] = bus[date_index][i];
			count++;
		}
	}
	else {
		for (int i = 0; i < MAX; i++) {
			if ((bus[date_index][i]->getGrade() == grade)) {
				selectBus[count] = bus[date_index][i];
				count++;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ". " << selectBus[i]->getDep() << " " << selectBus[i]->getGrade() << " " << selectBus[i]->getSeatCount() << endl;
	}		// 1번부터 뜨게 i + 1로 변경

	/////////////////////////////////////////////////////////////////////////////////////

	int busSelect;

	while (true) {
		cout << "\n버스 번호 입력:"; cin >> busSelect;
		if ((1 <= busSelect) && (busSelect < count+1)) break; // 1번부터 출력됨에 맞춰 0->1, count->count+1
		cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
		EMPTY_CIN
	} EMPTY_CIN

	system("cls");
	std::cout << "<좌석 선택>\n" << std::endl;
	selectBus[--busSelect]->showSeat(); // 좌석 출력 // UI상으로는 1번부터 시작하나 실제 인덱스는 0부터 시작하므로 --busSelect

	int seatSelect;
	while (true) { // 예매가 성공할 때까지 도는 루프
		while (true) {
			cout << "좌석 번호 입력:"; cin >> seatSelect;
			if ((1 <= seatSelect) && (seatSelect <= selectBus[busSelect]->getTotalSeats()))	break;
			cout << "잘못된 입력입니다. 다시 입력해주세요.\n" << endl;
			EMPTY_CIN
		} EMPTY_CIN
		if (selectBus[busSelect]->reserveSeat(seatSelect)) { // 입력받은 좌석번호로 예매 시도
			// 예매한 버스 포인터와 좌석번호를 가지고 예매정보 저장 함수로 넘어감
			saveInfo(selectBus[busSelect], seatSelect);
			cout << "-- 예매되었습니다 --\n" << endl;
			break;
		}
		else
			cout << "이미 예매된 좌석입니다." << endl;
	}	

}

void saveInfo(Bus* bus, int seatNum) {
	ofstream out(FILENAME, ios::app); // 파일쓰기, append모드

	std::string name, phone;

	cout << "이름, 전화번호를 입력해주세요. " << endl;
	cout << "이름: "; cin >> name;
	cout << "전화번호: ";  cin >> phone;

	out << name << " " << phone << " "; // 이름, 전화번호
	out << "Yuseong" << " " << "Seoul" << " "; // 출발지, 목적지 (※ 유성-서울 1노선 고정)	
	out << bus->getDate() << " " << bus->getDep() << " " << bus->getGrade() << " " << seatNum << endl;
	// ㄴ 날짜, 시간, 등급, 좌석번호 출력하고 줄바꿈

	out.close();
}

void checkReservation() {
	string check_name, check_phonenumber; // 입력 받는 이름, 전화번호
	string line; // 텍스트파일에서 읽은 라인
	bool isExist = false; // 입력 받은 이름&전화번호의 존재 여부
	int check_count = 0; // 잘못 입력한 횟수. 3회 이상 잘못 입력할 경우 예매 확인 종료.

	while (check_count < 3) {
		// 이름, 전화번호 입력 받음
		cout << "이름 입력: "; cin >> check_name;
		cout << "전화번호 입력: "; cin >> check_phonenumber;
		check_count++;

		// 텍스트파일에서 데이터 읽기 
		ifstream in(FILENAME);
		if (!in.is_open()) {
			std::cout << "파일을 찾을 수 없습니다!" << std::endl;
			system("pause"); // 디버깅 및 에러탐지용
			return; // 예외처리로 바꿔야?
		}

		while (in) {
			// 텍스트파일 한줄씩 읽어서, ' ' 기준으로 자른 뒤 배열에 저장
			getline(in, line);
			//cout << line << endl;
			vector<string> line_vector = split(line, ' ');

			// 텍스트파일의 맨 마지막 줄이 '\n'인 경우 처리
			if (line_vector.size() == 0)
				break;

			// 입력 받은 이름&전화번호와 동일하면, 예매 정보 출력
			if ((check_name == line_vector[0]) && (check_phonenumber == line_vector[1])) {
				isExist = true;
				cout << "-----------------------------------" << endl;
				cout << "출발-도착: " << line_vector[2] << " -> " << line_vector[3] << endl;
				cout << "출발 날짜: " << line_vector[4] << endl;
				cout << "출발 시간: " << line_vector[5] << endl;
				cout << "버스 등급: " << line_vector[6] << endl;
				cout << "좌석 번호: " << line_vector[7] << endl;
				cout << "-----------------------------------" << endl;
			}
		}

		// 입력 받은 이름&전화번호가 텍스트파일에 존재하지 않으면, 다시 입력받음 
		if (!isExist) {
			if (check_count != 3)
				cout << "\n이름 혹은 전화번호를 잘못 입력하셨습니다. 다시 입력해주세요.(" << check_count << "/3)\n" << endl;
			else {
				cout << "\n3회 잘못 입력하셨습니다. 예매 확인을 종료합니다." << endl;
				break;
			}
		}
		else
			break;
	}
}

void RemoveInfo(struct info *Info) {
	int select = 0; // 사용자 선택 저장용 변수
	string strTemp;
	bool isExist = false;
	int num = 0;
	string check_name, check_phonenumber; // 입력 받은 이름, 입력 받은 전화번호
	string line; //텍스트 파일에서 읽은 라인
	ofstream out("temp.txt", ios::trunc); // 쓰기모드 
	//trunc: 파일이 이미 있는 경우, 기존의 파일을 삭제하고 다시 만듦
	ifstream in(FILENAME); //읽기모드

	if (!in.is_open()) {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
		return;
	}
	cout << "예매취소를 진행합니다. " << endl;
	cout << "이름, 전화번호를 입력해주세요.\n" << endl;
	cout << "이름: "; cin >> check_name;
	cout << "전화번호: ";  cin >> check_phonenumber;

	cout << "\n<고객님의 예매정보는 다음과 같습니다.>\n" << endl;

	/*콘솔 출력*/
	while (in) {
		string s_num = to_string(num+1); // 1번부터 출력되게 조정(num -> num+1)
		getline(in, line);
		line = s_num + "번" + " " + line;
		if (in.eof()) {
			break;
		}

		vector<string> line_vector = split(line, ' ');
		if (line_vector.size() == 0) {
			break;
		}
		if ((check_name == line_vector[1]) && (check_phonenumber == line_vector[2])) {
			isExist = true;
			++num;
			cout << line << endl;
		}
	}
	if (isExist) {
		while (true) {
			cout << "\n취소할 건을 선택해주세요:"; cin >> select;
			if (1 <= select && select < num+1) break;  // 1번부터 출력되게 조정(0->1, num->num+1)
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
			EMPTY_CIN
		} EMPTY_CIN
	}
	else {
		cout << "--예매정보가 없습니다--\n" << endl;
		in.close();
		return;
	}

	int count = select - 1;  // 1번부터 출력되게 조정(select 뒤에 -1 추가)
	in.close();
	ifstream in_(FILENAME); // 읽기모드

	while (in_) { // 해당번호 삭제 진행
		getline(in_, line);
		strTemp = line;
		vector<string> line_vector = split(line, ' ');
		if (in_.eof()) {
			break;
		}
		if (line_vector.size() == 0) {
			break;
		}
		if ((check_name == line_vector[0]) && (check_phonenumber == line_vector[1])) {
			if (count == 0) { // count == 0 이면 해당 줄이 삭제할 줄이라는 뜻
				// 삭제하기전에 삭제 정보 복사
				Info->name = line_vector[0];
				Info->phone = line_vector[1];
				Info->src = line_vector[2];
				Info->dst = line_vector[3];
				Info->date = line_vector[4];
				Info->time = line_vector[5];
				Info->grade = line_vector[6];
				Info->seat = line_vector[7];
			}
			else
				out << strTemp << endl; // 그게 아니면 일반 줄처럼(아래 else처럼) 그대로 중간 텍스트 파일에 씀
			count--;
		}
		else {
			out << strTemp << endl;
		}
	}

	in_.close();
	out.close();

	if (isExist) {
		/*파일 복사*/		
		ofstream dst(FILENAME, ios::trunc);
		ifstream src("temp.txt");

		dst << src.rdbuf();
		src.close();
		dst.close();
	}

	cout << "\n" << select << "번 취소가 완료되었습니다. " << endl;
	return;
}

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}
	return internal;
}
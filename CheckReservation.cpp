#include <iostream>
#include <string> //Main에 추가
#include <fstream> //Main에 추가
#include <vector> //Main에 추가
#include <sstream> //Main에 추가
using namespace std;
// 한글-한글 안됨

// str(문자열)을 delimiter(' ')을 기준을 잘라서 배열에 넣어 주는 함수
vector<string> split(string str, char delimiter) { 
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

int main() {	
	// 변수선언
	string check_name, check_phonenumber; // 입력 받은 이름, 입력 받은 전화번호
	string line; // 텍스트파일에서 읽은 라인
	bool isExist = false; // 입력 받은 이름&전화번호의 존재 여부
	int check_count = 0; // 잘못 입력한 횟수. 3회 이상 잘못 입력할 경우 예매 확인 종료.

	while (check_count < 3) {
		// 이름, 전화번호 입력 받음
		cout << "이름 입력: ";
		cin >> check_name;
		cout << "전화번호 입력: ";
		cin >> check_phonenumber;
		check_count++;

		// 텍스트파일에서 데이터 읽기 
		ifstream in("savedInfo_test.txt");
		if (!in.is_open()) {
			std::cout << "파일을 찾을 수 없습니다!" << std::endl;
			return 0;
		}

		while (in) {
			// 텍스트파일 한줄씩 읽어서, ' ' 기준으로 자른 뒤 배열에 저장
			getline(in, line);
			//cout << line << endl;
			vector<string> line_vector = split(line, ' ');

			// 텍스트파일의 맨 마지막 줄이 '\n'인 경우 예외처리
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
			if(check_count != 3)
				cout << "\n이름 혹은 전화번호를 잘못 입력하셨습니다. 다시 입력해주세요.(" << check_count << "/3)" << endl;
			else {
				cout << "\n3회 잘못 입력하셨습니다. 예매 확인을 종료합니다." << endl;
				break;
			}
		} 
		else 
			break;

	}
	
	//cunt<<"처음으로 돌아가기..";

	return 0;
}


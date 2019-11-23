#include <iostream>
#include "Bus.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <cstring>

using namespace std;
struct info {
	string  number,src, dst, date, grade, name, phone, seatSelect;
};
// str(문자열)을 delimiter(' ')을 기준을 잘라서 배열에 넣어 주는 함수
vector<string> split(const string str, const char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp; //token

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

//입력 한글 x
int main() {
	int i = 0;
	string strTemp;
	int num=0;
	string check_name, check_phonenumber; // 입력 받은 이름, 입력 받은 전화번호
	string line; //텍스트 파일에서 읽은 라인
	bool isExist = false; // 입력 받은 이름&전화번호의 존재 여부
	int check_count = 0; // 잘못 입력한 횟수. 3회 이상 잘못 입력할 경우 예매 확인 종료.
	ofstream out("InfoOut.txt", ios::trunc); //쓰기모드 
	//trunc: 파일이 이미 있는 경우, 기존의 파일을 삭제하고 다시 만듦
	ifstream in("savedInfo.txt"); //읽기모드
	struct info Info[100];
	while (check_count < 3) {
		if (!in.is_open()) {
			std::cout << "파일을 찾을 수 없습니다!" << std::endl;
			return 0;
		}
		cout << "예매취소를 진행합니다. " << endl;
		cout << "이름, 전화번호를 입력해주세요. " << endl;
		cout << "이름: "; cin >> check_name;
		cout << "전화번호: ";  cin >> check_phonenumber;
		check_count++;

		cout << "고객님의 예매정보는 다음과 같습니다.\n" << endl;

		/*콘솔 출력*/
		while (in) {
			string s_num = to_string(num);
			getline(in, line);
			line = s_num +"번"+" "+ line;

			vector<string> line_vector = split(line, ' ');
			if (line_vector.size() == 0) {
				break;
			}
			if ((check_name == line_vector[1]) && (check_phonenumber == line_vector[2])) {
				isExist = true;
				Info[i].number = line_vector[0];
				Info[i].name = line_vector[1];
				Info[i].phone = line_vector[2];
				Info[i].src = line_vector[3];
				Info[i].dst = line_vector[4];
				Info[i].date = line_vector[5];
//				Info[i].grade = line_vector[6];
//				Info[i].seatSelect = line_vector[7];
				++i;
				++num;
				cout << line << endl;
			}
		}
		cout << "\n취소하고 싶은 예매목록을 입력해주세요.(번호입력)" << endl;
		cin >> num;
		///num만큼 반복문 돌려서 해당 행 찾고 이 문자열을 토큰단위로 쪼개서 savedInof파일에서 다 일치하면
		//예매정보 삭제진행
		in.close();
		ifstream in("savedInfo.txt"); //읽기모드

		//해당번호 삭제 진행
		while (!in.eof()) {
			getline(in, line);
			strTemp = line;
			vector<string> line_vector = split(line, ' ');
		
			if (line_vector.size() == 0) {
				break;
			}
			if ((Info[num].name == line_vector[0]) && (Info[num].phone == line_vector[1]) && (Info[num].src == line_vector[2]) && (Info[num].dst == line_vector[3]) && (Info[num].date == line_vector[4])) {
				isExist = true;

			}
			else {
				out << strTemp << endl;
			}

		}
		if (!isExist) {
			if (check_count != 3)
				cout << "\n이름 혹은 전화번호를 잘못 입력하셨습니다. 다시 입력해주세요.(" << check_count << "/3)" << endl;
			else {
				cout << "\n3회 잘못 입력하셨습니다. 예매 취소를 종료합니다." << endl;
				break;
			}
		}
		else {
			cout << "\n" << num << "번 취소가 완료되었습니다. " << endl;
			break;

		}

	}
	in.close();
	out.close();

	/*파일 복사*/
	ofstream dst("savedInfo.txt", ios::trunc);
	ifstream src("InfoOut.txt");

	dst << src.rdbuf();

	src.close();
	dst.close();
	system("pause");

	return 0;
}
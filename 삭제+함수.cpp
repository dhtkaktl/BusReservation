#include <iostream>
#include "Bus.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <cstring>

using namespace std;
struct info {
	string src, dst, date, grade, name, phone, seatSelect, time;
	int number;
};
// str(문자열)을 delimiter(' ')을 기준을 잘라서 배열에 넣어 주는 함수
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp; //token

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

struct info& RemoveInfo(struct info *Info, bool isExist);

//입력 한글 x
int main() {
	struct info Info;
	bool isExist = false;
	RemoveInfo(&Info, isExist);
	cout << Info.number << endl;
	system("pause");
	return 0;
}

struct info& RemoveInfo(struct info *Info, bool isExist) {
	int i = 0;
	string strTemp;
	isExist = false;
	int num = 0;
	string check_name, check_phonenumber; // 입력 받은 이름, 입력 받은 전화번호
	string line; //텍스트 파일에서 읽은 라인
	ofstream out("InfoOut.txt", ios::trunc); //쓰기모드 
	//trunc: 파일이 이미 있는 경우, 기존의 파일을 삭제하고 다시 만듦
	ifstream in("savedInfo.txt"); //읽기모드

	if (!in.is_open()) {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
		return *Info;
	}
	cout << "예매취소를 진행합니다. " << endl;
	cout << "이름, 전화번호를 입력해주세요. " << endl;
	cout << "이름: "; cin >> check_name;
	cout << "전화번호: ";  cin >> check_phonenumber;

	cout << "고객님의 예매정보는 다음과 같습니다.\n" << endl;

	/*콘솔 출력*/
	while (in) {
		string s_num = to_string(num);
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
			Info->name = line_vector[1];
			Info->phone = line_vector[2];
			Info->src = line_vector[3];
			Info->dst = line_vector[4];
			Info->date = line_vector[5];
			Info->time = line_vector[6];
			Info->grade = line_vector[7];
			Info->seatSelect = line_vector[8]; 
			++i;
			++num;
			cout << line << endl;
		}
	}
	if (isExist) {
		cout << "\n취소하고 싶은 예매목록을 입력해주세요.(번호입력)" << endl;
		cin >> num;
		Info->number = num;
		/*입력번호가 숫자가 아닐경우 예외처리
		  숫자 0-9까지 지원*/
		if (((char)num)>=48&&((char)num)<=57) {
			cout << "잘못 입력 하셨습니다." << endl;
			cout << "예매취소를 종료합니다" << endl;
			in.close();
			return *Info;
			
		}
	}
	else {
		cout << "\n예매정보가 없습니다." << endl;
		cout << "예매취소를 종료합니다" << endl;
		in.close();
		return *Info;
	}

	isExist = false;
	in.close();
	ifstream in_("savedInfo.txt"); //읽기모드
	//해당번호 삭제 진행

	while (in_) {
		getline(in_, line);
		strTemp = line;
		vector<string> line_vector = split(line, ' ');
		if (in_.eof()) {
			break;
		}

		if (line_vector.size() == 0) {
			break;
		}

		if ((Info->name == line_vector[0]) && (Info->phone == line_vector[1])) {
			isExist = true;
			if (num == 0) num--;
			else {
				out << strTemp << endl;
				num--;
			}
		}
		else {
			out << strTemp << endl;
		}

	}
	if (isExist) {
		cout << "\n" << Info->number << "번 취소가 완료되었습니다. " << endl;
		
	}

	in_.close();
	out.close();
	if (isExist) {
		/*파일 복사*/
		ofstream dst("savedInfo.txt", ios::trunc);
		ifstream src("InfoOut.txt");

		dst << src.rdbuf();
		src.close();
		dst.close();
	}
	return *Info;
}
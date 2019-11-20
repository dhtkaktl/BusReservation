#include <iostream>
#include "Bus.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 

using namespace std;

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

int main() {
	string strTemp;
	string check_name, check_phonenumber; // 입력 받은 이름, 입력 받은 전화번호
	string line; //텍스트 파일에서 읽은 라인
	bool isExist = false; // 입력 받은 이름&전화번호의 존재 여부
	int check_count = 0; // 잘못 입력한 횟수. 3회 이상 잘못 입력할 경우 예매 확인 종료.
	ofstream out("InfoOut.txt",ios::trunc); //쓰기모드 
	//trunc: 파일이 이미 있는 경우, 기존의 파일을 삭제하고 다시 만듦
	ifstream in("savedInfo.txt"); //읽기모드

	while (check_count < 3) {
		in.clear();
		cout << "예매취소를 진행합니다. " << endl;
		cout << "이름, 전화번호를 입력해주세요. " << endl;
		cout << "이름: "; cin >> check_name;
		cout << "전화번호: ";  cin >> check_phonenumber;
		check_count++;

		if (!in.is_open()) {
			std::cout << "파일을 찾을 수 없습니다!" << std::endl;
			return 0;
		}

		while (in) {
			getline(in, line);
			strTemp = line;
			vector<string> line_vector = split(line, ' ');

			if (line_vector.size() == 0) {
				break;
			}
			if ((check_name == line_vector[0]) && (check_phonenumber == line_vector[1])) {
				isExist = true;
			}
			else {
				strTemp += "\n";
				out << strTemp;
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
				cout << "\n취소가 완료되었습니다. " << endl;
				break;

			}

		}
	in.close();
	out.close();

	/*파일 복사*/
	ofstream dst("savedInfo.txt",ios::trunc); 
	ifstream src("InfoOut.txt"); 
	
	dst << src.rdbuf();

	src.close();
	out.close();
	cout << "\nㅎㅇ";
	system("pause");

	return 0;
}
#include<iostream>
#include<string>
#include "bus.cpp"
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>
#define MAX 3 // 하루당 총 버스 댓수

using namespace std;

//예매기능(); //확인기능(); //취소기능(); //안내화면출력();
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

//void mainMenu(Bus**); // main 함수의 버스 배열이 포인터의 배열이기 때문에 **
//void printWay(Bus** bus, string grade);

int main() {

	Bus* bus[7][MAX];
	for (int i = 0; i < 7; i++) {
		string date1 = "2019-11-2";
		string date2 = to_string(i);
		string sumString = date1 + date2;		
		bus[i][0] = new NormalBus("9:00", sumString);
		bus[i][1] = new HonorsBus("12:00", sumString);
		bus[i][2] = new PremiumBus("15:00", sumString);
	}

	cout<<bus[1][2]->getGrade();

	string line;
	ifstream in("test.txt");
	if (!in.is_open()) {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
		return 0;
	}
	while (in) {
		// 텍스트파일 한줄씩 읽어서, ' ' 기준으로 자른 뒤 배열에 저장
		getline(in, line);
		//cout << line << endl;
		vector<string> line_vector = split(line, ' ');
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < MAX; j++) {
				//날찌 시간 등급 자리 4 5 6 7
				if ((line_vector[4] == bus[i][j]->getDate()) && (line_vector[5] == bus[i][j]->getDep()) && (line_vector[6] == bus[i][j]->getGrade())) {
					bus[i][j]->reserveSeat(stoi(line_vector[7]));
				}
			}
		}
		// 텍스트파일의 맨 마지막 줄이 '\n'인 경우 예외처리
		if (line_vector.size() == 0)
			break;
	}
	


	//bus[0][0]->showSeat();

	/*Bus* busss = new NormalBus("9:00");
	cout << busss->getDep() << endl;
	busss->showSeat();*/


		
	system("pause");
	return 0;
}
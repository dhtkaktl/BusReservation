#include<iostream>
#include<string>
#include "bus.cpp"
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>
#define MAX 3 // �Ϸ�� �� ���� ���

using namespace std;

//���ű��(); //Ȯ�α��(); //��ұ��(); //�ȳ�ȭ�����();
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

//void mainMenu(Bus**); // main �Լ��� ���� �迭�� �������� �迭�̱� ������ **
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
		std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
		return 0;
	}
	while (in) {
		// �ؽ�Ʈ���� ���پ� �о, ' ' �������� �ڸ� �� �迭�� ����
		getline(in, line);
		//cout << line << endl;
		vector<string> line_vector = split(line, ' ');
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < MAX; j++) {
				//���� �ð� ��� �ڸ� 4 5 6 7
				if ((line_vector[4] == bus[i][j]->getDate()) && (line_vector[5] == bus[i][j]->getDep()) && (line_vector[6] == bus[i][j]->getGrade())) {
					bus[i][j]->reserveSeat(stoi(line_vector[7]));
				}
			}
		}
		// �ؽ�Ʈ������ �� ������ ���� '\n'�� ��� ����ó��
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
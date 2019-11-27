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
// str(���ڿ�)�� delimiter(' ')�� ������ �߶� �迭�� �־� �ִ� �Լ�
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

//�Է� �ѱ� x
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
	string check_name, check_phonenumber; // �Է� ���� �̸�, �Է� ���� ��ȭ��ȣ
	string line; //�ؽ�Ʈ ���Ͽ��� ���� ����
	ofstream out("InfoOut.txt", ios::trunc); //������ 
	//trunc: ������ �̹� �ִ� ���, ������ ������ �����ϰ� �ٽ� ����
	ifstream in("savedInfo.txt"); //�б���

	if (!in.is_open()) {
		std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
		return *Info;
	}
	cout << "������Ҹ� �����մϴ�. " << endl;
	cout << "�̸�, ��ȭ��ȣ�� �Է����ּ���. " << endl;
	cout << "�̸�: "; cin >> check_name;
	cout << "��ȭ��ȣ: ";  cin >> check_phonenumber;

	cout << "������ ���������� ������ �����ϴ�.\n" << endl;

	/*�ܼ� ���*/
	while (in) {
		string s_num = to_string(num);
		getline(in, line);
		line = s_num + "��" + " " + line;
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
		cout << "\n����ϰ� ���� ���Ÿ���� �Է����ּ���.(��ȣ�Է�)" << endl;
		cin >> num;
		Info->number = num;
		/*�Է¹�ȣ�� ���ڰ� �ƴҰ�� ����ó��
		  ���� 0-9���� ����*/
		if (((char)num)>=48&&((char)num)<=57) {
			cout << "�߸� �Է� �ϼ̽��ϴ�." << endl;
			cout << "������Ҹ� �����մϴ�" << endl;
			in.close();
			return *Info;
			
		}
	}
	else {
		cout << "\n���������� �����ϴ�." << endl;
		cout << "������Ҹ� �����մϴ�" << endl;
		in.close();
		return *Info;
	}

	isExist = false;
	in.close();
	ifstream in_("savedInfo.txt"); //�б���
	//�ش��ȣ ���� ����

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
		cout << "\n" << Info->number << "�� ��Ұ� �Ϸ�Ǿ����ϴ�. " << endl;
		
	}

	in_.close();
	out.close();
	if (isExist) {
		/*���� ����*/
		ofstream dst("savedInfo.txt", ios::trunc);
		ifstream src("InfoOut.txt");

		dst << src.rdbuf();
		src.close();
		dst.close();
	}
	return *Info;
}
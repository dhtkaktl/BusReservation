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
// str(���ڿ�)�� delimiter(' ')�� ������ �߶� �迭�� �־� �ִ� �Լ�
vector<string> split(const string str, const char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp; //token

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

//�Է� �ѱ� x
int main() {
	int i = 0;
	string strTemp;
	int num=0;
	string check_name, check_phonenumber; // �Է� ���� �̸�, �Է� ���� ��ȭ��ȣ
	string line; //�ؽ�Ʈ ���Ͽ��� ���� ����
	bool isExist = false; // �Է� ���� �̸�&��ȭ��ȣ�� ���� ����
	int check_count = 0; // �߸� �Է��� Ƚ��. 3ȸ �̻� �߸� �Է��� ��� ���� Ȯ�� ����.
	ofstream out("InfoOut.txt", ios::trunc); //������ 
	//trunc: ������ �̹� �ִ� ���, ������ ������ �����ϰ� �ٽ� ����
	ifstream in("savedInfo.txt"); //�б���
	struct info Info[100];
	while (check_count < 3) {
		if (!in.is_open()) {
			std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
			return 0;
		}
		cout << "������Ҹ� �����մϴ�. " << endl;
		cout << "�̸�, ��ȭ��ȣ�� �Է����ּ���. " << endl;
		cout << "�̸�: "; cin >> check_name;
		cout << "��ȭ��ȣ: ";  cin >> check_phonenumber;
		check_count++;

		cout << "������ ���������� ������ �����ϴ�.\n" << endl;

		/*�ܼ� ���*/
		while (in) {
			string s_num = to_string(num);
			getline(in, line);
			line = s_num +"��"+" "+ line;

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
		cout << "\n����ϰ� ���� ���Ÿ���� �Է����ּ���.(��ȣ�Է�)" << endl;
		cin >> num;
		///num��ŭ �ݺ��� ������ �ش� �� ã�� �� ���ڿ��� ��ū������ �ɰ��� savedInof���Ͽ��� �� ��ġ�ϸ�
		//�������� ��������
		in.close();
		ifstream in("savedInfo.txt"); //�б���

		//�ش��ȣ ���� ����
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
				cout << "\n�̸� Ȥ�� ��ȭ��ȣ�� �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.(" << check_count << "/3)" << endl;
			else {
				cout << "\n3ȸ �߸� �Է��ϼ̽��ϴ�. ���� ��Ҹ� �����մϴ�." << endl;
				break;
			}
		}
		else {
			cout << "\n" << num << "�� ��Ұ� �Ϸ�Ǿ����ϴ�. " << endl;
			break;

		}

	}
	in.close();
	out.close();

	/*���� ����*/
	ofstream dst("savedInfo.txt", ios::trunc);
	ifstream src("InfoOut.txt");

	dst << src.rdbuf();

	src.close();
	dst.close();
	system("pause");

	return 0;
}
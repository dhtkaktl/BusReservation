#include <iostream>
#include "Bus.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 

using namespace std;

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

int main() {
	string strTemp;
	string check_name, check_phonenumber; // �Է� ���� �̸�, �Է� ���� ��ȭ��ȣ
	string line; //�ؽ�Ʈ ���Ͽ��� ���� ����
	bool isExist = false; // �Է� ���� �̸�&��ȭ��ȣ�� ���� ����
	int check_count = 0; // �߸� �Է��� Ƚ��. 3ȸ �̻� �߸� �Է��� ��� ���� Ȯ�� ����.
	ofstream out("InfoOut.txt",ios::trunc); //������ 
	//trunc: ������ �̹� �ִ� ���, ������ ������ �����ϰ� �ٽ� ����
	ifstream in("savedInfo.txt"); //�б���

	while (check_count < 3) {
		in.clear();
		cout << "������Ҹ� �����մϴ�. " << endl;
		cout << "�̸�, ��ȭ��ȣ�� �Է����ּ���. " << endl;
		cout << "�̸�: "; cin >> check_name;
		cout << "��ȭ��ȣ: ";  cin >> check_phonenumber;
		check_count++;

		if (!in.is_open()) {
			std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
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
					cout << "\n�̸� Ȥ�� ��ȭ��ȣ�� �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.(" << check_count << "/3)" << endl;
				else {
					cout << "\n3ȸ �߸� �Է��ϼ̽��ϴ�. ���� ��Ҹ� �����մϴ�." << endl;
					break;
				}
			}
			else {
				cout << "\n��Ұ� �Ϸ�Ǿ����ϴ�. " << endl;
				break;

			}

		}
	in.close();
	out.close();

	/*���� ����*/
	ofstream dst("savedInfo.txt",ios::trunc); 
	ifstream src("InfoOut.txt"); 
	
	dst << src.rdbuf();

	src.close();
	out.close();
	cout << "\n����";
	system("pause");

	return 0;
}
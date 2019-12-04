#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>
#include "Bus.cpp"
#define MAX 3 // �Ϸ�� �� ���� ���
#define FILENAME "Info.txt" // �߿�1: �ٸ� �̸��� ���Ϸ� �׽�Ʈ �غ��� ������ �� �κи� �����Ұ�
// �߿�2: �׽�Ʈ�� �ؽ�Ʈ ���� ���� �� 9�� ������ "9:00"�� �ƴ϶� "09:00"���� �� ��!

using namespace std;

struct info { // ������� ���� ������ ����ü
	string  number, src, dst, date, grade, name, phone, seat, time;
};

void mainMenu(Bus* bus_array[][MAX]);
// �ð�ǥ ��� �� �¼� ����, ���ű��� �� �ϴ�.. �Լ�
void showTable(Bus* bus_array[][MAX], int date_index, string grade);
// ���ų��� ���� �Լ�(����� �������� ����-����� ������) 
void saveInfo(Bus* bus_pointer, int seatNum);
void checkReservation(); // ����Ȯ�� �Լ�
void RemoveInfo(struct info*); // �ؽ�Ʈ ���Ͽ��� ����� ���ų��� ����� �Լ�
vector<string> split(string str, char delimiter);

int main() {

	Bus* bus[7][MAX]; // 1���� x ���� �� ���� ���
	for (int i = 0; i < 7; i++) {
		string date1 = "2019-12-";
		string date2 = to_string(i + 6); // ��ǥ���� 12�� 6�Ϻ��� 1����
		string sumString = date1 + date2;
		bus[i][0] = new NormalBus("09:00", sumString); // 09:00���� ���� ���� ����� ���� ��
		bus[i][1] = new HonorsBus("12:00", sumString);
		bus[i][2] = new PremiumBus("15:00", sumString);
	}

	// ���� ����� ��Ʈ - �Լ��� ��ȯ?
	string line;
	ifstream in0(FILENAME);
	if (!in0.is_open()) {
		ofstream outFile;
		outFile.open(FILENAME);
		outFile.close();
	}
	in0.close();

	ifstream in(FILENAME);

	getline(in, line);
	while (!in.eof()) {	// �ؽ�Ʈ���� ���پ� �о, ' ' �������� �ڸ� �� �迭�� ����
		vector<string> line_vector = split(line, ' ');
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < MAX; j++) { // [4]=��¥ [5]=�ð� [6]=��� [7]=�¼���ȣ				
				if ((line_vector[4] == bus[i][j]->getDate()) && (line_vector[5] == bus[i][j]->getDep()) && (line_vector[6] == bus[i][j]->getGrade())) {
					bus[i][j]->reserveSeat(stoi(line_vector[7]));
				}
			}
		}
		// �ؽ�Ʈ������ �� ������ ���� '\n'�� ��� ó��
		getline(in, line);
		if (line_vector.size() == 0)
			break;
	}

	// �� �۵���(���� �޴�)
	mainMenu(bus);

}

void mainMenu(Bus* bus[][MAX]) {
	while (true) {
		system("cls");
		cout << "1. ��������" << endl;
		cout << "2. ����Ȯ��" << endl;
		cout << "3. �������" << endl;
		cout << "4. ����" << endl;
		cout << "\n�޴� ��ȣ �Է�: ";

		string inputGrade; // �������ſ��� ��� ������ �� ���
		int select;	// �پ��� ���ÿ��� ���̴� ����
		int dateIndex; // ��¥ ���ó����� ������ ����
		cin >> select;

		system("cls");
		switch (select) {

		case 1: // 1. ��������
			cout << "<����� ����>" << endl;
			cout << "1. ����" << endl;
			while (true) {
				cout << "\n�Է�: "; cin >> select;
				if (select == 1) break;
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
			}
			cout << "\n<������ ����>" << endl;
			cout << "1. ����" << endl;
			while (true) {
				cout << "\n�Է�: "; cin >> select;
				if (select == 1) break;
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
			}
			cout << "\n<��¥ ����>" << endl;
			cout << "1. 2019. 12. 6. ��" << endl;
			cout << "2. 2019. 12. 7. ��" << endl;
			cout << "3. 2019. 12. 8. ��" << endl;
			cout << "4. 2019. 12. 9. ��" << endl;
			cout << "5. 2019. 12. 10. ȭ" << endl;
			cout << "6. 2019. 12. 11. ��" << endl;
			cout << "7. 2019. 12. 12. ��" << endl;
			while (true) {
				cout << "\n�Է�: "; cin >> select;
				if (1 <= select && select <= 7)	break;
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
			}
			dateIndex = select - 1; // �ε����� 0���� �����ϹǷ�

			cout << "\n<��� ����>" << endl;
			cout << "1. ��ü" << endl;
			cout << "2. �����̾�" << endl;
			cout << "3. ���" << endl;
			cout << "4. �Ϲ�" << endl;
			while (true) {
				cout << "\n��ȸ�ϱ�: "; cin >> select;
				if (1 <= select && select <= 4)	break;
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
			}
			switch (select) {
			case 1:	inputGrade = "��ü"; break;
			case 2:	inputGrade = "Premium"; break;
			case 3:	inputGrade = "Honor"; break;
			case 4:	inputGrade = "Normal"; break;
			}

			showTable(bus, dateIndex, inputGrade); // ������ �������� ���� ��ȸ

			// ���� ��ȸ�����(�̸� ��ȭ��ȣ ����, �������� �� ����) // ������ ��Ʈ
			// �����Ǿ����ϴ� ���
			system("pause");
			break; // case 1 break

		case 2:	// 2. ����Ȯ��
			checkReservation();
			system("pause");
			break;

		case 3: {// 3. ������� // case�� �ȿ��� ���� �����Ϸ��� ��� ó��
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

		case 4: // 4. ����
			cout << "-- ���α׷��� ����Ǿ����ϴ� --" << endl;
			return; // return �ϹǷ� break ����

		default: // �� �� �Է�
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
			system("pause");
			break;
		}
	}
}

void showTable(Bus* bus[][MAX], int date_index, string grade) { // ������ bus�� grade 2��
	Bus* selectBus[MAX]; // ������ ����� ������(�� ������)���� ������ �迭
	int count = 0; // ���õ� �������� ��� ����

	system("cls");
	cout << "<���� ��ȸ>" << endl;

	if (grade == "��ü") {
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
		cout << "[" << i << "] " << selectBus[i]->getDep() << " " << selectBus[i]->getGrade() << " " << selectBus[i]->getSeatCount() << endl;
	}

	/////////////////////////////////////////////////////////////////////////////////////

	int busSelect;

	while (true) {
		cout << "\n���� ��ȣ �Է�:"; cin >> busSelect;
		if ((0 <= busSelect) && (busSelect < count)) break;
		cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
	}

	system("cls");
	std::cout << "<�¼� ����>\n" << std::endl;
	selectBus[busSelect]->showSeat(); // �¼� ���

	int seatSelect;
	while (true) { // ���Ű� ������ ������ ���� ����
		while (true) {
			cout << "�¼� ��ȣ �Է�:"; cin >> seatSelect;
			if ((1 <= seatSelect) && (seatSelect <= selectBus[busSelect]->getTotalSeats()))	break;
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n" << endl;
		}
		if (selectBus[busSelect]->reserveSeat(seatSelect)) { // �Է¹��� �¼���ȣ�� ���� �õ�
			// ������ ���� �����Ϳ� �¼���ȣ�� ������ �������� ���� �Լ��� �Ѿ
			saveInfo(selectBus[busSelect], seatSelect);
			cout << "-- ���ŵǾ����ϴ� --\n" << endl;
			break;
		}
		else
			cout << "�̹� ���ŵ� �¼��Դϴ�." << endl;
	}

}

void saveInfo(Bus* bus, int seatNum) {
	ofstream out(FILENAME, ios::app); // ���Ͼ���, append���

	std::string name, phone;

	cout << "�̸�, ��ȭ��ȣ�� �Է����ּ���. " << endl;
	cout << "�̸�: "; cin >> name;
	cout << "��ȭ��ȣ: ";  cin >> phone;

	out << name << " " << phone << " "; // �̸�, ��ȭ��ȣ
	out << "Yuseong" << " " << "Seoul" << " "; // �����, ������ (�� ����-���� 1�뼱 ����)	
	out << bus->getDate() << " " << bus->getDep() << " " << bus->getGrade() << " " << seatNum << endl;
	// �� ��¥, �ð�, ���, �¼���ȣ ����ϰ� �ٹٲ�

	out.close();
}

void checkReservation() {
	string check_name, check_phonenumber; // �Է� �޴� �̸�, ��ȭ��ȣ
	string line; // �ؽ�Ʈ���Ͽ��� ���� ����
	bool isExist = false; // �Է� ���� �̸�&��ȭ��ȣ�� ���� ����
	int check_count = 0; // �߸� �Է��� Ƚ��. 3ȸ �̻� �߸� �Է��� ��� ���� Ȯ�� ����.

	while (check_count < 3) {
		// �̸�, ��ȭ��ȣ �Է� ����
		cout << "�̸� �Է�: "; cin >> check_name;
		cout << "��ȭ��ȣ �Է�: "; cin >> check_phonenumber;
		check_count++;

		// �ؽ�Ʈ���Ͽ��� ������ �б� 
		ifstream in(FILENAME);
		if (!in.is_open()) {
			std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
			system("pause"); // ����� �� ����Ž����
			return; // ����ó���� �ٲ��?
		}

		while (in) {
			// �ؽ�Ʈ���� ���پ� �о, ' ' �������� �ڸ� �� �迭�� ����
			getline(in, line);
			//cout << line << endl;
			vector<string> line_vector = split(line, ' ');

			// �ؽ�Ʈ������ �� ������ ���� '\n'�� ��� ó��
			if (line_vector.size() == 0)
				break;

			// �Է� ���� �̸�&��ȭ��ȣ�� �����ϸ�, ���� ���� ���
			if ((check_name == line_vector[0]) && (check_phonenumber == line_vector[1])) {
				isExist = true;
				cout << "-----------------------------------" << endl;
				cout << "���-����: " << line_vector[2] << " -> " << line_vector[3] << endl;
				cout << "��� ��¥: " << line_vector[4] << endl;
				cout << "��� �ð�: " << line_vector[5] << endl;
				cout << "���� ���: " << line_vector[6] << endl;
				cout << "�¼� ��ȣ: " << line_vector[7] << endl;
				cout << "-----------------------------------" << endl;
			}
		}

		// �Է� ���� �̸�&��ȭ��ȣ�� �ؽ�Ʈ���Ͽ� �������� ������, �ٽ� �Է¹��� 
		if (!isExist) {
			if (check_count != 3)
				cout << "\n�̸� Ȥ�� ��ȭ��ȣ�� �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.(" << check_count << "/3)" << endl;
			else {
				cout << "\n3ȸ �߸� �Է��ϼ̽��ϴ�. ���� Ȯ���� �����մϴ�." << endl;
				break;
			}
		}
		else
			break;
	}


}

void RemoveInfo(struct info *Info) {
	int select = 0; // ����� ���� ����� ����
	string strTemp;
	bool isExist = false;
	int num = 0;
	string check_name, check_phonenumber; // �Է� ���� �̸�, �Է� ���� ��ȭ��ȣ
	string line; //�ؽ�Ʈ ���Ͽ��� ���� ����
	ofstream out("temp.txt", ios::trunc); // ������ 
	//trunc: ������ �̹� �ִ� ���, ������ ������ �����ϰ� �ٽ� ����
	ifstream in(FILENAME); //�б���

	if (!in.is_open()) {
		std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
		return;
	}
	cout << "������Ҹ� �����մϴ�. " << endl;
	cout << "�̸�, ��ȭ��ȣ�� �Է����ּ���. " << endl;
	cout << "�̸�: "; cin >> check_name;
	cout << "��ȭ��ȣ: ";  cin >> check_phonenumber;

	cout << "\n<������ ���������� ������ �����ϴ�.>\n" << endl;

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
			++num;
			cout << line << endl;
		}
	}
	if (isExist) {
		while (true) {
			cout << "\n����� ���� �������ּ���:"; cin >> select;
			if (0 <= select && select < num) break;
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
		}
	}
	else {
		cout << "--���������� �����ϴ�--.\n" << endl;
		in.close();
		return;
	}

	int count = select; // �߰�
	in.close();
	ifstream in_(FILENAME); // �б���

	while (in_) { // �ش��ȣ ���� ����
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
			if (count == 0) { // count == 0 �̸� �ش� ���� ������ ���̶�� ��
				// �����ϱ����� ���� ���� ����
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
				out << strTemp << endl; // �װ� �ƴϸ� �Ϲ� ��ó��(�Ʒ� elseó��) �״�� �߰� �ؽ�Ʈ ���Ͽ� ��
			count--;
		}
		else {
			out << strTemp << endl;
		}
	}

	in_.close();
	out.close();

	if (isExist) {
		/*���� ����*/
		ofstream dst(FILENAME, ios::trunc);
		ifstream src("temp.txt");

		dst << src.rdbuf();
		src.close();
		dst.close();
	}

	cout << "\n" << select << "�� ��Ұ� �Ϸ�Ǿ����ϴ�. " << endl;
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
#include<iostream>
#include<string>
#include "Bus.cpp"
#define MAX 3 // �Ϸ�� �� ���� ���

using namespace std;

//���ű��(); //Ȯ�α��(); //��ұ��(); //�ȳ�ȭ�����();


void mainMenu(Bus**); // main �Լ��� ���� �迭�� �������� �迭�̱� ������ **
void printWay(Bus** bus, string grade);
int main() {

	Bus* bus[MAX];
	NormalBus n("9:00");
	HonorsBus n1("12:00");
	PremiumBus n2("15:00");
	bus[0] = &n;
	bus[1] = &n1;
	bus[2] = &n2;

	mainMenu(bus);
	return 0;
}

void mainMenu(Bus** bus) {
	cout << "1. �����ϱ�\n"<<endl;
	cout << "�޴� ��ȣ �Է�: " << endl;
	string inputGrade;
	int select;
	while (true) {
		cin >> select;
		system("cls");
		switch (select) {
		case 1:
			/*
			cout << "����� �Է�: " << endl;
			cin >> start;
			cout << "������ �Է�: " << endl;
			cin >> end;
			cout << "��¥ �Է�: " << endl;
			cin >> day;
			*/
			cout << "��� �Է�: " << endl;
			cin >> inputGrade;
			printWay(bus,inputGrade);
			//���� 4�� ���� �����, ������, ���³�¥, ��ȸ�� ���
			//�뼱��ȸ(*, *, *, *) ȣ�� // ������ ������ �װ� ������ �����͸� �Ű�������
			//��ȸ��޺����� ���� ������� ���(){
			//������ ��ȸ��޿� ���� �ش� ��޹����� ���
			//for������ bus[i]->grade == "�ش���" ������ �ð�, ���, �ܿ��� ���
			//}
			////////////////////////////////////////////////////////////////////////
			// ���� ���� �� �¼���ġ ���	

/*
			cout << "���� ��ȣ �Է�:";

			int busSelect;

			while (true) {
				cin >> busSelect;
				if (0 <= busSelect && busSelect < MAX)
					break;
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���:";
			}
			bus[busSelect]->showSeat();

			
*/




			// �¼���ȣ ���� �� �ż� �ܰ� 


/*
			while (true) {
				cout << "�¼� ��ȣ ����:";
				int seatSelect;
				while (true) {
					cin >> seatSelect;
	//				if ((1 <= seatSelect) && (seatSelect <= bus[busSelect]->getTotalSeats));
					break;
					cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���:";

				}
				if (bus[busSelect]->reserveSeat(seatSelect)) { // �Է¹��� �¼���ȣ�� ���� �õ�
					cout << "���ŵǾ����ϴ�.";
					break;
				}
				else
					cout << "�̹� ���ŵ� �¼��Դϴ�." << endl;
			*/

			// ���� ��ȸ�����(�̸� ��ȭ��ȣ ����, �������� �� ����)
			break;


			// �����Ǿ����ϴ�. ���
		case 2:



			//�̸� ��ȭ��ȣ �����Ŀ� �Է¹���



			//���� Ȯ��ȭ�� ����Լ�( �̸� ��ȭ��ȣ �����ͷ� �Է¹���);





			break;

		case 3:



			//���� ���ȭ�����



			//���� ��ұ��



			break;



		case 4:



			//���� �ȳ� ȭ�� ���



			//���� �����ȳ� ��±��





			break;

		case 5:



			//����
			break;


		}



	}



}
void printWay(Bus** bus,string grade) {
	int check = 0;
	int count = 0;
	Bus* selectBus[MAX];

	if (grade == "��ü") {
		for (int j = 0; j < MAX; j++) {
			selectBus[count] = bus[j];
			count++;
		}
		for (int j = 0; j < count; j++) {
			cout << "[" << j << "]" << " ��� : " << selectBus[j]->getGrade() << "  �ܿ� �¼� : " << selectBus[j]->getSeatCount() << "\n" << endl;
		}
	}
	else {
		for (int k = 0; k < MAX; k++) {
			if ((bus[k]->getGrade() == grade)) {
				selectBus[count] = bus[k];
				count++;
			}
		}
		for (int k = 0; k < count; k++) {
			cout << "[" << k << "]" << " ��� : " << selectBus[k]->getGrade() << "  �ܿ� �¼� : " << selectBus[k]->getSeatCount() << "\n" << endl;
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "���� ��ȣ �Է�:";

	int busSelect;

	while (true) {
		cin >> busSelect;
		if ((0 <= busSelect) && (busSelect < MAX))
			break;
		cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���:";
	}

	selectBus[busSelect]->showSeat();

	while (true) {
		cout << "�¼� ��ȣ ����:";
		int seatSelect;
		
		while (true) {
			cin >> seatSelect;
			if ((1 <= seatSelect) && (seatSelect <= selectBus[busSelect]->getTotalSeats())) {
				break;	
			}
			else {
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���:";
			}

		}
	
	//	cin >> seatSelect;
		if (selectBus[busSelect]->reserveSeat(seatSelect)) { // �Է¹��� �¼���ȣ�� ���� �õ�
			cout << "���ŵǾ����ϴ�.";
			break;
		}
		else {
			cout << "�̹� ���ŵ� �¼��Դϴ�." << endl;
			// ���� ��ȸ�����(�̸� ��ȭ��ȣ ����, �������� �� ����)
			break;
		}
	}
}



//���� �뼱��ȸȭ�����(���������, ������ ����, ���³�¥ ����, ��ȸ��޼��� �����ͷ�){ 



//



//



// }



//���ű��(){} ����



//Ȯ�α��(){} ����



//��ұ��(){} ����



//�ȳ�ȭ�����(){} ����
string line;
ifstream in("test.txt");
if (!in.is_open()) {
	std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
	return 0;
}
getline(in, line);
while (!in.eof()) {
	// �ؽ�Ʈ���� ���پ� �о, ' ' �������� �ڸ� �� �迭�� ����
	//cout << line << endl;
	vector<string> line_vector = split(line, ' ');
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < MAX; j++) {
			//���� �ð� ��� �ڸ� 4 5 6 7
			if ((line_vector[4] == bus[i][j]->getDate()) && (line_vector[5] == bus[i][j]->getDep()) && (line_vector[6] == bus[i][j]->getGrade())) {
				int num;
				num = stoi(line_vector[7]);
				bus[i][j]->reserveSeat(num);
			}
		}
	}
	// �ؽ�Ʈ������ �� ������ ���� '\n'�� ��� ����ó��
	getline(in, line);
	if (line_vector.size() == 0)
		break;
}
string line;
ifstream in("test.txt");
if (!in.is_open()) {
	std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	return 0;
}
getline(in, line);
while (!in.eof()) {
	// 텍스트파일 한줄씩 읽어서, ' ' 기준으로 자른 뒤 배열에 저장
	//cout << line << endl;
	vector<string> line_vector = split(line, ' ');
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < MAX; j++) {
			//날찌 시간 등급 자리 4 5 6 7
			if ((line_vector[4] == bus[i][j]->getDate()) && (line_vector[5] == bus[i][j]->getDep()) && (line_vector[6] == bus[i][j]->getGrade())) {
				int num;
				num = stoi(line_vector[7]);
				bus[i][j]->reserveSeat(num);
			}
		}
	}
	// 텍스트파일의 맨 마지막 줄이 '\n'인 경우 예외처리
	getline(in, line);
	if (line_vector.size() == 0)
		break;
}
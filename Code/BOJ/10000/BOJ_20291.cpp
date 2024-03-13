#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int size, num;
	cin >> size;
	// 입력받을 파일명의 개수

	string temp, buffer;
	map<string, int> list;
	// 파일명을 입력받을 temp와 확장자 부분만 저장할 buffer
	// 확장자들의 개수를 저장할 list(map)

	for (int i = 0; i < size; i++) { // 입력된 개수 만큼의 파일명을 입력받음
		cin.ignore();
		getline(cin, temp);
		// 파일명을 입력받아 temp에 저장

		num = 0; buffer.clear();
		// 확장자만 가져오기 위한 변수 세팅
		while (temp[num] != '.') num++;
		for (int j = num + 1; j < temp.length(); j++) buffer += temp[j];
		// 확장자명이 시작되는 '.' 까지 이동 후 확장자명 부분만 buffer에 저장

		if (list.find(buffer) == list.end()) list[buffer] = 1;
		else list[buffer]++;
		// list 내에 인식한 확장자명이 존재하면 값을 +1하고 없으면 새로 추가 후 값을 1로 설정
	}

	for (auto i=list.begin(); i != list.end(); i++) {
		cout << i->first << ' ' << i->second << "\n";
	} // list 전체의 확장자명, 개수를 출력

	return 0;
}
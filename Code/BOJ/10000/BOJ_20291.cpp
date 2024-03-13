#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int size, num;
	cin >> size;
	// �Է¹��� ���ϸ��� ����

	string temp, buffer;
	map<string, int> list;
	// ���ϸ��� �Է¹��� temp�� Ȯ���� �κи� ������ buffer
	// Ȯ���ڵ��� ������ ������ list(map)

	for (int i = 0; i < size; i++) { // �Էµ� ���� ��ŭ�� ���ϸ��� �Է¹���
		cin.ignore();
		getline(cin, temp);
		// ���ϸ��� �Է¹޾� temp�� ����

		num = 0; buffer.clear();
		// Ȯ���ڸ� �������� ���� ���� ����
		while (temp[num] != '.') num++;
		for (int j = num + 1; j < temp.length(); j++) buffer += temp[j];
		// Ȯ���ڸ��� ���۵Ǵ� '.' ���� �̵� �� Ȯ���ڸ� �κи� buffer�� ����

		if (list.find(buffer) == list.end()) list[buffer] = 1;
		else list[buffer]++;
		// list ���� �ν��� Ȯ���ڸ��� �����ϸ� ���� +1�ϰ� ������ ���� �߰� �� ���� 1�� ����
	}

	for (auto i=list.begin(); i != list.end(); i++) {
		cout << i->first << ' ' << i->second << "\n";
	} // list ��ü�� Ȯ���ڸ�, ������ ���

	return 0;
}
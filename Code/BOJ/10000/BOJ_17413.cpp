#include <iostream>
#include <string>
#include <algorithm> // reverse �Լ� ��� ����
using namespace std;

int main() {
	string input;
	// ���ڿ��� �Է¹��� ����
	getline(cin, input);
	// ���ڿ� �Է�

	for (int i = 0; i < input.length();) {
	// ��ü ���ڸ� Ȯ���ϱ� ���� �ݺ���
		string temp = "";
		// ������ ���ڿ��� �����ϱ� ���� ����

		if (input[i] == '<') {
			while (input[i] != '>') i++;
			i++;
		} // �±׸� ���� '<'�� ���� ���, '>'�� ���� ������ ���ڸ� �ǳʶ�
		else if (input[i] == ' ') i++; // ������ ���� ��� �ǳʶ�
		else { // �±� �ٱ��� �����ϴ� ������ ���

			int start_point = i; // �ܾ ���۵Ǵ� ��ġ ���

			while (i < input.length() && !(input[i] == ' ' || input[i] == '<')) {
			// �ʱ� �Է� ������ ���� ������
			// �ܾ��� ���� ��Ÿ���� ���� Ȥ�� �±׸� ���� '<' ���ڰ� ���� ������ �ݺ�

				temp += input[i]; // ������ ���ڿ� ���� ������ ���� ����
				i++; // ���� ���ڷ� �̵�
			}
			reverse(temp.begin(), temp.end());
			// �ݺ����� �����ٴ� ���� �ܾ� �ν��� ���´ٴ� �ǹ��̹Ƿ�
			// �����س��� ���ڿ��� ��������

			input.replace(start_point, temp.length(), temp);
			// ���� ���ڿ��� �ִ� �ܾ ������ ������ �ܾ�� ��ü
		}
	}

	cout << input; // ��� �۾��� �Ϸ������Ƿ� ���
	return 0;
}
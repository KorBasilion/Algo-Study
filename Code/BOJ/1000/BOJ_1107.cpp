#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checker(int num, vector<int> ignore) {
// ���ڷ� ���� ���ڿ� ���� �� ���� ��ư�� ���� ���� ���� ��ȯ
// ture: ���Ե� ���� ����(��� ����) || false: ���Ե� ���� ����(��� �Ұ���)
	
	bool flag = true; // ���� ���� ��Ÿ���� flag
	string check = to_string(num); // ���� ���θ� Ȯ���ϱ� ���� string���� ��ȯ
	for (int i = 0; i < ignore.size(); i++) {
	// ���� �� ���� ��ư�� ��� Ȯ���ϱ� ���� �ݺ���
		if (check.find(to_string(ignore[i])) != string::npos)
		// ���ڷ� ���� ���� ���� ���� �� ���� ��ư�� �ִ��� �˻�
		{
			flag = false;
			break;
			// ���� �� ���� ��ư�� ������ ���, flag�� false�� ��ȯ �� �˻� ����
		}
	} // �ش� �ݺ��� ������ flag�� false�� �� �ٲ� ���,
	// ���Ե� ���ڰ� ���� ���̹Ƿ� flag = true

	return flag;
	// flag �� ��ȯ
}

int main() {
	// channel: ��� ä��(Ʋ��� �ϴ� ä��) || num: ���� �� ���� ��ư ��
	// up: ��� ä�κ��� ���� ������ ä�� || down: ��� ä�κ��� ���� ������ ä��
	// up, down ��� ��� ä���� �������� +/- 1�� �����
	// check: �⺻ ä��(100)���� ������� Ȯ�� �뵵 || answer: +/- ��ư�� ������ Ƚ��
	// best: ��� ä�ΰ� ���� ����� ä�� || ignore: ���� �� ���� ��ư ���

	int channel, num, up, down, check, answer;
	int best = 100;
	// �ʱⰪ�� 100���� ����

	cin >> channel; // ��� ä�� �Է�
	cin >> num; // ��ư �� �Է�

	vector<int> ignore(num, 0);
	for (int i = 0; i < num; i++) cin >> ignore[i];
	// ���� �� ���� ��ư ��� �Է�

	up = channel, down = channel;
	// up�� down�� channel ������ �ʱ�ȭ

	while (down != 100 && up != 100) {
	// up�� down �� � ���̶� 100�� �ȴٸ� �ݺ� ����
	// �ش� �ݺ����� ������ true���� ��� X
		if (checker(down, ignore)) {
		// down�� checker ����� true�� best�� down�� ���� ���� �� �ݺ� ����
			best = down;
			break;	
		}
		else if (checker(up, ignore)) {
		// up�� checker ����� true�� best�� up�� ���� ���� �� �ݺ� ����
			best = up;
			break;
		}
		else {
		// �� �� �ƴ� ���, �� ���� +/- 1�� ����
			if (down > 0) down--;
			// down�� ���� ������ �Ǵ� ���� ����
			up++;
		}
	}

	if (channel >= best) answer = channel - best;
	else answer = best - channel;
	// channel�� best ������ �Ÿ��� answer�� ����

	if (channel >= 100) check = channel - 100;
	else check = 100 - channel;
	// answer�� �񱳸� ���� �⺻ ä�� ����, channel���� �Ÿ��� check�� ����

	if (check - 3 <= answer) {
	// check�� answer�� ���� ��, check�� �� ũ�� answer�� check��, best�� 100���� ����
	// check - 3�� ������ ������ �⺻ ä��(100)�� ���ڸ� �Է��ϴ� ������ �ʿ� ���� ����
	// e.g) 101 ���ؿ��� 100�� +�� �� ���� ������ ������
	//      102�� '102'�� �Է��ϰ� -�� ������ �ϱ⿡ �� 4���� ������ ��
	//      ��, �Ÿ��� �� �� 1������ ��ư�� ������ Ƚ���� �ٸ�
		answer = check;
		best = 100;
	}

	if (best == 100) {
	// �Է��� ä���� �⺻ ä���̸� ä�� ���̸� ���ϴ� ���� ���� ���
		cout << answer;
		return 0;
	}
	else {
	// �⺻ ä���� �ƴ϶�� answer ���� ä�� ���̸�ŭ�� ������ ���� ���
		int ch_btn = to_string(best).length();
		cout << answer + ch_btn;
		return 0;
	}
}

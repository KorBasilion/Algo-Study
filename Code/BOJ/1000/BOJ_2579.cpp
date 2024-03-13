#include <iostream>
#include <vector>
using namespace std;

int top_down(int num, vector<int> inputs, vector<int>* best) {
// Top Down DP�� �����ϴ� �Լ�
	if ((*best)[num] == 0) {
	// ������ ����� ���� ���� index�� ���, �� ����
		if (num == 0) {
		// index�� 0, 1�� ���, ���� �ϳ��̹Ƿ� ��� ����
			(*best)[0] = inputs[0];
			return (*best)[0];
		}
		else if (num == 1) {
			(*best)[1] = inputs[0] + inputs[1];
			return inputs[0] + inputs[1];
		}
		else if (num == 2) {
		// index�� 2�� ���, 0 -> 2 Ȥ�� 1 -> 2 �� ���� ��츸 �����ϹǷ�
		// �� ��� �� ���� ū ���� ����
			(*best)[2] = max(inputs[0] + inputs[2], inputs[1] + inputs[2]);
			return (*best)[2];
		}
		else {
		// index�� 3 �̻��� ���, n-3 -> n-1 -> n | n-2 -> n �� ���� ��츸 �����ϹǷ�
		// �� ��� �� ���� ū ���� �����ϵ� �̶��� DP�� �����Ͽ� ���� �˾ƿ��� ������ ����
			(*best)[num] = max(top_down(num - 3, inputs, best) + inputs[num - 1],
				top_down(num - 2, inputs, best)) + inputs[num];
			return (*best)[num];
		}
	}
	else return (*best)[num];
	// ������ ����� ���� �ִ� index�� ���, ����� �� ��ȯ
}

int main() {
	// num: �Է��� ����� �� | inputs: �Է��� �� ����� ����
	// best: �ش� ��ġ���� ���� ��� �� ���� ���� ū ���
	int num;
	cin >> num;

	vector<int> inputs(num, 0);
	vector<int> best(num, 0);
	// ���� �ʱ�ȭ
	
	for (int i = 0; i < num; i++) cin >> inputs[i];
	// �� ����� ���� ���Ϳ� ����
	cout << top_down(num-1, inputs, &best);
	// top_down�� ������ ����� ���
	return 0;
}
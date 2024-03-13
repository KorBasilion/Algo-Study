#include <iostream>
#include <vector>
#include <algorithm> // sort ��� ����
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
// �־��� �� ������ �����ִ� �Լ�
// ù ��°, �� ��° �μ� ��� ������������ ����

	if (a.first > b.first) return 0;
	// ù ��° �μ��� 1�� ��
	else if (a.first == b.first) {
		if (a.second > b.second) return 0;
		// ù ��° �μ��� ���ٸ� �� ��° �μ� ��
		else return 1;
	}
	else return 1;
}

int main() {
	int size, counter = 0;
	// �Է¹��� ������ ȸ�� ������ ������ ����
	cin >> size; // ���� �Է�
	vector<pair<int, int>> inputs(size, {0, 0});
	// �Էµ� ���� ��ŭ�� �� ���� �� �μ� ���·� ���� �� �ʱ�ȭ

	for (int i = 0; i < size; i++) {
		cin >> inputs[i].first >> inputs[i].second;
	} // �Էµ� ������ŭ ȸ�� �������� �Է� �� ����
	sort(inputs.begin(), inputs.end(), compare);
	// �Է¹��� ȸ�� �������� ������������ ����
	
	int cur_time; // ȸ�ǰ� ���� �ð��� �����ϴ� ����
	// cur_time�� last.second �� ��ü ����
	pair<int, int> last; // ���� �������� Ȯ���� ȸ�� �ð�
	for (int i = 0; i < size;) {
		if (i == 0) {
			cur_time = inputs[i].second;
			last = inputs[i];
			// �� ó���� �����ϴ� �����̹Ƿ� �̸� �ʱⰪ���� ����
			counter++; i++;
			// ȸ�� ������ 0���� �ƴ� �̻�, ������ 1���� ȸ�Ǵ� ����ǹǷ� counter ����
		}
		else {
			if (cur_time <= inputs[i].first) {
			// �������� Ȯ���� ȸ�� �ð� ������ ȸ�Ǹ� �����ϴ� ����
				cur_time = inputs[i].second;
				last = inputs[i];
				// ������ �����ϱ⸸ �Ѵٸ� �ϴ� last�� ����
				counter++; i++;
				// �߰��� ���� ������ ȸ�ǰ� �����Ѵٴ� �ǹ��̹Ƿ� counter ����
			}
			else if (last.first < inputs[i].first && last.second > inputs[i].second) {
				last = inputs[i];
				cur_time = inputs[i].second;
				i++;
				// ���� last�� ����� ȸ�� �ð� ���� �ȿ� ����� �� �ִ�
				// �Ǵٸ� ȸ�ǰ� ������ ���, �ش� ȸ�� �ð��� last�� ����
			}
			else i++;
			// �������� Ȯ���� ȸ�� �ð� ���ĵ� �ƴϰ�, ȸ�� �ð� ���� ���� �ִ� �͵� �ƴϸ�
			// �ش� ȸ�� �ð��� �ǳʶ�
		}
	}

	cout << counter;
	return 0;
}
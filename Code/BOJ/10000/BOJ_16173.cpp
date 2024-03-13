#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isOver(int size, pair<int, int> target) {
	if (target.first >= size || target.second >= size) {
		return true;
	}
	else return false;
} // �־��� Target�� ��ǥ�� Grid ����� ������� �Ǻ����ִ� �Լ�

int main() {
	int size, buffer;
	cin >> size;
	// Grid�� ������ �Է�

	vector<vector<int>> grid(size, vector<int>(size, 0));
	// Grid�� ������ 2���� Vector ���� -> �ʱⰪ 0

	queue<pair<int, int>> que;
	pair<int, int> cur = { 0,0 };
	pair<int, int> next;
	// BFS �����Ȳ�� ������ Queue�� ���� ��ġ, ���� ��ġ���� �� �� �ִ� ��ġ

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> grid[i][j];
		}
	} // Grid ������ ������ �޾ƿ���

	if (grid[cur.first][cur.second] == -1) {
		cout << "HaruHaru";
		return 0;
	} // ���� ���� ������ ���� �����̸� ���� ����
	// �����غ��ϱ� ����� 2~3���� �����Ǿ� �־ �׷� ���� ����

	que.push(cur);
	// BFS ������ �ݺ��ϱ� ���� �ʱ� ��ġ�� Queue�� ����

	while (!que.empty()) { // While���� BFS ���� ����
		cur = que.front();
		// Queue�� �ִ� ���� �ϳ��� ������ BFS ����

		if (grid[cur.first][cur.second] != 0) {
			// ���� ���� ��ġ�� ���� 0�̶�� �ƹ����� �� �� �����Ƿ� ���� 0 ���� �ĺ�
			next = cur;
			next.first += grid[cur.first][cur.second];
			// ���� ��ġ���� ���������� �� ��쿡 ������ ��ǥ�� next�� ���� 
			if (!isOver(size, next)) {
				if (grid[next.first][next.second] == -1) {
					cout << "HaruHaru";
					return 0;
				}
				// next�� ��ǥ ���� ���� -1�̶�� ����
				que.push(next);
				// next�� ��ǥ�� ���� ���̶�� Queue�� ����
			}

			next = cur;
			next.second += grid[cur.first][cur.second];
			if (!isOver(size, next)) {
				if (grid[next.first][next.second] == -1) {
					cout << "HaruHaru";
					return 0;
				}
				que.push(next);
			}
			// �� ������ ���� ��ġ���� �Ʒ������� �� ��� ������ ��ǥ�� next�� �����Ͽ� �ݺ�
		}

		que.pop();
		// ���� ��ǥ���� �̵� ������ ��θ� ��� Ȯ�������� Queue���� pop ����
	}

	cout << "Hing";
	return 0;
	// �ش� �������� �Դٴ� ���� ��ǥ ���� ���� -1�� ���� ������ �� ������ �ǹ�
}
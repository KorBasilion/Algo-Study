#include <iostream>
#include <vector>
using namespace std;

void DFS_function(int x, int y, char color, int size, vector<vector<char>>grid, vector<vector<int>>* visit) {
	// ���� DFS ���� �Լ� - ��� ����

	int move_x[] = { 0,-1,0,1 };
	int move_y[] = { 1,0,-1,0 };
	// �����ʺ��� �ð� ���� ������ �ֺ� ��带 Ȯ���ϱ� ���� �̵� ��ǥ

	for (int i = 0; i < 4; i++) {
		int cur_x = x + move_x[i];
		int cur_y = y + move_y[i];
		// ���� ��ǥ�� �������� Ȯ���� �ֺ� ����� ��ǥ

		if (cur_x >= 0 && cur_y >= 0 && cur_x < size && cur_y < size && (*visit)[cur_x][cur_y] == 0 && grid[cur_x][cur_y] == color) {
		// Ȯ������ ��尡 �湮�� �� �ִ���, ���� ��ǥ�� ����� ������, �׸��� ���� ���� ���ϴ��� Ȯ��
			(* visit)[cur_x][cur_y] = 1;
			// ������ �����Ѵٸ� �ش� ��ǥ�� �湮 ǥ��
			DFS_function(cur_x, cur_y, grid[cur_x][cur_y], size, grid, visit);
			// �湮 ǥ���� ��ǥ�� �������� DFS ����
		}
	}
}

int DFS_main(int size, vector<vector<char>> grid) { // DFS ���� �Լ�
	vector<vector<int>> visit(size, vector<int>(size, 0));
	// DFS�� �����ϸ鼭 �湮 ���θ� Ȯ���� �׸��� ����
	// 0: Not visited || 1: Visited
	
	int counter = 0;
	// ������ ������ ����� ����

	for (int i = 0; i < size; i++) { // ��� �׸��带 �湮�ϱ� ���� �ݺ���
		for (int j = 0; j < size; j++) {
			if (visit[i][j] == 1) continue;
			// �湮�ߴ� ����� �ǳʶ�
			else {
				visit[i][j] = 1;
				counter++;
				// �湮���� �ʾҴ� ����̹Ƿ� �湮 ǥ��
				// �湮���� �ʾҴٴ� ���� ���ο� �����̶�� �ǹ��̹Ƿ� �� ����

				DFS_function(i, j, grid[i][j], size, grid, &visit);
				// �ش� ��ǥ�� �������� DFS ����
			}
		}
	}
	return counter;
	// ����� ������ ���� ��ȯ
}

int main() {
	int size; // �Է¹��� �׸����� ũ�� ����
	cin >> size; // �׸��� ũ�� �Է�

	vector<vector<char>> normal_grid(size, vector<char>(size, 'N'));
	vector<vector<char>> colorblind_grid(size, vector<char>(size, 'N'));
	// �Է¹��� ũ�� ��ŭ�� �׸��� ���� ���� �� �� ���� 'N'���� �ʱ�ȭ
	// normal_grid�� �Ϲ��� �ð������� �׸���, colorblind_grid�� ������ �ð������� �׸���

	for (int i = 0; i < size; i++) { // N x N ���� ������ �Է¹ޱ� ���� �ݺ���
		for (int j = 0; j < size; j++) {
			char temp; // �Է¹��� ���� �ӽ� ���� ����
			cin >> temp; // ���� �Է�
			
			normal_grid[i][j] = temp; // �Է¹��� ������ �׸��忡 ����
			if (temp == 'G') colorblind_grid[i][j] = 'R';
			else colorblind_grid[i][j] = temp;
			// �������� R�� G�� ������ �� ������ G�� R�� ����
		}
	}

	cout << DFS_main(size, normal_grid) << ' ' << DFS_main(size, colorblind_grid);
	return 0;
}
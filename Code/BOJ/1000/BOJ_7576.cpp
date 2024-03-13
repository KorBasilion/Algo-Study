#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int x_range, y_range;
	int move_x[] = {0, 1, 0, -1};
	int move_y[] = {-1, 0, 1 , 0};

	vector<int> input;
	queue<vector<int>> in_queue;
	queue<vector<int>> next_queue;

	cin >> x_range >> y_range;
	vector<vector<int>> matrix(y_range, vector<int>(x_range, 0));

	for (int i = 0; i < y_range; i++) {
		for (int j = 0; j < x_range; j++) {
			int input_num;
			cin >> input_num;
			if (i == 0) input.push_back(input_num);
			else input[j] = input_num;
		}
		matrix[i] = input;
	}

	int one_cnt = 0;
	for (int i = 0; i < y_range; i++) {
		for (int j = 0; j < x_range; j++) {
			int block_cnt = 0;
			if (matrix[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					int check_x, check_y;
					check_y = i - move_y[k];
					check_x = j - move_x[k];
					if (check_y < 0 || check_x < 0 || check_y >= y_range || check_x >= x_range || matrix[check_y][check_x] == -1) block_cnt++;
				}
			}
			else if (matrix[i][j] == 1) {
				in_queue.push({ i, j });
				one_cnt++;
			}

			if (block_cnt == 4) {
				cout << "-1";
				return 0;
			}
		}
	}
	if (one_cnt == 0) {
		cout << "-1";
		return 0;
	}

	int day_cnt = 0;
	while (1) {
		while (!in_queue.empty()) {
			vector<int> cur_loc = in_queue.front();
			in_queue.pop();

			for (int i = 0; i < 4; i++) {
				int check_x, check_y;
				check_y = cur_loc[0] - move_y[i];
				check_x = cur_loc[1] - move_x[i];
				if (check_y >= 0 && check_x >= 0 && check_y < y_range && check_x < x_range && matrix[check_y][check_x] == 0) {
					matrix[check_y][check_x] = 1;
					next_queue.push({ check_y, check_x });
				}
			}
		}
		if (!next_queue.empty()) {
			swap(next_queue, in_queue);
			day_cnt++;
		}
		else break;
	}

	for (int i = 0; i < y_range; i++) {
		for (int j = 0; j < x_range; j++) {
			if (matrix[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << day_cnt;
	return 0;
}
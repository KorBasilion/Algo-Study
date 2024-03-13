#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isOver(int size, pair<int, int> target) {
	if (target.first >= size || target.second >= size) {
		return true;
	}
	else return false;
} // 주어진 Target의 좌표가 Grid 사이즈를 벗어나는지 판별해주는 함수

int main() {
	int size, buffer;
	cin >> size;
	// Grid의 사이즈 입력

	vector<vector<int>> grid(size, vector<int>(size, 0));
	// Grid를 저장할 2차원 Vector 선언 -> 초기값 0

	queue<pair<int, int>> que;
	pair<int, int> cur = { 0,0 };
	pair<int, int> next;
	// BFS 진행상황을 저장할 Queue와 현재 위치, 현재 위치에서 갈 수 있는 위치

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> grid[i][j];
		}
	} // Grid 내부의 데이터 받아오기

	if (grid[cur.first][cur.second] == -1) {
		cout << "HaruHaru";
		return 0;
	} // 만약 시작 시점이 도착 지점이면 조기 종료
	// 생각해보니까 사이즈가 2~3으로 지정되어 있어서 그럴 일이 없음

	que.push(cur);
	// BFS 과정을 반복하기 위해 초기 위치를 Queue에 삽입

	while (!que.empty()) { // While문은 BFS 수행 과정
		cur = que.front();
		// Queue에 있는 값을 하나씩 가져와 BFS 수행

		if (grid[cur.first][cur.second] != 0) {
			// 만약 현재 위치의 값이 0이라면 아무곳도 갈 수 없으므로 값의 0 여부 식별
			next = cur;
			next.first += grid[cur.first][cur.second];
			// 현재 위치에서 오른쪽으로 갈 경우에 나오는 좌표를 next로 지정 
			if (!isOver(size, next)) {
				if (grid[next.first][next.second] == -1) {
					cout << "HaruHaru";
					return 0;
				}
				// next의 좌표 내부 값이 -1이라면 종료
				que.push(next);
				// next의 좌표가 범위 안이라면 Queue에 삽입
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
			// 위 과정을 현재 위치에서 아래쪽으로 갈 경우 나오는 좌표를 next로 지정하여 반복
		}

		que.pop();
		// 현재 좌표에서 이동 가능한 경로를 모두 확인했으니 Queue에서 pop 진행
	}

	cout << "Hing";
	return 0;
	// 해당 과정까지 왔다는 것은 좌표 내부 값이 -1인 곳에 도달할 수 없음을 의미
}
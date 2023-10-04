#include <iostream>
#include <vector>
using namespace std;

void DFS_function(int x, int y, char color, int size, vector<vector<char>>greed, vector<vector<int>>* visit) {
	// 실제 DFS 실행 함수 - 재귀 목적

	int move_x[] = { 0,-1,0,1 };
	int move_y[] = { 1,0,-1,0 };
	// 오른쪽부터 시계 방향 순서로 주변 노드를 확인하기 위한 이동 좌표

	for (int i = 0; i < 4; i++) {
		int cur_x = x + move_x[i];
		int cur_y = y + move_y[i];
		// 현재 좌표를 기준으로 확인할 주변 노드의 좌표

		if (cur_x >= 0 && cur_y >= 0 && cur_x < size && cur_y < size && (*visit)[cur_x][cur_y] == 0 && greed[cur_x][cur_y] == color) {
		// 확인중인 노드가 방문한 적 있는지, 현재 좌표의 색상과 같은지, 그리드 범위 내에 속하는지 확인
			(* visit)[cur_x][cur_y] = 1;
			DFS_function(cur_x, cur_y, greed[cur_x][cur_y], size, greed, visit);
		}
	}
}

int DFS_main(int size, vector<vector<char>> greed) { // DFS 수행 함수
	vector<vector<int>> visit(size, vector<int>(size, 0));
	// DFS를 수행하면서 방문 여부를 확인할 그리드 선언
	// 0: Not visited || 1: Visited
	
	int counter = 0;
	// 구역의 개수를 기록할 변수

	for (int i = 0; i < size; i++) { // 모든 그리드를 방문하기 위한 반복문
		for (int j = 0; j < size; j++) {
			if (visit[i][j] == 1) continue;
			// 방문했던 노드라면 건너뜀
			else {
				visit[i][j] = 1;
				counter++;
				// 방문하지 않았던 노드이므로 방문 표시
				// 방문하지 않았다는 것은 새로운 구역이라는 의미이므로 값 증가

				DFS_function(i, j, greed[i][j], size, greed, &visit);
				// 해당 좌표를 기준으로 DFS 수행
			}
		}
	}
	return counter;
	// 기록한 구역의 개수 반환
}

int main() {
	int size; // 입력받을 그리드의 크기 변수
	cin >> size; // 그리드 크기 입력

	vector<vector<char>> normal_greed(size, vector<char>(size, 'N'));
	vector<vector<char>> colorblind_greed(size, vector<char>(size, 'N'));
	// 입력받은 크기 만큼의 그리드 벡터 구현 및 각 값을 'N'으로 초기화
	// normal_greed는 일반인 시각에서의 그리드, colorblind_greed는 색약인 시각에서의 그리드

	for (int i = 0; i < size; i++) { // N x N 개의 색상을 입력받기 위한 반복문
		for (int j = 0; j < size; j++) {
			char temp; // 입력받을 색상 임시 저장 변수
			cin >> temp; // 색상 입력
			
			normal_greed[i][j] = temp; // 입력받은 색상을 그리드에 삽입
			if (temp == 'G') colorblind_greed[i][j] = 'R';
			else colorblind_greed[i][j] = temp;
			// 색약인은 R와 G를 구분할 수 없으니 G를 R로 삽입
		}
	}

	cout << DFS_main(size, normal_greed) << ' ' << DFS_main(size, colorblind_greed);
	return 0;
}

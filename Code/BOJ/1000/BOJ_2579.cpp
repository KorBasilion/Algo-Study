#include <iostream>
#include <vector>
using namespace std;

int top_down(int num, vector<int> inputs, vector<int>* best) {
// Top Down DP를 수행하는 함수
	if ((*best)[num] == 0) {
	// 이전에 수행된 적이 없는 index일 경우, 값 저장
		if (num == 0) {
		// index가 0, 1일 경우, 답이 하나이므로 즉시 연산
			(*best)[0] = inputs[0];
			return (*best)[0];
		}
		else if (num == 1) {
			(*best)[1] = inputs[0] + inputs[1];
			return inputs[0] + inputs[1];
		}
		else if (num == 2) {
		// index가 2일 경우, 0 -> 2 혹은 1 -> 2 두 가지 경우만 존재하므로
		// 두 경우 중 값이 큰 것을 저장
			(*best)[2] = max(inputs[0] + inputs[2], inputs[1] + inputs[2]);
			return (*best)[2];
		}
		else {
		// index가 3 이상일 경우, n-3 -> n-1 -> n | n-2 -> n 두 가지 경우만 존재하므로
		// 두 경우 중 값이 큰 것을 저장하되 이때는 DP를 수행하여 값을 알아오는 과정이 존재
			(*best)[num] = max(top_down(num - 3, inputs, best) + inputs[num - 1],
				top_down(num - 2, inputs, best)) + inputs[num];
			return (*best)[num];
		}
	}
	else return (*best)[num];
	// 이전에 수행된 적이 있는 index일 경우, 저장된 값 반환
}

int main() {
	// num: 입력할 계단의 수 | inputs: 입력할 각 계단의 값들
	// best: 해당 위치까지 가는 방법 중 가장 값이 큰 방법
	int num;
	cin >> num;

	vector<int> inputs(num, 0);
	vector<int> best(num, 0);
	// 벡터 초기화
	
	for (int i = 0; i < num; i++) cin >> inputs[i];
	// 각 계단의 값을 벡터에 저장
	cout << top_down(num-1, inputs, &best);
	// top_down을 수행한 결과를 출력
	return 0;
}
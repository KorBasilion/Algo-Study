#include <iostream>
#include <vector>
#include <algorithm> // sort 사용 목적
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
// 주어진 두 변수를 비교해주는 함수
// 첫 번째, 두 번째 인수 모두 오름차순으로 정렬

	if (a.first > b.first) return 0;
	// 첫 번째 인수로 1차 비교
	else if (a.first == b.first) {
		if (a.second > b.second) return 0;
		// 첫 번째 인수가 같다면 두 번째 인수 비교
		else return 1;
	}
	else return 1;
}

int main() {
	int size, counter = 0;
	// 입력받을 개수와 회의 개수를 저장할 변수
	cin >> size; // 개수 입력
	vector<pair<int, int>> inputs(size, {0, 0});
	// 입력된 개수 만큼의 페어를 벡터 내 인수 형태로 선언 및 초기화

	for (int i = 0; i < size; i++) {
		cin >> inputs[i].first >> inputs[i].second;
	} // 입력된 개수만큼 회의 스케줄을 입력 및 저장
	sort(inputs.begin(), inputs.end(), compare);
	// 입력받은 회의 스케줄을 오름차순으로 정렬
	
	int cur_time; // 회의가 끝난 시간을 저장하는 변수
	// cur_time은 last.second 로 대체 가능
	pair<int, int> last; // 가장 마지막에 확정된 회의 시간
	for (int i = 0; i < size;) {
		if (i == 0) {
			cur_time = inputs[i].second;
			last = inputs[i];
			// 맨 처음에 수행하는 과정이므로 이를 초기값으로 설정
			counter++; i++;
			// 회의 개수가 0개가 아닌 이상, 무조건 1개의 회의는 진행되므로 counter 증가
		}
		else {
			if (cur_time <= inputs[i].first) {
			// 마지막에 확정된 회의 시간 이후의 회의를 결정하는 과정
				cur_time = inputs[i].second;
				last = inputs[i];
				// 조건을 충족하기만 한다면 일단 last로 저장
				counter++; i++;
				// 추가로 진행 가능한 회의가 존재한다는 의미이므로 counter 증가
			}
			else if (last.first < inputs[i].first && last.second > inputs[i].second) {
				last = inputs[i];
				cur_time = inputs[i].second;
				i++;
				// 만약 last에 저장된 회의 시간 범위 안에 진행될 수 있는
				// 또다른 회의가 존재할 경우, 해당 회의 시간을 last로 갱신
			}
			else i++;
			// 마지막에 확정된 회의 시간 이후도 아니고, 회의 시간 범위 내에 있는 것도 아니면
			// 해당 회의 시간은 건너뜀
		}
	}

	cout << counter;
	return 0;
}
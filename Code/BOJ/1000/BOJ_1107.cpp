#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checker(int num, vector<int> ignore) {
// 인자로 들어온 숫자에 누를 수 없는 버튼의 숫자 포함 여부 반환
// ture: 포함된 숫자 없음(사용 가능) || false: 포함된 숫자 존재(사용 불가능)
	
	bool flag = true; // 포함 여부 나타내는 flag
	string check = to_string(num); // 포함 여부를 확인하기 위해 string으로 변환
	for (int i = 0; i < ignore.size(); i++) {
	// 누를 수 없는 버튼을 모두 확인하기 위한 반복문
		if (check.find(to_string(ignore[i])) != string::npos)
		// 인자로 들어온 숫자 내에 누를 수 없는 버튼이 있는지 검사
		{
			flag = false;
			break;
			// 누를 수 없는 버튼이 존재할 경우, flag를 false로 변환 및 검사 종료
		}
	} // 해당 반복문 내에서 flag가 false로 안 바뀐 경우,
	// 포함된 숫자가 없는 것이므로 flag = true

	return flag;
	// flag 값 반환
}

int main() {
	// channel: 대상 채널(틀어야 하는 채널) || num: 누를 수 없는 버튼 수
	// up: 대상 채널보다 높은 숫자의 채널 || down: 대상 채널보다 낮은 숫자의 채널
	// up, down 모두 대상 채널을 기준으로 +/- 1씩 진행됨
	// check: 기본 채널(100)보다 가까운지 확인 용도 || answer: +/- 버튼을 누르는 횟수
	// best: 대상 채널과 가장 가까운 채널 || ignore: 누를 수 없는 버튼 목록

	int channel, num, up, down, check, answer;
	int best = 100;
	// 초기값을 100으로 설정

	cin >> channel; // 대상 채널 입력
	cin >> num; // 버튼 수 입력

	vector<int> ignore(num, 0);
	for (int i = 0; i < num; i++) cin >> ignore[i];
	// 누를 수 없는 버튼 목록 입력

	up = channel, down = channel;
	// up과 down을 channel 값으로 초기화

	while (down != 100 && up != 100) {
	// up과 down 중 어떤 값이라도 100이 된다면 반복 종료
	// 해당 반복문의 조건은 true여도 상관 X
		if (checker(down, ignore)) {
		// down의 checker 결과가 true면 best에 down의 값을 저장 및 반복 종료
			best = down;
			break;	
		}
		else if (checker(up, ignore)) {
		// up의 checker 결과가 true면 best에 up의 값을 저장 및 반복 종료
			best = up;
			break;
		}
		else {
		// 둘 다 아닐 경우, 각 값을 +/- 1씩 해줌
			if (down > 0) down--;
			// down의 값이 음수가 되는 것을 방지
			up++;
		}
	}

	if (channel >= best) answer = channel - best;
	else answer = best - channel;
	// channel과 best 사이의 거리를 answer에 저장

	if (channel >= 100) check = channel - 100;
	else check = 100 - channel;
	// answer과 비교를 위해 기본 채널 기준, channel과의 거리를 check에 저장

	if (check - 3 <= answer) {
	// check와 answer의 값을 비교, check가 더 크면 answer를 check로, best를 100으로 갱신
	// check - 3을 적용한 이유는 기본 채널(100)은 숫자를 입력하는 과정이 필요 없기 때문
	// e.g) 101 기준에서 100은 +를 한 번만 누르면 되지만
	//      102는 '102'를 입력하고 -를 눌러야 하기에 총 4번을 눌러야 함
	//      즉, 거리는 둘 다 1이지만 버튼을 누르는 횟수가 다름
		answer = check;
		best = 100;
	}

	if (best == 100) {
	// 입력할 채널이 기본 채널이면 채널 길이를 더하는 과정 없이 출력
		cout << answer;
		return 0;
	}
	else {
	// 기본 채널이 아니라면 answer 값에 채널 길이만큼을 더해준 값을 출력
		int ch_btn = to_string(best).length();
		cout << answer + ch_btn;
		return 0;
	}
}

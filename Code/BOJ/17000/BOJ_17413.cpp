#include <iostream>
#include <string>
#include <algorithm> // reverse 함수 사용 목적
using namespace std;

int main() {
	string input;
	// 문자열을 입력받을 변수
	getline(cin, input);
	// 문자열 입력

	for (int i = 0; i < input.length();) {
	// 전체 문자를 확인하기 위한 반복문
		string temp = "";
		// 뒤집을 문자열을 저장하기 위한 변수

		if (input[i] == '<') {
			while (input[i] != '>') i++;
			i++;
		} // 태그를 여는 '<'가 나올 경우, '>'가 나올 때까지 문자를 건너뜀
		else if (input[i] == ' ') i++; // 공백이 나올 경우 건너뜀
		else { // 태그 바깥에 존재하는 문자일 경우

			int start_point = i; // 단어가 시작되는 위치 기록

			while (i < input.length() && !(input[i] == ' ' || input[i] == '<')) {
			// 초기 입력 범위를 넘지 않으며
			// 단어의 끝을 나타내는 공백 혹은 태그를 여는 '<' 문자가 나올 때까지 반복

				temp += input[i]; // 뒤집을 문자열 저장 변수에 문자 저장
				i++; // 다음 문자로 이동
			}
			reverse(temp.begin(), temp.end());
			// 반복문이 끝났다는 것은 단어 인식을 끝냈다는 의미이므로
			// 저장해놓은 문자열을 뒤집어줌

			input.replace(start_point, temp.length(), temp);
			// 기존 문자열에 있던 단어를 뒤집힌 형태의 단어로 교체
		}
	}

	cout << input; // 모든 작업을 완료했으므로 출력
	return 0;
}

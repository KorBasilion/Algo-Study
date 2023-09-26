#include <iostream>
#include <string>
using namespace std;

int main() {
	// input_alpha는 큰 의미 없음
	char input_alpha[50], output_alpha[25];
	int alpha_sum[26] = {0,};
	int counter = 0, odd_sum = 0;
	char center = NULL;

	string input;
	cin >> input;
		
	int cnt = 0;
	while (input[cnt] != NULL) {
		input_alpha[counter] = input[cnt];
		alpha_sum[int(input[cnt]) - 'A']++;
		counter++; cnt++;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha_sum[i] % 2 != 0) {
			odd_sum++;
			center = i + 'A';
		}
	}

	if ( (counter % 2 == 0 && odd_sum == 0) || (counter % 2 != 0 && odd_sum == 1) ) {
		int count = 0;
		for (int i = 0; i<int(counter / 2); i++) {
			while(1) {
				int cnt_num = alpha_sum[count];
				if (cnt_num == 0 || cnt_num == 1) count++;
				else if (cnt_num != 0 && cnt_num / 2 != 0) {
					output_alpha[i] = count + 'A';
					alpha_sum[count] -= 2;
					break;
				}
			}
		}
	}
	else {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (int i = 0; i<int(counter / 2); i++) cout << output_alpha[i];
	if (center != NULL) cout << center;
	for (int i = int(counter / 2) - 1; i >= 0; i--) cout << output_alpha[i];
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;
	int answer = 0;
	cin >> num;

	vector<int> inputs(num, 0);
	vector<int> best(num, 0);

	for (int i = 0; i < num; i++) cin >> inputs[i];


	for (int i = 0; i < num; i++) {
		if (i == 0) {
			best[0] = inputs[0];
			answer = best[0];
		}
		else if (i == 1) {
			best[1] = inputs[0] + inputs[1];
		}
		else if (i == 2) {
			best[2] = max(inputs[0] + inputs[2], inputs[1] + inputs[2]);
		}
		else if (i==3) {
			best[i] = max(best[i - 3], best[i - 3] + inputs[i - 1], best[i - 2]) + inputs[i];
		}
		else {
			int buffer = max(best[i - 4] + inputs[i - 1], best[i - 3]);
			best[i] = max(buffer, best[i - 3] + inputs[i - 1], best[i - 2]) + inputs[i];
		}
		if (answer < best[i]) answer = best[i];
	}

	std::cout << answer;
	return 0;
}
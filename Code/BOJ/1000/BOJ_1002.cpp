#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int counter = 0;
	int turret1[3] = {0, 0, 0};
	int turret2[3] = {0, 0, 0};

	cin >> counter;
	for (int i = counter; i > 0; i--) {
		cin >> turret1[0] >> turret1[1] >> turret1[2] >> turret2[0] >> turret2[1] >> turret2[2];
		float dis, range_sum, shorter, longer;
		dis = sqrt( pow(turret1[0] - turret2[0], 2) + pow(turret1[1] - turret2[1], 2));
		range_sum = turret1[2] + turret2[2];
		if (turret1[2] < turret2[2]) {
			shorter = turret1[2];
			longer = turret2[2];
		}
		else {
			shorter = turret2[2];
			longer = turret1[2];
		}

		if (dis == 0 && shorter == longer) cout << -1 << endl;
		else if ( (dis > range_sum) || (dis + shorter < longer)) cout << 0 << endl;
		else if ( (dis == range_sum) || (dis + shorter == longer) ) cout << 1 << endl;
		else if ( (dis < range_sum) || (dis + shorter > longer)) cout << 2 << endl;
	}
}
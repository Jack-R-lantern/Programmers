#include <string>
using namespace std;

int solution(string name) {
	int answer = 0;
	int length = name.length();
	int move_min = length - 1;

	for (int i=0;i<length;i++) {
		answer += min(name[i] - 'A', 'Z' - name[i] + 1);

		int cursor = i + 1;
		while (cursor < length && name[cursor] == 'A')
			cursor++;
		move_min = min(move_min, min(2 * i + (length - cursor), 2 * (length - cursor) + i));
	}
	answer += move_min;
	return answer;
}
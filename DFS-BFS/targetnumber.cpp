#include <string>
#include <vector>
using namespace std;

int dfs(vector<int>& number, int target, int depth, int sum) {
	int answer = 0;
	if (depth == number.size()) {
		if (target == sum)
			return 1;
		return 0;
	}

	sum += number[depth];
	answer += dfs(number, target, depth + 1, sum);
	sum -= number[depth] * 2;
	answer += dfs(number, target, depth + 1, sum);
	return answer;
}

int solution(vector<int> number, int target) {
	int answer = 0;
	answer = dfs(number, target, 0, 0);
	return answer;
}
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int>	q;
	int cnt = 0;
	for (int i=0;i<progresses.size();i++) {
		q.push(progresses[i]);
	}
	vector<int>::iterator it;
	it = speeds.begin();

	while (!q.empty()) {
		int total = 0;
		while(!q.empty() && (q.front() + *it * cnt) >= 100) {
			q.pop();
			++total;
			++it;
		}
		if (total)
			answer.push_back(total);
		cnt++;
	}
	return answer;
}
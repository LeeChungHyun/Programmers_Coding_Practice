#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*play의 합을 알기 위해서 map에 정보를 넣고 이를 다시 vector에 넣으면서 정렬한다.
-->map을 index정보를 넣는다 -->index에 담겨진 장르별 앨범을 모아서 구하면 된다.*/
map<string, int> m;
map<string, int> midx;
vector<pair<int, int>> mv[100];

bool cmp1(const pair<string, int>& u, const pair<string, int>& v) {
	return u.second > v.second;
}

bool cmp2(const pair<int, int>& u, const pair<int, int>& v) {
	if (u.second == v.second) {
		return u.first < v.first;
	}
	return u.second > v.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	int idx = 0;
	for (int i = 0; i < genres.size(); i++) {
		if (!m.count(genres[i])) {
			m[genres[i]] = plays[i];
			midx[genres[i]] = idx;
			idx += 1;
		}
		else {
			m[genres[i]] += plays[i];
		}

		mv[midx[genres[i]]].push_back(make_pair(i, plays[i]));
	}

	for (int i = 0; i < idx; i++) {
		sort(mv[i].begin(), mv[i].end(), cmp2);
	}

	vector<pair<string, int>> tmp;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
		tmp.push_back(make_pair(it->first, it->second));
	}

	sort(tmp.begin(), tmp.end(), cmp1);
	for (int i = 0; i < tmp.size(); i++) {
		string g = tmp[i].first;
		int gidx = midx[g];
		int cnt = 0;

		for (int j = 0; j < mv[gidx].size(); j++) {
			if (cnt == 2) break;
			answer.push_back(mv[gidx][j].first);
			cnt += 1;
		}
	}
	return answer;
}

void print(vector<string> genres, vector<int> plays, vector<int> answer){
    vector<int> t = solution(genres, plays);
    if(t == answer) cout<< "Correct" << endl;
    else cout << "Wrong" << endl;
}

int main(){
    print({"classic","pop","classic","classic", "pop"}, {500,600,150,800,2500}, {4,1,3,0});
    return 0;
}
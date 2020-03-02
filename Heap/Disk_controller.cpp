#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
/*시간순으로 jobs정렬한다-->작업시간 제일 작은거 먼저 우선순위에 둔다.
-->우선순위queue와 jobs가 비어있을 때까지 반복한다
-->jobs의 작업이 들어온 시간보다 넘거나 같으면 우선순위queue에 대기하도록 한다.
queue가 비어있지 않다면 제일 작은 작업부터 처리한다.
대기시간은 현재시간-작업이 들어온 시간이다.
-->이 작업 반복할때, queue가 비어있는데 jobs 남아있으면 
제일 빨리 들어오는 작업시간으로 변경한다.
*/

struct cmp{
bool operator()(vector<int>a, vector<int>b){
    return a.at(1) > b.at(1);
}
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;//결과 저장
    int index = 0;//index관리
    int time = 0;//시간
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp>pq;
    //우선순위queue
    while(index < jobs.size() || !pq.empty()){//들어올 대기열이 남아있고, 들어올 대기열이 현재시간보다 작으면
    if(jobs.size() > index && time >= jobs[index][0]){
        pq.push(jobs[index++]);
        continue;
    }
    //queue가 비어있지 않으면
    if(!pq.empty()){
        time += pq.top()[1];
        answer += time - pq.top()[0];
        pq.pop();
    }
    else time = jobs[index][0];
    }
    return answer/jobs.size();
}

void print(vector<vector<int>> jobs, int answer){
    int t = solution(jobs);
    if(t == answer) cout<<"Correct"<<endl;
    else cout<<"Wrong"<<endl;
}

int main(){
    print({{0, 3}, {1, 9}, {2, 6}}, 9);
    print({{0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3}}, 13);
    print({{1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3}}, 13);
    print({{0, 3}, {4, 4}, {5, 3}, {4, 1}}, 3);
    print({{0, 3}, {1, 9}, {500, 6}}, 6);
    return 0;
}
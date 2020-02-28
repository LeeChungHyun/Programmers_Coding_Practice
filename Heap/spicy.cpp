#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>>q(scoville.begin(), scoville.end());
    //우선순위queue greater<int>를 사용하므로서 오름차순으로 정렬한다.
    //begin(), end()는 각각 시작/끝 iterator를 반환한다.
    //우선순위queue는 항상 top에 min/max값을 위치시킨다. 그래서 힙이랑 연관있다.
    while(q.size() > 1 && q.top() < K){
        int first = q.top();
        q.pop();//가장 맵지않는 음식을 pop한다
        int second = q.top();//두번째로 맵지 않는 음식을 pop한다.
        q.pop();
        q.push(first + (second * 2));//선별한 두 음식을 섞는다.
        answer++;//섞는 횟수룰 증가한다.
        }
    if(q.top()<K){
        return -1;
    }//모든 음식의 스콜빌 지수가 K보다 작을때 -1반환한다.
    return answer;
}

void print(vector<int>scoville, int K, int answer){
    int t = solution(scoville, K);
    if(t == answer){
        cout<<"Correct"<< endl;
    }
    else cout<<"Wrong" << endl;
    return;
}

int main(){
    print({ 1,2,3,9,10,12 }, 4, 2);
    return 0;
}
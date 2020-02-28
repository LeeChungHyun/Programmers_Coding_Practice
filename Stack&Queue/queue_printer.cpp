#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*priority_queue<T, Container, Compare> : 원하는 자료형 및 클래스 T를 통해 생성. 여기서 Container는 vector와 같은 컨테이너이며 Compare는 비교함수 클래스이다.*/
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>>q;//일반queue에 다 집어넣는다.
    priority_queue<int>q1;//그 후 우선순위 큐 사용해 중요도를 고려해 문서를 인쇄한다. 
    for(int i=0; i < priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
        q1.push(priorities[i]);
    }
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(j == q1.top()){//현재 문서의 중요도가 가장 높을때 인쇄한다.
            q1.pop();
            answer += 1;//우선순위 queue도 pop하고 answer 1증가한다.
        
        if(i == location){//현재 문서가 내가 요청한 문서일때 인쇄 할 필요가 없으므로 break.
            break;
        }
        }
        else{
            q.push(make_pair(i,j));//그 외이면 현재보다 중요문서가 있으므로 다시 queue에 넣는다.
        }
    }
    return answer;
}

void print(vector<int> priorities, int location){
    int t = solution(priorities, location);
    cout<< t << endl;   
}

int main(){
    print({2,1,3,2},2);
    print({1,1,9,1,1,1},0);
    return 0;
}
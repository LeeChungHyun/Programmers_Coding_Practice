#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;//최소 공급 횟수
    priority_queue<int>q;//우선순위 queue
        for(int currentDay = 0, j=0; currentDay < k; currentDay++){
            //현재날이 k날보다 적을때까지 반복한다.
            if(dates.size() > j && dates.at(j) <= currentDay){
                //공급 가능한 날이 지나갔을때
                q.push(supplies.at(j));//우선순위 queue에 넣는다.
                j++;
            }
            if(!stock){//현재 밀가루 없을때
                stock += q.top();//공급 최대량을 받는다.
                q.pop();
                answer++;//공급횟수 증가한다.
            }
            stock--;//하루에 한개씩 밀가루 사용한다.
        } 
    return answer;
}

void print(int stock, vector<int>dates, vector<int>supplies, int k, int answer){
int t = solution(stock, dates, supplies, k);
if(t == answer) cout<<"Correct"<<endl;
else cout<< "wrong"<<endl;
}

int main(){
    print(4, {4, 10, 15}, {20, 5, 10}, 30, 2);
    return 0;
}
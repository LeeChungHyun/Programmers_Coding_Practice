#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int begin = 0;
    int end = 1;
    int count = 0;

    sort(people.begin(), people.end());//몸무게 작은 사람먼저 sorting한다.

    while(true){
        int first = people[people.size() - end++];//제일 무거운 사람을 먼저 first로 태운다.
        count++;//탔으니까 보트 count 증가한다.
        if(limit - first >= people[begin]){
            begin++;
            count++;//보트의 제한 무게가 first와 몸무게가 제일 덜 나가는 people[begin]을 합한 거보다 크면 count증가한다.
        }
   answer++;
    if(count >= people.size()) break;//다 빠져나갔으면 보트는 필요가 없으니 break하여 종료한다.
    }
    return answer;
}

void solution(vector<int>people, int limit, int answer){
    int t = solution(people, limit);
    if(t == answer){
        cout<<"Correct"<<endl;
    }
    else cout<<"Wrong"<<endl;
}

int main(){

    solution({70, 50, 80, 50}, 100, 3);
    solution({70, 80, 50}, 100, 3);

    return 0;
}
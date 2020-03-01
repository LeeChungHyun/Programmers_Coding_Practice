#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;
vector<int> solution(vector<string> operations) {
    deque<int> deq;
    for(auto o : operations){//범위기반 for문 사용한다.
        string a = o.substr(0,1);//문자열 추출한다("I"부분).
        int num = atoi(o.substr(2).c_str());//문자열을 정수 타입으로 변환하는 함수이다.
        if(a=="I") deq.push_back(num);
        else if(!deq.empty()){
            sort(deq.begin(), deq.end());//전체 다 정렬한다. sort는 기본적으로 오름차순으로 정렬한다.
            if(num == 1) deq.pop_back();
            else deq.pop_front();
        }
    }
    if(deq.empty()) return {0,0};
    else{
        sort(deq.begin(), deq.end());
        return {deq.back(), deq.front()};
    }
}

void print(vector<string> operations, vector<int> answer) {
    vector<int> t = solution(operations);
    if (t == answer)
        cout << "Correct" << endl;
    else
        cout << "Wrong" << endl;
}
 
int main()
{
    print({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" }, {0,0});
    print({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" }, {333, -45});
    return 0;
}

/*범위 기반 for문
문법은 다음과 같다.
for (element_declaration : array)
statement;
1. 루프는 각 array의 요소를 반복하여 element_declaration에
선언된 변수에 현재 배열 요소의 값을 할당한다.
단점 = 내부에서는 배열의 요소를 변경 불가하다(그러나 const 사용하면 변경 가능하다).
2. auto는 변수의 자료형을 컴파일 시간에 자동으로 추론해준다.
*/
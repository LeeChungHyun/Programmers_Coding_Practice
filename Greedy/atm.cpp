#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>list, int answer){
    int sum = 0;

    sort(list.begin(), list.end());

    for(int i= 0; i<list.size(); i++){
        sum += list[i];
        answer += sum;
    }
    return answer;
}

void print(vector<int>list, int time){
    int t = solution(list, time);
    cout<<t<<endl;
    if(t == time) cout<< "Correct"<<endl;
    else cout<<"wrong"<<endl;
}

int main(){
    print({3,1,4,3,2}, 32);
    return 0;
}
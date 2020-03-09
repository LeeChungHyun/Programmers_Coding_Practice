#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b){
    if (a+b > b+a) return true;
    else return false;
}//각 문자끼리 합쳐서 비교해서 큰 수으로 정렬한다.

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>array;
    for(int i=0; i<numbers.size(); i++){
        array.push_back(to_string(numbers[i]));
    }//string으로 바꾸고 array벡터에 넣는다.
    sort(array.begin(), array.end(), compare);//오름차순으로 정렬한다.

    for(int i=0; i < array.size(); i++){
        answer = answer + array[i];
    }

    if(answer[0] == '0') answer = '0';//0이면 0반환

    return answer;
}

void print(vector<int>numbers, string answer){
    string t = solution(numbers);
    if(t == answer){
        cout<<"Correct"<<endl;
    }
    else cout<<"Wrong"<<endl;
}

int main(){
    print({6, 10, 2}, "6210");
    print({3, 30, 34, 5, 9}, "9534330");
    print({0, 0, 0, 0, 0, 0, 0}, "0");
    return 0;
}

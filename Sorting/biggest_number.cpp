#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b){
    if (a+b > b+a) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>array;
    for(int i=0; i<numbers.size(); i++){
        array.push_back(to_string(numbers[i]));
    }
    sort(array.begin(), array.end(), compare);

    for(int i=0; i < array.size(); i++){
        answer = answer + array[i];
    }

    if(answer[0] == '0') answer = '0';

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
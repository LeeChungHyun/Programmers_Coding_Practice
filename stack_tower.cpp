#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> st;
    bool check = true;
    for(int j=heights.size()-1; j>=0; j--){
        for(int i=j-1; i>=0; i--){
            if(heights.at(i) > heights.at(j)){
                st.push(i+1);
                check = false;
                break;
            }
        }
    if(check)
        st.push(0);
    check = true;
    }
    while(!st.empty()){
        answer.push_back(st.top());
        st.pop();
    }
    return answer;
}

void print(vector<int>heights, vector<int>answer){
    vector<int>t = solution(heights);
    for(int i=0; i<answer.size(); i++) {
        cout<<answer[i]<<endl;
        if(answer[i]!=t[i]){
            cout<<"wrong"<<endl;
            return;
        }
    }
    cout<<"answer"<<endl;
}

int main(){
    print({ 6, 9, 5, 7, 4 }, { 0,0,2,2,4 });
    print({ 3,9,9,3,5,7,2 }, { 0,0,0,3,3,3,6 });
    print({ 1,5,3,6,7,6,5 }, { 0,0,2,0,0,5,6 });
    return 0;
}
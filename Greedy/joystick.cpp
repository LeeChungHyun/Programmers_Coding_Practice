#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int i=0;
    string temp(name.length(), 'A');
    while(true){
        temp[i] = name[i];
        name[i] - 'A' > 'Z'+1-name[i]? answer +='Z'+1-name[i]:answer +=name[i]-'A';
        if(temp == name) break;
        for(int move=1; move<name.length(); move++){
            if(name[(i+move)%name.length()] != temp[(i+move)%name.length()]){
                i = (i+move)%name.length();
                answer += move;
                break;
            }
            else if(name[(i+name.length()-move)%name.length()] != temp[(i+name.length()-move)%name.length()]){
                i = (i+name.length()-move)%name.length();
                answer +=move;
                break;
            }
        }
    }
    return answer;
}

void print(string name, int answer){
    int t = solution(name);
    cout<<t<<" ";
    if(t == answer) cout<<"Correct"<<endl;
    else cout << "Wrong"<<endl;
}

int main(){
    print("JEROEN", 56);
    print("JAN", 23);
    print("AABAAAAAAAB", 6);
    print("AAAAAAAA", 0);
    print("ABBBBAAAABAA", 14);
    print("ABAAAAAAABA", 6);
    print("AAB", 2);
    print("AABAAAAAAABBB", 12);
    print("ZZZ", 5);
    return 0;
}
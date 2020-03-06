#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> tmp;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp.at(commands[i][2] - 1));
    }
    return answer;
}

void print(vector<int>array, vector<vector<int>> commands, vector<int> answer){
    vector<int> t = solution(array, commands);
    if(t == answer) cout<<"Correct"<<endl;
    else cout<<"Wrong"<<endl;
}

int main(){
    print({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}}, {5, 6, 3});
    return 0;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열 progresses와 각 작업의 개발 속도가 적힌 정수 배열 speeds가
 주어질 때 각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하는 프로그램 만든다.*/

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> temp;
    int s;

    for (int i = 0; i < progresses.size(); i++)
    {
        s = (100 - progresses[i]) % speeds[i];//진행률을 속도로 나눌때 나머지 존재하면 1 추가한다.
        if (s > 0)//1 더한 값을 push한다.
        {
            temp.push_back((100 - progresses[i]) / speeds[i] + 1);
        }
        else
        {
            temp.push_back((100 - progresses[i]) / speeds[i]);
        }
    }
    s = temp[0];
    int count = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if (s < temp[i])
        {
            answer.push_back(count);
            count = 1;
            s = temp[i];
        }

        else //더 오래 걸리는 기능을 만났을때, count를 answer배열에 push한다.
        {
            count++;
        }

        if (i == temp.size() - 1)
        {
            answer.push_back(count);
        }//마지막 기능 만날때 count값을 push하고 종료
    }
    return answer;
}

void print(vector<int> progresses, vector<int> speeds)
{
    vector<int> t = solution(progresses, speeds);
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << endl;
        return;
    }
    cout << "The Final function time is" << endl;
}

int main()
{
    print({93, 30, 55}, {1, 30, 5});
    return 0;
}

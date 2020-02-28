#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int solution(string arrangement)
{
    stack<int> pipe; //쇠막대기 갯수
    int answer = 0;  //레이저에 의해 잘린 쇠막대기 총 갯수
    for (int i = 0; i < arrangement.length(); i++)
    {
        //string에서는 length으로 길이를 표시한다.
        if (arrangement[i] == '(')
        {
            pipe.push(1);
        }
        else
        {
            pipe.pop();
            if (arrangement[i - 1] == '(')
            { //바로 전의 괄호가 "("이면 ()가 되므로 레이저 발사한다.
                answer += pipe.size();
            }
            else
            {
                answer++; //")"이라면 쇠막대기의 회수부분이므로 1개씩 추가한다.
            }
        }
    }
    return answer;
}

void print(string a, int answer)
{
    int t = solution(a);
    cout << t << "";
}

int main()
{
    print("()(((()())(())()))(())", 17);
    return 0;
}
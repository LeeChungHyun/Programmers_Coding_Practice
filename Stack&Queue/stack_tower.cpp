#include <stack>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> solution(vector<int> heights)
{
    vector<int> answer;
    stack<int> st;
    bool check = true;
    for (int j = heights.size() - 1; j >= 0; j--)
    { //리스트를 뒤에서부터 돈다
        for (int i = j - 1; i >= 0; i--)
        { // 제일 뒤에꺼보다 앞의 타워가 큰 경우
            if (heights.at(i) > heights.at(j))
            {
                st.push(i + 1); // 스택이 몇번째 타워인지 넣는다
                check = false;  //조건문 비활성화
                break;
            }
        }
        if (check)
            st.push(0);
        check = true; // 만약 자신보다 큰 타워가 없거나 첫번째 타워는 0으로 표시한다.
    }
    while (!st.empty())
    {
        answer.push_back(st.top());
        st.pop();
    } //스택이 비는 동안 정답에 푸쉬한다.
    return answer;
}

void print(vector<int> heights, vector<int> answer)
{
    vector<int> t = solution(heights);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
        if (answer[i] != t[i])
        {
            cout << "wrong" << endl;
            return;
        }
    }
    cout << "the answer is" << endl;
}

int main()
{
    print({6, 9, 5, 7, 4}, {0, 0, 2, 2, 4});
    print({3, 9, 9, 3, 5, 7, 2}, {0, 0, 0, 3, 3, 3, 6});
    print({1, 5, 3, 6, 7, 6, 5}, {0, 0, 2, 0, 0, 5, 6});
    return 0;
}

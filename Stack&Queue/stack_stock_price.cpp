#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    int size = prices.size();
    vector<int> answer(size);
    stack<int> st;
    for (int i = 0; i < size; i++)
    {
        //스택이 비어있지않고 스택마지막 값이 현재값보다 크다면
        //-> 가격이 떨어졌다면
        while (!st.empty() && prices[st.top()] > prices[i])
        {
            //가격이 떨어졌으므로 i - 스택 마지막값 대입
            answer[st.top()] = i - st.top();
            //값제거
            st.pop();
            //반복문인 이유: 가격이 같은값이 유지되었을경우
            //현재값보다 계속작으므로 1개차이씩 넣어주기 위해서다.
        }
        //현재 인덱스를 스택에 넣기
        st.push(i);
    }
    //스택이 빌때까지 반복
    while (!st.empty())
    {
        //위에서 특정위치에 이미 값을 넣었으므로 pushback이나 insert로하면 안된다.
        //뒤에서부터 넣어야하므로 size-1 에서 top값을 빼준다.
        answer[st.top()] = size - st.top() - 1;
        st.pop();
    }
    return answer;
}

void print(vector<int> prices, vector<int> answer)
{
    vector<int> t = solution(prices);
    if (answer == t)
        cout << "정답" << endl;
    else
        cout << "틀림" << endl;
}

int main()
{
    print({1, 2, 3, 2, 3}, {4, 3, 1, 1, 0});
    vector<int> prices, answer;
    for (int i = 1; i <= 100000; i++)
    {
        prices.push_back(i);
        answer.push_back(100000 - i);
    }
    print(prices, answer);
    return 0;
}
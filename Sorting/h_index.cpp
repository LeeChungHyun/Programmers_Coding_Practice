#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());//내림차순한다.
    if (citations[0] == 0)//최댓값이 0이면 0으로 리턴한다.
        return 0;
    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] > i)
            answer++;
        else
            break;
    }
    return answer;
}

void print(vector<int> citations, int answer)
{
    int t = solution(citations);
    if (t == answer)
        cout << "Correct" << endl;
    else
        cout << "Wrong" << endl;
}

int main()
{
    print({3, 0, 6, 1, 5}, 3);
    print({7}, 1);
    print({1545, 2, 999, 790, 540, 10, 22}, 6);
    print({22, 47}, 2);
    print({2, 7, 5}, 2);
    print({4, 3, 3, 3, 3}, 3);
    print({10, 50, 100}, 3);
    print({1, 7, 0, 1, 6, 4}, 3);
    print({0}, 0);
    return 0;
}
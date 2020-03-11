#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    for (string candidate : phone_book)
    {
        int candidate_size = candidate.size();
        for (string phone_number : phone_book)
        {
            if (candidate_size > phone_number.size() || candidate == phone_number)
                continue;
            string sub_num = phone_number.substr(0, candidate_size);
            if (candidate.compare(sub_num) == 0)
            {
                return false;
            }
        }
    }
    return answer;
}

void print(vector<string> phone_book, string answer){
    bool t = solution(phone_book);
    if(t == false) cout << "Correct" << endl;
    else cout << "Wrong" << endl;
}

int main(){
    print({ "119", "97674223", "11912234"}, {false});
    print({"123", "456", "789"}, {true});
    print({"12", "123", "1235", "567", "88"}, {true});
    return 0;
}


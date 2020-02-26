#include <string>
#include <vector>//자동으로 메모리가 할당되는 배열, 맨 뒤쪽에서 삽입/삭제 가능, 중간에도 삽입/삭제 가능
#include <queue>//FIFO(먼저 들어온 데이터가 먼저 나간다)이므로 queue사용한다.
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;//경과시간 
    int currentWeight=0;//다리위에 올라가져있는 트럭들의 현재무게
    queue<int>truckList, bridgeOn;//다리위에 올라가져있는 트럭 리스트, 다리위에 올라가져있는 트럭마다 남은 거리
    while(true){
        int size = bridgeOn.size();//size를 고정한다.
        for(int i=0; i<size; i++){
            int length = bridgeOn.front();//첫번째 원소를 참조한다
            bridgeOn.pop();//마지막 원소 제거
            if(length<=1){//다리에서 남은 길이가 없으면
                currentWeight -= truckList.front();//다리에서 현재차 무게 제외
                truckList.pop();
                continue;
            }
            bridgeOn.push(length-1);//남아있다면 길이 감소후 다시넣는다
        }
        if(truck_weights.size()>0 && currentWeight+truck_weights.at(0) <= weight){//대기 차가 1대 이상이고 다리가 무게 견딜 수 있는 경우
            truckList.push(truck_weights.at(0));//push는 마지막 원소 뒤에 원소 추가한다.
            currentWeight += truck_weights.at(0); //at은 n번째 원소를 참조한다.
            bridgeOn.push(bridge_length);//남은 다리거리 추가한다.
            truck_weights.erase(truck_weights.begin());//begin은 첫번째 원소를 가리킨다. 대기차량 삭제
        }
        answer++;
        if(truck_weights.size()==0 && truckList.size()==0)//모두 없다면 break
            break;
    }
    return answer;
}

void print(int bridge_length, int weight, vector<int>truck_weights, int answer){
    int t = solution(bridge_length, weight, truck_weights);
    cout<<t<<endl;
    if(t==answer)
        cout<<"Correct"<<endl;
    else
        cout<<"Wrong"<<endl;
}

int main(){
    print(2,10,{7,4,5,6},8);
    print(100,100,{10},101);
    print(100,100,{10,10,10,10,10,10,10,10,10,10},110);
    return 0;
}
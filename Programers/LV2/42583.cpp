//다리를 지나는 트럭
//https://school.programmers.co.kr/learn/courses/30/lessons/42583
//reference: https://velog.io/@qhsh866/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4Level2-%EB%8B%A4%EB%A6%AC%EB%A5%BC-%EC%A7%80%EB%82%98%EB%8A%94-%ED%8A%B8%EB%9F%AD-C
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int idx = 0; //truck idx;
    int sum=0; //현재 다리의 무게
    queue<int> q; //다리
    
    while(true){
        //마지막 차
        if(idx == truck_weights.size()){
            answer+=bridge_length;
            break;
        }
        answer++;
        
        int nxtTruck=truck_weights[idx];
        
        //다리를 다 건넜는지 확인
        if(q.size()==bridge_length){
            sum-=q.front();
            q.pop();
        }
        
        if(sum+nxtTruck<=weight){
            sum+=nxtTruck;
            q.push(nxtTruck);
            idx++;
        }else{
            q.push(0);  //진입 할 수 없을 경우 0을 넣어서 시간 초 계산
        }
        
        
    }
    
    
    return answer;
}
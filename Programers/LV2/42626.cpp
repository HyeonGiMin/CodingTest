//더 맵게
//https://school.programmers.co.kr/learn/courses/30/lessons/42626
//reference: https://mungto.tistory.com/8
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> q(scoville.begin(),scoville.end());
    
    //섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
    while(q.size()>1 && q.top()<K){
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        q.push(first+(second*2));
        answer++;
    }
    
    if(q.top()<K) return -1;
    
    
    return answer;
}
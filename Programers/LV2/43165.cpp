//타겟 넘버
//https://school.programmers.co.kr/learn/courses/30/lessons/43165
//reference: https://i-believe-in-me.tistory.com/214
#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(vector<int> numbers,int target,int sum,int idx){
    //마지막일 경우
    if(idx == numbers.size()){
        //합계가 대상과 같을 경우 
        if(sum==target) answer++;
        return;
    }
    //양수
    DFS(numbers,target,sum+numbers[idx],idx+1);
    //음수
    DFS(numbers,target,sum-numbers[idx],idx+1);
    
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target, 0, 0);
    return answer;
}
//프로세스
//https://school.programmers.co.kr/learn/courses/30/lessons/42587
//reference: https://velog.io/@jimojjing/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4CLv.2-%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> execute;
    queue<int> q;
    
    //priorities를 idx겂으로  queue에 넣는다
    for(int i=0;i<priorities.size();i++){
        q.push(i);
    }
    
    //Queue가 다 소진될때까지
    while(!q.empty())
    {
        //첫번째 요소를 가져온.
        int curIdx = q.front();
        q.pop();
        
        //더 높은 프로세스가 있는지 확인하기
        if(priorities[curIdx] != *max_element(priorities.begin(),priorities.end())) {
            q.push(curIdx);
        }else{
            execute.push_back(curIdx);
            priorities[curIdx] =0;
        }
    }
    
    for(int i=0;i<execute.size();i++){
        if(execute[i] == location) answer = i+1;
    }
    
    return answer;
}
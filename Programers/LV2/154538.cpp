//숫자 변환하기
//https://school.programmers.co.kr/learn/courses/30/lessons/154538
//refrence : https://jinho082008.tistory.com/23
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    
    //현재 값, 횟수
    queue<pair<int,int>> q;
    //현재 값 중복확인
    set<int> s; 
    
    //초기 값
    q.push({x,0});
    s.insert(x);
    
    while(!q.empty()){
        
        int cur = q.front().first;
        int cnt = q.front().second;
        
        q.pop();
        
        if(cur==y)
            return cnt;
        
        int val[3] = {cur+n,cur*2,cur*3};
        
        for(int v:val){
            //연산 결과가 y보다 작고, 중복되지 않았으면 queue에 집어 넣는다.
            if(v<=y && s.find(v)==s.end()){
                q.push({v,cnt+1});
                s.insert(v);
            }
        }
        
    }
    
    return -1;
}
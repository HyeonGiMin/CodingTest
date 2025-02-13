//짝지어 제거하기
//https://school.programmers.co.kr/learn/courses/30/lessons/12973
//reference https://velog.io/@redgem92/C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-Level-2-%EC%A7%9D%EC%A7%80%EC%96%B4-%EC%A0%9C%EA%B1%B0%ED%95%98%EA%B8%B0
#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> stk;
    
    if(s.empty() || s.size()%2!=0)
        return answer;
    
    for(int i=0;i<s.size();i++){
        if(stk.empty()||stk.top() != s[i]){
            stk.push(s[i]);
        }else
            stk.pop();
    }
    
    if(stk.empty())
        answer=1;

    return answer;
}
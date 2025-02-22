//괄호 회전하기
//https://school.programmers.co.kr/learn/courses/30/lessons/76502
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool isCollect(string str){
    //stack을 이용해서 마지막 요소와 같으면 
    stack<char> st;
    
    for(char c:str){
         //왼쪽 브라켓은 무조건 넣는다.
         if(c == '(' || c == '{'||c == '['){
            st.push(c);
        }else{
            if(st.empty()){
                return false;
            }else if(c == ')' && st.top() == '('){
                st.pop();
            }else if(c == '}' && st.top() == '{'){
                st.pop();
            }else if(c == ']' && st.top() == '['){
                st.pop();
            }
        }
    }
    
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.size();i++){
        //rotate를 이용해서 하나씩 회전
        rotate(s.begin(), s.begin() + 1, s.end());
        if(isCollect(s))
            answer++;
        
    }
    
    return answer;
}
//올바른 괄호
//https://school.programmers.co.kr/learn/courses/30/lessons/12909
//reference https://velog.io/@minsu_lighting--/C-%EC%8A%A4%ED%83%9D-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%98%AC%EB%B0%94%EB%A5%B8-%EA%B4%84%ED%98%B8

//처음
// #include<string>
// #include <iostream>

// using namespace std;

// bool solution(string s)
// {
//     bool answer = false;
//     //문자열의 () 을 모두 공백으로 치환해서 제거해 나가면 마지막에 공백이 되면 true
//     while(s.find("()",0)!=string::npos){
//         s.replace(0,2,"");
//     }
    
//     if(s =="")
//         answer=true;

//     return answer;
// }

#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    stack<char> st;
    
    
    for(char c:s){
        if(c == '('){
            st.push(c);
        }else{
            if(st.empty()){
                return false;
            }else{
                st.pop();
            }
        }
    }
    
    answer =st.empty();
    
    return answer;
}

int main(int argc, char const *argv[])
{
    /* code */
    solution("(())()");
    return 0;
}

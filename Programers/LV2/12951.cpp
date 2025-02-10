//JadenCase 문자열 만들기
// /https://school.programmers.co.kr/learn/courses/30/lessons/12951
// Reference : https://hirodevelodiary.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4Lv2-JadenCase-%EB%AC%B8%EC%9E%90%EC%97%B4-%EB%A7%8C%EB%93%A4%EA%B8%B0
// 단순하게 접근하기, 굳이 split 할 피요 없음
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    //첫번째는 대문자로
    answer+=toupper(s[0]);
    
    for(int i=1;i<s.size();i++){
        if(s[i-1] == ' '){
            answer+=toupper(s[i]);
        }else{
            answer+=tolower(s[i]);
        }
    }
    
    
    return answer;
}
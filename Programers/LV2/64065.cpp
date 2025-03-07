//튜플
//https://school.programmers.co.kr/learn/courses/30/lessons/64065
//reference: https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%ED%8A%9C%ED%94%8C
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    unordered_map<int, int> m;
    
    //문자열 s에서 숫자만 추출
    //첫번째 값은 2부터 나온다 
    for(int i=2;i<s.size();i++){
        if (isdigit(s[i])) {// 숫자면
            m[stoi(s.substr(i))]++; //stoi는 숫자가 아닌 문자를 만나면 변환을 멈춤.
            while (isdigit(s[i]))
                i++;
        }
    }
    
    int size = m.size();
    vector<int> answer(size);
    
    for (auto c : m) answer[size - c.second] = c.first;// size - c.second 가 곧 인덱스이다.
    return answer;
}
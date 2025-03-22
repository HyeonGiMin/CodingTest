//가장 큰 수
//https://school.programmers.co.kr/learn/courses/30/lessons/42746
//reference: https://velog.io/@dianestar/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B0%80%EC%9E%A5%ED%81%B0%EC%88%98
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b){
    return a+b > b+a;
}


string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    
    //sring으로 변환
    for(int number:numbers){
        v.push_back(to_string(number));
    }
    sort(v.begin(),v.end(),cmp);
    
    for(auto it : v){
        answer+=it;
    }
    
    
    //0이 여러개 나올 수 있다.
    if(answer[0] == '0'){
        answer="0";
    }
    
    
    
    
    return answer;
}
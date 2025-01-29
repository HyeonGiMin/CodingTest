//문자열 나누기 https://school.programmers.co.kr/learn/courses/30/lessons/140108
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int sCount = 0; // 같은수
    int dCount = 0; // 다른수
    char diff;
    
    for(int i=0;i<s.size();i++){
        if(sCount ==0){
            //같은 수 가 0이라는 것은 처음 값을 읽어야 하는 상황
            diff= s[i];
            sCount++;
        }else if(s[i] == diff){ //같은 값이 나온 경우 
            sCount++;
        }else if(s[i] != diff){
            dCount++;
        }
        
        
        if(sCount == dCount){
            sCount=0;
            dCount=0;
            answer++;
        }
    }
    
    //마지막까지 문자열이 완성되지 않은 경우
    if(sCount!=0){
         answer++;
    }
    
    return answer;
}
//뒤에 있는 큰 수 찾기
//https://school.programmers.co.kr/learn/courses/30/lessons/154539
//reference: https://velog.io/@slow_cosmos/c%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%92%A4%EC%97%90-%EC%9E%88%EB%8A%94-%ED%81%B0-%EC%88%98-%EC%B0%BE%EA%B8%B0
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<int> stk;
    
    //역순으로 확인
    //뒤라는게 index 기준 뒤
    for(int i=numbers.size()-1;i>=0;i--){
     
        while(true){
            if(stk.empty()){
                answer[i] = -1;
                break;
            }
               
           if(stk.top()>numbers[i]){
              answer[i] = stk.top();
                break;
           }
            stk.pop();
        }
        stk.push(numbers[i]);
    }
   
    
    return answer;
}
//2개 이하로 다른 비트
//https://school.programmers.co.kr/learn/courses/30/lessons/77885
//reference: https://yoonsys.tistory.com/25
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0;i<numbers.size();i++){
    //짝수의 경우 마지막을 0->1로 바꾸면 된다.
        if(numbers[i]%2==0){
            answer.push_back(numbers[i]+1);
        }else{
                
             //홀수의 경우 뒤에서부터 처음 0을 1로 바꾸고 그 옆에 1을 0으로 바꾼다.
            long long b=1;
            
            while(true){
                if((numbers[i] & b) ==0 ) break;
                b*=2;
            }
            
            // 01 => 10 으로 변환
            answer.push_back(numbers[i]+(b/2));
        }
    }
    

    
    
    return answer;
}
//숫자의 표현
//https://school.programmers.co.kr/learn/courses/30/lessons/12924
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1;i<=n;i++){
        int sum=0;
        int num =i;
        while(sum<n){
            sum+=num;
            
            if(sum == n)
                answer++;
            
            num++;
        }
        
        
    }
    
    return answer;
}
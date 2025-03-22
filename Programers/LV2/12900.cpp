//2 x n 타일링
//https://school.programmers.co.kr/learn/courses/30/lessons/12900
//reference: https://gdlovehush.tistory.com/603

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int D[60001];
    
    D[1]=1; D[2]=2;
    
    for(int i=3;i<=n;i++){
        D[i] =(D[i-1]+D[i-2])%1000000007;
    }
    
    answer=D[n];
    
    return answer;
}
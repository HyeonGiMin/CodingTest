//멀리 뛰기
//https://school.programmers.co.kr/learn/courses/30/lessons/12914
//reference https://yabmoons.tistory.com/588
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> vec(n+1,0);
    vec[1] =1;
    vec[2]=2;
    
    //피보나치 수열
    //f(n) = f(n-1)+f(n-2);
    for(int i=3;i<=n;i++){
        vec[i]=vec[i-1]+vec[i-2];
        vec[i]%=1234567;
    }
    
    answer = vec[n];
    
    return answer;
}
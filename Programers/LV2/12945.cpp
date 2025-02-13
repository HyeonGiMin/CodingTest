//피보나치 수
// https://school.programmers.co.kr/learn/courses/30/lessons/12945

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> vec(n+1,0);
    
    vec[0] =0;
    vec[1] =1;

    for(int i=2;i<=n;i++){
        vec[i]=vec[i-1]+vec[i-2];
        vec[i]=vec[i]%1234567;
    }

    return vec[n];
}
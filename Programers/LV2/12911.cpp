//다음 큰 숫자
//https://school.programmers.co.kr/learn/courses/30/lessons/12911
//Refrence https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%8B%A4%EC%9D%8C-%ED%81%B0-%EC%88%AB%EC%9E%90
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int bitCount(int n){
    string bitStr= bitset<20>(n).to_string();
    int cnt =0;
    for(auto c :bitStr){
        if(c=='1') cnt++;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int cnt=bitCount(n);
    int start = n+1;
    //2진수로 변환했을때 1의 개수 
    while(cnt != bitCount(start)){
        start++;
    }
    
    answer=start;
    return answer;
}
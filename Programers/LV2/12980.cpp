//점프와 순간 이동
//https://school.programmers.co.kr/learn/courses/30/lessons/12980
//refrence https://yabmoons.tistory.com/697
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    //한번에 순간이동으로 많이 갈 수 있으면 득
    while(n>0){
        //짝수인 경우 순간이동
        if(n%2==0) n/=2;
        else{
            //홀수인 경우 한칸 앞으로, 건전지 소모
            n-=1;
            ans++;
        }
    }
    
    return ans;
}
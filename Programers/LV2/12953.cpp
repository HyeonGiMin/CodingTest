//N개의 최소공배수
//https://school.programmers.co.kr/learn/courses/30/lessons/12953
//reference https://yabmoons.tistory.com/702
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    //두수의 최소공배수 와 그 뒤에 수와의 최소공배수 관계를 구하면 된다
    //최소 공배수는 a*b/최대공약수
    answer = arr[0];
    for(int i=1;i<arr.size();i++){
        int a =gcd(answer,arr[i]);
        int b= answer*arr[i]/a;
        answer=b;
    }
    
    
    return answer;
}
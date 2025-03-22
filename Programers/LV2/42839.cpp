//소수 찾기
//https://school.programmers.co.kr/learn/courses/30/lessons/42839
//reference: https://i-believe-in-me.tistory.com/205
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    //조합의 결과가 중복일 수 있다.=> Set 사용
    set<int> s;
    
    //next_permutation을 사용하기 위해선 정렬이 되어 있어야함
    sort(numbers.begin(),numbers.end());
    int num =0;
    do{
        //문자를 합쳐서 숫자로 만들어서 소수인지 확인
        for(int i=1;i<numbers.size()+1;i++){
            num=stoi(numbers.substr(0,i));
            if(isPrime(num)) s.insert(num);
        }

    }while(next_permutation(numbers.begin(),numbers.end()));
    
    answer=s.size();
                     
    return answer;
}
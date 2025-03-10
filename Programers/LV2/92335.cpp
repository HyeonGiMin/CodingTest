//k진수에서 소수 개수 구하기
//https://school.programmers.co.kr/learn/courses/30/lessons/92335
//refrence https://velog.io/@ddyy094/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-K%EC%A7%84%EC%88%98%EC%97%90%EC%84%9C-%EC%86%8C%EC%88%98-%EA%B0%9C%EC%88%98-%EA%B5%AC%ED%95%98%EA%B8%B0-C-2022%EC%B9%B4%EC%B9%B4%EC%98%A4
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

vector<string> split(const string& input,char delimeter){
    vector<string> result;
    stringstream ss(input);
    string item;
    while(getline(ss,item,delimeter)){
        if(!item.empty())
            result.push_back(item);
    }
    
    return result;
}

string convertFomat(int n,int k){
    string format="";
    
    while(n!=0){
        format+=to_string(n%k);
        n/=k;
    }
    
    reverse(format.begin(),format.end());
    
    return format;
    
    
}

bool isPrime(long long n){
    if(n<2) return false;
    
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
        
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    //10진법 -> k진법 변환
    string cnvtFormat=convertFomat(n,k);
    
    //0을 기준으로 문자열을 잘라서 소수인지 확인
    vector<string> pVec = split(cnvtFormat,'0');
    
    for(string p: pVec){
        if(isPrime(stoll(p))){
            answer++;
        }
    }
    
    return answer;
}
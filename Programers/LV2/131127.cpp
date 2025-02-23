//할인 행사
//https://school.programmers.co.kr/learn/courses/30/lessons/131127
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> wMap;

bool check(map<string,int> m){
    for(auto p:wMap){
        if(m.find(p.first) == m.end()) // 없는경우
        {
            return false;
        }else if(m[p.first] < p.second){ // 사려는 수량 만큼이 없다면
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    //시작일 기준으로 10일에 원하는 제품이 다 있어야 한다
    //이를 만족하는 가입 일의 수
    //원하는 수량은 순서와 상관없다.

    for(int i =0; i<want.size();i++){
        wMap[want[i]] = number[i];
    }
    
    for(int i=0;i<=discount.size()-10;i++){
        map<string,int> m; // 할인 품목
        for(int j=i;j<i+10;j++){
            m[discount[j]]++;
        }
        answer+=check(m);
        m.clear();
    }
    
    
    return answer;
}
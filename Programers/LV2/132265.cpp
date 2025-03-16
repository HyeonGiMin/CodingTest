//롤케이크 자르기
//https://school.programmers.co.kr/learn/courses/30/lessons/132265
//reference: https://codingbutterfly.tistory.com/51
#include <string>
#include <vector>
#include <map>


using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m1;
    map<int, int> m2;
    
    //토핑의 갯수를 항목별로 map으로 만든다.
    for(int t:topping){
        m2[t]++;
    }
    
    //한개씩 동생에게 주면서 남은 갯수 확인
    for(int t:topping){
        //m1으로 이동
        m1[t]++;
        m2[t]--;
        
        if(m2[t]==0){
            m2.erase(t);
        }
        
        if(m1.size() == m2.size()) answer++;
         
     }
    
    
    
    //서로 나누어진 토핑의 종류가 같아야 한다.
    
    return answer;
}
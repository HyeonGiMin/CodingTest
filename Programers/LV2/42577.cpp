//전화번호 목록
//https://school.programmers.co.kr/learn/courses/30/lessons/42577
//reference: https://foameraserblue.tistory.com/16
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int> m;
    
    for(auto number:phone_book){
        m[number]++;
    }
    
    for(int i=0;i<phone_book.size();i++){
        string tmp ="";
        //앞에서 부터 하나씩 더해서 map에 값이 있는지 확인
        for(int j=0;j<phone_book[i].size();j++){
            tmp+=phone_book[i][j];
            //접두어 일 경우 false처리, 전체가 일치하는 경우는 제외
            if(m[tmp] && tmp != phone_book[i]){
                return false;
            }
        }
    }
    
    return answer;
}
//달리기 경주
//https://school.programmers.co.kr/learn/courses/30/lessons/178871
//refrence https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%8B%AC%EB%A6%AC%EA%B8%B0-%EA%B2%BD%EC%A3%BC
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    //rank,player
    map<int,string> m1;
    //player,rank
    map<string,int> m2;
    
    for(int i=0;i<players.size();i++){
        m1[i] = players[i];
        m2[players[i]] = i;
    }

    //순회하면 이름이 불릴 경우 앞의 값과 swap
    for(string calling:callings){
        //현재 내 순위를 확인
        int curRank = m2[calling];
        string target = m1[curRank-1];
        
        m1[curRank - 1] = calling;
        m1[curRank] = target;
        m2[calling] = curRank - 1;
        m2[target] = curRank;
        
    }
    
    for(auto m : m1) answer.push_back(m.second);
    return answer;
}
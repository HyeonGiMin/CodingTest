//가장 많이 받은 선물
//https://school.programmers.co.kr/learn/courses/30/lessons/258712
//reference: https://hwooo.tistory.com/345
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string>gifts) {
    int answer = 0;
    int n = friends.size();
    vector<int> pScore(n, 0); // 선물 지수 초기화
    vector<vector<int>> giftMap(n, vector<int>(n, 0)); // 선물 기록 초기화
    vector<int> gScore(n, 0); // 선물 점수 초기화
    
    for(int i=0; i<gifts.size(); i++){
        string gift = gifts[i];
        int spaceIdx = gift.find(' ');
        string from = gift.substr(0, spaceIdx), to = gift.substr(spaceIdx + 1);
        
        int fromIdx = find(friends.begin(), friends.end(), from) - friends.begin();
        int toIdx = find(friends.begin(), friends.end(), to) - friends.begin();
        
        // 서로 선물을 주고 받은 기록을 표로 옮김       
        giftMap[fromIdx][toIdx]++;
        
        // 선물 지수 계산
        pScore[fromIdx]++;
        pScore[toIdx]--;
    }
   
    for(int i=0; i<friends.size(); i++){
        for(int j=0; j<friends.size(); j++){
            if(i == j)
                continue;
            
            if(giftMap[i][j] > giftMap[j][i]){
                gScore[i]++;
            } else if(giftMap[i][j] == giftMap[j][i] && pScore[i] > pScore[j]){
                gScore[i]++;
            }
        }
        answer = max(answer, gScore[i]);
    }
    
    return answer;
}
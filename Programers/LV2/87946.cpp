//피로도
//https://school.programmers.co.kr/learn/courses/30/lessons/87946
//reference: https://uiop5809.tistory.com/213
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[9]; //던전의 갯수는 8이하, idx를 1~8로 사용
int res;

int dfs(vector<vector<int>> dungeons,int k,int cnt){
    res = max(res, cnt); // 최대 던전수
    
    for(int i=0;i<dungeons.size();i++){
        //방문 했거나, 최소 피로도보다 현재 피로도가 작으면 skip
        if(visited[i] || dungeons[i][0]> k)
            continue;
        
        visited[i] = true;
        dfs(dungeons, k - dungeons[i][1], cnt + 1); // 현재 피로도 - 소모 피로도
        visited[i] = false;
    }
    return res;
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    

     answer = dfs(dungeons, k, 0);
    

    return answer;
}
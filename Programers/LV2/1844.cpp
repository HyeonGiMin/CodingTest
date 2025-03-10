//게임 맵 최단거리
//https://school.programmers.co.kr/learn/courses/30/lessons/1844
//reference: https://bonnate.tistory.com/536

#include<vector>
#include<queue>

int dx[4]={-1,1,0,0,};
int dy[4]={0,0,-1,1};

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int row = maps.size();
    int col = maps[0].size();
    
    //누적 거리
    vector<vector<int>> dist(row,vector<int>(col,-1));
    queue<pair<int,int>> q;
    
    
    //0,0에서 시작
    q.push({0,0});
    dist[0][0] = 1;
    
    while(!q.empty()){
        
        //좌표 확인
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        
        //4방향 확인하기 
        for(int i=0;i<4;i++){
            int targetX = x+dx[i];
            int targetY = y+dy[i];
            
            if(targetX == -1 || targetY == -1 || targetX == col || targetY == row|| maps[targetY][targetX] == 0 || dist[targetY][targetX] != -1)
                continue;
            
            q.push({targetX,targetY});
            dist[targetY][targetX] = dist[y][x]+1;
        }
        
    }
    
    
    answer= dist[row-1][col-1];
    
    return answer;
}
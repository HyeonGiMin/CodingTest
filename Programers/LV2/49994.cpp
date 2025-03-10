//방문 길이
//https://school.programmers.co.kr/learn/courses/30/lessons/49994
//reference: https://ansohxxn.github.io/programmers/104/
#include <string>
#include <map>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    //출발점 {5,5}
    
    //간선으로 해야함!!
    map<pair<pair<int, int>, pair<int, int>>, bool> visitedEdge;
    
    
    //5,5에서 시작
    int curX=5;
    int curY=5;
    for(int i=0;i<dirs.size();i++){
        int startX=curX;
        int startY=curY;
        char dir = dirs[i];
        
        if(dir == 'U'){
            if(curX-1<0)
                continue;
            
            curX--;
        }
        
        if(dir == 'D'){
            if(curX+1>10)
                continue;
            
            curX++;
        }
        
        if(dir == 'L'){
            if(curY-1<0)
                continue;
            
            curY--;
        }
        
        if(dir == 'R'){
            if(curY+1>10)
                continue;
            
            curY++;
        }
        
        //이미 지나간 경우
        if(visitedEdge[{{startX,startY},{curX,curY}}]==true)
            continue;
        
        //지나간것으로 설정
        visitedEdge[{{startX,startY},{curX,curY}}]=true;
        visitedEdge[{{curX,curY},{startX,startY}}]=true;
        answer++;
    }
    
    
    
    
    return answer;
}
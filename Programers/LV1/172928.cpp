//공원 산책
//https://school.programmers.co.kr/learn/courses/30/lessons/172928
//reference https://steadycodist.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4C-%EA%B3%B5%EC%9B%90-%EC%82%B0%EC%B1%85
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    vector<vector<char>> map;
    int posX,posY;
    
    int maxX=park.size();
    int maxY=park[0].size();
    
    //이차원 배열로 제작
    for(int i=0;i<park.size();i++){
        vector<char> v;
        for(int j=0;j<park[i].size();j++){
            v.push_back(park[i][j]);
            
            if(park[i][j]=='S'){
                posX=i;
                posY=j;
            }
        }
        map.push_back(v);
    }
    
    for(int i=0;i<routes.size();i++)
    {
        char dir=routes[i][0];
        int dist =  routes[i][2] -'0'; //routes[i][2]는 char 형 이므로 
        
        int curX =posX;
        int curY =posY;
        
        while(dist>0){
            switch(dir){
                case 'N':
                    curX--;
                    break;
                case 'S':
                    curX++;
                    break;
                case 'W':
                    curY--;
                    break;
                case 'E':
                    curY++;
                    break;
            }
            
            //구간을 벗어난 경우
            if(curX>=maxX || curX<0 || curY >=maxY|| curY <0)
                break;
            
            if(map[curX][curY] == 'X')
                break;
            
            dist--;
        }
        
        if(dist==0){
            posX=curX;
            posY=curY;
        }
    }
    
    answer.push_back(posX);
    answer.push_back(posY);
    
    return answer;
}
//바탕화면 정리
//https://school.programmers.co.kr/learn/courses/30/lessons/161990
//reference: https://transferhwang.tistory.com/698
//드래그를 한번에 하는게 아니라 여러번 해야한다고 생각해서 문제를 이해하지 못함
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> xPos,yPos;
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].size();j++){
            if(wallpaper[i][j] == '#'){
                xPos.push_back(i);
                yPos.push_back(j);
            }
        }
    }
    
        
    //x,y 좌표의 최소,최대값을 찾은 후 
    int xMin = *min_element(xPos.begin(),xPos.end());
    int yMin = *min_element(yPos.begin(),yPos.end());
    int xMax = *max_element(xPos.begin(),xPos.end());
    int yMax = *max_element(yPos.begin(),yPos.end());
    
    
    answer.push_back(xMin);
    answer.push_back(yMin);
    //끝에는 파일크기를 포함해야해서 +1
    answer.push_back(xMax+1);
    answer.push_back(yMax+1);

    
    
    return answer;
}
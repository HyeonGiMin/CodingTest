//땅따먹기
//https://school.programmers.co.kr/learn/courses/30/lessons/12913
//reference: https://iwillfindmyuniverse.tistory.com/137
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    //다음 Row에 현재 idx 이외의 가장 큰 값을 추가
    for(int i=0;i<land.size()-1;i++){
        land[i+1][0] += max(land[i][1],max(land[i][2],land[i][3]));
        land[i+1][1] += max(land[i][0],max(land[i][2],land[i][3]));
        land[i+1][2] += max(land[i][0],max(land[i][1],land[i][3]));
        land[i+1][3] += max(land[i][0],max(land[i][1],land[i][2]));
    }
    
    //합 중에 가장 큰 값
    answer = *max_element(land[land.size()-1].begin(),land[land.size()-1].end());
    

    return answer;
}
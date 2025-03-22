//쿼드압축 후 개수 세기
//https://school.programmers.co.kr/learn/courses/30/lessons/68936
//reference: https://sindh718.tistory.com/103
#include <string>
#include <vector>

using namespace std;

void dfs(int x,int y,int size, vector<int>& answer, vector<vector<int>>& arr){
    bool isZero=true,isOne=true;

    
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(arr[i][j]==0) isOne =false;
            if(arr[i][j]==1) isZero =false;
        }
    }
    
    if(isZero){
        answer[0]++;
        return;
    }
    
    if(isOne){
        answer[1]++;
        return;
    }
    
    dfs(x,y,size/2,answer,arr);
    dfs(x,y+size/2,size/2,answer,arr);
    dfs(x+size/2,y,size/2,answer,arr);
    dfs(x+size/2,y+size/2,size/2,answer,arr);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    dfs(0,0,arr.size(),answer,arr);
    return answer;
}
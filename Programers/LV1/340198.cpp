//[PCCE 기출문제] 10번 / 공원
//https://school.programmers.co.kr/learn/courses/30/lessons/340198
//refrence: https://velog.io/@ian125/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-PCCE-%EA%B8%B0%EC%B6%9C%EB%AC%B8%EC%A0%9C-10%EB%B2%88-%EA%B3%B5%EC%9B%90-C
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int max =0;
    sort(mats.begin(), mats.end());
    
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].size();j++){
            if(park[i][j] != "-1")
                continue;
            
            int m=1;
            //벗어나지 않는 범위
            while(i+m<park.size() && j+m<park[i].size()){
                
                //왼쪽 상단부터 순회하기 때문에 오른쪽 대각선으로만 판단
                int dx = 0, dy = 0;
                while (park[i + dy++][j+m] == "-1" && dy <= m);
                while (park[i+m][j + dx++] =="-1" && dx <= m);
                if (dy != dx || dy != m+1) break;
                
                m++;
            }
              max = max > m ? max : m;
              
        }
    }
    for (int i = mats.size() - 1; i >= 0; i--) {
        if (mats[i] <= max) return mats[i];
    }
    
    return answer;
    
}
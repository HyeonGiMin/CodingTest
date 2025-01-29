//로또의 최고 순위와 최저 순위  https://school.programmers.co.kr/learn/courses/30/lessons/77484
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getLank(int match){
    switch(match){
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    //현재 맞은 수에서 noneCount가 다 맞을 경우가 최대 
    //현재 맞은 수에서 noneCount가 다 틀릴 경우가 최소
    int curMatchCnt=0;
    int noneCount =0;
    //순서와는 상관 없다.
    
    for(int i=0;i<lottos.size();i++){
        if(lottos[i] == 0){
            noneCount++;
        }
        //win_nums에 있는 번호가 lottos에 있는지 확인
        else if(count(win_nums.begin(),win_nums.end(),lottos[i])>0){
            curMatchCnt++;
        }
    }
    
    //0은 모르는 번호    
    
    answer.push_back(getLank(curMatchCnt+noneCount));
    answer.push_back(getLank(curMatchCnt));
    
    
    return answer;
}

int main(){
    solution({44, 1, 0, 0, 31, 25},{31, 10, 45, 1, 6, 19});
}
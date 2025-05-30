//[PCCE 기출문제] 9번 / 이웃한 칸
//https://school.programmers.co.kr/learn/courses/30/lessons/250125
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    vector<int> dh = {0,1,-1,0};
    vector<int> dw = {1,0,0,-1};
    
    //4개의 값을 확인
    for(int i=0;i<4;i++){
        int h_check = h + dh[i];
        int w_check = w + dw[i];
        
        if(h_check>=0 &&h_check<n &&w_check>=0 &&w_check<n){
            if(board[h][w] == board[h_check][w_check])
                answer++;
        }
    }
    
    
    return answer;
}
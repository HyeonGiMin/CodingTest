//크레인 인형뽑기 게임
//https://school.programmers.co.kr/learn/courses/30/lessons/64061
//예시로 든 2차원 배열은 각 가로 값이라 j가 앞으로 나와야 한다
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    
    //back()은 마지막 원소 가져오기
    //pop_back()은 마지막 원소 제거
    for(int i=0;i<moves.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[j][moves[i]-1] !=0){
                if(!basket.empty()&&basket.top() == board[j][moves[i]-1]){
                    basket.pop();
                    board[j][moves[i]-1]=0;
                    answer+=2;
                    break; 
                }else{
                    basket.push(board[j][moves[i]-1]);
                    board[j][moves[i]-1]=0;
                    break; 
                }
            }
        }
    }
    
    return answer;
}

int main(){
    vector<vector<int>> a = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> b = {1,5,3,5,1,2,1,4};
    int result = solution(a, b);
}
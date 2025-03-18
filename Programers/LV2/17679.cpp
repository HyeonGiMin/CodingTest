//[1차] 프렌즈4블록
//https://school.programmers.co.kr/learn/courses/30/lessons/17679
//reference: https://non-stop.tistory.com/479
#include <string>
#include <vector>
#include <set>

using namespace std;

bool checkValue(int i,int j, vector<string>& board){
    //현재 위치의 값
    char c = board[i][j];
    if(c !='x' && board[i][j+1] == c && board[i+1][j] == c && board[i+1][j+1] == c)
        return true;
    else
        return false;
}

int remove(int m,int n,vector<string>& board){
    //중복없이 넣도록 set 사용
    set<pair<int,int>> v;
    //오른쪽 ,대각선,아래 값 확인
    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            //2x2 값이 있을 경우 
            if(checkValue(i,j,board)){
                v.insert({i,j});
                v.insert({i,j+1});
                v.insert({i+1,j});
                v.insert({i+1,j+1});
            }
        }
    }
    
    for(auto p:v){
        board[p.first][p.second] = 'x';
    }
    
    return v.size();
}

void move(int m,int n,vector<string>& board){
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(board[i][j]=='x'){ //지워진 값일 경우
                int y=i;
                while(y>=0){
                    if(board[y][j]!='x'){
                        board[i][j]=board[y][j];
                        board[y][j]='x';
                        break;
                    }else{
                        y--;
                    }
                }
                
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    //지워질 대상이 없을때 까지 계속
    while(true){
        int removedCnt = remove(m,n,board);
        
        if(removedCnt !=0){
            answer+=removedCnt;
            //이동
            move(m, n, board);
        }else{
            break;
        }        
    }
    
    return answer;
}
//키패드 누르기
//https://school.programmers.co.kr/learn/courses/30/lessons/67256
//referece: https://hwan-shell.tistory.com/350

#include <string>
#include <vector>
#include <map>
using namespace std;
map<int,pair<int,int>> keypad={
    {1,{0,0}}, {2,{1,0}}, {3,{2,0}},
    {4,{0,1}}, {5,{1,1}}, {6,{2,1}},
    {7,{0,2}}, {8,{1,2}}, {9,{2,2}},
    {10,{0,3}},{0,{1,3}}, {11,{2,3}},
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 11;
    for(auto n: numbers){
        if( n == 3 || n == 6 || n == 9){
            answer+="R";
            right=n;
        }else if(n == 1 || n == 4 || n == 7){
            answer+="L";
            left=n;
        }else{
            int left_loc = abs(keypad[n].first-keypad[left].first)+abs(keypad[n].second-keypad[left].second);
            int right_loc = abs(keypad[n].first-keypad[right].first)+abs(keypad[n].second-keypad[right].second);
            
            //같은 경우 손잡이를 따진다
            if(left_loc==right_loc){
                if(hand=="left"){
                    answer+="L";
                    left=n;
                }else{
                    answer+="R";
                    right=n;
                }
            }else if(left_loc<right_loc){
                answer+="L";
                left=n;
            }else{
                answer+="R";
                right=n;
            }
            
        }
    }
    
    
    return answer;
}
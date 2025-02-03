//성격 유형 검사하기
//https://school.programmers.co.kr/learn/courses/30/lessons/118666
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//map에 각 유형별 점수를 초기화
map<char, int> surveyMap = {
    {'R', 0},
    {'T', 0},
    {'C', 0},
    {'F', 0},
    {'J', 0},
    {'M', 0},
    {'A', 0},
    {'N', 0},
};
// => map 말고 2차원 배열로 MBTI 별로 그룹 했으면 더 나았을듯


void addSuervey(string& answer,char a,char b){
         if(surveyMap[a] > surveyMap[b]){
            answer+=a;
        }else if(surveyMap[a] < surveyMap[b]){
            answer+=b;
        }else{
            //같을 경우 
            char c = a<b ? a:b;
            answer+=c;
        }
    
    
}


string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    
    int score[] = {3,2,1,0,1,2,3};
    
    //앞에 나오는게 비동의시 점수, 뒤에 나오는게 동의 시 점수
    for(int i=0;i<survey.size();i++)
    {
        char negative = survey[i][0];
        char positive = survey[i][1];
        
      
        int choice = choices[i];
        int choiceValue = score[choice-1];
        //Positive
        if(choice >4 ){
            surveyMap[positive]+=choiceValue;
        }else if(choice<4){ //Negative
            surveyMap[negative]+=choiceValue;
        }
        
    }
    

    //1번지표 
    addSuervey(answer,'R','T');
    //2번지표
    addSuervey(answer,'C','F');
    //3번지표
    addSuervey(answer,'J','M');
    //4번지표
    addSuervey(answer,'A','N');
    
  
    
    return answer;
}
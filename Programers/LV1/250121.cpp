//[PCCE 기출문제] 10번 / 데이터 분석
//https://school.programmers.co.kr/learn/courses/30/lessons/250121
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    string dataIdx[] = {"code", "date", "maximum", "remain"};
    int extIdx,sortIdx;
    
    //ext < val_ext
    //ext의 Idx 구하기
    //sort대상의Idx 구하기
    for(int i=0;i<4;i++){
        if(dataIdx[i]==ext){
            extIdx=i;
        }
      if(dataIdx[i]==sort_by){
           sortIdx=i;   
      }
    }
    
    for(vector<int> v:data){
        if(v[extIdx]<val_ext){
            answer.push_back(v);
        }
    }
    
    //sort_by에 해당 하는 값 기준으로 오름차순 정렬
    sort(answer.begin(), answer.end(), [&](vector<int> a, vector<int> b) {
        return a[sortIdx]<b[sortIdx];
    });
    
    return answer;
}
//최솟값 만들기
//https://school.programmers.co.kr/learn/courses/30/lessons/12941
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    //큰수 x 작은수 가 최소
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),less<int>());

    
    for(int i=0;i<A.size();i++){
        answer +=(A[i]*B[i]);
    }
    
    return answer;
}
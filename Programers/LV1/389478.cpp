//택배 상자 꺼내기
//https://school.programmers.co.kr/learn/courses/30/lessons/389478
//reference: https://rosoa0475.tistory.com/382

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<int> v;
    
    //시작지점규칙 w*2-1
    for(int i=1;i<w*2;i+=2){
        v.push_back(i);
    }
    
    //역순으로 변경
    sort(v.rbegin(), v.rend());
    
    int floor = num/w - (num%w==0?1:0);
    

    int nextNum=num;
    while(nextNum<=n){
        int addNum;
        //위치 확인
        addNum = nextNum%w==0?w:nextNum%w;
        nextNum = nextNum+v[addNum-1];
        answer++;
        floor++;
    }
    
    return answer;
}

// 몇층인지가 중요한 문제
// #include <string>
// #include <vector>

// using namespace std;

// int solution(int n, int w, int num) {
//     int answer = 0;
//     while(num<=n){answer++;num+=(w-1-(w+num-1)%w)*2+1;}
//     return answer;
// }

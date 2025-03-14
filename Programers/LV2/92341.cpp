//주차 요금 계산
//https://school.programmers.co.kr/learn/courses/30/lessons/92341
//reference: https://wadekang.tistory.com/8 https://ggjjdiary.tistory.com/100
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,vector<string>> parking; //차량 번호, 입출차 시간
    
    //01. 각 차량 번호 별 입출차 시간을 Map으로 만든다.
    for(string record:records){
        stringstream ss(record);
        string time = "";
        string car_num = "";
        string in_out = "";

        ss >> time;
        ss >> car_num;
        ss >> in_out;

        parking[car_num].push_back(time); 
    }
    
    //02. 출자 내역을 확인
    for(auto it:parking){
        //만약 입출차 내역이 홀수라면 마지막에 23:59 추가
        if(it.second.size() % 2 ==1){
            it.second.push_back("23:59");
        }
        
        int total = 0;
  
        for(int i=0;i<it.second.size()-1;i+=2){
            // i 는 입차 i+1은 출차 
            int in_hour = stoi(it.second[i].substr(0,2));
            int in_min = stoi(it.second[i].substr(3,2));
            
            int out_hour = stoi(it.second[i+1].substr(0,2));
            int out_min = stoi(it.second[i+1].substr(3,2));
            
            //총 분으로 변환
            total+=((out_hour-in_hour)*60 + (out_min-in_min));
        
        }
        
        int price = fees[1]; //기본 요금
        
        //기본 시간을 초과할 경우
        if(total>fees[0]){
            price += ceil((total-fees[0]) / (double)fees[2]) * fees[3];
        }
        
         answer.push_back(price);
        
    }
    
    
    return answer;
}
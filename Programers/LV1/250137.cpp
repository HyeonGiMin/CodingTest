//[PCCP 기출문제] 1번 / 붕대 감기
//https://school.programmers.co.kr/learn/courses/30/lessons/250137
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int castringTime = bandage[0];
    int healPerSec= bandage[1];
    int addtional = bandage[2];
    int maxHealth = health;
    map<int,int> attackMap; // 공격시간,피해랑
    
    //01.attacks를 map으로 만든다.
    for(auto attack:attacks){
        attackMap.insert(make_pair(attack[0],attack[1]));
    }
    
    //
    int maxTime = attackMap.rbegin()->first;
    int seqSuccess = 0;
    
    //마지막 공격시간까지 순회
    for(int i =0; i<=maxTime;i++){
        //map에 값이 있으면 공격당한것
        if(attackMap.find(i) != attackMap.end()){
            health-= attackMap[i] ;
            //연속성공 초기화 
            seqSuccess=0;
        }else{
            health+=healPerSec;
            seqSuccess++;
        }
        
        //캐릭터의 체력이 0이하가 되면 종료
        if(health<=0){
            answer=-1;
            break;
        }
            
        if(seqSuccess == castringTime){
            health+=addtional;
            //연속성공 초기화 
            seqSuccess=0;
        }
        
        //현재 체력이 최대 체력보다 커지면 최대 값으로 맞춤
        if(health>maxHealth){
            health=maxHealth;
        }
        answer=health;
    }
    
    return answer;
}
//[1차] 캐시
//https://school.programmers.co.kr/learn/courses/30/lessons/17680
//reference: https://excited-hyun.tistory.com/174
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>   

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    if(cacheSize==0){
        return cities.size()*5;
    }
    
    for(auto city:cities){
        // 대문자로 변환
        transform(city.begin(), city.end(), city.begin(), ::toupper);
        
        //cache에 값이 있는지 확인 
        auto lt= find(cache.begin(),cache.end(),city);
        
        //값이 있는 경우 
        if(lt != cache.end()){
            //기존 캐시 데이터 제거 후 마지막으로 다시 추가
            cache.erase(lt);
            cache.push_back(city);
            answer+=1;
        }else{ //값이 없을 경우 
            //캐시 사이즈를 보고
            
            //자리가 있을 경우 맨 뒤에 추가
            if(cache.size()<cacheSize){
                cache.push_back(city);
            }else{ 
                //자리가 없을 경우 오래된거 제거 후 추가
                cache.erase(cache.begin());
                cache.push_back(city);
            }
            
            answer+=5;
        }
    }
    
    
    
    return answer;
}
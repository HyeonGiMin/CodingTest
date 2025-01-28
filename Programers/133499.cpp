//옹알이(2)
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(auto s:babbling){
        bool canSpeak =true;
        int flag = 0;
        
        for(int i=0;i<s.size();i++){
            if(s.substr(i,3) == "aya" && flag!=1){
                flag=1;
                i+=2;
            }else if(s.substr(i,2) == "ye" && flag!=2){
                flag=2;
                i+=1;
            }else if(s.substr(i,3) == "woo" && flag!=3){
                flag=3;
                i+=2;
            }else if(s.substr(i,2) == "ma" && flag!=4){
                flag =4;
                i+=1;
            }else{
                canSpeak=false;
                break;
            }
        }
        
        if(canSpeak)
            answer++;
        
    }
    
    return answer;
}
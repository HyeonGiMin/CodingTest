#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    sort(wallet.begin(),wallet.end());
    
    int wMax = wallet[1];
    int wMin = wallet[0];
    
    while(true){
        sort(bill.begin(),bill.end());
        
        int bMax = bill[1];
        int bMin =  bill[0];
            
        //bill의 가장 작은 값이 wallet의 가장 작은 값 보다 작고 
        //bill의 가장 큰 값이 wallert의 가장 큰 값 보다 작으면 된다.
        if(bMin<=wMin && bMax<=wMax)
            break;
        
        // 큰 값을 절반으로 줄인다.
        bill[1] /=2;
        answer++;
        
        
    }
    
    return answer;
}
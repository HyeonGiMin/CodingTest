//대충 만든 자판
//https://school.programmers.co.kr/learn/courses/30/lessons/160586
// #include <string>
// #include <vector>
// #include <algorithm>
// #define INF 123456789
// using namespace std;


// int getCount(vector<string> keymap,char target){
//     int minIdx=INF;
//     for(auto s :keymap){
//         if(find(s.begin(),s.end(),target)!=s.end()){
//             int idx = find(s.begin(),s.end(),target)-s.begin();
//             if(minIdx>idx){
//                 minIdx=idx;
//             }
//         }
//     }
    
//     if(minIdx ==INF)
//         return 0;
//     else
//         return minIdx+1;
// }

// vector<int> solution(vector<string> keymap, vector<string> targets) {
//     vector<int> answer;
    
//     //어떤 키를 했는지는 중요하지 않음
//     //누르는 횟수
    
//     for(auto target:targets){
//         int count=0;
//         for(auto c : target){
//             int r = getCount(keymap,c);
//             count+=r;
//         }
        
//         if(count ==0)
//             answer.push_back(-1);
//         else
//             answer.push_back(count);
//     }
    
    
//     return answer;
// }

// int main(){
//     vector<string> keymap = {"ABACD","BCEFD"};
//     vector<string> targets = {"ABCD","AABB"};
//     vector<int> result = solution(keymap,targets);
//     for(auto r:result){
//         printf("%d\n",r);
//     }
//     return 0;
// }


//Insight : https://im-gonna.tistory.com/13
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    //각 값을 map에 저장 
    map<char,int> m;
    
    //keymap[i][j] 의 값
    for(int i=0;i<keymap.size();i++){
        for(int j=0;j<keymap[i].size();j++){
            //값이 없을 경우 
            if(m.find(keymap[i][j]) == m.end()){
                m.insert(make_pair(keymap[i][j],j+1)); //j+1번 눌러야 현재 문자가 나온다
            }else{
                //값이 있는경우 비교
                if(m[keymap[i][j]]>j+1){
                    m[keymap[i][j]] = j+1;  //더 작은 값으로 대체 
                }
            }
        }
    }
    
    int count;
    
    for(int i=0;i<targets.size();i++){
        count=0;
        for(int j=0;j<targets[i].size();j++){
            if(m.find(targets[i][j]) == m.end()){
                count = -1;
                break;
            }
            char c = targets[i][j];
            count+=m[c];
        }
        answer.push_back(count);
    }
    
    return answer;
}
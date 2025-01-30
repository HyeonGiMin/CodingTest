//둘만의 암호
//https://school.programmers.co.kr/learn/courses/30/lessons/155652
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string s, string skip, int index) {
    string answer = "";
    std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                 'u', 'v', 'w', 'x', 'y', 'z'};
    
    //letters에서 skip에 해당 하는 값을 제거 
    for(int i=0; i<skip.size();i++){
        letters.erase(std::remove(letters.begin(), letters.end(), skip[i]), letters.end());
    }
    
    
    for(int i=0;i< s.size();i++){
        //letter에서 일치하는 값의 idx를 찾은뒤 +5
        int idx = find(letters.begin(), letters.end(), s[i]) - letters.begin();
        
        //Loop를 돌도록 나머지 값으로 idx처리 하도록
        idx = (idx+index)%letters.size();
        
        
        answer+=letters[idx];
        
        
    }
    return answer;
}
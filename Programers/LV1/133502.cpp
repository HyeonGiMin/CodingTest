//햄버거 만들기
//https://school.programmers.co.kr/learn/courses/30/lessons/133502

//처음 풀이, 일부 항목에서 시간 초과 발생
// #include <string>
// #include <vector>

// using namespace std;

// bool canPack(vector<int>& vec){
//     int startIdx=-1;
//     bool can =false;
//     for(int i=0;i<vec.size()-3;i++){
//         //요소가 순서대로 뒤에 있는지 확인 있을 경우 can을 true로 
//         if(vec[i]==1 && vec[i+1]==2 && vec[i+2]==3 && vec[i+3] ==1){
//             can=true;
//             startIdx=i;
//             break;
//         }
//     }
    
//     if(can){
//          //can이 true일 경우 vector에서 요소를 제거 
//         vec.erase(vec.begin()+startIdx,vec.begin()+startIdx+4);
//     }
   
    
//     return can;
// }


// int solution(vector<int> ingredient) {
//     int answer = 0;
//     //vector erase를 통해 특정 범위 값을 제거 
//     //빵 =1, 야채 =2, 고기 =3
    
//     //재료가 3개 이하 일 경우 반복문 해제
//     while(ingredient.size()>3){
        
//         //남은 재료에서 순차적으로 값이 나오는게 있는지 확인 
//         bool result=canPack(ingredient);
        
//         if(!result)
//             break;
//         else
//             answer++;
//     }
    
//     return answer;
// }


//문자열로 구성해서 사용

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string str="";
    
    for(int i:ingredient){
        char c = i+'0';
        str+=c;
    }
    
    int pos =0;
    
    while(true){
        //포장이 가능한지 확인 
        size_t ret = str.find("1231", pos);
        
        //불가능 하면 break;
        if (ret == std::string::npos)
            break;
        
        //문자열에서 해당 영역 제가
        str.erase(ret, 4);
        
        if (ret > 2)
            pos = ret - 3;
        answer++;
    }
    
    return answer;
}
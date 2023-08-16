class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer ;
        for(int i= 1 ; i<= n ; i++){
            if(i%3 == 0 && i%5 != 0){
                answer.push_back("Fizz");
            }else if(i%3 != 0 && i%5 == 0){
                answer.push_back("Buzz");
            }else if(i%3 == 0 && i%5 == 0){
                answer.push_back("FizzBuzz");
            }else{
                
                answer.push_back(to_string(i));
            }
        }
        return answer ;
    }
};
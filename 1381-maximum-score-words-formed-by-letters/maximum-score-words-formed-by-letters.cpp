class Solution {
public:

    int rec(int i,vector<string>& words, vector<char>& letters, vector<int>& score,map<char,int>&remainingLetters){
        if(i>=words.size()) return 0;
        bool checker= true;
        map<char,int>remainingLetters2 = remainingLetters;
            int temp = 0;
        for(auto &it:words[i]){
            temp+=score[it-'a'];
            if(remainingLetters.find(it)==remainingLetters.end()){
                checker =false;
            }
            else{
                remainingLetters[it]--;
                if(remainingLetters[it]<0) checker = false;
            }
        }
        if(checker){
            
            return max(temp + rec(i+1,words,letters,score,remainingLetters),rec(i+1,words,letters,score,remainingLetters2));
        }
        return rec(i+1,words,letters,score,remainingLetters2);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        map<char,int>remainingLetters;
        for(auto &it:letters) remainingLetters[it]++;



        return rec(0,words,letters,score,remainingLetters);

    }
};
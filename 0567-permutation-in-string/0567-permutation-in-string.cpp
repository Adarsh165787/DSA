// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
        
//         if (s1.size() > s2.size())
//             return false;

//         sort(s1.begin(), s1.end());

//         int k = s1.size();

//         for (int i = 0; i <= s2.size() - k; i++) {
            
//             string temp = s2.substr(i, k);

//             sort(temp.begin(), temp.end());

//             if (temp == s1)
//                 return true;
//         }

//         return false;
//     }
// };




















class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> freq1(26,0),freq2(26,0);
        for(auto it : s1) {
            freq1[it-'a']++;
        }
        int k = s1.size();
        for(int i =0;i<k;i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1 == freq2) return true;
        for(int i =k;i<s2.size();i++){
            freq2[s2[i] -'a']++;
            freq2[s2[i - k] - 'a']--;
            if(freq1 == freq2) return true;
        }
        return false;
    }
};
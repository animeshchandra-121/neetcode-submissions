class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> ans;
        vector<int> prefix_score(n + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++){
            bool ok = vowels.count(words[i][0]) &&
                      vowels.count(words[i].back());

            prefix_score[i + 1] = prefix_score[i] + (ok ? 1 : 0);
        }
        for(vector<int> query: queries){
            int l = query[0], r = query[1];
            ans.push_back(prefix_score[r + 1] - prefix_score[l]);
        }
        return ans;
    }
};
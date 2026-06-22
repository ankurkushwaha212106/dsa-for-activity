class Solution {
public:
    unordered_map<string, int> level;
    vector<vector<string>> ans;

    void dfs(string word, string beginWord,
             vector<string>& path) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        int steps = level[word];

        for (int i = 0; i < word.size(); i++) {
            string original = word;

            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if (level.count(word) &&
                    level[word] == steps - 1) {

                    path.push_back(word);
                    dfs(word, beginWord, path);
                    path.pop_back();
                }
            }

            word = original;
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        unordered_set<string> st(
            wordList.begin(),
            wordList.end());

        queue<string> q;

        q.push(beginWord);
        level[beginWord] = 0;

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int steps = level[word];

            for (int i = 0; i < word.size(); i++) {

                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    temp[i] = ch;

                    if (st.count(temp)) {

                        q.push(temp);
                        level[temp] = steps + 1;

                        st.erase(temp);
                    }
                }
            }
        }

        if (!level.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};
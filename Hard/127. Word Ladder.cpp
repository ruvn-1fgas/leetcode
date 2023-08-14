class Solution
{
public:
    int ladderLength(string begin_word, string end_word, vector<string> &word_list)
    {
        unordered_set<string> wordSet(word_list.begin(), word_list.end());
        if (wordSet.find(end_word) == wordSet.end())
            return 0;
        unordered_map<string, int> visited;
        queue<string> q;
        q.push(begin_word);
        visited[begin_word] = 1;
        while (!q.empty())
        {
            string word = q.front();
            q.pop();
            for (int i = 0; i < word.size(); i++)
            {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    newWord[i] = ch;
                    if (wordSet.find(newWord) != wordSet.end() && visited.find(newWord) == visited.end())
                    {
                        if (newWord == end_word)
                            return visited[word] + 1;
                        q.push(newWord);
                        visited[newWord] = visited[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
};
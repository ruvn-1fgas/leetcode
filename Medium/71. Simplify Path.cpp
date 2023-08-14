class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> v;
        string s = "";
        path += "/";
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == '/')
            {
                if (s == "..")
                {
                    if (!v.empty())
                        v.pop_back();
                }
                else if (s != "." && s != "")
                    v.push_back(s);
                s = "";
            }
            else
                s += path[i];
        }
        string res = "";
        for (int i = 0; i < v.size(); i++)
            res += "/" + v[i];
        if (res == "")
            res = "/";
        return res;
    }
};
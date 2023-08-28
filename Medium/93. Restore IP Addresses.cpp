class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        string ip;

        for (int a = 1; a < 4; a++)
        {
            for (int b = 1; b < 4; b++)
            {
                for (int c = 1; c < 4; c++)
                {
                    for (int d = 1; d < 4; d++)
                    {
                        if (a + b + c + d == s.length())
                        {
                            uint64_t A = stoull(s.substr(0, a));
                            uint64_t B = stoull(s.substr(a, b));
                            uint64_t C = stoull(s.substr(a + b, c));
                            uint64_t D = stoull(s.substr(a + b + c, d));

                            if (A <= 255 && B <= 255 && C <= 255 && D <= 255)
                            {
                                ip = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                                if (ip.length() == s.length() + 3)
                                {
                                    result.push_back(ip);
                                }
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
};
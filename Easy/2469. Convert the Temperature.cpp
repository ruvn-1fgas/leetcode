class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        return {celsius + 273.15, celsius * 9 / 5 + 32};
    }
};
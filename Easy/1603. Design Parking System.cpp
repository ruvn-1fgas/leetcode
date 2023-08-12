class ParkingSystem
{
public:
    ParkingSystem(int big, int medium, int small)
        : capacities({{1, big}, {2, medium}, {3, small}})
    {
    }

    bool addCar(int carType)
    {
        auto& capacity = capacities[carType];
        if (capacity > 0)
        {
            capacity--;
            return true;
        }
        return false;
    }

private:
    std::unordered_map<int, int> capacities;
};
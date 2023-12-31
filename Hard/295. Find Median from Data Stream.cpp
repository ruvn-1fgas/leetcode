class MedianFinder
{
public:
    MedianFinder()
    {

    }

    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        return maxHeap.size() == minHeap.size() ? (maxHeap.top() + minHeap.top()) / 2.0 : (maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top());
    }
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

};
class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    double median;
    
    int compare() {
        int m = minHeap.size();
        int n = maxHeap.size();
        if (m < n) {
            return 1;
        } else if (m > n) {
            return -1;
        } else {
            return 0;
        }
    }
public:

    MedianFinder() {
        median = 0;
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        switch(compare()) {
            case 0:
                if (num < median) {
                    maxHeap.push(num);
                    median = maxHeap.top();
                } else {
                    minHeap.push(num);
                    median = minHeap.top();
                }
                break;
                
            case 1:
                // More elements in max heap
                if (num < median) {
                    // This number goes into the max heap
                    // and max heap's  top goes into min heap to rebalance
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(temp);
                    maxHeap.push(num);
                } else {
                    minHeap.push(num);
                }
                
                median =(double) (minHeap.top()+maxHeap.top()) / (double)2;
                break;
                
            case -1:
                //More elements in the min heap
                if (num < median) {
                    maxHeap.push(num);
                } else {
                    int temp = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(temp);
                    minHeap.push(num);
                }
                
                median = (double)(minHeap.top() + maxHeap.top()) / (double)2;
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return median;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
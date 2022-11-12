class MedianFinder {
private:
    priority_queue<int>largest; //maxHeap
    priority_queue<int,vector<int>,greater<int>>smaller; //minHeap
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(largest.empty() || num <= largest.top()){
            largest.push(num);
        }
        else{
            smaller.push(num);
        }
        
        if(largest.size()>smaller.size()+1){
            int temp=largest.top();
            largest.pop();
            smaller.push(temp);
            
        }
        else if(largest.size()<smaller.size()){
            int temp=smaller.top();
            smaller.pop();
            largest.push(temp);
        }
        
        return;
    }
    
    double findMedian() {
        if(largest.size()==smaller.size()){
            return (largest.top()+smaller.top())/2.0;
        }
        else{
            return (largest.top()/1.0);
        }
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
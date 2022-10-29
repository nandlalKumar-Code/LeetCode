class Flower{
    public : 
    int growTime, plantTime;
    Flower(int growTime, int plantTime){ 
        this->growTime = growTime; this->plantTime = plantTime; 
    }
};

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime)
    {
        vector<Flower>flowers;
        int flowerCount = plantTime.size();
        
        for (int i = 0; i < flowerCount; i++) 
            flowers.push_back(Flower(growTime[i], plantTime[i]));
       
        sort(flowers.begin(), flowers.end(), [](Flower& a, Flower& b)->bool{
            return (a.growTime > b.growTime);
        });
        
        
        int currTime = 0, mxBloomTime = 0;
        for (Flower flower : flowers)
        {
            currTime += flower.plantTime; 
            int bloomTime = currTime + flower.growTime; 
            
            mxBloomTime = max(mxBloomTime, bloomTime);
        }
        
        return mxBloomTime;
        
    }
};
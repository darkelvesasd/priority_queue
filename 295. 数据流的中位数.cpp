struct cmp
{
    bool operator()(int a,int b)
    {
    return     a > b;
    }
};
class MedianFinder {
public:
    priority_queue<double, vector<double>>bq;
    priority_queue<double, vector<double>,cmp>sq;
    MedianFinder() {

    }

    void addNum(int num) {
        int bn = bq.size();
        int sn = sq.size(); 
        if (bn == sn)
        {
            if (bq.empty()||num <= sq.top())
            {
                bq.emplace(num);
            }
            else
            {
                bq.emplace(sq.top());
                sq.pop();
                sq.emplace(num);
            }
        }
        else
        {
            if (num >= bq.top())
            {
                sq.emplace(num);
            }
            else
            {
                sq.emplace(bq.top());
                bq.pop();
                bq.emplace(num);
            }
        }
    }

    double findMedian() {
        if ((bq.size() + sq.size()) % 2)
        {
            return bq.top();
        }
        return  (bq.top() + sq.top()) / 2;
    }
};

class KthLargest {
public:
    priority_queue<int, vector<int>,greater<int>>pq;
    int key;
    KthLargest(int k, vector<int>& nums):key(k)
    {
        for (auto a : nums)
        {
            add(a);
        }
    }

    int add(int val) {
        pq.emplace(val);
        if (pq.size()>key)
        {
            pq.pop();
        }
        return pq.top();
    }
};

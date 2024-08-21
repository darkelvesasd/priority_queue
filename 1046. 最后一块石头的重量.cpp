class Solution {
public:
   int lastStoneWeight(vector<int>& stones) {
    if (!stones.size())
    {
        return 0;
    }
    int t1;
    int t;
    priority_queue<int>pq;
    for (auto a : stones)
    {
        pq.emplace(a);
    }
    while (!pq.empty())
    {
        t = pq.top();
        pq.pop();
        if (!pq.empty())
        {
            t1 = pq.top();
            pq.pop();
        }
        else
        {
            break;
        }
        t = abs(t - t1);
        if (t != 0)
        {
            pq.emplace(t);
        }
    }
    return t;
}
};

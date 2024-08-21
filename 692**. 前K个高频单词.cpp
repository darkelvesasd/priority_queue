class Solution {
public:
  struct cmp
{
    bool operator()(pair<string,int>a1,pair<string,int>a2)
    {
        if (a1.second == a2.second)
        {
            return a1.first < a2.first;
        }
        return a1.second > a2.second;
    }
};
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> hash;
    priority_queue<pair<string, int>, vector<pair<string, int>>,cmp> pq;
    vector<string>ret;
    for (auto a : words)
    {
        hash[a]++;
    }
    for (auto a:hash)
    {
        pq.emplace(a);
         if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        ret.emplace_back(pq.top().first);
        pq.pop();
    }
     reverse(ret.begin(),ret.end());
    return ret;
}
};

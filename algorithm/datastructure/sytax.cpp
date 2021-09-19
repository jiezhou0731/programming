// custom sort
sort( a.begin( ), a.end( ), [ ]( const auto& x, const auto& y )
{
   if (x[0] != y[0]) return x[0] < y[0];
   return x[1] > y[1];
});

sort(pairs.begin(), pairs.end(), cmp);
static bool cmp(vector<int>& a, vector<int>&b) {
    return a[1] < b[1];
}


priority_queue<int, vector<int>, greater<int>> que;

// hash can be ineffcient better use m*r + c
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};
unordered_map<int, int, pair_hash> a;
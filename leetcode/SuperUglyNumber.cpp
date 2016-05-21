struct UglyNum
{
    int base;
    int idx;
    long res;
    UglyNum(int b, int i, long r): base(b), idx(i), res(r){};
};
struct UglyCmp
{
    bool operator()(const UglyNum &u1, const UglyNum &u2)
    {
        return u1.res > u2.res;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<UglyNum, vector<UglyNum>, UglyCmp> pq;
        pq.push(UglyNum(1,0,1));
        while(--n)
        {
            UglyNum u = pq.top();
            //cout << "Popped : ( " << u.base << ", " << u.idx << ", " << u.res << " )" << endl;
            pq.pop();
           // cout << "Pushed : ( " << u.res << ", " << u.idx << ", " << u.res * primes[u.idx] << " )" << endl;
            pq.push(UglyNum(u.res, u.idx, u.res * primes[u.idx]));

            if((u.base != 1 || u.idx != 0 || u.res != 1)&& u.idx+1 < primes.size()) {
                //cout << "Pushed Special: ( " << u.base << ", " << u.idx+1 << ", " << u.base * primes[u.idx+1] << " )" << endl;
                pq.push(UglyNum(u.base, u.idx+1, u.base * primes[u.idx+1]));
            }
        }
        return pq.top().res;
    }
};
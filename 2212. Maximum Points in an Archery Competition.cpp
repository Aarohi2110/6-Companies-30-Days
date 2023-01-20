typedef vector<int> vi;

class Solution {
private:
    int totalPoint(int mask) {
        int point= 0;
        for (int i=0; i < 12; ++i) {
            if (mask & (1<<i)) point += i;
        }
        return point;
    }
    
    int arrowsNeeded(int mask, vi &aliceArrows) {
        int arrows= 0;
        for (int i=0; i < 12; ++i) {
            if (mask & (1<<i)) {
                arrows += aliceArrows[i]+1;
            }
        }
        return arrows;
    }

public:
    vi maximumBobPoints(int numArrows, vi &aliceArrows) {
        int maxPoint= 0, maxMask;
        for (int mask=0; mask < (1<<12); ++mask) {
            if (totalPoint(mask) > maxPoint &&
                arrowsNeeded(mask, aliceArrows) <= numArrows) {
                maxPoint= totalPoint(mask);
                maxMask= mask;
            }
        }
        vi ret(12,0);
        int cnt= numArrows;
        for (int i=1; i < 12; ++i) {
            if (maxMask & (1<<i)) {
                ret[i]= aliceArrows[i]+1;
                cnt -= ret[i];
            }
        }
        ret[0]= cnt;
        return ret;
    }
};

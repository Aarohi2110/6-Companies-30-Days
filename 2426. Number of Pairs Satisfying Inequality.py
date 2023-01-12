from sortedcontainers import SortedList
class Solution(object):
    def numberOfPairs(self, nums1, nums2, diff):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type diff: int
        :rtype: int
        """
        dif=[x-y for x,y in zip(nums1,nums2)]
        ax=SortedList();
        res=0
        for i in dif:
            cnt=ax.bisect_right(i+diff)
            res+=cnt
            ax.add(i)
        return res    

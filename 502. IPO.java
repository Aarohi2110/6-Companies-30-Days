class Solution {
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        PriorityQueue<int[]> minHeapCapital = new PriorityQueue<>((a, b) -> (a[0] - b[0]));
        PriorityQueue<int[]> maxHeapProfits = new PriorityQueue<>((a, b) -> (b[1] - a[1]));

        for (int i = 0; i < Profits.length; i++) {
            minHeapCapital.add(new int[] {Capital[i], Profits[i]});
        }

        for (int i = 0; i < k; i++) {
            while (!minHeapCapital.isEmpty() && minHeapCapital.peek()[0] <= W) {
                maxHeapProfits.add(minHeapCapital.remove());
            }

            if (maxHeapProfits.isEmpty()) {
                break;
            }

            W += maxHeapProfits.remove()[1];
        }
        return W;
    }
}

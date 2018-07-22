/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> result = new ArrayList<Interval>();
        int i = 0;
        while (i < intervals.size()) {
            if (newInterval.start > intervals.get(i).end) {
                result.add(intervals.get(i));
            } else if (newInterval.end < intervals.get(i).start) {
                break;
            } else {
                if (newInterval.end < intervals.get(i).end) {
                    newInterval.end = intervals.get(i).end;
                }
                if (newInterval.start > intervals.get(i).start) {
                    newInterval.start = intervals.get(i).start;
                }
            }
            i ++;
        }
        result.add(newInterval);
        while (i < intervals.size()) {
            result.add(intervals.get(i));
            i ++;
        }
        return result;
    }
}
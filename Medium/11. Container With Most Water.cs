public class Solution
{
    public int MaxArea(int[] a)
    {
        int maxArea = 0;
        int left = 0, right = a.Length - 1;
        while (left < right)
        {
            maxArea = Math.Max(maxArea, Math.Min(a[left], a[right]) * (right - left));
            if (a[left] < a[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
}
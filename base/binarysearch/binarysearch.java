import java.util.Arrays;

public class binarysearch
{
    public static int rank(int key, int[] a)
    {
        int lo = 0;
        int hi = a.length - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (key < a[mid])
                hi = mid - 1;
            else if (key > a[mid])
                lo = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    
    public static void main(String[] args)
    {
        int[] whitelist =  args[0];
        Arrays.sort(whitelists);
        while (!System.in.isEmpty())
        {
            int key = System.in.read();
            if(rank(key, whitelist) == -1)
                System.out.println(key);
        }
        System.out.println(1);
    }
}

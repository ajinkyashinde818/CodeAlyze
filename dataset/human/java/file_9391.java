import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        //long start = System.currentTimeMillis();
        final long MOD = (long)Math.pow(10,9)+7;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count = 0;
        String ans = "No";
        for (int i = 0;i<n;++i)
        {
            int a = sc.nextInt();
            int b = sc.nextInt();

            if (a == b) ++count;
            else count = 0;

            if (count >= 3)
            {
                ans = "Yes";
                break;
            }
        }
        System.out.println(ans);
        sc.close();
//        long end = System.currentTimeMillis();
//        System.err.println((end-start)+"ms");
    }
}

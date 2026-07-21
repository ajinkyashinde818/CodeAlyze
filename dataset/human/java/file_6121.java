import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        //Compute c1 = new Compute();//calc

        int count = 0;
        boolean sw = false;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        double dMax = Double.MIN_VALUE;
        double dMin = Double.MAX_VALUE;
        //StringBuilder answer=new StringBuilder();

        //input
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();

        for (int i=0;i<=k;++i)
        {
            for (int j = 0;j<=k;++j)
            {
                int a=s-i-j;
                if (a<=k && a>=0)
                {
                    ++count;
                }
            }
        }
        System.out.println(count);
    }
}

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
        int n = sc.nextInt();
        long a[] = new long[n];
        for (int i=0;i<n;++i) a[i]=sc.nextLong();
        long b[] = new long[n];
        for (int i=0;i<n;++i) b[i]=sc.nextLong();
        long c[] = new long[n-1];
        for (int i=0;i<n-1;++i) c[i]=sc.nextLong();

        long ans=0;
        int bb=0;
        for (int i=0;i<n;++i)
        {
            int aa=(int)a[i];
            //System.out.println("aa="+aa);
            ans+=b[aa-1];
            if (i==0)
            {
                //System.out.println("bb="+bb);
                bb=aa;
            }
            else
            {
                //System.out.println("bb="+bb);
                if (bb==aa-1)
                {
                    if (aa-2>=0)ans+=c[bb-1];
                }
                bb=aa;
            }
            //System.out.println(ans);
        }
        //System.out.println(String.format("%.0f",answer));
        System.out.println(ans);
    }
}

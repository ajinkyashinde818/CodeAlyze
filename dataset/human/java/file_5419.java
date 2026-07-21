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
        int n=sc.nextInt();
        String ans[] = {"ABC","ARC"};
        //long n = sc.nextLong();

        if(n<1200)
        {
            System.out.println(ans[0]);
        }else
        {
            System.out.println(ans[1]);
        }

        sc.close();
    }
}

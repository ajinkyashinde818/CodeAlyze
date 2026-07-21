import java.util.*;

public class Main
{

    public static void main(String args[])
    {
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();

        int d1[] = new int[n];
        int d2[] = new int[n];

        for(int i = 0 ; i < n ; i++)
        {
            d1[i] = kb.nextInt();
            d2[i] = kb.nextInt();
        }

        int flag = 0;

        if(n >= 3)
        {
            int p1 = 0;
            int p2 = 1;
            int p3 = 2;

            while(p3 < n)
            {
                if(d1[p1] == d2[p1] && d1[p2] == d2[p2] && d1[p3] == d2[p3])
                {
                    flag = 1;
                    break;
                }

                p1++;
                p2++;
                p3++;
            }
        }

        if(flag == 1)
            System.out.println("Yes");
        else
            System.out.println("No");

    }
}

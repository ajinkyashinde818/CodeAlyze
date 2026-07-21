import java.util.*;
public class Main
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[][]=new int[n][2];
        for(int i=0;i<n;i++)
        {
            arr[i][0]=sc.nextInt();
            arr[i][1]=sc.nextInt();
        }
        for(int i=0;i<=n-3;i++)
        {
            boolean yes=true;
            for(int j=i;j<i+3;j++)
            {
                if(arr[j][0]!=arr[j][1])
                {
                    yes=false;
                    break;
                }
            }
            if(yes)
            {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}

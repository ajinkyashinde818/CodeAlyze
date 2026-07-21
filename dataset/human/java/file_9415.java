import java.util.*;
class Main {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] ar = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = sc.nextInt();
            ar[i] = sc.nextInt();
        }
        int c=0;
        int m=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==ar[i])
            {
                c++;
                if(i==n-1)
                {
                    if(c>=3)
                        System.out.println("Yes");
                }
            }
            else
            {
                if(c>=3)
                {
                    System.out.println("Yes");
                    break;
                }
                else
                    c=0;
            }
        }
        if(c<3)
            System.out.println("No");
        
    }
}

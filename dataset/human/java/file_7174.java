import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int A[] = new int[N+1];
        int max = 0;
        for(int i=0;i<N;i++)
        {
            A[i] = sc.nextInt();
        }
        A[N] = K;
        int sum = 0;
        for(int j=0;j<N-1;j++)
        {
            int sa = A[j]-A[j+1];
            if(sa<0)
            {
                sa = sa * (-1);
            }
            if(max<sa)
            {
                max = sa;
            }
            sum = sum + sa;
        }
        int last = A[N]-A[N-1]+A[0];
        if(max<last)
        {
            max = last;
        }
        sum = sum + last;
        System.out.println(sum - max);
        
    }
}

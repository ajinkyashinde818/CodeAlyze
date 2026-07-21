import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc  = new Scanner(System.in);
        
        int K = sc.nextInt();
        int N = sc.nextInt();
        
        int []A = new int[N];
        int []leng = new int[N];
        
        for (int i = 0; i < N; i++)
        {
            A[i] = sc.nextInt();
        }
        
        for (int i = 0; i < N; i++)
        {
            if ((i+1) == N)
            {
                leng[i] = A[0] + (K - A[i]); 
                break;
            }
            
            leng[i] = A[i+1] - A[i];
        }
        
        Arrays.sort(leng);
        
        int total = 0;
        for (int i = 0; i < N-1; i++)
        {
            total += leng[i];
        }
        
        System.out.println(total);
    }
}

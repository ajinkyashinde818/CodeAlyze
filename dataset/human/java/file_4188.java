import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int A[] = new int[n];
        int B[] = new int[n];
        int C[] = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = s.nextInt();
        }
        for (int i = 0; i < n; i++) {
            B[i] = s.nextInt();
        }
        for (int i = 0; i < (n-1); i++) {
            C[i] = s.nextInt();
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=B[i];
        }
        for(int i=0;i<n-1;i++){
            if((A[i]+1)==A[i+1]) {
                ans += C[A[i]-1];
            }
        }
        System.out.print(ans);
    }
}

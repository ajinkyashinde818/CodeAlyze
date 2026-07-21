import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int[] A = new int[N];
        long sum = 0L;
        boolean flag = true;
        for (int i=0;i<N;i++) {
            A[i] = Integer.parseInt(sc.next());
            sum += A[i];
        }

        if (sum%((long)N*(N+1)/2)!=0) flag=false;

        long val = sum/((long)N*(N+1)/2);
        for (int i=0;i<N-1;i++) {
            long tmp = val-(A[i+1]-A[i]);
            if (tmp<0 || tmp%N!=0) flag=false;
        }
        long tmp_last = val-(A[0]-A[N-1]);
        if (tmp_last<0 || tmp_last%N!=0) flag=false;

        if (flag) System.out.println("YES");
        else System.out.println("NO");
    }
}

import java.util.*;
        import java.lang.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long[] A = new long[N];
        int negElm = 0;
        long minAbs = Long.MAX_VALUE;
        long absSum = 0;
        for(int n=0; n<N; n++){
            A[n] = sc.nextLong();
            if(A[n]<0) negElm++;
            minAbs = Math.min(minAbs, Math.abs(A[n]));
            absSum += Math.abs(A[n]);
        }
        if(negElm%2==0) System.out.println(absSum);
        else System.out.println(absSum - minAbs*2);

    }
}

import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        long[] a = new long[N];
        long sum = 0;
        
        for(int i=0; i<N; i++) {
            a[i] = Long.parseLong(sc.next());
            sum += a[i];
        }
        long sunuke = a[0];
        long araiguma = sum-a[0];
        long min = sa(sunuke, araiguma);
        for(int i=1; i<N-1; i++) {
            sunuke += a[i];
            araiguma -= a[i];
            if(min > sa(sunuke, araiguma)) min = sa(sunuke, araiguma);
        }
        System.out.println(min);
    }   
    //差の絶対値
    static long sa(long a, long c) {
        if(a <= c) return c-a;
        else return a-c;
    }
}

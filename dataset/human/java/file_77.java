import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long a[] = new long[n];
        for (int i = 0; i < n; ++i){
            a[i] = in.nextLong();
        }


        for (int i = 0; i < n-1; ++i){
            if (a[i] < 0){
                a[i] = a[i]*(-1);
                a[i+1] = a[i+1]*(-1);
            }
        }
        Arrays.sort(a);
        if (Math.abs(a[0]) > a[1]){
            a[0] = a[0]*(-1);
            a[1] = a[1]*(-1);
        }

        long sum = 0;

        for (int i = 0; i < n; ++i){
            sum += a[i];
        }
        System.out.println(sum);
    }
}

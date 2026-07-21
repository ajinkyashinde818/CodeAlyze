import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        long[] a=new long[n+1];
        for (int i = 1; i <= n; i++) {
            a[i]=sc.nextLong()+a[i-1];
        }
        long ans=Long.MAX_VALUE; 
        for (int i = 1; i < n; i++) {
            long x=a[i];
            long y=a[n]-a[i];
            ans=min(ans,abs(x-y));
        }
        out.println(ans);
    }
}

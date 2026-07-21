import java.util.*;
import static java.lang.System.*;

public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n = sc.nextInt();
        long[] a = new long[n];
        long sum=0;
        int cnt=0;
        int zero=0;
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
            if(a[i]<0) cnt++;
            if(a[i]==0) zero++;
            sum+=Math.abs(a[i]);
        }
        long ans=0;
        for(int i=0;i<n;i++){
            // out.println(ans);
            ans=Math.max(ans,sum-2*Math.abs(a[i]));
        }
        if(cnt%2==0) ans=sum;
        if(cnt%2==1&&zero>0) ans=sum;
        out.println(ans);
	}
}

// int n = sc.nextInt();
// int[] array = new int[n];
// String s = sc.next();
// s.charAt(i)
// out.println();
// Math.min()

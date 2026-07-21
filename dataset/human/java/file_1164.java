import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        long[] llist = new long[n];
        long[] rlist = new long[n];
        long[] list = new long[n];
        for(int i=0;i<n;i++) list[i] = Long.parseLong(sc.next());
        for(int i=0;i<n;i++){
            if(i==0){
                llist[i] = list[i];
                rlist[n-i-1] = list[n-i-1];
            }else{
                llist[i] = llist[i-1] + list[i];
                rlist[n-i-1] = rlist[n-i] + list[n-i-1];
            }
        }
        long ans = Math.abs(llist[0] - rlist[1]);
        for(int i=0;i<n-1;i++){
            ans = Math.min(ans,Math.abs(llist[i] - rlist[i+1]));
        }
        System.out.println(ans);
    }
}

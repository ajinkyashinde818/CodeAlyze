import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] li = new long[n];
        for(int i = 0; i < n; i++){
            li[i] = sc.nextLong();
            if(i != 0){
                li[i] += li[i-1];
            }
        }
        long ans = Long.MAX_VALUE;
        for(int i = 1; i < n; i++){
            ans = Math.min(ans,Math.abs(li[n-1]-li[i-1]-li[i-1]));
        }
        System.out.println(ans);
    }
}

import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        long[] l = new long[N]; 
        long x = 0;
        long y = 0;
        long ans = 0;
        for(int i = 0;i < N;i++){  
            l[i] = sc.nextLong();
            if(i == 0)  x += l[i];
            else y += l[i];
        }
        ans = Math.abs(x-y);
        for(int i = 1;i < N-1;i++){
            x += l[i];
            y -= l[i];
            ans = Math.min(ans, Math.abs(x-y));
        }
        System.out.println(ans);
    }
}

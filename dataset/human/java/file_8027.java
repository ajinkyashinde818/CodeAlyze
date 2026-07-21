import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        long N = scan.nextLong();
        long M = scan.nextLong();
        long ans = 1;
        if(M%N==0){
            ans=M;
        }else if(N%M==0){
            ans=N;
        }else{
            for(long i=Math.min(N, M);i>1;i--){
                if(N%i==0 && M%i==0){
                    N/=i;
                    M/=i;
                    ans*=i;
                }
            }
            ans*=N*M;
        }
        System.out.println(ans);
    }
}

import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        long N=sc.nextLong();
        
        if(N%2==1){
            System.out.println(0);
            return ;
        }

        N/=2;
        long i=5;
        long ans=0;
        
        for(i=5;i<=N;i*=5){
            ans+=N/i;
        }
        
        System.out.println(ans);
    }
}

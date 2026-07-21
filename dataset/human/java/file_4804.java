import java.util.*;

 class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        long N = sc.nextLong();
        long S = 1;
        long ans =0;
        
        if(N%2==0) {
        	ans=N/10;
        	for(long i=50;i<=N;i=i*5) {
        		ans=ans+N/i;
        	}
        } else {
        	ans = 0;
        }
        System.out.println(ans);	
        
        
    }
    

}

import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
      	long n = sc.nextLong();
      	int cnt = 0;
      	int bor = 1;
      	int ans = 0;
      	long div = 2;
      	while(true){
          if( n % div == 0 ){
            //System.out.println(n);
            n /= div;
            cnt++;
            if( cnt == bor ){
              ans++;
              cnt = 0;
              bor++;
            }
          }else{
            div++;
            cnt = 0;
            bor = 1;
            if( div > n ){
            	break;
            }
            if( div * div > n  ){
              div = n;
            }
          }
          
        }
      System.out.println(ans);
	}
}

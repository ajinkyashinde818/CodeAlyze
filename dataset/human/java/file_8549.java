import java.util.*;
 
public class Main {
	public static void main (String[] args) {
		Scanner in = new Scanner(System.in);
		
		int nam  = in.nextInt();
      	int nam2 = in.nextInt();
      	int min =  Math.min(nam,nam2);
      	int K    = in.nextInt();
      	int KK[] = new int[min+1];
      
      int cnt = 0;
      for(int i = 1;i <= min ;i++){
        if(nam % i==0 && nam2 % i==0){
        	cnt++;
          	KK[cnt] = i;
          }
        }
      
  		System.out.print(KK[cnt-K+1]);
      
	}
}

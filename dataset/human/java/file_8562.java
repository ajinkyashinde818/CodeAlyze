import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
	        int A = sc.nextInt();
	        int B = sc.nextInt();
	        int K = sc.nextInt();
	        int cnt = 0;
	        int ans = 0;
	        
	        for(int i=100; i>0; i--){
	        	if(A % i == 0){
	        		if(B % i == 0){
	        			cnt = cnt +1;
	        			if (K == cnt){
	        				ans = i;
	        				break;
	        			}
	        		}
	        	}
	        }
	        System.out.println(ans);
	}
}

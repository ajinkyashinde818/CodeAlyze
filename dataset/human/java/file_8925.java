import java.util.Arrays;
import java.util.Scanner;


class Main {
    public static void main(String[] args) {
    	
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();
        int Q = sc.nextInt();
        
        int[] ans = new int[101];
        
        for(int i = 100;i > 0 ; i--) {
        	if((A%i==0) && (B%i==0)) {
        		ans[i] = i;
        	}
        }
        Arrays.sort(ans);
        System.out.println(ans[101-Q]);
    }
}

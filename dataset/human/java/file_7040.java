import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k  = in.nextInt();
		int n  = in.nextInt();
		int[] ary = new int[n];
		for(int i=0; i<n; i++){
			ary[i] = in.nextInt();
		}
		int result = 10000000;
		for(int i=0; i<n; i++){
			if(i == 0){
				result = Math.min(result, ary[n-1]- ary[i]);
			} else {
				result = Math.min(result, k - ary[i] + ary[i-1]);
			}
		}
		System.out.println(result);
	}
}

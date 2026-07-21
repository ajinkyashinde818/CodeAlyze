import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner seer = new Scanner(System.in);
		int n = seer.nextInt();
		long[] arr = new long[n];
		int countneg = 0; long min = Integer.MAX_VALUE, tot = 0;
		for(int i = 0; i < n; i++){
			arr[i] = seer.nextInt();
			tot += Math.abs(arr[i]);
			min = Long.min(min, Math.abs(arr[i]));
			if(arr[i] < 0) {
				countneg++;
			}
		}
		if(countneg % 2 == 0){
			System.out.println(tot);
		}
		else{
			System.out.println(tot - 2*min);
		}
	}
}

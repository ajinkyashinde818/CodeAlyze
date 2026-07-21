import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long n = Long.parseLong(sc.next());
		
		List <Integer> L = new ArrayList <Integer>();
		final long m = n;
		for(long i = 2 ;i*i<= m;i++) {
			int cnt = 0;
			while(n % i == 0) {
				n = n /i;
				cnt++;
			}
			L.add(cnt);
			if(n == 1) {
				break;
			}
		}
		
		long cnt = n == 1 ? 0 :1;
		for(long num : L) {
			long sum = 0L;
			long id = 0;
			for(long i = 1 ;; i++) {
				sum += i;
				if(sum > num) {
					break;
				}
				id = i;
			}
			cnt += id;
		}
		
		System.out.println(cnt);
		
	}
}

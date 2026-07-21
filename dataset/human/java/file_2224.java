import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int calc(int e){
		int cnt = 0;
		for(int i = 1 ; i <= e; ++i){
			e -= i;
			++cnt;
			if(e < (i + 1)){
				break;
			}
		}
//		System.out.println(e+" "+cnt);
		return cnt;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int primes[] = new int[1000001];
		Arrays.fill(primes, 1);		
		List<Integer> plist = new ArrayList<Integer>();
		for(int i = 2 ; i < primes.length ; ++i){
			if(primes[i] == 1){
				plist.add(i);
				for(int j = i * 2 ; j < primes.length ; j += i){
					primes[j] = 0;
				}
			}
		}
//		System.out.println(plist.size());
		long N = sc.nextLong();
		long ret = 0;
		for(int p : plist){
			int e = 0;
			while(N % p == 0){
				N = N / p;
				++e;
			}
			if(e > 0){
				ret += calc(e);
//				System.out.println(e);
			}
		}
		if(N != 1){
			ret++;
		}
		System.out.println(ret);
	}
}

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int ans = getKth(getGcd(a, b), k);
		System.out.println(ans);
	}
	
	static int getGcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return getGcd(b % a, a);
	}
	static int getKth(int n, int k) {
		ArrayList<Integer> divisors = new ArrayList<>();
		for(int i = 1; i <= n / 2; i++){
			if(n % i == 0){
				divisors.add(i);
			}
		}
		divisors.add(n);
		return(divisors.get(divisors.size() - k));
	}
}

import java.util.Scanner;

class Main{
	static int n;
	static long ans = 1000000000;
	static int[] memo;
	static int[] dp;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//文字の入力
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		long ans = 0;
		if(c-a >= 0){
			ans += a;
			c -= a;
			if(b - c < 0){
				ans += 2*b+1;
			}else{
				ans += c+ b;
			}
		}else{
			ans += c + b;
		}
		System.out.println(ans);
	}
}







class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}

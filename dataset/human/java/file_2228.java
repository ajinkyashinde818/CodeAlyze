import java.util.*;

public class Main{
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		//入力
		long n = sc.nextLong();
		TreeMap<Integer, Integer> map = primeFactorization(n);
		
		long result = 0;

		//出力
		int i = 0;
		for (Map.Entry<Integer, Integer> e: map.entrySet()) {
			
				long x = e.getValue();
				long y = 1;
				do {
					x -= y;
					result++;
					y++;
				}while(x - y >= 0);

			i++;
		}
		System.out.println(result);

	}

	private static TreeMap<Integer, Integer> primeFactorization (long n) {

		TreeMap<Integer, Integer> map = new TreeMap<>();
		int sq = (int)Math.sqrt(n);

		//nが素数ならn^1の形で返す
		if (isPrime(n) == true) {
			map.put((int) n, 1);
			return map;
		}

		for (int i=2; i<=sq; i++) {
			//n<iなら明らかにnをiで除算できないので終了（ループを余計に回さない）
			if (n < i) break;

			//iが素数なら、nをiで何回除算できるか、その回数をmapに記録する
			if (isPrime(i) == true) {
				int count = 0;
				while (n%i == 0) {
					n /= i;
					count++;
				}
				if (count > 0) {//1回以上割れた場合のみ、mapに記録する
					map.put(i, count);
				}
			}

		}

		//2～sqrt(n)で除算した結果、なお残った数をmapに追加する
		if (n != 1) map.put((int) n, 1);

		return map;

	}
	
	private static boolean isPrime (long n) {
		if (n==2) return true;
		if (n<2 || n%2==0) return false;
		int d = (int)Math.sqrt(n);
		for (int i=3; i<=d; i+=2) {
			if(n%i==0){return false;}
		}
		return true;
	}
	
}

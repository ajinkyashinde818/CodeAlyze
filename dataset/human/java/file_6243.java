import java.util.Scanner;

class Main{

	static	int[] data;




	public static void main(String[] args) {





		Scanner sc = new Scanner(System.in);			//文字の入力
		int k = sc.nextInt();
		int s = sc.nextInt();
		
		int ans = 0;
		for(int a = 0;a <= k;a++){
			for(int b = 0;b <= k;b++){
				int c =  s - (b + a);
				if(c <= k && c >= 0){
					ans++;
				}
			}
		}

		System.out.println(ans);


	}



	static void num(int n){


		int num = n;
		for(int i = 1;i <= n;i++){
			if(n % i == 0){
				data[i]++;
				n /= i;
				i = 1;
			}
		}
		return;

	}
}


class Pair implements Comparable{
	Character from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}

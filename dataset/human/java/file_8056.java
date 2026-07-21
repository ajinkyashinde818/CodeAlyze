import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		
		for(long i=1; i<=B; i++) {
          //最小公倍数を求めればよいので
          //Aに順にかけてBで割り切れれば答えとなる
			if((A*i)%B==0) {
				System.out.println(A*i);
				break;
			}
		}
	}
}

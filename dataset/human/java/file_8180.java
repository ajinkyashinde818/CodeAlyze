import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		//最小公倍数を入れる
		long lcm = 0;

		//最小公倍数を求める
		int i=1;
		while(i<=b){
			if((long)a * i % b == 0) {
				lcm = (long)a*i;
				break;
			}
			else{
				i++;
			}
		}

		 System.out.println(lcm);
		 sc.close();
	}
}

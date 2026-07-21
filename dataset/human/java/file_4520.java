import java.util.Scanner;
//AGC030A
//Main
public class Main{

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt(); //解毒NOTおいC
		int B = sc.nextInt(); //解毒おいC
		int C = sc.nextInt(); //毒入りおいC
		int ans = 0;
		int cure =  A + B;

		if(C <= cure) {
			ans = B + C;
		}else {
			ans = cure + B +1;
		}
		System.out.println(ans);

	}
}

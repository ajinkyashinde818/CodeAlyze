import java.util.Scanner;

//public class atcoder0221_A{
public class Main{

	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int R = scan.nextInt();
		//		int C = scan.nextInt();
		int result = R;
		//
		if(N<10) {
			result = result+(100*(10-N));
		}
		//		if(A==B && B==C && A==C) {
		//			result="No";
		//
		//		}else if(A!=B && B!=C && A!=C) {
		//			result="No";
		System.out.println(result);
	}
}

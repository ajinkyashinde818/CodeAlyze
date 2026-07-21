import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int A = scan.nextInt();
		int B = scan.nextInt();
		int C = scan.nextInt();
		int ans;
		if(C<=A+B){
			ans=C+B;
		}else{
			int p=C-B-A;
			ans=C+B-p+1;
		}
		System.out.println(ans);
	}
}

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn=new Scanner(System.in);
		int a=scn.nextInt();
		int b=scn.nextInt();
		int c=scn.nextInt();
		if(b<a) {
			int t=b;
			b=a;
			a=t;
		}
		int cnt=0;
		for(int i=a;i>=1;i--) {
			if(b%i==0&&a%i==0) {
				cnt++;
			}
			if(cnt==c) {
				System.out.println(i);
				break;
			}
		}
	}

}

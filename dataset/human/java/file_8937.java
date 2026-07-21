import java.util.Scanner;public class Main{public static void main(String[]args){Scanner scan=new Scanner(System.in);
		//String str=scan.next();
		int a=scan.nextInt();
		int b=scan.nextInt();
		int ans=scan.nextInt();
		int count=0;
		for(int i=a>=b?a:b;;i--) {
			if(a%i==0&&b%i==0) {
				count++;
				if(count==ans) {
					System.out.println(i);
					break;
				}
			}
		}
	}
}

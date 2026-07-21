import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner stdIn=new Scanner(System.in);
		int n=stdIn.nextInt(),f=0;
		do {
			if(n%10==9) f=1;
			n/=10;
		}while(n!=0);
		System.out.print(f==0?"No":"Yes");
	}
}

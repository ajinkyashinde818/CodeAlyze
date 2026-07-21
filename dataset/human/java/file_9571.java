import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		int count=0;
		boolean flag=false;
		for (int i=0;i<n;i++){
			int a=in.nextInt();
			int b=in.nextInt();
			if (a==b) count ++;
			else count =0;
			if (count>=3) flag=true;
		}
		if (flag) System.out.println("Yes");
		else System.out.println("No");
	}
}

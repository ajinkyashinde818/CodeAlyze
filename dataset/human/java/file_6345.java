import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int k=scan.nextInt(),s=scan.nextInt(),a=0,i,j;
		scan.close();
		for(i=0;i<=k;i++) {
			for(j=0;j<=k;j++) {
				if(i+j>s) break;
				if(k>=s-i-j) a++;
			}
		}
		System.out.print(a);
	}
}

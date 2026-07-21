import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int k=sc.nextInt();
		int count=0;
		int ans=0;
		int []div=new int[15];

		for(int i=1;i<=a;i++){
			if(a%i==0 && b%i==0 ){
				div[count]=i;
				count++;
			}
		}
		ans=div[count-k];


		System.out.println(ans);
		sc.close();
	}
}

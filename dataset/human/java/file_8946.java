import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();//A
		int b = sc.nextInt();//B
		int c = sc.nextInt();//banme
		int n=0;
		int ans=0;
		for(int i=1;i<=b;i++){
			if(a%i==0&&b%i==0){
				n++;
			}
		}

			c=n-c+1;
			n=0;



			for(int i=1;i<=b;i++){
				if(a%i==0&&b%i==0){
					n++;
					}

				if(n==c){
					ans=i;
					i=b+1;
					}
			}


		System.out.println(ans);

	}}

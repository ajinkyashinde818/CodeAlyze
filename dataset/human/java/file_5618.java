import java.util.Scanner;


	public class Main {
		

		public static void main(String[] args) {

			Scanner sc = new Scanner(System.in);
	        
			int n = sc.nextInt();
			int k = sc.nextInt();
			int s = sc.nextInt();
			int a = 0;
			int b = 0;
			
			
			if(s%2==1) {
				a = s/2;
				b = a+1;
			}else {
				a = s/2;
				b = a;
			}
			int x =0;
			
			if((s-1)==a||(s-1)==b) {
				x=s+1;
			}else {
				x=s-1;
			}
			
			if(k==n) {
				for(int i=1;i<=n-1;i++) {
					System.out.print(s+" ");
				}
				System.out.print(s);
			}else if(s==1) {
				for(int i=1;i<=k;i++) {
					System.out.print(1+" ");
				}
				for(int i=1;i<n-k;i++) {
					System.out.print(2+" ");
				}
				if(n-k-1>0) {
					System.out.println(2);
				}
				
			}else {
				if(k%2==1) {
					for(int i=1;i<=(k+1)/2;i++) {
						System.out.print(a+" "+b+" ");
					}
					for(int i=1;i<n-k-1;i++) {
						System.out.print((x)+" ");
					}
					if(n-k-1>0) {
						System.out.print((x));
					}
				}else {
					for(int i=1;i<=k/2;i++) {
						System.out.print(a+" "+b+" ");
					}
					System.out.print(a+" ");
					for(int i=1;i<n-k-1;i++) {
						System.out.print((x)+" ");
					}
					if(n-k-1>0) {
						System.out.print((x));
					}
					
				}
			}
		}
		
	}

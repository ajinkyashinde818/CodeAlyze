import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);

		int n=sc.nextInt();
		int[] d1=new int[n];
		int[] d2=new int[n];
		for(int i=0;i<=n-1;i++) {
			d1[i]=sc.nextInt();
			d2[i]=sc.nextInt();
		}
		
		for(int i=0;i<=n-3;i++) {
				if(d1[i]==d2[i]&&d1[i+1]==d2[i+1]&&d1[i+2]==d2[i+2]) {
					System.out.println("Yes");
					break;
					}
				else if(i==n-3) {
					System.out.println("No");
				}		
		}
		sc.close();
		}
	}

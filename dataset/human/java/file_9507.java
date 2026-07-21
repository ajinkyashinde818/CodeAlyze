import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n+1];
		int[] b = new int[n+1];
		boolean status=false;
		for(int i=1;i<=n;i++) {
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
		}
		for(int i=1;i<=n-2;i++) {
			if(a[i]==b[i]&&a[i+1]==b[i+1]&&a[i+2]==b[i+2]) {
				status=true;
				break;
			}
		}
		System.out.println(status?"Yes":"No");
		sc.close();
	}

}

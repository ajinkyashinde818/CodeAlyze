import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];
		for(int i = 0;i<n;i++) {
			a[i] = sc.next();
		}
		for(int i=0;i<m;i++) {
			b[i] = sc.next();
		}
		
		for(int i=0;i<n-m+1;i++) {
			for(int k=0;k<n-m+1;k++) {
				boolean flag = true;
				for(int x=0;x<m;x++) {
					for(int y=0;y<m;y++) {
						if(a[i+x].charAt(k+y) != b[x].charAt(y)) {
							flag=false;
						}
					}
				}
				if(flag) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}
}

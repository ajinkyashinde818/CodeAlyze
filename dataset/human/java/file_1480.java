import java.util.Scanner;

public class Main {

	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt(), m = scan.nextInt();
		String[] A = new String[n];
		for(int i=0; i<n; i++)A[i]=scan.next();
		String[] B = new String[m];
		for(int i=0; i<m; i++)B[i]=scan.next();

		boolean f = true;
		for(int i=0; i<n-m+1; i++) {
			for(int j=0; j<n-m+1; j++) {
				for(int k=0; k<m; k++) {
					for(int l=0; l<m; l++) {
						if(A[i+k].charAt(j+l) != B[k].charAt(l)) {
							f = false;
							break;
						}
					}
				}
				if(f) {
					System.out.println("Yes");
					System.exit(0);
				}
				f = true;
			}

		}
		System.out.println("No");
	}

}

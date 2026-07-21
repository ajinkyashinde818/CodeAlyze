import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n=scan.nextInt();
		int m=scan.nextInt();
		char a[][]=new char[n][n];
		char b[][]=new char[m][m];
		for(int i=0;i<n;i++){
			String str=scan.next();
			a[i]=str.toCharArray();
		}
		for(int i=0;i<m;i++){
			String str=scan.next();
			b[i]=str.toCharArray();
		}
		scan.close();
		int check=0;
		for(int i=0;i<n-m;i++) {
			for(int j=0;j<n-m;j++) {
				check=0;
				for(int k=0;k<m;k++) {
					for(int l=0;l<m;l++) {
						if(a[i+k][j+l]!=b[k][l]) {
							check=-1;
							break;
						}
					}
					if(check==-1)break;
				}
				if(check==0)break;
			}
			if(check==0)break;
		}
		System.out.println((check==0)? "Yes":"No");

	}
}

import java.math.BigInteger;
import java.util.*;
public class Main {





public static void main(String[] args)
{
	Scanner sc=new Scanner(System.in);
int n=sc.nextInt();
int m=sc.nextInt();
char a[][]=new char[n][n];
char b[][]=new char[m][m];
for(int i=0;i<n;i++) {
	char s[]=sc.next().toCharArray();
	for(int j=0;j<n;j++) {
		a[i][j]=s[j];
	}
}
for(int i=0;i<m;i++) {
	char s[]=sc.next().toCharArray();
	for(int j=0;j<m;j++) {
		b[i][j]=s[j];
	}
}
int count=0;
int f=1;
outer:for(int i=0;i<n;i++) {
	for(int j=0;j<n;j++) {
		for(int k=0;k<m;k++) {
			for(int l=0;l<m;l++) {
				if(i+j+k<n&&j+l<n&&a[i+j+k][j+l]==b[k][l]) {
					count++;
				}
			}
		}
		if(count==m*m) {
			f=0;
			System.out.println("Yes");
	break outer;
}
count=0;

		
	}
}
if(f!=0) {
	System.out.println("No");
}

	


	

}

}

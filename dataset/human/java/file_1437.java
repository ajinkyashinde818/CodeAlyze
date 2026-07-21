import java.util.Scanner;

public class Main {
	private static Scanner sc=new Scanner(System.in);
	private static int n=sc.nextInt();
	private static int m=sc.nextInt();
	private static String[] nstr=new String[n];
	private static String[] mstr=new String[m];
	private static char[][] a=new char[n][n];
	private static char[][] b=new char[m][m];
	public static void main(String[] args){
		for(int i=0;i<n;i++){
			nstr[i]=sc.next();
			for(int j=0;j<n;j++){
				a[i][j]=nstr[i].charAt(j);
			}
		}
		for(int i=0;i<m;i++){
			mstr[i]=sc.next();
			for(int j=0;j<m;j++){
				b[i][j]=mstr[i].charAt(j);
			}
		}
		System.out.println(check());
	}
	private static String check(){
		for(int i=0;i<=n-m;i++){
			for(int j=0;j<=n-m;j++){
				boolean com=true;
				label: for(int k=i;k<i+m;k++){
					for(int l=j;l<j+m;l++){
						if(a[k][l]!=b[k-i][l-j]){
							com=false;
							break label;
						}
					}
				}
				if(com) return "Yes";
			}
		}
		return "No";
	}
}

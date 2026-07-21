import java.util.Scanner;
public class Main {
	public static void main(String args[]) {
	Scanner sc=new Scanner(System.in);
	int N=sc.nextInt();
	int M=sc.nextInt();
	int X=sc.nextInt();
	int C[]=new int[N];
	int A[][]=new int[N][M];
	int B[]=new int[M];
	int Cmax=0;
	for(int i=0;i<N;i++) {
		C[i]=sc.nextInt();
		for(int j=0;j<M;j++) {
		A[i][j]=sc.nextInt();
		B[j]=0;
		}
	}
	for(int i=0;i<Math.pow(2, N);i++) {
		String bin=Integer.toBinaryString(i);
		int Ct=0;
		for(int j=0;j<bin.length();j++) {
			int b=bin.length()-j-1;
		String a=bin.substring(b,b+1);
		if(a.equals("1")) {
			Ct+=C[j];
			for(int k=0;k<M;k++) {
				B[k]+=A[j][k];
			}
		}
		}
		
		int tot=0;
		for(int j=0;j<M;j++) {
			if(B[j]>=X) {
				tot++;
				}
		}
		if(tot==M) {
			if(Cmax==0) {
				Cmax=Ct;
			}
			else{
				Cmax=Math.min(Ct,Cmax);
			}
		}
		for(int j=0;j<M;j++) {
			B[j]=0;
			}
		
	}
	if(Cmax==0) {
		System.out.println(-1);
	}
	else {
		System.out.println(Cmax);
	}
	}
	
}

import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner stdIn=new Scanner(System.in);
		int N=stdIn.nextInt();
		int M=stdIn.nextInt();
		int a[]=new int[N];
		int b[]=new int[N];
		int z=0,y=0,x=0,n=0,m=0,fin=0;
		while(z<M){
			y=stdIn.nextInt();
			x=stdIn.nextInt();
			if(y==1){
				a[n]=x;
				n++;
			}
			if(x==N){
				b[m]=y;
				m++;
			}
			z++;
		}z=0;y=0;x=0;
		int c[]=new int[n];
		int d[]=new int[m];
		while(z<n||y<m){
			if(z<n){
				c[z]=a[z];
				z++;
			}
			if(y<m){
				d[y]=b[y];
				y++;
			}
		}z=0;y=0;
		Arrays.sort(c);
		Arrays.sort(d);
		while(z<n){
			while(y<m){
				if(c[z]==d[y]){
					fin=1;
					break;
				}
				if(c[z]<d[y]){
					break;
				}
				y++;
			}
			if(fin==1)
				break;
			z++;
		}
		if(fin==1)
			System.out.println("POSSIBLE");
		else
			System.out.println("IMPOSSIBLE");
	}
}

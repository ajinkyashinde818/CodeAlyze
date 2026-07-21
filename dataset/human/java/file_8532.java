import java.util.*;
 
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		System.out.println(getCD(a,b,k));
	}
	private static int getCD(int a,int b,int k){
		int n=k;
		for(int i=chmin(a,b);i>0;i--){
			if(a%i==0 && b%i==0){
				n--;
				if(n==0)return i;
			}
		}
		return 0;
	}
	private static int chmax(int a,int b){
		if(a>b) return a;
		else return b;
	}
	private static int chmin(int a,int b){
		if(a<b) return a;
		else return b;
	}
}

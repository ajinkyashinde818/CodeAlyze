import java.util.Scanner;
public class Main {
	public static void main(String[] args)throws Exception{
		Scanner stdIn=new Scanner(System.in);
		int N=stdIn.nextInt();
		long K=stdIn.nextLong();
		int A[]=new int[N];
		int key[]=new int[N*5];
		boolean visit[]=new boolean[N];
		int s=0,f=0,si=0,fi=0;
		for(int i=0;i<N;i++){
			A[i]=stdIn.nextInt()-1;
		}
		for(int i=0;;i++){
			if(i==K){
				System.out.println(key[i]+1);
				System.exit(0);
			}
			key[i+1]=A[key[i]];
			visit[key[i]]=true;
			if(visit[key[i+1]]){
				s=key[i+1];f=key[i];
				break;
			}
		}
		for(int i=0;i<N*5;i++){
			if(key[i]==s)
				si=i;
			if(key[i]==f){
				fi=i;
				break;
			}
		}
		int ans=fi-si+1;
		System.out.println(key[si+(int)((K-si)%ans)]+1);
	}
}

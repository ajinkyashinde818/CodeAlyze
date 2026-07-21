import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int N = sc.nextInt();
		long[] list=new long[N];
		for(int i=0;i<N;i++){
			list[i]=sc.nextInt();
		}
		//１回で取れる個数
		long pick=(long)N*(long)(N+1)/2;

		long sum=0;
		for(int i=0;i<N;i++){
			sum=sum+list[i];
		}
		if(sum-(long)(sum/pick)*pick!=0){
			System.out.println("NO");
			return;
		}
		//総ピック回数
		long count=sum/pick;
		if(((int)(list[0]-list[N-1])-count)%N!=0||((int)(list[0]-list[N-1])-count)>0){				
			System.out.println("NO");
			return;
		}

		for(int i=1;i<N;i++){
			if(((int)(list[i]-list[i-1])-count)%N!=0||((int)(list[i]-list[i-1])-count)>0){				
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");

	}
}

//20200510 D
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt();
		long K=sc.nextLong();
		int[] A=new int[N];
		for(int i=0;i<N;i++){
			A[i]=sc.nextInt()-1;
		}
		List<Integer> Q=new ArrayList<>();
        boolean[] C=new boolean[N];
		Q.add(0);
		int lsn;
		int len;
        int t=0;
        C[0]=true;
		while(true){
			int a=A[t];
			if(C[a]){
				lsn=Q.indexOf(a);
				len=Q.size()-1;
				break;
			}
			Q.add(a);
            C[a]=true;
            t=a;
		}
      	/*for(Integer i:Q){
          System.out.println(i);
        }
      	System.out.println(lsn);
      	System.out.println(len);
      	System.out.println("");*/
		if(K<lsn){
			System.out.println(Q.get((int)K)+1);
		}else{
			int n=(int)((K-lsn)%(len-lsn+1))+lsn;
			System.out.println(Q.get(n)+1);
		}
	}
}

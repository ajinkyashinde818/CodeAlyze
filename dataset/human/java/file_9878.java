import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
 


public class Main {
	private static Scanner sc = new Scanner(System.in);
	//result = Math.pow(num1, num3)
	//StringBuffer str = new StringBuffer(hoge1);
	//String hoge2 = str.reverse().toString();
	//map.containsKey(A)

	//Map<String, Integer> map = new HashMap<String, Integer>(n);
	/*for ( キーのデータ型 key : マップの名前.keySet() ) {
		データのデータ型 data = マップの名前.get( key );
		
		// keyやdataを使った処理;
	}*/
	//int i = Integer.parseInt(s);
	//Queue<String> qq=new ArrayDeque<>(); //add,poll,peek
	//Deque<String> qq=new ArrayDeque<>();//push,pop,peek
	//ArrayList<String> cc = new ArrayList<>(n);
	//Collections.sort(list);
	//Array.sort(list);   cc.contains(tmp)
	//Arrays.asList(c).contains("a")
	//list.set(1,"walk");//1 1 2 3 5
	//static long mod =1000000007;
	//static 	ArrayList<Integer> cc = new ArrayList<>(100);
	
	
	static int N,M,X;
	static int c[]=new int[100001];
	
	public static void main(String[] args) {
		//int N=sc.nextInt();for(int i=0;i<N;i++) {}
		//int a[]=new int[N];
		N=sc.nextInt();
		M=sc.nextInt();
		X=sc.nextInt();

		
		int a[][]=new int[N][M];
		
		
		
		for(int i=0;i<N;i++) {
			c[i]=sc.nextInt();
			for(int i1=0;i1<M;i1++) {
				a[i][i1]=sc.nextInt();
			}
		}
	
		
			int v[]=new int[M];
			
			Queue<Integer> qq=new ArrayDeque<>(); //add,poll,peek
			qq.add(0);
			Queue<Integer> sum1=new ArrayDeque<>(); //add,poll,peek
			sum1.add(0);
			Queue<int[]> vv=new ArrayDeque<>(); //add,poll,peek
			vv.add(v);
			int ans=1000000009;
			while(qq.peek() != null) {
				
				int t=qq.poll();
				int s=sum1.poll();
				int bb[]=vv.poll();
				//for(int i:bb)System.out.print(i+" ");
				//System.out.println(t+" ");
				if(t==N) {
					boolean f=true;
				for(int i=0;i<M;i++) {
					if(bb[i]<X) {
						f=false;
						break;
					}
				}
				
				if(f)ans=Math.min(ans, s);
				continue;
				}
				
				
				qq.add(t+1);sum1.add(s);vv.add(bb.clone());
				
				qq.add(t+1);
				sum1.add(s+c[t]);
				for(int i=0;i<M;i++) {
					bb[i]+=a[t][i];
				}
				vv.add(bb.clone());
				
				
			}
			if(ans==1000000009)p(-1);
			else p(ans);
			
			
			
		}
		
		
	
	
	
	static int dfs(int i) {
		
		
		
		
		
		return 0;
	}
	
	
	

	


	
	static void p(String ans) {System.out.println(ans);};
	static void p(int ans) {System.out.println(ans);};
	static void p() {System.out.println();};
	static void p(long ans) {System.out.println(ans);};
	static void p(double ans) {System.out.println(ans);};
	
}

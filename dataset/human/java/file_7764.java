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
	
	
	
	public static void main(String[] args) {
		//int N=sc.nextInt();for(int i=0;i<N;i++) {}
		//int a[]=new int[N];
		
		
		long N=sc.nextInt();
			
			long K=sc.nextLong();
			boolean v[]=new boolean[(int) N];
			for(int i=0;i<N;i++)v[i]=false;
			
			long t[]=new long[(int) N];
			for(int i=0;i<N;i++) {
				t[i]=sc.nextInt()-1;
			}
			
			long f=0;
			long ctn=0;
			boolean s=true;
			while(true) {
				if(v[(int) f]) {
					break;
				}
				ctn++;
				v[(int) f]=true;
				f=t[(int) f];
				if(ctn==K) {
					p((f+1));
					s=false;
				}
			}
			if(!s) {
				
			}else {
			long g=f;
			long ctn2=0;
			long ans[]=new long[(int) N];
			while(ctn2<N) {
				ans[(int) ctn2]=g;
				ctn2++;
				g=t[(int) g];
				if(g==f) {
					break;
				}
			}
			
			long x=((K-ctn)%ctn2);
			p((ans[(int)x]+1));
			}
		
		
	}
	
	
	

	


	
	static void p(String ans) {System.out.println(ans);};
	static void p(int ans) {System.out.println(ans);};
	static void p() {System.out.println();};
	static void p(long ans) {System.out.println(ans);};
	static void p(double ans) {System.out.println(ans);};
	
}

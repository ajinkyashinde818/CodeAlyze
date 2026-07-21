import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
 


public class Main {
	private static Scanner sc = new Scanner(System.in);
	//StringBuffer S = new StringBuffer(sc.next());
	//String hoge2 = str.reverse().toString();
	//map.containsKey(A)
	//Map<Integer, Integer> map = new HashMap<Integer, Integer>(N);
	/*for ( キーのデータ型 key : マップの名前.keySet() ) {
		データのデータ型 data = マップの名前.get( key );
		
		// keyやdataを使った処理;
	}*/
	//int i = Integer.parseInt(s);
	//Queue<String> qq=new ArrayDeque<>(); //add,poll,peek
	//Deque<String> dd=new ArrayDeque<>();//push後ろに入れる,poll(pop)後ろからとる,peek addは先頭に入るからバグ注意
	//ArrayList<Integer> cc = new ArrayList<>(N);
	//cc.contains(tmp)
	//Arrays.asList(c).contains("a")
	//list.set(1,"walk");//1 1 2 3 5
	static long mod =1000000007;
	static long longINF=1000000000000000007L;
	static int INF=1000000007;

	
	public static void main(String[] args) {
		//StringBuffer str = new StringBuffer(sc.nextInt());
		//for(int i=0;i<N;i++) {}
		//String S=sc.next();
		
		long N=sc.nextLong();
		
		ArrayList<Integer> cc = new ArrayList<>();
		ArrayList<Long> cc1 = new ArrayList<>();
		long F=N;
			for(long i=2;i*i<=N;i++) {
				if(N%i==0) {
					int t=0;
					while(N%i==0) {
						N/=i;
						t++;
					}
					cc1.add(i);
					cc.add(t);
					i=1;
				}
			}
			if(N!=1) {
				cc1.add(N);
				cc.add(1);
			}
			int ans=0;
			if(cc.size()==0&&N!=1)ans++;
			
			long t=1;
			
			for(int i:cc) {
				for(int a=1;i>=a;a++) {
						ans++;
						i-=a;
				}
			}p(ans);
			
		}
		
	
		
	
		static boolean r(long a) {
			for(int i=2;i*i<=a;i++) {
				if(a%i==0)return false;
			}return true;
		}
		
		
	
	
	
	static long bi(int i) {
		long t=1;
		for(int a=1;a<=i;a++) {
			t*=a;
			t%=mod;
		}
		return t;
	}
	public static long modPow(long g,long N) {
		long T=1;
		for(int i=0;i<N;i++) {
			T*=g;
			T%=mod;
		}
		return T;
	}
	static void bit() {
		int n=3;
		String[] ar = {"a","b","c"};
		for(int i =0;i<(1<<n);i++) {
			String S="";
			for(int j=0;j<n;j++) {
				if((1&i>>j)==1) {
					S+=ar[j];
				}
			}
			p("S="+S);
		}
	}
	public static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
	}
	
	public static long gcd(long a, long b) {
        return b == 0 ? a: gcd(b, a % b);
	}
	static String nextPermutation(String s) {
		ArrayList<Character> list=new ArrayList<>();
		for(int i=0;i<s.length();i++) {
			list.add(s.charAt(i));
		}
		int pivotPos=-1;
		char pivot=0;
		for(int i=list.size()-2;i>=0;i--) {
			if(list.get(i)<list.get(i+1)) {
				pivotPos=i;
				pivot=list.get(i);
				break;
			}
		}
		if(pivotPos==-1&&pivot==0) {
			return "Final";
		}
		int L=pivotPos+1,R=list.size()-1;
		
		
		
		int minPos=-1;
		char min =Character.MAX_VALUE;
		
		for(int i=R;i>=L;i--) {
			if(pivot<list.get(i)) {
				if(list.get(i)<min) {
					min=list.get(i);
					minPos=i;
				}
			}
		}
		
		Collections.swap(list, pivotPos, minPos);
		Collections.sort(list.subList(L, R+1));
		
		
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<list.size();i++) {
			sb.append(list.get(i));
		}
		return sb.toString();
	}
	


	
	static void p(String ans) {System.out.println(ans);};
	static void p(int ans) {System.out.println(ans);};
	static void p() {System.out.println();};
	static void p(long ans) {System.out.println(ans);};
	static void p(double ans) {System.out.println(ans);};
	
}

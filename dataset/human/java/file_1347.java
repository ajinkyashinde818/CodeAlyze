/*
 * Remember a 6.72 student can know more than a 10.0 student.
 * Grades don't determine intelligence, they test obedience. 
 * I Never Give Up.
 * I will become Candidate Master today.
 * I will defeat Saurabh Anand.
 * Skills are Cheap,Passion is Priceless.
 */
import java.util.*;
import java.util.Map.Entry;
import java.io.*;

import static java.lang.System.out;
import static java.util.Arrays.*;
import static java.lang.Math.*;
 
public class Main{
	private static Reader in=new Reader();
	private static StringBuilder ans=new StringBuilder();
	private static long MOD=(long)1e9+7;
	private static final int N=(int) (1e6+7); // 1e5+7
    private static ArrayList<Integer> v[]=new ArrayList[N];
	private static boolean mark[]=new boolean[N];
//    private static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	private static long powmod(long x,long n){
		if(n==0||x==0)
			return 1;
		else if(n%2==0)
			return(powmod((x*x)%MOD,n/2));
		else
			return (x*(powmod((x*x)%MOD,(n-1)/2)))%MOD;
	}
	private static void shuffle(long[] arr){
		for(int i=arr.length-1;i>=2;i--){
			int x=new Random().nextInt(i-1);
			long temp=arr[x];
			arr[x]=arr[i];
			arr[i]=temp;
		}
	}
	private static void shuffle(int[] arr){
		for(int i=arr.length-1;i>=2;i--){
			int x=new Random().nextInt(i-1);
			int temp=arr[x];
			arr[x]=arr[i];
			arr[i]=temp;
		}
	}
    private static long gcd(long a, long b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
//    private static boolean check(int x,int y){
//        if((x>=0&&x<n)&&(y>=0&&y<m)&&mat[x][y]!='X'&&!visited[x][y])return true;
//        return false;
//    }
    public static int mod(int n,int c){
    	if(n<0)return n%c+c;
    	return n%c;
    }
//    public static boolean setCheck(long num,int pos){
//    	int c=1;
//    	int len=0;
//    	while(c<=num){
//    		if(len==pos&&(num&c)>=1){
//    			return true;
//    		}
//    		len++;
//    		c<<=1;
//    	}
//    	return false;
//    }
//    public static void setBit(int bit[],long num){
//    	long c;
//    	for(int j=0;j<64;j++){
//    		c=1L<<j;
//			if((num&c)>=1){
//				bit[j]++;
//			}
//		}
//    }
    
	public static void main(String[] args) throws IOException{
		int n=in.nextInt();
		int m=in.nextInt();
		String ar[]=new String[n];
		String br[]=new String[m];
		for(int i=0;i<n;i++)
			ar[i]=in.next();
		for(int i=0;i<m;i++)
			br[i]=in.next();
		boolean flag;
		for(int i=0;i+m-1<n;i++){
			for(int j=0;j+m-1<n;j++){
				if(ar[i].charAt(j)==br[0].charAt(0)){
					flag=true;
					for(int k=0;k<m;k++){
						for(int l=0;l<m;l++){
							if(ar[i+k].charAt(j+l)!=br[k].charAt(l)){flag=false;break;}
						}
					}
					if(flag){pn("Yes");return;}
				}
			}
		}
		pn("No");
	}
	static class Pair<T> implements Comparable<Pair>{
		int l;
		int r;
		Pair(){
			l=0;
			r=0;
		}
		Pair(int k,int v){
			l=k;
			r=v;
		}
		@Override
		public int compareTo(Pair o){
			if(l!=o.l)return (int)(l-o.l);
			return (int)(r-o.r);
		}
		// Fenwick tree question comparator
//        @Override
//        public int compareTo(Pair o) {
//            if(o.r!=r)return (int) (r-o.r);
//            else return (int)(l-o.l);
//        }
	}
	//Reader Class
	static class Reader{
		BufferedReader br;
		StringTokenizer st;
		public Reader(){br=new BufferedReader(new InputStreamReader(System.in));}
		String next(){
			while(st==null||!st.hasMoreElements()){
				try{st=new StringTokenizer(br.readLine());
				}catch(IOException e){e.printStackTrace();}
			}
			return st.nextToken();
		}
		int nextInt(){return Integer.parseInt(next());}
		long nextLong(){return Long.parseLong(next());}
		double nextDouble(){return Double.parseDouble(next());}
		String nextLine(){
			String str="";
			try{
				str=br.readLine();
			}catch(IOException e){
				e.printStackTrace();
			}
			return str;
		}
	}
	//Printer Methods
	static void pn(Object o){out.print(o);}
	static void pln(Object o){out.println(o);}
	static void pln(){out.println();}
	static void pf(String format,Object o){out.printf(format,o);}
	//Appenders
	static void app(Object o){ans.append(o);}
}

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.NoSuchElementException;


public class Main {
	public static void main(String[] args) {
		
		for(int i=0;i<1;i++) {
			
			slover();
			out.flush();
		}
	}
	static FastScanner sc = new FastScanner();
	static PrintWriter out = new PrintWriter(System.out);
	

		



		private static class D{
		
			ArrayList<Integer> X=new ArrayList<Integer>();
			ArrayList<Integer> Y=new ArrayList<Integer>();
			int t=0;
			int index=0;
			D(ArrayList<Integer> X,ArrayList<Integer> Y,int t,int index){
				this.X=X;;
				this.Y=Y;
				this.t=t;
				this.index=index;
			}

		}



	//Set<Long> a=new HashSet<Long>();
	
	
	
	//Integer.toBinaryString(i);
	//Integer.toString(i, 2);
//	//Integer.parseInt(bin, 2);
	//bitset
		//StringBuffer S = new StringBuffer(sc.next());
				//String hoge2 = str.reverse().toString();
				//map.containsKey(A)
				//Map<Integer, Integer> map = new HashMap<Integer, Integer>(N);
				/*for ( キーのデータ型 key : マップの名前.keySet() ) {
					データのデータ型 data = マップの名前.get( key );

					// keyやdataを使った処理;
				}*/
				//int i = Integer.parseInt(s);
				//Queue<String> qq=new ArrayDeque<>(); //add,poll,peek BFSは前から実行される
				//Deque<String> dd=new ArrayDeque<>();//push後ろに入れる,poll(pop)後ろからとる,peek addは先頭に入るからバグ注意
				//stackdfsは後ろから実行される
				//ArrayList<Integer> cc = new ArrayList<>(N);
				//cc.contains(tmp)
				//Arrays.asList(c).contains("a")
				//list.set(1,"walk");//1 1 2 3 5
				//PriorityQueue<Integer> r=new PriorityQueue<Integer>();//add poll
		
		public static class Pair<K, V> extends AbstractMap.SimpleEntry<K, V> implements Comparable<Pair<K, V>> {
			/** serialVersionUID. */
		    private static final long serialVersionUID = 6411527075103472113L;
	 
		    public Pair(final K key, final V value) {
		        super(key, value);
		    }
	 
			@Override
			public int compareTo(Pair<K, V> o) {
	 
				Comparable key = (Comparable)this.getKey();
				Comparable key2 = (Comparable)o.getKey();
	 
				return key.compareTo(key2);
			}
	 
		}
	 
		// 文字列として入力を取得
		
		
		
		
	private static long mod=1000000007;
	private static int INF =999999999;
	private static long LINF=4000000000000000000L;
	
	private static long ncr(long n,long r) {
		long res=1;
		
		for(int i=0;i<r;i++) {
			res*=n-i;
			res/=i+1;
		}
		return res;
	}
	private static int StringCount(String T,String v) {
		int res=0;
		int t=0;
		while(T.indexOf(v,t)>=0) {
			//p(t);
			res++;
			t=T.indexOf(v,t)+1;
		}
		return res;
	}
	
	private static int slover()   {
		
		String S=sc.next();
		
		String V[]= {"dream","dreamer","erase","eraser"};
		
		for(int i=0;i<S.length();) {
			//p(i);
			if(S.charAt(i)=='d') {
				if(i+V[0].length()-1<S.length()&&S.substring(i,i+V[0].length()).equals(V[0])) {
					//dream + anything
					i+=V[0].length();
					
					
					
					if(i+3<S.length()&&S.substring(i,i+4).equals("erer")) {
						//p("dreamer");
						//dreamer + erase (+er)になる
						i+=2;
						continue;
					}else if(i+1<S.length()&&S.substring(i,i+2).equals("er")) {
						//dreamer +"dream" or dream + erase (+er)
						
						i+=2;
						if(i<S.length()&&S.charAt(i)=='d') {
							//dreamer + d~~
							//p("dreamer");
							continue;
						}else if(i<S.length()&&S.charAt(i)=='a'){
							//dream + er + ase
							//p("dream");
							i-=2;
							continue;
						}else if(i<S.length()){
							
							p("NO");
							return 0;
						}else {
						//	p("dreamer");
						}
						
					}else {
					//	p("dream");
						continue;
					}
				}else {
					p("NO");
					return 0;
				}
			}else if(S.charAt(i)=='e'){
			
				if(i+V[2].length()-1<S.length()&&S.substring(i,i+V[2].length()).equals(V[2])) {
					i+=V[2].length();
					
					
					//erase + erase
					//eraser + erase
					//erase + dream
					//eraser + dream
					
					if(i<S.length()&&S.substring(i,i+1).equals("r")) {
						//p("eraser");
						i+=1;
						continue;
						
					}else if(i+1<S.length()&&S.substring(i,i+2).equals("er")) {
						//p("erase");
					}else if(i<S.length()&&S.substring(i,i+1).equals("d")) {
						//p("erase");
					}else if(i<S.length()) {
						p("NO");
						return 0;
					}
					else {
						//p("erase");
					}
					
					
					
				
				
				
				}else {
					p("NO");
					return 0;
				}
			}else {
				p("NO");
				return 0;
			}
			
			
		}
		p("YES");
		return 0;
	}
	private static void shape(int Q[]) {
		for(int i=0;i<Q.length;i++) {
			find2(Q,i);
		}
	}
	private static int find2(int Q[],int a) {
		//aの根をbの根にする。
		if(Q[a]==a) {
			return Q[a];
		}else {
			return Q[a]=find2(Q,Q[a]);
		}
		
	}
	private static void union2(int Q[],int a,int b) {
		
		int root1=find2(Q,a);
		int root2=find2(Q,b);
		Q[root1]=Q[root2];
	}
	
	
	private static void set_add(int Q[],int index,int value) {
		if(Q[index]==value) {
			
		}
		else if(Q[index]==INF) {
			Q[index]=value;
			
		}else if(value<Q[index]) {
			set_add(Q,index*2+1,value);
		}else {
			set_add(Q,index*2+2,value);
		}
	}
	
	private static void priority_queue_add(int Queue[],int index,int value) {
		Queue[index]=value;
		
		if(index!=0) {
			if((index-1)/2>=0&&Queue[(index-1)/2]>value) {
				Queue[index]=Queue[(index-1)/2];
				priority_queue_add(Queue,(index-1)/2,value);
				
			}
			if((index-2)/2>=0&&Queue[(index-2)/2]>value) {
				Queue[index]=Queue[(index-2)/2];
				priority_queue_add(Queue,(index-2)/2,value);
				
			}
		}
		
		
	}
private static int priority_queue_getFirst(int[] Queue) {
		int res=Queue[0];
		Queue[0]=Queue[Queue.length-1];
		Queue[Queue.length-1]=INF;
		//System.out.println(Arrays.toString(Queue));
		//大きさのチェック
		Q_shape(Queue,0);
		
		return res;
	}
	private static void Q_shape(int[] Queue,int index) {
			
			
		
			if(index*2+1<Queue.length&&Queue[index*2+1]<Queue[index]) {
				int v=Queue[index];
				Queue[index]=Queue[index*2+1];
				Queue[index*2+1]=v;
				Q_shape(Queue,index*2+1);
				
			}
			if(index*2+2<Queue.length&&Queue[index*2+2]<Queue[index]) {
				int v=Queue[index];
				Queue[index]=Queue[index*2+2];
				Queue[index*2+2]=v;
				Q_shape(Queue,index*2+2);
				
			}
		
		
		
	}
	private static int union_MaxSize(int[] tree) {
		
		union_shape(tree);
		
		int V[]=new int[tree.length+1];
		
		for(int i=0;i<tree.length;i++) {
			V[tree[i]]++;
		}
		int max=0;
		for(int i=0;i<=tree.length;i++) {
			max=Math.max(max, V[i]);
		}
		return max;
	}
	
	public static int find(int[] tree,int idx) {
        if(tree[idx]==idx) return idx;
        else {
        	
        	return tree[idx] = find(tree,tree[idx]);
        }
    }
	public static void union_shape(int[] tree) {
		for(int i=0;i<tree.length;i++) {
			find(tree,i);
		}
	}

    //union idx2 tree to idx1 tree O(a(N))
    public static int[] union(int tree[],int idx1,int idx2) {
        int root1 = find(tree,idx1);
        int root2 = find(tree,idx2);
        tree[root2] = root1;
        return tree;
    }
	private static boolean heihou(long T) {
		if(Math.pow((int)Math.sqrt(T), 2)==T)return true;
		return false;
	}
	private static String zeroume(String S) {
		while(S.length()<6)S='0'+S;
		return S;
	}
	
	//速度が足りないときは、前計算を1回だけにしたり、longをintに変えたりするといい
	private static long modNcR2(int n,int r) {
		long x_b=1;
		
		for(int i=0;i<r;i++) {
			x_b*=(n-i);
			x_b%=mod;
		}
		
		long y=1;
		for(int i=1;i<=r;i++) {
			y*=i;
			y%=mod;
			//nPrにr!%modの逆元を掛ける
		}
		return  (x_b*modPow((int) y,mod-2,mod)%mod);
		
	}
	
	

	
	
	
	private static long modPow(int i,long t,long mod) {
		//iのt乗をO(log t)で返す
		i%=mod;
		t%=mod;
		long a=i;
		long res=1;
		//for(int i=0;i<S.length();i++) {if(S.charAt(N-i)=='1') {res=res*a%mod;}
		//tをStringで受け取りたい時用
		while(t!=0) {
			if((1&t)==1) {
				res=res*a%mod;
			}
			a=a*a%mod;
			t=t>>1;
		}
		return res;
	}
	
	public static long gcd(long num1,long num2) {
        if(num2==0) return num1;
        else return gcd(num2,num1%num2);
    }
	public static long lcm(long num1,long num2) {
		return num1*num2/gcd(num1,num2);
	}
	//O(N^0.5)
	private static boolean isPrime(long t) {
		if(t<2)return false;
		for(int i=2;i*i<=t;i++) {
			if(t%i==0)return false;
		}
		return true;
	}
	private static ArrayList<Long> Divisors(long t) {
		ArrayList<Long> c=new ArrayList<Long>();
		
		for(long i=1;i*i<=t;i++) {
			if(t%i==0) {
				
				if(i*i!=t) {
					c.add(t/i);
				}
				c.add((long)i);
			}
		}
		return c;
	}
	private static ArrayList<Long> Sorted_Divisors(long t) {
		ArrayList<Long> c=new ArrayList<Long>();
		for(long i=2;i*i<=t;i++) {
			
			
			if(t%i==0) {
				p(t+" "+i);
				c.add((long)i);
				t/=i;
				i--;
			}
		}
		if(t!=1)c.add(t);
		Collections.sort(c);
		
		return c;
	}
	private static void bubunwa() {
		int N=sc.nextInt();
		int K=sc.nextInt();
		int a[]=sc.nextIntArray(N, false);

		boolean dp[] =new boolean[K+1];

		Arrays.fill(dp, false);
		dp[0]=true;
		for(int i=0;i<N;i++) {
			for(int x=K-a[i];x>=0;x--) {
				if(dp[x])dp[x+a[i]]=true;
			}
		}

		p(dp[K] ? "Yes":"No");
	}
	
	private static String bitToString(int i) {
		return Integer.toBinaryString(i);
	}
/*********************************************************************/
	//target以下までの値のindexを返す
	//target以上が欲しいときは返り値+1すればいい
	//0-indexで個数を求めるときはさらにindex+1する必要あり
	private static int lower_bound(long a[],long target) {
	//p(target+ " "+Arrays.toString(a));
	if(a[0]>target)return -1;
	//最後の値がtarget以下であるときは最後のindexを返す。
	//target以上が欲しいときは注意する必要あり
	if(a[a.length-1]<=target) return a.length-1;

	int S=-1;
	int E=a.length;

	while(S<E) {

		int G=(S+E)/2;
		if(G+1==a.length) {
			G--;
		}
		//未満にしたいときは=の場所を変える
		if(a[G]<=target&&a[G+1]>target) {
			return G;

		}else if(a[G]<=target){
			S=G;
		}else if(a[G]>target) {
			E=G;
		}

	}


	return -1;
	}
	static String nextPermutation(String s) {
		ArrayList<Character> list=new ArrayList<Character>();
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
private static long[][] com;
private static void nCr() {
	int MAX = 3001;
	com= new long[MAX][MAX];
	for(int i = 0; i < MAX; i++)
	    com[i][0] = 1;
	for(int i = 1; i < MAX; i++) {
	    for(int j = 1; j <= i; j++) {
	        com[i][j] = com[i-1][j-1] + com[i-1][j];
	        com[i][j] %= mod;
	    }
	}
}


	static void p(String ans) {out.println(ans);}
	static void p(int ans) {out.println(ans);}
	static void p() {out.println();}
	static void p(long ans) {out.println(ans);}
	static void p(double ans) {out.println(ans);}
	static void p(boolean ans) {out.println(ans);}
	
	
	static void pn(String ans) {out.print(ans);};
	static void pn(int ans) {out.print(ans);};
	static void pn() {out.print("");};
	static void pn(long ans) {out.print(ans);};
	static void pn(double ans) {out.print(ans);};

	static class FastScanner {
	    private final InputStream in = System.in;
	    private final byte[] buffer = new byte[1024];
	    private int ptr = 0;
	    private int buflen = 0;

	    private boolean hasNextByte() {
	      if (ptr < buflen) {
	        return true;
	      } else {
	        ptr = 0;
	        try {
	          buflen = in.read(buffer);
	        } catch (IOException e) {
	          e.printStackTrace();
	        }
	        if (buflen <= 0) {
	          return false;
	        }
	      }
	      return true;
	    }

	    private int readByte() {
	      if (hasNextByte()) return buffer[ptr++];
	      else return -1;
	    }

	    private static boolean isPrintableChar(int c) {
	      return 33 <= c && c <= 126;
	    }

	    private void skipUnprintable() {
	      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
	    }

	    public boolean hasNext() {
	      skipUnprintable();
	      return hasNextByte();
	    }

	    public String next() {
	      if (!hasNext()) throw new NoSuchElementException();
	      StringBuilder sb = new StringBuilder();
	      int b = readByte();
	      while (isPrintableChar(b)) {
	        sb.appendCodePoint(b);
	        b = readByte();
	      }
	      return sb.toString();
	    }

	    public long nextLong() {
	      if (!hasNext()) throw new NoSuchElementException();
	      long n = 0;
	      boolean minus = false;
	      int b = readByte();
	      if (b == '-') {
	        minus = true;
	        b = readByte();
	      }
	      if (b < '0' || '9' < b) {
	        throw new NumberFormatException();
	      }
	      while (true) {
	        if ('0' <= b && b <= '9') {
	          n *= 10;
	          n += b - '0';
	        } else if (b == -1 || !isPrintableChar(b)) {
	          return minus ? -n : n;
	        } else {
	          throw new NumberFormatException();
	        }
	        b = readByte();
	      }
	    }

	    public int nextInt() {
	      return (int) nextLong();
	    }

	    public double nextDouble(){
	    	return Double.parseDouble(next());
	    }

	    public int[] nextIntArray(int N, boolean oneBased) {
	      if (oneBased) {
	        int[] array = new int[N + 1];
	        for (int i = 1; i <= N; i++) {
	          array[i] = sc.nextInt();
	        }
	        return array;
	      } else {
	        int[] array = new int[N];
	        for (int i = 0; i < N; i++) {
	          array[i] = sc.nextInt();
	        }
	        return array;
	      }
	    }

	    public long[] nextLongArray(int N, boolean oneBased) {
	      if (oneBased) {
	        long[] array = new long[N + 1];
	        for (int i = 1; i <= N; i++) {
	          array[i] = sc.nextLong();
	        }
	        return array;
	      } else {
	        long[] array = new long[N];
	        for (int i = 0; i < N; i++) {
	          array[i] = sc.nextLong();
	        }
	        return array;
	      }
	    }
	  }
}

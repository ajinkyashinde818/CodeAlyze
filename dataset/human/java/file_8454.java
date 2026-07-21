import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
 
 
public class Main {
 
	static long MOD = 1_000_000_007;
	static int INF = 1_000_000_007;
	//二項係数関連ここから-----
	static boolean isPreprocessing = false;	//二項係数を計算するための前処理を行っているかどうかのフラグ
	static int MAX = 260;				//MAXまで階乗やそれらの逆元のテーブルを保持する。
	static long[] fac;	//fac[i] := i! % MOD
	static long[] inv;	//inv[i] := mod. MODにおける i の逆元
	static long[] finv;	//finv[i] := mod. MODにおける i! の逆元(invの累積"積")
	//二項係数関連おわり------
	
	static int[] roots;		//Union-find木用
	static int[] ans;
	static List<ArrayList<Integer>> G;
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		//int N = Integer.parseInt(sc.next());
		//long L = Long.parseLong(sc.next());
		//char[] A = sc.next().toCharArray();
		int N = Integer.parseInt(sc.next());
		int K = Integer.parseInt(sc.next());
		int L = Integer.parseInt(sc.next());
		UnionFind uf_road = new UnionFind(N);
		UnionFind uf_train = new UnionFind(N);
		
		for(int i=0; i<K; i++){
			int p = Integer.parseInt(sc.next())-1;
			int q = Integer.parseInt(sc.next())-1;
			uf_road.join(p, q);
		}
		for(int i=0; i<L; i++){
			int r = Integer.parseInt(sc.next())-1;
			int s = Integer.parseInt(sc.next())-1;
			uf_train.join(r, s);
		}
		for(int i=0; i<N; i++){
			uf_road.root(i);
			uf_train.root(i);
		}
		class City{
			private int root_road;
			private int root_train;
			private int number;
			public City(int root_road, int root_train, int number){
				this.number = number;
				this.root_road = root_road;
				this.root_train = root_train;
			}
			public int getRoot_road() {
				return root_road;
			}
			public int getNumber() {
				return number;
			}
			public int getRoot_train() {
				return root_train;
			}

		}
		City[] data = new City[N];
		for(int i=0; i<N; i++){
			data[i] = new City(uf_road.getRoots()[i], uf_train.getRoots()[i], i);
		}
		Comparator<City> c = Comparator.comparing(City::getRoot_road).thenComparing(City::getRoot_train);
		Arrays.sort(data, c);
		
		City tmp = data[0];
		int count = 0;
		int[] ans = new int[N];
		int first = 0;
		for(int i=0; i<N; i++){
			if(data[i].getRoot_road() == tmp.getRoot_road() && data[i].getRoot_train() == tmp.getRoot_train()){
				count++;
			}else{
				for(int j=first; j<first+count; j++){
					ans[data[j].getNumber()] = count;
				}
				count = 1;
				tmp = data[i];
				first = i;
			}
		}
		for(int j=first; j<first+count; j++){
			ans[data[j].getNumber()] = count;
		}
		for(int a:ans){
			System.out.print(a+" ");
		}
		
	}
	
	//Union-Find木
	static class UnionFind{
		private int[] roots;
		public UnionFind(int N){
			this.roots = new int[N];
			for(int i=0; i<N; i++){
				this.roots[i] = i;
			}
		}
		
		public boolean same(int a, int b){
			if(root(a) == root(b)){
				return true;
			}else{
				return false;
			}
		}
		
		public int root(int a){
			if(a == this.roots[a])return a;
			return this.roots[a] = root(this.roots[a]);
		}
		
		public void join(int a, int b){
			if(root(a) == root(b))return;
			this.roots[root(b)] = root(a);
		}
		
		public int[] getRoots(){
			return this.roots;
		}
	}

	//素因数分解をする(index_0:素数 index_1:個数)
	static List<long[]> factorization(long M){
		List<long[]> primes = new ArrayList<>();
 
		long now_prime = 2;
		long now_M = M;
		while(now_prime*now_prime<=M){
			if(now_M%now_prime == 0){
				now_M /= now_prime;
				long[] prime = new long[2];
				prime[0] = now_prime;
				prime[1] = 1;
				while(now_M%now_prime == 0){
					now_M /= now_prime;
					prime[1]++;
				}
				primes.add(prime);
				
			}
			if(now_prime%2 == 0){
				now_prime++;
			}else{
				now_prime += 2;
			}
		}
		if (now_M>1 || M==1){
			long[] prime = new long[2];
			prime[0] = now_M;
			prime[1] = 1;
			primes.add(prime);
		}
		
		return primes;
	}
	
	//２つのint配列を連結させる
	static int[] joinArray(int[] A, int[] B){
		int[] tmp = new int[A.length + B.length];
		System.arraycopy(A, 0, tmp, 0, A.length);
		System.arraycopy(B, 0, tmp, A.length, B.length);
		return tmp;
	}
	
	//２つのint配列が等しいかどうか判定する
	static boolean arrayEqual(int[] A, int[] B){
		if(A.length != B.length)return false;
		for(int i=0; i<A.length; i++){
			if(A[i] != B[i])return false;
		}
		return true;
	}
	
	//int配列をindex順に見て、要素の重複があった場合その要素と間の要素を削除する12123→23
	static int[] calc(int[] A){
		boolean[] tmp = new boolean[A.length];
		Arrays.fill(tmp, true);
		int fetch = 0;
		while(fetch<A.length-1){
			boolean isExist = false;
			for(int i=fetch+1; i<A.length;i++){
				if(A[fetch] == A[i]){
					for(int j=fetch;j<=i;j++){
						tmp[j]=false;
					}
					fetch = i+1;
					isExist = true;
					break;
				}
			}
			if(!isExist)fetch++;
		}
		List<Integer> list = new ArrayList<>();
		for(int i=0; i<A.length; i++){
			if(tmp[i])list.add(A[i]);
		}
		
		int[] foo = new int[list.size()];
		for(int i=0; i<list.size(); i++){
			foo[i] = list.get(i);
		}
		/*
		for(boolean t : tmp)
			System.out.print(t+" ");
		*/
		return foo;
	}
	
	
	//aとbの最小公倍数を返す
	static long lcm (long a, long b) {
		long temp;
		long c = a;
		c *= b;
		while((temp = a%b)!=0) {
			a = b;
			b = temp;
		}
		return (c/b);
	}
	
	//二項係数用の前処理
	static void COMinit(){
		//二項係数演算用前処理
		fac = new long[MAX+1];
		fac[0] = 1L;
		fac[1] = 1L;
		inv = new long[MAX+1];
		inv[1] = 1L;
		finv = new long[MAX+1];
		finv[0] = 1L;
		finv[1] = 1L;
		for(int i=2;i<MAX;i++){
			fac[i] = fac[i-1] * i % MOD;
			inv[i] = MOD - inv[(int)(MOD%i)] * (MOD/i) % MOD;
			finv[i] = finv[i-1] * inv[i] % MOD;
		}
		isPreprocessing = true;
	}
	
	//二項係数i_C_jをMODで割った余りを返す
	static long COM(int i, int j){
		if(i<j)return 0;
		if(i<0 || j<0)return 0;
		if(!isPreprocessing)COMinit();
		return fac[i] * (finv[j] * finv[i-j] % MOD) % MOD;
	}
	
}

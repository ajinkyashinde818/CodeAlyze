import java.util.*;
public class Main {
  	static int mod = 1000000007;
  static int size = 200001;
	static long[] fac = new long[size];
	static long[] finv = new long[size];
	static long[] inv = new long[size];
	static int INF = Integer.MAX_VALUE;
public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	// 整数の入力
	int N = sc.nextInt();
	int[] A = new int[N];
  int[] B = new int[N];
  int[] C = new int[N-1];
  int i=0;
  int sum=0;
  int befor=-1;
  for(i=0;i<N;i++){
    A[i]=sc.nextInt();
  }
  for(i=0;i<N;i++){
    B[i]=sc.nextInt();
  }
  for(i=0;i<N-1;i++){
    C[i]=sc.nextInt();
  }
  sum=B[A[0]-1];
  for(i=1;i<N;i++){
    sum=sum+B[A[i]-1];
    befor=A[i-1];
    if(befor+1==A[i]){
      sum=sum+C[befor-1];
    }
  }
    System.out.println(sum);



} 

 //fac, inv, finvテーブルの初期化、これ使う場合はinitComb()で初期化必要
	public static  void initComb(){
		fac[0] = finv[0] = inv[0] = fac[1] = finv[1] = inv[1] = 1;
		for (int i = 2; i < size; ++i) {
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - (mod / i) * inv[(int) (mod % i)] % mod;
			finv[i] = finv[i - 1] * inv[i] % mod;
		}
	}
 
	//nCk % mod
	public static long comb(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
		return fac[n] * finv[k] % mod * finv[n - k] % mod;
	}
 
	//n! % mod
	public static long fact(int n){
		return fac[n];
	}
 
	//(n!)^-1 with % mod
	public static long finv(int n){
		return finv[n];
	}
  
}

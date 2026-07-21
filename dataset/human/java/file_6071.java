import java.util.*;
import java.lang.*;
import java.io.*;


public class Main {

    static final int MOD = 998244353;
    public static long addMod(long a, long b){
    	long tmp = (a+b)%MOD;
    	return tmp>=0 ? tmp : tmp+MOD;
    }
    public static long subMod(long a, long b){
    	return addMod(a,-b);
    }
    public static long multMod(long a, long b){
    	long tmp = (a*b)%MOD;
    	return tmp>=0 ? tmp : tmp+MOD;
    }
    public static long powerMod(long a, long x){ //calculate a^x
        if(x<0)return 0;
        if(x==0)return 1;
        if(x%2==0) {
        	long half = powerMod(a,x/2);
        	return multMod(half,half);
        }
        return (a*powerMod(a,x-1)) % MOD;
    }
    public static long inverseMod(long a){
        return powerMod(a,MOD-2);
    }
    public static long divMod(long a, long b){
    	return multMod(a, inverseMod(b));
    }
    public static long[] makeFactorialArray(int size){
        long[] array = new long[size];
        array[0]=1;
        for(int i=1;i<size;i++){
        	array[i]=multMod(array[i-1],i);
        }
        return array;
    }
    public static long[] makeInversedArray(long[] original){
        long[] array = new long[original.length];
        for(int i=0;i<original.length;i++){
        	array[i] = inverseMod(original[i]);
        }
        return array;
    }
    public static long combination(int n, int r, long[] fact, long[] factInv){
        return multMod(fact[n], multMod(factInv[r],factInv[n-r]));
    }

    public static void main(String[] args) {
        long[] fact = makeFactorialArray(10001);
        long[] factInv = makeInversedArray(fact);
        Scanner sc = new Scanner(System.in);
        
        int K = sc.nextInt();
        int N = sc.nextInt();
        for(int i=2;i<=2*K;i++){
        	System.out.println(solve(K,N,i,fact,factInv));
        }
    }

    //lemma 1.
    //roll N dice having K size
    //the number of all combinations is comb(N+K-1,N)
    public static long lemma1(int K,int N, long[] fact, long[] factInv){
        if(K<=0) return 0;
        return combination(N+K-1,K-1,fact,factInv);
    }
    public static long solve(int K, int N, int i, long[] fact, long[] factInv){
        if(i>K+1) return solve(K,N,2*K+2-i,fact,factInv);
        if(i%2==0){
        	int pair = i/2;
        	int independent = K - pair*2;
        	
        	int sign = 1;
        	long ans = 0;
        	for(int usePair = pair;usePair>=0;usePair--){
        	    long a = multMod(combination(pair,usePair,fact,factInv),powerMod(2,usePair));
        	    a = multMod(a, lemma1(independent+usePair,N,fact,factInv));
        	    ans = addMod(ans,a*sign);
        	    sign = -sign;
        	}
        	return ans;
        }else{
        	return solve(K,N,i-1,fact,factInv);
        }
    }
}

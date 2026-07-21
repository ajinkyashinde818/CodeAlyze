import java.util.*;
import java.lang.*;

class Mod{
    static final long MOD = 1000_000_007;
    static final long[] fact = makeFactorialArray(1000000);
    static final long[] factInv = makeInversedArray(fact);

    public static long add(long a, long b){
        long tmp = (a+b)%MOD;
        return tmp>=0 ? tmp : tmp+MOD;
    }
    public static long adds(long... ar){
        long ans=0;
        for(long x:ar) ans = Mod.add(ans, x);
        return ans;
    }
    public static long sub(long a, long b){
        return add(a,-b);
    }
    public static long mult(long a, long b){
        long tmp = (a*b)%MOD;
        return tmp>=0 ? tmp : tmp+MOD;
    }
    public static long mults(long... ar){
        long ans=1;
        for(long x:ar) ans = Mod.mult(ans, x);
        return ans;
    }
    public static long power(long a, long x){ //calculate a^x
        if(x<0)return 0;
        if(x==0)return 1;
        if(x%2==0) {
            long half = power(a,x/2);
            return mult(half,half);
        }
        return (a*power(a,x-1)) % MOD;
    }
    public static long inverse(long a){
        return power(a,MOD-2);
    }
    public static long div(long a, long b){
        return mult(a, inverse(b));
    }
    public static long[] makeFactorialArray(int size){
        long[] array = new long[size];
        array[0]=1;
        for(int i=1;i<size;i++){
            array[i]=mult(array[i-1],i);
        }
        return array;
    }
    public static long[] makeInversedArray(long[] original){
        long[] array = new long[original.length];
        for(int i=0;i<original.length;i++){
            array[i] = inverse(original[i]);
        }
        return array;
    }
    public static long combination(long n, long r){
        int N = (int)n,  R = (int)r;
        if(n<0 || r<0 || n<r) return 0;
        return mults(fact[N],factInv[R],factInv[N-R]);
    }
    public static long permutation(long n, long r){
        int N = (int)n,  R = (int)r;
        if(n<0 || r<0 || n<r) return 0;
        return mult(fact[N], factInv[N-R]);
    }
}

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] x = new long[N];
        for(int n=0; n<N; n++) x[n]=sc.nextLong();
        long[] d = new long[N-1];
        for(int n=0; n<N-1; n++) d[n]=x[n+1]-x[n];

        long[] c = new long[N-1];
        Arrays.fill(c,0L);


        long[] unitfracsum = new long[110000];
        for(int i=1; i<110000; i++) unitfracsum[i] = Mod.add(unitfracsum[i-1], Mod.inverse(i));

        for(int i=0; i<N-1; i++){
            c[i] = Mod.mults(Mod.fact[i+1], unitfracsum[i+1], Mod.permutation(N-1, N-i-2));
        }


        long ans = 0;
        for(int n=0; n<N-1; n++) ans = Mod.add(ans, Mod.mult(d[n], c[n]));
        System.out.println(ans);


    }

}

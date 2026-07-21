import java.util.*;
import java.util.function.*;
import java.util.stream.*;
import java.util.Map.Entry;
// import static java.util.Arrays.compare;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;
import static java.util.Collections.sort;
import static java.util.Comparator.reverseOrder;
// import static java.util.List.of;
import static java.util.Objects.isNull;
import static java.util.Objects.nonNull;
import static java.util.Objects.hash;

import java.io.*;

import java.math.BigInteger;
import static java.math.BigInteger.ZERO;
import static java.math.BigInteger.ONE;
// import static java.math.BigInteger.TWO;
import static java.math.BigInteger.TEN;

import static java.lang.Math.PI;
import static java.lang.Math.E;
import static java.lang.Math.min;
import static java.lang.Math.max;
import static java.lang.Math.abs;
import static java.lang.Math.sin;
import static java.lang.Math.cos;
import static java.lang.Math.tan;
import static java.lang.Math.asin;
import static java.lang.Math.acos;
import static java.lang.Math.atan;
import static java.lang.Math.atan2;
import static java.lang.Math.hypot;
import static java.lang.Math.sqrt;
import static java.lang.Math.log;
import static java.lang.Math.exp;
import static java.lang.String.format;
import static java.lang.System.exit;
import static java.lang.System.currentTimeMillis;

public class Main{
   public static void main(String[] args){
      FastScanner fsc = new FastScanner();
      char[] n=fsc.next().toCharArray();
      int ans=0;
      int c=0;
      for(int i=n.length-1;i>=0;i--){
         if(c==1){
            if(n[i]=='9'){
               n[i]='0';
            } else{
               n[i]+=1;
               c=0;
            }
         }

         if(n[i]-'0'>5){
            c=1;
            ans+=10-(n[i]-'0');
         } else if(n[i]-'0'==5){
            if(i==0 || (i>0 && n[i-1]-'0'<5)){
                c=0;
                ans+=5;
            } else{
               c=1;
               ans+=10-(n[i]-'0');
            }
         } else{
            ans+=n[i]-'0';
         }
      }

      if(c==1) ans++;
      System.out.println(ans);
   }
}


class ArrayUtil{
    public static int[] input(FastScanner fsc, int n){
        int[] a=new int[n];
        for(int i=0;i<n;i++){
            a[i]=fsc.nextInt();
        }
        return a;
    }
    public static int[][] input(FastScanner fsc, int n, int m){
        int[][] a=new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]=fsc.nextInt();
            }
        }
        return a;
    }
    public static int[] map(IntUnaryOperator op, int[] a){
        int[] b=new int[a.length];
        for(int i=0;i<a.length;i++) b[i] = op.applyAsInt(a[i]);
        return b;
    }
    /**
     * s[i] is the sum of the range [0, i) in a.
     * @param a
     * @return cumulative sum array of a.
     */
    public static int[] cumsum(int[] a){
        int n=a.length;
        int[] s=new int[n+1];
        for(int i=1;i<=n;i++){
            s[i]=s[i-1]+a[i-1];
        }
        return s;
    }
    public static int[][] cumsum(int[][] a){
        int n=a.length;
        int m=a[0].length;
        int[][] s=new int[n+1][m+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i-1][j-1];
            }
        }
        return s;
    }
    public static void reverse(int[] a, int begin, int end){
        for(int i=begin;i<begin+(end-begin)/2;i++){
            swap(a, i, begin+end-i-1);
        }
    }
    public static void reverse(int[] a){
        reverse(a, 0, a.length);
    }
    public static void revSort(int[] a){
        Arrays.sort(a);
        reverse(a);
    }
    public static int[] nextPermutation(int[] a){
        int[] ret=a.clone();
        int n=ret.length;
        for(int i=n-1;i>=1;i--){
            if(ret[i]>ret[i-1]){
                int fail=n, pass=i;
                while(fail-pass>1){
                    int mid=pass+(fail-pass)/2;
                    if(ret[mid]>ret[i-1]) pass=mid;
                    else fail=mid;
                }
                swap(ret, pass, i-1);
                reverse(ret, i, n);
                return ret;
            }
        }
        return null;
    }
    public static int[] predPermutation(int[] a){
        int[] ret=a.clone();
        int n=ret.length;
        for(int i=n-1;i>=1;i--){
            if(ret[i]<ret[i-1]){
                int fail=n, pass=i;
                while(fail-pass>1){
                    int mid=pass+(fail-pass)/2;
                    if(ret[mid]<ret[i-1]) pass=mid;
                    else fail=mid;
                }
                swap(ret, pass, i-1);
                reverse(ret, i, n);
                return ret;
            }
        }
        return null;
    }
    public static void swap(int[] a, int u, int v){
        int tmp=a[u];
        a[u]=a[v];
        a[v]=tmp;
    }
    public static int compare(int[] a, int[] b){
        for(int i=0;i<a.length;i++){
            if(i>=b.length){
                return -1;
            } else if(a[i]>b[i]){
                return 1;
            } else if(a[i]<b[i]){
                return -1;
            }
        }
        if(a.length<b.length){
            return 1;
        } else{
            return 0;
        }
    }
    public static boolean equals(int[] a, int[] b){
        return compare(a, b)==0;
    }

    /*
     *      IntArray
     * _________________________
     *      LongArray
     */

    public static long[] linput(FastScanner fsc, int n){
        long[] a=new long[n];
        for(int i=0;i<n;i++){
            a[i]=fsc.nextLong();
        }
        return a;
    }
    public static long[][] linput(FastScanner fsc, int n, int m){
        long[][] a=new long[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]=fsc.nextLong();
            }
        }
        return a;
    }
    public static long[] map(LongUnaryOperator op, long[] a){
        long[] b=new long[a.length];
        for(int i=0;i<a.length;i++) b[i]=op.applyAsLong(a[i]);
        return b;
    }
    /**
     * s[i] is the sum of the range [0, i) in a.
     * @param a
     * @return cumulative sum array of a.
     */
    public static long[] cumsum(long[] a){
        int n=a.length;
        long[] s=new long[n+1];
        for(int i=1;i<=n;i++){
            s[i]=s[i-1]+a[i-1];
        }
        return s;
    }
    public static long[][] cumsum(long[][] a){
        int n=a.length;
        int m=a[0].length;
        long[][] s=new long[n+1][m+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i-1][j-1];
            }
        }
        return s;
    }
    public static void reverse(long[] a, int begin, int end){
        for(int i=begin;i<begin+(end-begin)/2;i++){
            long tmp=a[i];
            a[i]=a[begin+end-i-1];
            a[begin+end-i-1]=tmp;
        }
    }
    public static void reverse(long[] a){
        reverse(a, 0, a.length);
    }
    public static void revSort(long[] a){
        Arrays.sort(a);
        reverse(a);
    }
    public static void compress(long[] a){
        int n=a.length;
        long[] sorted = a.clone();
        Arrays.sort(sorted);
        for(int i=0;i<n;i++){
            int l=0, r=n;
            while(r-l>1){
                int m=l+(r-l)/2;
                if(sorted[m]<=a[i]) l=m;
                else r=m;
            }
            a[i]=l;
        }
    }
    public static long[] nextPermutation(long[] a){
        long[] ret=a.clone();
        int n=ret.length;
        for(int i=n-1;i>=1;i--){
            if(ret[i]>ret[i-1]){
                int fail=n, pass=i;
                while(fail-pass>1){
                    int mid=pass+(fail-pass)/2;
                    if(ret[mid]>ret[i-1]) pass=mid;
                    else fail=mid;
                }
                swap(ret, pass, i-1);
                reverse(ret, i, n);
                return ret;
            }
        }
        return null;
    }
    public static long[] predPermutation(long[] a){
        long[] ret=a.clone();
        int n=ret.length;
        for(int i=n-1;i>=1;i--){
            if(ret[i]<ret[i-1]){
                int fail=n, pass=i;
                while(fail-pass>1){
                    int mid=pass+(fail-pass)/2;
                    if(ret[mid]<ret[i-1]) pass=mid;
                    else fail=mid;
                }
                swap(ret, pass, i-1);
                reverse(ret, i, n);
                return ret;
            }
        }
        return null;
    }
    public static void swap(long[] a, int u, int v){
        long tmp=a[u];
        a[u]=a[v];
        a[v]=tmp;
    }
    public static int compare(long[] a, long[] b){
        for(int i=0;i<a.length;i++){
            if(i>=b.length){
                return -1;
            } else if(a[i]>b[i]){
                return 1;
            } else if(a[i]<b[i]){
                return -1;
            }
        }
        if(a.length<b.length){
            return 1;
        } else{
            return 0;
        }
    }
    public static boolean equals(long[] a, long[] b){
        return compare(a, b)==0;
    }
}


class BellmanFord{
    public long[] bellmanFord(Node[] nodes, int s){
        int n = nodes.length;
        boolean negativeLoop[] = new boolean[n];
        long[] d = new long[n];
        fill(d, Const.LINF);
        d[s] = 0;
        for(int i = 0; i < n; i++){
            for(int from = 0; from < n; from++){
                for(Edge edge: nodes[from].edges){
                    int to = edge.to;
                    long c = edge.cost;
                    if(d[to] > d[from] + c){
                        d[to] = d[from]+c;
                    }
                }
            }
        }           
        for(int i = 0; i < n; i++){
            for(int from = 0; from < n; from++){
                for(Edge edge: nodes[from].edges){
                    int to = edge.to;
                    long c = edge.cost;
                    if(d[to] > d[from] + c){
                        negativeLoop[to] = true;
                        d[to] = -Const.LINF;
                    }
                    if(negativeLoop[from]){
                        negativeLoop[to] = true;
                        d[to] = -Const.LINF;
                    }
                }
            }
        }
        return d;
    }
    public long bellmanFord(Node[] nodes, int s, int t){
        return bellmanFord(nodes, s)[t];
    }
}

/**
 * BinaryIndexedTree(n=10): [ 8 ] [ 4 ] [ 2 ] [ 6 ] [ 10 ] [1] [3] [5] [7] [9]
 * 
 * original array: (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
 * 
 * if you want to get the sum of range (l, r], caluculate S(r)-S(l). (S(n) means
 * \sum_{i=1}^n array[i].)
 * 
 * then, you need to be able to calculate S(n) quickly. actually, you can.
 * 
 * 1. binarize n. Ex: n=5(10)=101(2). 2. decompose
 * n=2**p_1+2**p_2+...+2**p_m.(p_1<...<p_m) Ex: n=1+100. 3. acutually,
 * S(n)=\sum_{i=1}^m{tree[\sum_{j=i}^m 2**p_j]} Ex: S(n)=tree[101]+tree[100].
 * 
 * computational complexity of sum-query is O(log n).
 */

class BinaryIndexedTree{
    private int[] tree;
    private int[] originalArray;
    private int n;
    /**
     * @param array 0-indexed array.
     */
    public BinaryIndexedTree(int[] array){
        this.originalArray = array.clone();
        this.n = array.length;
        this.tree = new int[n+1];
        init();
    }
    public BinaryIndexedTree(int initial, int n){
        this.originalArray = new int[n];
        this.n = n;
        this.tree = new int[n+1];
        for(int i = 0; i < n; i++) originalArray[i] = initial;
        init();
    }
    public BinaryIndexedTree(int n){
        this(0, n);
    }
    private void init(){
        for(int i = 1; i <= n; i++){
            tree[i] += originalArray[i-1];
            int parent = i + (-i & i);
            if(parent <= n) tree[parent] += tree[i];
        }
    }

    /**
     * Calculate the sum of range (l, r] in array (1-indexed).
     * @param l left border (open)
     * @param r right border (closed)
     * @return sum of range (l, r] in array (1-indexed).
     */
    public int sum(int l, int r){
        return sum(r) - sum(l);
    }
    public int sum(int r){
        int ret = 0;
        for(; r > 0; r -= -r & r) ret += tree[r];
        return ret;
    }
    public int sum(){
        return sum(n);
    }

    /**
     * add v to array[i] and update BIT.
     * @param i index of array (1-indexed)
     * @param v adding value
     */
    public void add(int i, int v){
        originalArray[i-1] += v;
        for(; i <= n; i += -i & i) tree[i] += v;
    }

    /**
     * update the value of array[i] to v and update BIT.
     * @param i index of array (1-indexed)
     * @param v adding value
     */
    public void update(int i, int v){
        add(i, v - originalArray[i-1]);
        originalArray[i] = v;
    }

    @Override
    public String toString(){
        int msb=0;
        for(int m=n;m>>1!=0;m>>=1, msb++);
        char[][] c=new char[msb+1][1<<(2*msb+1)];
        int[] indx=new int[msb+1];
        for(int i=1;i<=n;i++){
            int j=0;
            for(int l=-i&i;l>>1!=0;l>>=1, j++);
            char[] intc=Integer.toString(tree[i]).toCharArray();
            int intl=intc.length;
            c[j][indx[j]]='[';
            c[j][indx[j]+(1<<(j+2))-1]=']';
            int st=indx[j]+(1<<(j+1))-intl/2-1;
            for(int l=0;l<intl;l++){
                c[j][st+l]=intc[l];
            }
            indx[j]+=1<<(j+3);
        }
        StringBuilder sb=new StringBuilder();
        for(int i=msb;i>=0;sb.append(String.valueOf(c[i--])).append("\n"));
        return sb.toString();
    }
}


class Complex implements Cloneable{
    public static final double PI=Math.PI;
    public static final Complex I=new Complex(0, 1);
    public static final Complex ZERO=new Complex(0, 0);
    public static final Complex ONE=new Complex(1, 0);

    public double x;
    public double y;
    public double r;
    public double theta;

    public Complex(double x, double y){
        this.x=x;
        this.y=y;
        this.r=Math.hypot(x, y);
        this.theta=Math.atan2(y, x);
    }
    public Complex(double r, double theta, boolean radian){
        this.r=r;
        if(radian){
            this.theta=theta;
        } else{
            this.theta=Math.toRadians(theta);
        }
        this.x=this.r*Math.cos(this.theta);
        this.y=this.r*Math.sin(this.theta);
    }
    public Complex(double theta, boolean radian){
        this(1., theta, radian);
    }

    private double re(){
        return x;
    }
    private double im(){
        return y;
    }
    private double abs(){
        return r;
    }
    private double arg(){
        return theta;
    }
    private Complex conj(){
        return new Complex(x, -y);
    }
    private double sin(){
        return Math.sin(arg());
    }
    private double cos(){
        return Math.cos(arg());
    }
    private double tan(){
        return Math.tan(arg());
    }
    private Complex rot(double phi, boolean radian){
        return new Complex(r, theta+(radian?phi:Math.toRadians(phi)), true);
    }
    private Complex exp(int n){
        return new Complex(Math.pow(r, n), theta*n, true);
    }
    private double dist(Complex c){
        return abs(this.sub(c));
    }

    private Complex add(Complex c){
        return new Complex(x+c.x, y+c.y);
    }
    private Complex sub(Complex c){
        return new Complex(x-c.x, y-c.y);
    }
    private Complex mul(Complex c){
        return new Complex(x*c.x-y*c.y, x*c.y+y*c.x);
    }
    private Complex div(Complex c){
        double retx, rety;
        if(c.equals(ZERO)){
            if(x>0){
                retx=Double.POSITIVE_INFINITY;
            } else if(x<0){
                retx=Double.NEGATIVE_INFINITY;
            } else{
                retx=Double.NaN;
            }
            if(y>0){
                rety=Double.POSITIVE_INFINITY;
            } else if(y<0){
                rety=Double.NEGATIVE_INFINITY;
            } else{
                rety=Double.NaN;
            }
            return new Complex(retx, rety);
        }
        return mul(div(this, c.r), new Complex(-c.theta, true));
    }

    private Complex add(double r){
        return new Complex(x+r, y);
    }
    private Complex sub(double r){
        return new Complex(x-r, y);
    }
    private Complex mul(double r){
        return new Complex(x*r, y*r);
    }
    private Complex div(double r){
        return new Complex(x/r, y/r);
    }

    public static Complex conj(Complex c){
        return c.conj();
    }
    public static double re(Complex c){
        return c.re();
    }
    public static double im(Complex c){
        return c.im();
    }
    public static double abs(Complex c){
        return c.abs();
    }
    public static double arg(Complex c){
        return c.arg();
    }
    public static double sin(Complex c){
        return c.sin();
    }
    public static double cos(Complex c){
        return c.cos();
    }
    public static double tan(Complex c){
        return c.tan();
    }
    public static Complex rot(Complex c, double phi, boolean radian){
        return c.rot(phi, radian);
    }
    public static Complex exp(Complex c, int n){
        return c.exp(n);
    }
    public static double dist(Complex a, Complex b){
        return a.dist(b);
    }
    public static Complex[] nthRoot(int n){
        Complex[] ret=new Complex[n];
        for(int i=0;i<n;i++){
            ret[i]=new Complex(2.*PI*i/n, true);
        }
        return ret;
    }

    public static Complex add(Complex a, Complex... c){
        Complex ret=a.clone();
        for(Complex b:c){
            ret=ret.add(b);
        }
        return ret;
    }
    public static Complex sub(Complex a, Complex... c){
        Complex ret=a.clone();
        for(Complex b:c){
            ret=ret.sub(b);
        }
        return ret;
    }
    public static Complex mul(Complex a, Complex... c){
        Complex ret=a.clone();
        for(Complex b:c){
            ret=ret.mul(b);
        }
        return ret;
    }
    public static Complex div(Complex a, Complex... c){
        Complex ret=a.clone();
        for(Complex b:c){
            ret=ret.div(b);
        }
        return ret;
    }

    public static Complex add(Complex a, double r, Complex... c){
        return add(a.add(r), c);
    }
    public static Complex sub(Complex a, double r, Complex... c){
        return sub(a.sub(r), c);
    }
    public static Complex mul(Complex a, double r, Complex... c){
        return mul(a.mul(r), c);
    }
    public static Complex div(Complex a, double r, Complex... c){
        return div(a.div(r), c);
    }

    public static Complex pM(Complex a, Complex b){
        return div(add(a, b), 2.);
    }
    public static Complex internalDivision(Complex a, Complex b, int m, int n){
        return div(add(mul(a, n), mul(b, m)), m+n);
    }
    public static Complex externalDivision(Complex a, Complex b, int m, int n){
        return internalDivision(a, b, -m, n);
    }

    public static Complex pG(Complex a, Complex b, Complex c){
        return div(add(a, b, c), 3.); 
    }
    public static Complex pH(Complex a, Complex b, Complex c){
        double tanA=Math.tan(arg(c, a, b));
        double tanB=Math.tan(arg(a, b, c));
        double tanC=Math.tan(arg(b, c, a));
        return div(add(mul(a, tanA), mul(b, tanB), mul(c, tanC)), tanA + tanB + tanC);
    }
    public static Complex pI(Complex a, Complex b, Complex c){
        double la=abs(sub(b, c));
        double lb=abs(sub(c, a));
        double lc=abs(sub(a, b));
        return div(add(mul(a, la), mul(b, lb), mul(c, lc)), la + lb + lc);
    }
    public static Complex pO(Complex a, Complex b, Complex c){
        double la=abs(sub(b, c)); la*=la;
        double lb=abs(sub(c, a)); lb*=lb;
        double lc=abs(sub(a, b)); lc*=lc;
        double sa=la*(lb+lc-la);
        double sb=lb*(lc+la-lb);
        double sc=lc*(la+lb-lc);
        return div(add(mul(a, sa), mul(b, sb), mul(c, sc)), sa+sb+sc);
    }
    public static Complex[] pIabc(Complex a, Complex b, Complex c){
        Complex[] pIabc=new Complex[3];
        pIabc[0]=pI(mul(a, -1.), b, c);
        pIabc[1]=pI(a, mul(b, -1.), c);
        pIabc[2]=pI(a, b, mul(c, -1.));
        return pIabc;
    }

    public static boolean onLine(Complex a, Complex b, Complex... c){
        for(Complex z:c){
            if(PI-arg(a, b, z)>=0.0000001){
                return false;
            }
        }
        return true;
    }

    public static double arg(Complex a, Complex b, Complex c){
        double arg=arg(div(sub(c, b), sub(a, b)));
        if(arg<0){
            arg*=-1.;
        }
        return arg;
    }

    private Complex(double x, double y, double r, double theta){
        this.x=x;
        this.y=y;
        this.r=r;
        this.theta=theta;
    }

    @Override 
    public Complex clone(){
        return new Complex(this.x, this.y, this.r, this.theta);
    }
    @Override
    public boolean equals(Object o){
        if(o==this){
            return true;
        } else if(o instanceof Complex){
            Complex c=(Complex) o;
            if(c.x==this.x && c.y==this.y && c.r==this.r && c.theta==this.theta){
                return true;
            } else{
                return false;
            }
        } else{
            return false;
        }
    }
    @Override
    public int hashCode(){
        return Objects.hash(x, y, r, theta);
    }
    @Override
    public String toString(){
        return "(x, y) = ("+x+", "+y+"), (r, theta) = ("+r+", "+theta+").";
    }
}

class Const{
    public static long MOD = 1_000_000_007;
    public static final long LINF = 1_000_000_000_000_000_000l;
    public static final int IINF = 1_000_000_000;
    public static void setMod(long mod){
        MOD = mod;
    }
}


class Coordinate{
    private static double PI=Math.PI;
    private static double DELTA=0.0000001;
    private static double P_INF=1e100;
    private static double N_INF=-1e100;
    private static double NaN=Double.NaN;

    public static double innerProduct(Complex u, Complex v){
        return u.x*v.x+u.y+v.y;
    }
    public static double outerProductZ(Complex u, Complex v){
        return u.x*v.y-u.y*v.x;
    }

    public static Complex pM(Complex a, Complex b){
        return Complex.div(Complex.add(a, b), 2.);
    }
    public static Complex internalDivision(Complex a, Complex b, int m, int n){
        return Complex.div(Complex.add(Complex.mul(a, n), Complex.mul(b, m)), m+n);
    }
    public static Complex externalDivision(Complex a, Complex b, int m, int n){
        return internalDivision(a, b, -m, n);
    }

    public static Complex pG(Complex a, Complex b, Complex c){
        if(!isTriangle(a, b, c)){
            return null;
        }
        return Complex.div(Complex.add(a, b, c), 3.); 
    }
    public static Complex pH(Complex a, Complex b, Complex c){
        if(!isTriangle(a, b, c)){
            return null;
        }
        Complex pO=pO(a, b, c);
        return Complex.add(Complex.sub(a, pO), Complex.sub(b, pO), Complex.sub(c, pO), pO);
    }
    public static Complex pI(Complex a, Complex b, Complex c){
        if(!isTriangle(a, b, c)){
            return null;
        }
        double la=Complex.dist(b, c);
        double lb=Complex.dist(c, a);
        double lc=Complex.dist(a, b);
        return Complex.div(Complex.add(Complex.mul(a, la), Complex.mul(b, lb), Complex.mul(c, lc)), la + lb + lc);
    }
    public static Complex pO(Complex a, Complex b, Complex c){
        if(!isTriangle(a, b, c)){
            return null;
        }
        double la=Complex.distSq(b, c);
        double lb=Complex.distSq(c, a);
        double lc=Complex.distSq(a, b);
        double sa=la*(lb+lc-la);
        double sb=lb*(lc+la-lb);
        double sc=lc*(la+lb-lc);
        return Complex.div(Complex.add(Complex.mul(a, sa), Complex.mul(b, sb), Complex.mul(c, sc)), sa+sb+sc);
    }
    public static Complex[] pIabc(Complex a, Complex b, Complex c){
        if(!isTriangle(a, b, c)){
            return null;
        }
        Complex[] pIabc=new Complex[3];
        pIabc[0]=pI(Complex.mul(a, -1.), b, c);
        pIabc[1]=pI(a, Complex.mul(b, -1.), c);
        pIabc[2]=pI(a, b, Complex.mul(c, -1.));
        return pIabc;
    }

    public static boolean onLine(Line l, Complex c){
        return Math.abs(l.a*c.x+l.b*c.y+l.c)<DELTA && c.x>=l.lx && c.x<=l.rx && c.y>=l.ly && c.y<=l.ry;
    }

    public static boolean oneLine(Complex a, Complex b, Complex c){
        if(a.equals(b) || b.equals(c) || c.equals(a)){
            return true;
        }
        double arg=arg(a, b, c);
        return arg<=DELTA || arg>=PI-DELTA;
    }

    public static boolean isTriangle(Complex a, Complex b, Complex c){
        return !oneLine(a, b, c);
    }

    public static double dist(Line l, Complex c){
        return Math.abs(l.a*c.x+l.b*c.y+l.c);
    }

    public static Complex crossPoint(Line l1, Line l2){
        Complex o=l1.begin;
        Complex v1=Complex.sub(l1.end, o);
        Complex v2=Complex.sub(l2.begin, o);
        Complex v3=Complex.sub(l2.end, o);
        double opz12=Coordinate.outerProductZ(v1, v2);
        double opz13=Coordinate.outerProductZ(v1, v3);
        if((opz12>0 && opz13>0) || (opz12<0 && opz13<0)){
            return null;
        }
        double p=l1.a*l2.b-l2.a*l1.b;
        double qx=l1.b*l2.c-l2.b*l1.c;
        double qy=l2.a*l1.c-l1.a*l2.c;
        if(Math.abs(p)<=DELTA){
            if(Math.abs(qx)<=DELTA && Math.abs(qy) <= DELTA){
                return new Complex(NaN, NaN);
            } else{
                return new Complex(P_INF, P_INF);
            }
        } else{
            return new Complex(qx/p, qy/p);
        }
    }

    public static Complex[] crossPoint(Circle c, Line l){
        double d=dist(l, c.c);
        if(c.r<d){
            return null;
        } else if(c.r-d<DELTA){
            Complex v=Complex.mul(new Complex(l.a, l.b), c.r);
            Complex p=onLine(l, Complex.add(c.c, v))?Complex.add(c.c, v):Complex.sub(c.c, v);
            Complex[] ret={p};
            return ret;
        } else{
            if(c.in(l.begin) && c.in(l.end)){
                return null;
            } else {
                ArrayList<Complex> cross=new ArrayList<>();
                Complex v=Complex.mul(new Complex(l.a, l.b), d);
                for(int i=0;i<2;i++){
                    Complex h=i==0?Complex.add(c.c, v):Complex.sub(c.c, v);
                    for(int j=0;j<2;j++){
                        Complex mov=j==0?new Complex(-l.b, l.a):new Complex(l.b, -l.a);
                        Complex p=Complex.add(h, mov);
                        if(onLine(l, p)){
                            cross.add(p);
                        }
                    }
                }
                return (Complex[]) cross.toArray();
            }
        }
    }

    public static Complex[] crossPoint(Circle c1, Circle c2){
        double d=Complex.dist(c1.c, c2.c);
        if(d>c1.r+c2.r+DELTA){
            return null;
        } else if(Math.abs(c1.r+c2.r-d)<=DELTA){
            Complex[] ret={Complex.mul(Complex.sub(c2.c, c1.c), c1.r/d)};
            return ret;
        } else if(d>Math.abs(c1.r-c2.r)+DELTA){
            double a=c1.r, b=c2.r;
            double l=(a+b+d)*(a+b-d)*(a-b+d)*(-a+b+d)/(4*d*d);
            Complex h=Complex.mul(Complex.sub(c2.c, c1.c), (d*d+a*a-b*b)/(2*d*d));
            Line line=Line.create(c1.c, c2.c, false, false);
            Complex mov=Complex.mul(new Complex(line.b, -line.a), l);
            Complex[] ret={Complex.add(h, mov), Complex.sub(h, mov)};
            return ret;
        } else if(Math.abs(Math.abs(c1.r-c2.r)-d)<=DELTA){
            if(c1.r>c2.r){
                Complex[] ret={Complex.mul(Complex.sub(c2.c, c1.c), c1.r/d)};
                return ret;
            } else if(c1.r<c2.r){
                Complex[] ret={Complex.mul(Complex.sub(c1.c, c2.c), c2.r/d)};
                return ret;
            } else{
                Complex[] ret={new Complex(NaN, NaN)};
                return ret;
            }
        } else{
            return null;
        }
    }

    public static double arg(Complex a, Complex b, Complex c){
        double arg=Complex.arg(Complex.div(Complex.sub(c, b), Complex.sub(a, b)));
        if(arg<0){
            arg*=-1.;
        }
        return arg;
    }

    static class Circle{
        public Complex c;
        public double r;
         
        public Circle(Complex center, double radius){
            this.c=center;
            this.r=Math.abs(radius);
        }

        public boolean inon(Complex z){
            return Complex.dist(c, z) <= r + DELTA;
        }
        public boolean in(Complex z){
            return Complex.dist(c, z) < r-DELTA;
        }
        public boolean on(Complex z){
            return inon(z) && !in(z);
        }
    }

    static class Line{
        // a*a+b*b=1.
        public double a, b ,c;
        public double t;
        public double lx, rx, ly, ry;
        public Complex begin, end;

        public static Line create(Complex a, Complex b, boolean extendA, boolean extendB){
            if(a.x>b.x){
                return new Line(b, a, extendB, extendA);
            } else {
                return new Line(a, b, extendA, extendB);
            }
        }

        private Line(Complex a, Complex b, boolean extendA, boolean extendB){
            this.a=b.y-a.y;
            this.b=a.x-b.x;
            this.c=-a.x*b.y+b.x*a.y;
            double hp=Math.hypot(this.a, this.b);
            this.a/=hp;
            this.b/=hp;
            this.c/=hp;
            if(a.x==b.x){
                this.t=P_INF;
                if(a.y<b.y){
                    if(!extendA){
                        this.begin=a.clone();
                        this.lx=a.x;
                        this.ly=a.y;
                    } else{
                        this.begin=new Complex(this.lx=a.x, this.ly=N_INF);
                    }
                    if(!extendB){
                        this.end=b.clone();
                        this.rx=b.x;
                        this.ry=b.y;
                    } else{
                        this.end=new Complex(this.rx=b.x, this.ry=P_INF);
                    }
                }
            } else {
                this.t=(b.y-a.y)/(b.x-a.x);
                if(!extendA){
                    this.begin=a.clone();
                    this.lx=a.x;
                    this.ly=a.y;
                } else{
                    if(t>0){
                        if(t>=1.){
                            this.begin=new Complex(this.lx=x(N_INF), this.ly=N_INF);
                        } else{
                            this.begin=new Complex(this.lx=N_INF, this.ly=y(N_INF));
                        }
                    } else{
                        if(t<=-1.){
                            this.begin=new Complex(this.lx=x(P_INF), this.ly=P_INF);
                        } else{
                            this.begin=new Complex(this.lx=N_INF, this.ly=y(N_INF));
                        }
                    }
                }
                if(!extendB){
                    this.end=b.clone();
                    this.rx=b.x;
                    this.ry=b.y;
                } else{
                    if(t>0){
                        if(t>=1.){
                            this.begin=new Complex(this.rx=x(P_INF), this.ry=P_INF);
                        } else{
                            this.begin=new Complex(this.rx=P_INF, this.ry=y(P_INF));
                        }
                    } else{
                        if(t<=-1.){
                            this.begin=new Complex(this.rx=x(N_INF), this.ry=N_INF);
                        } else{
                            this.begin=new Complex(this.rx=P_INF, this.ry=y(P_INF));
                        }
                    }
                }
            }
        }
        
        private double x(double y){
            return -(b*y+c)/a;
        }
        private double y(double x){
            return -(a*x+c)/b;
        }
    }

    static class Complex implements Cloneable{
        public static final Complex I=new Complex(0, 1);
        public static final Complex ZERO=new Complex(0, 0);
        public static final Complex ONE=new Complex(1, 0);
    
        public double x;
        public double y;
        public double r;
        public double theta;
    
        public Complex(double x, double y){
            this.x=x;
            this.y=y;
            this.r=Math.hypot(x, y);
            this.theta=Math.atan2(y, x);
        }
        public Complex(double r, double theta, boolean radian){
            this.r=r;
            if(!radian){
                theta=Math.toRadians(theta);
            }
            this.theta=theta%PI;
            this.x=this.r*Math.cos(this.theta);
            this.y=this.r*Math.sin(this.theta);
        }
        public Complex(double theta, boolean radian){
            this(1., theta, radian);
        }
    
        private double re(){
            return x;
        }
        private double im(){
            return y;
        }
        private double abs(){
            return r;
        }
        private double arg(){
            return theta;
        }
        private Complex conj(){
            return new Complex(x, -y);
        }
        private double sin(){
            return Math.sin(arg());
        }
        private double cos(){
            return Math.cos(arg());
        }
        private double tan(){
            return Math.tan(arg());
        }
        private Complex rot(double phi, boolean radian){
            return new Complex(r, theta+(radian?phi:Math.toRadians(phi)), true);
        }
        private Complex exp(int n){
            return new Complex(Math.pow(r, n), theta*n, true);
        }
        private double dist(Complex c){
            return abs(this.sub(c));
        }
        private double distSq(Complex c){
            return c.x*c.x+c.y*c.y;
        }
    
        private Complex add(Complex c){
            return new Complex(x+c.x, y+c.y);
        }
        private Complex sub(Complex c){
            return new Complex(x-c.x, y-c.y);
        }
        private Complex mul(Complex c){
            return new Complex(x*c.x-y*c.y, x*c.y+y*c.x);
        }
        private Complex div(Complex c){
            double retx, rety;
            if(c.equals(ZERO)){
                if(x>0){
                    retx=Double.POSITIVE_INFINITY;
                } else if(x<0){
                    retx=Double.NEGATIVE_INFINITY;
                } else{
                    retx=NaN;
                }
                if(y>0){
                    rety=Double.POSITIVE_INFINITY;
                } else if(y<0){
                    rety=Double.NEGATIVE_INFINITY;
                } else{
                    rety=NaN;
                }
                return new Complex(retx, rety);
            }
            return mul(div(this, c.r), new Complex(-c.theta, true));
        }
    
        private Complex add(double r){
            return new Complex(x+r, y);
        }
        private Complex sub(double r){
            return new Complex(x-r, y);
        }
        private Complex mul(double r){
            return new Complex(x*r, y*r);
        }
        private Complex div(double r){
            return new Complex(x/r, y/r);
        }
    
        public static Complex conj(Complex c){
            return c.conj();
        }
        public static double re(Complex c){
            return c.re();
        }
        public static double im(Complex c){
            return c.im();
        }
        public static double abs(Complex c){
            return c.abs();
        }
        public static double arg(Complex c){
            return c.arg();
        }
        public static double sin(Complex c){
            return c.sin();
        }
        public static double cos(Complex c){
            return c.cos();
        }
        public static double tan(Complex c){
            return c.tan();
        }
        public static Complex rot(Complex c, double phi, boolean radian){
            return c.rot(phi, radian);
        }
        public static Complex exp(Complex c, int n){
            return c.exp(n);
        }
        public static double dist(Complex a, Complex b){
            return a.dist(b);
        }
        public static double distSq(Complex a, Complex b){
            return a.distSq(b);
        }
        public static Complex[] nthRoot(int n){
            Complex[] ret=new Complex[n];
            for(int i=0;i<n;i++){
                ret[i]=new Complex(2.*PI*i/n, true);
            }
            return ret;
        }
    
        public static Complex add(Complex a, Complex... c){
            Complex ret=a.clone();
            for(Complex b:c){
                ret=ret.add(b);
            }
            return ret;
        }
        public static Complex sub(Complex a, Complex... c){
            Complex ret=a.clone();
            for(Complex b:c){
                ret=ret.sub(b);
            }
            return ret;
        }
        public static Complex mul(Complex a, Complex... c){
            Complex ret=a.clone();
            for(Complex b:c){
                ret=ret.mul(b);
            }
            return ret;
        }
        public static Complex div(Complex a, Complex... c){
            Complex ret=a.clone();
            for(Complex b:c){
                ret=ret.div(b);
            }
            return ret;
        }
    
        public static Complex add(Complex a, double r, Complex... c){
            return add(a.add(r), c);
        }
        public static Complex sub(Complex a, double r, Complex... c){
            return sub(a.sub(r), c);
        }
        public static Complex mul(Complex a, double r, Complex... c){
            return mul(a.mul(r), c);
        }
        public static Complex div(Complex a, double r, Complex... c){
            return div(a.div(r), c);
        }
    
        private Complex(double x, double y, double r, double theta){
            this.x=x;
            this.y=y;
            this.r=r;
            this.theta=theta;
        }
    
        @Override 
        public Complex clone(){
            return new Complex(this.x, this.y, this.r, this.theta);
        }
        @Override
        public boolean equals(Object o){
            if(o==this){
                return true;
            } else if(o instanceof Complex){
                Complex c=(Complex) o;
                // if(c.x==this.x && c.y==this.y && c.r==this.r && c.theta==this.theta){
                //     return true;
                // } else{
                //     return false;
                // }
                return dist(c)<DELTA;
            } else{
                return false;
            }
        }
        @Override
        public int hashCode(){
            return Objects.hash(x, y, r, theta);
        }
        @Override
        public String toString(){
            return 
            "(x, y) = ("+x+", "+y+"), (r, theta(rad), theta(deg)) = ("+r+", "+theta+", "+Math.toDegrees(theta)+").";
        }
    }
}


class Dijkstra{
    public static Info dijkstra(Node[] nodes, int s){
        return dijkstra(nodes, s, -1);
    }   
    public static Info dijkstra(Node[] nodes, int s, int t){
        int n = nodes.length;
        int[] prev = new int[n];
        long[] d = new long[n];
        Queue<Integer> pq = new PriorityQueue<>((u, v) -> Long.compare(d[u], d[v]));
        fill(d, Const.LINF);
        d[s] = 0;
        pq.add(s);
        while(pq.size() > 0){
            int now = pq.poll();
            if(now == t) break;
            for(Edge e: nodes[now].edges){
                int next = e.to;
                long c = e.cost;
                if(d[now] + c < d[next]){
                    d[next] = d[now] + c;
                    prev[next] = now;
                    pq.add(next);
                }
            }
        }
        return new Info(prev, d);
    }

    public static int[] path(Info info, int from, int to){
        ArrayList<Integer> rev=new ArrayList<>();
        for(int now = to; now != from; now = info.prev[now]){
            rev.add(now);
        }
        rev.add(from);
        int[] path = new int[rev.size()];
        for(int i = 0; i < path.length; i++) path[i] = rev.get(path.length - i - 1);
        return path;
    }

    static class Info{
        public int[] prev;
        public long[] d;
        public Info(int[] prev, long[] d){
            this.prev=prev;
            this.d=d;
        }
        public int prev(int i){
            return prev[i];
        }
        public long d(int to){
            return d[to];
        }
    }
}


//caluculate maximum-flow in O(|E|*|V|^2), but often fast.
class Dinic{
    static void addEdge(int from, int to, long cap, Node[] nodes) {
        nodes[from].edges.add(new Edge(to, cap, nodes[to].edges.size()));
        nodes[to].edges.add(new Edge(from, 0l, nodes[from].edges.size() - 1));
    }

    static long dinic(int s, int t, int n, Node[] nodes) {
        long flow = 0;
        int[] level, iter;
        while (true) {
            level = bfs(s, t, n, nodes);
            if (level[t] < 0) {
                break;
            }
            iter = new int[n];
            long f = dfs(s, t, nodes, Const.LINF, level, iter);
            while (f > 0) {
                flow += f;
                f = dfs(s, t, nodes, Const.LINF, level, iter);
            }
        }
        return flow;
    }

    private static int[] bfs(int s, int t, int n, Node[] nodes) {
        IntQueue iq = new IntQueue(n);
        iq.addLast(s);
        int[] level = new int[n];
        fill(level, -1);
        level[s] = 0;
        while (iq.size() > 0) {
            int now = iq.pollFirst();
            for (Edge e : nodes[now].edges) {
                if (level[e.to] < 0 && e.cap > 0) {
                    iq.addLast(e.to);
                    level[e.to] = level[now] + 1;
                }
            }
        }
        return level;
    }

    private static long dfs(int now, int t, Node[] nodes, long f, int[] level, int[] iter) {
        if (now == t) return f;
        for (int i = iter[now]++; i < nodes[now].edges.size(); i++) {
            Edge e = nodes[now].edges.get(i);
            if (level[now] < level[e.to] && e.cap > 0) {
                long d = dfs(e.to, t, nodes, Math.min(f, e.cap), level, iter);
                if (d > 0) {
                    e.cap -= d;
                    nodes[e.to].edges.get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
}


class DuplicateSet<T>{
    private HashMap<T, Integer> map=new HashMap<>();
    @SafeVarargs
    public DuplicateSet(T... elements){
        for(T e:elements){
            if(!map.containsKey(e)){
                map.put(e, 0);
            }
            map.put(e, map.get(e)+1);
        }
    }
    public DuplicateSet(Collection<T> elements){
        for(T e:elements){
            if(!map.containsKey(e)){
                map.put(e, 0);
            }
            map.put(e, map.get(e)+1);
        }
    }

    @Override
    public String toString(){
        String str="";
        for(Entry<T, Integer> e:map.entrySet()){
            str+="("+e.getKey().toString()+"=> "+e.getValue()+") ";
        }
        return str;
    }

    @SuppressWarnings("unchecked")
    @Override
    public boolean equals(Object obj) {
        if(obj==this){
            return true;
        } else if(obj.getClass().equals(this.getClass())){
            DuplicateSet<T> ds=(DuplicateSet<T>) obj;
            return this.map.equals(ds.map);
        } else{
            return false;
        }
    }
    @Override
    public int hashCode(){
        return map.hashCode();
    }
}

class Edge{
    public int from;
    public int to;
    public long cost;
    public long cap;
    public int rev;
    public Edge(int to, long cap, int rev) {
        this.to = to;
        this.cap = cap;
        this.rev = rev;
    }
    public Edge(int from, int to, long cost){
        this.from = from;
        this.to = to;
        this.cost=cost;
    }
    public Edge(int from, int to){
        this.from = from;
        this.to = to;
    }
    public Edge(int to, long cost){
        this.to = to;
        this.cost = cost;
    }
}


class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
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
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
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
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}

// caluculate maximum-flow in O(|E|*F). F is the maximum-flow.
class FordFulkerson{
    static void addEdge(int fr, int to, long cap, Node[] nodes) {
        nodes[fr].edges.add(new Edge(to, cap, nodes[to].edges.size()));
        nodes[to].edges.add(new Edge(fr, 0l, nodes[fr].edges.size() - 1));
    }

    static long fordFulkerson(int s, int t, int n, Node[] nodes) {
        long flow = 0;
        boolean[] used;
        while (true) {
            used = new boolean[n];
            long f = dfs(s, t, nodes, Const.LINF, used);
            flow += f;
            if(f <= 0) break;
        }
        return flow;
    }

    private static long dfs(int now, int t, Node[] nodes, long f, boolean[] used) {
        if(now == t) return f;
        used[now] = true;
        for (int i = 0; i < nodes[now].edges.size(); i++) {
            Edge e = nodes[now].edges.get(i);
            if (!used[e.to] && e.cap > 0) {
                long d = dfs(e.to, t, nodes, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    nodes[e.to].edges.get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
}



class Graph{
    public Node[] nodes;
    public Edge[] edges;
    public int n;
    public int m;

    private int mIndx = 0;

    public Graph(int n, int m){
        this.nodes = new Node[n];
        for(int i = 0; i < n; i++) nodes[i] = new Node(i);
        this.edges = new Edge[m];
        this.n = n;
        this.m = m;
    }

    public void addDirectedEdge(int from, int to, long cost){
        Edge e = new Edge(from, to, cost);
        nodes[from].edges.add(e);
        nodes[to].in++;
        edges[mIndx++] = e;
    }
    public void addNonDirectedEdge(int from, int to, long cost){
        Edge e = new Edge(from, to, cost);
        Edge er = new Edge(to, from, cost);
        nodes[from].edges.add(e);
        nodes[to].edges.add(er);
        nodes[from].in++;
        nodes[to].in++;
        edges[mIndx++] = e;
    }
    public void addDirectedEdge(int from, int to){
        addDirectedEdge(from, to, 1l);
    }
    public void addNonDirectedEdge(int from, int to){
        addNonDirectedEdge(from, to, 1l);
    }
    public void addCapEdge(int from, int to, long cap) {
        nodes[from].edges.add(new Edge(to, cap, nodes[to].edges.size()));
        nodes[to].edges.add(new Edge(from, 0l, nodes[from].edges.size() - 1));
    }
    public void setNodeWeight(long[] w){
        for(int i = 0; i < n; i++) nodes[i].w = w[i];
    }

    public long[] bellmanFord(int s){
        int n = nodes.length;
        boolean negativeLoop[] = new boolean[n];
        long[] d = new long[n];
        fill(d, Const.LINF);
        d[s] = 0;
        for(int i = 0; i < n; i++){
            for(int from = 0; from < n; from++){
                for(Edge edge: nodes[from].edges){
                    int to = edge.to;
                    long c = edge.cost;
                    if(d[to] > d[from] + c){
                        d[to] = d[from]+c;
                    }
                }
            }
        }           
        for(int i = 0; i < n; i++){
            for(int from = 0; from < n; from++){
                for(Edge edge: nodes[from].edges){
                    int to = edge.to;
                    long c = edge.cost;
                    if(d[to] > d[from] + c){
                        negativeLoop[to] = true;
                        d[to] = -Const.LINF;
                    }
                    if(negativeLoop[from]){
                        negativeLoop[to] = true;
                        d[to] = -Const.LINF;
                    }
                }
            }
        }
        return d;
    }
    public long bellmanFord(int s, int t){
        return bellmanFord(s)[t];
    }

    public Info dijkstra(int s){
        return dijkstra(s, -1);
    }   
    public Info dijkstra(int s, int t){
        int[] prev = new int[n];
        long[] d = new long[n];
        Queue<Integer> pq = new PriorityQueue<>((u, v) -> Long.compare(d[u], d[v]));
        fill(d, Const.LINF);
        d[s] = 0;
        pq.add(s);
        while(pq.size() > 0){
            int now = pq.poll();
            if(now == t) break;
            for(Edge e: nodes[now].edges){
                int next = e.to;
                long c = e.cost;
                if(d[now] + c < d[next]){
                    d[next] = d[now] + c;
                    prev[next] = now;
                    pq.add(next);
                }
            }
        }
        return new Info(prev, d);
    }

    public int[] dijkstraPath(Info info, int from, int to){
        ArrayList<Integer> rev=new ArrayList<>();
        for(int now = to; now != from; now = info.prev[now]){
            rev.add(now);
        }
        rev.add(from);
        int[] path = new int[rev.size()];
        for(int i = 0; i < path.length; i++) path[i] = rev.get(path.length - i - 1);
        return path;
    }

    static class Info{
        public int[] prev;
        public long[] d;
        public Info(int[] prev, long[] d){
            this.prev=prev;
            this.d=d;
        }
        public int prev(int i){
            return prev[i];
        }
        public long d(int to){
            return d[to];
        }
    }

    public long dinic(int s, int t) {
        long flow = 0;
        int[] level, iter;
        while (true) {
            level = dinicBFS(s, t);
            if (level[t] < 0) {
                break;
            }
            iter = new int[n];
            long f = dinicDFS(s, t, Const.LINF, level, iter);
            while (f > 0) {
                flow += f;
                f = dinicDFS(s, t, Const.LINF, level, iter);
            }
        }
        return flow;
    }

    private int[] dinicBFS(int s, int t) {
        IntQueue iq = new IntQueue(n);
        iq.addLast(s);
        int[] level = new int[n];
        fill(level, -1);
        level[s] = 0;
        while (iq.size() > 0) {
            int now = iq.pollFirst();
            for (Edge e : nodes[now].edges) {
                if (level[e.to] < 0 && e.cap > 0) {
                    iq.addLast(e.to);
                    level[e.to] = level[now] + 1;
                }
            }
        }
        return level;
    }

    private long dinicDFS(int now, int t, long f, int[] level, int[] iter) {
        if (now == t) return f;
        for (int i = iter[now]++; i < nodes[now].edges.size(); i++) {
            Edge e = nodes[now].edges.get(i);
            if (level[now] < level[e.to] && e.cap > 0) {
                long d = dinicDFS(e.to, t, Math.min(f, e.cap), level, iter);
                if (d > 0) {
                    e.cap -= d;
                    nodes[e.to].edges.get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    public long fordFulkerson(int s, int t){
        long flow = 0;
        boolean[] used;
        while (true) {
            used = new boolean[n];
            long f = fordFulkersonDFS(s, t, Const.LINF, used);
            flow += f;
            if(f <= 0) break;
        }
        return flow;
    }

    private long fordFulkersonDFS(int now, int t, long f, boolean[] used) {
        if(now == t) return f;
        used[now] = true;
        for (int i = 0; i < nodes[now].edges.size(); i++) {
            Edge e = nodes[now].edges.get(i);
            if (!used[e.to] && e.cap > 0) {
                long d = fordFulkersonDFS(e.to, t, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    nodes[e.to].edges.get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    public Edge[] kruskal(){
        UnionFindTree t = new UnionFindTree(n);
        PriorityQueue<Edge> pq = new PriorityQueue<>((u, v) -> Long.compare(u.cost, v.cost));
        for(Edge e:edges) pq.add(e);
        Edge[] ret=new Edge[n-1];
        int index = 0;
        while(pq.size() > 0 && index < n){
            Edge e = pq.poll();
            if(!t.isSame(e.from, e.to)){
                t.unite(e.from, e.to);
                ret[index++] = e;
            }
        }
        return ret;
    }

    public Edge[] prim(){
        HashSet<Integer> connected = new HashSet<>();
        connected.add(0);
        PriorityQueue<Edge> pq = new PriorityQueue<>((u, v) -> Long.compare(u.cost, v.cost));
        for(Edge e: nodes[0].edges) pq.add(e);
        Edge[] ret = new Edge[n-1];
        int index = 0; 
        while(pq.size() > 0 && connected.size() < n){
            Edge e = pq.poll();
            for(int i = 0; i < 2; i++){
                int v = i==0 ? e.from : e.to;
                if(!connected.contains(v)){
                    ret[index++] = e;
                    connected.add(v);
                    for(Edge edge: nodes[v].edges){
                        if(!connected.contains(edge.from) || !connected.contains(edge.to)) pq.add(edge);
                    }
                    break;
                }
            }
        }
        return ret;
    }

    public int[] topologicalSort(){
        int[] ret = new int[n];
        IntQueue zeros=new IntQueue(3 * n);
        for(Node node: nodes) if(node.in == 0) zeros.addLast(node.id);
        int index = 0;
        while(zeros.size() > 0){
            int v = zeros.pollFirst();
            for(Edge e: nodes[v].edges) if(--nodes[e.to].in == 0) zeros.addLast(e.to);
            ret[index++]=v;
        }
        if(index < n) return null;
        return ret;
    }

    // for example (n=9)
    // [1, 8] -> [2, 5, 6] -> [3, 7] -> [4] -> [9]
    // => length:5
    public int topologicalShortestPathLength(){
        int ret = 0;
        IntQueue zeros = new IntQueue(3 * n);
        for(Node node: nodes) if(node.in == 0) zeros.addLast(node.id);
        int num = zeros.size();
        while(zeros.size() > 0){
            int size = zeros.size();
            while(size > 0){
                int v = zeros.pollFirst();
                size--;
                for(Edge e: nodes[v].edges){
                    int u = e.to;
                    if(--nodes[u].in == 0){
                        zeros.addLast(u);
                        num++;
                    }
                }
            }
            ret++;
        }
        if(num < n) return -1;
        return ret;
    }

    public long[] bfs(int s) {
        IntQueue q = new IntQueue(n);
        q.addLast(s);
        long[] d = new long[n];
        fill(d, -1);
        d[s] = 0;
        while(q.size() > 0){
            int now = q.pollFirst();
            for(Edge e: nodes[now].edges){
                int next = e.to;
                if(d[next] < 0){
                    d[next] = d[now] + e.cost;
                    q.addLast(next);
                }
            }
        }
        return d;
    }

    // return the shortest path from 's' to 't' as an array.
    // [s, a1, a2, ..., ak, t] => distance = array.length-1
    // if NO path from 's' to 't' exists, returns NULL.
    public int[] bfsPath(int s, int t){
        IntQueue q = new IntQueue(n);
        q.addLast(s);
        int[] d = new int[n];
        int[] prev = new int[n];
        prev[t] = -1;
        fill(d, -1);
        d[s] = 0;
        while(q.size() > 0){
            int now = q.pollFirst();
            for(Edge e: nodes[now].edges){
                int next = e.to;
                if(d[next] < 0){
                    d[next] = d[now] + 1;
                    prev[next] = prev[s];
                    q.addLast(next);
                }
            }
        }
        if(prev[t] < 0) return null;
        int now = t;
        int[] path = new int[d[t] + 1];
        for (int i = 0; i <= d[t]; i++) {
            path[d[t] - i] = now;
            now = prev[now];
        }
        return path;
    }

    public int[] _01bfs(int s){
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        dq.add(s);
        int[] d = new int[n];
        boolean[] visited=new boolean[n];
        fill(d, Const.IINF);
        d[s] = 0;
        while (dq.size() > 0) {
            int now = dq.pollFirst();
            if(visited[now]) continue;
            visited[now] = true;
            for (Edge e: nodes[now].edges) {
                int next = e.to;
                int cost = (int) e.cost;
                if (d[next] > d[now]) {
                    if (cost == 0) {
                        dq.addFirst(next);
                    } else {
                        dq.addLast(next);
                    }
                    d[next] = d[now] + cost;
                }
            }
        }
        return d;
    }
}

class IntQueue {
    private int[] a;
    private int head = 0, tail = 0;

    public IntQueue(int max) {
        a=new int[max+2];
    }

    public void addLast(int x) {
        a[tail++]=x;
    }

    public int pollFirst() {
        if(tail==head) {
            try {
                throw new Exception("no elements.");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return a[head++];
    }

    public int pollLast() {
        if(tail==head) {
            try {
                throw new Exception("no elements.");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return a[tail--];
    }

    public int getFirst() {
        return a[head];
    }

    public int getLast() {
        return a[tail-1];
    }

    public int size() {
        return tail-head;
    }

    public void init() {
        head=0;
        tail=0;
    }
}


class IntUtil {
    public static int min(int... a) {
        int ret = Const.IINF;
        for (int c : a) {
            ret = Math.min(ret, c);
        }
        return ret;
    }

    public static int max(int... a) {
        int ret = -Const.IINF;
        for (int c : a) {
            ret = Math.max(ret, c);
        }
        return ret;
    }

    /**
     * Caluculate the ceil of a/b. Returns the smallest integer greater than or
     * equal to a/b while 'a/b' rounds fractional parts to ZERO.
     * 
     * @param a
     * @param b
     * @return the smallest integer greater than or equal to a/b
     */
    public static int cld(int a, int b) {
        if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
            if (b > 0) {
                return (a + b - 1) / b;
            } else {
                return (a + b + 1) / b;
            }
        } else {
            return a / b;
        }
    }

    /**
     * Caluculate the floor of a/b. Returns the largest integer less than or equal
     * to a/b while 'a/b' rounds fractional parts to ZERO.
     * 
     * @param a
     * @param b
     * @return the largest integer less than or equal to a/b
     */
    public static int fld(int a, int b) {
        if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
            return a / b;
        } else {
            if (b > 0) {
                return (a - b + 1) / b;
            } else {
                return (a - b - 1) / b;
            }
        }
    }

    public static int fold(IntBinaryOperator func, int a, int... b) {
        int ret = a;
        for (int c : b) {
            ret = func.applyAsInt(ret, c);
        }
        return ret;
    }
}


// minimum spanning tree
class Kruskal{
    public static Edge[] kruskal(int n, Edge[] edges){
        UnionFindTree t = new UnionFindTree(n);
        PriorityQueue<Edge> pq = new PriorityQueue<>((u, v) -> Long.compare(u.cost, v.cost));
        for(Edge e:edges) pq.add(e);
        Edge[] ret=new Edge[n-1];
        int index = 0;
        while(pq.size() > 0 && index < n){
            Edge e=pq.poll();
            if(!t.isSame(e.from, e.to)){
                t.unite(e.from, e.to);
                ret[index++]=e;
            }
        }
        return ret;
    }
}


class LazySegmentTree{
    private long[] tree;
    private long[] lazy;
    private long idElm;
    private long defaultLazyValue;
    private LongBinaryOperator operator;
    private LongBinaryOperator updateFunction;
    private LongBinaryOperator mergeLazyFunction;
    private BiFunction<Long, Integer, Long> collapseUpdateFunction;
    private int size;
    private int leafs;
    private int height;
    private int baseOfLeaf;

    public LazySegmentTree(long[] t, LongBinaryOperator operator, long idElm, LongBinaryOperator updateFunction, LongBinaryOperator mergeLazyFunction , BiFunction<Long, Integer, Long> collapseUpdateFunction, long defaultLazyValue){
        int n = t.length;
        this.operator = operator;
        this.idElm = idElm;
        this.updateFunction = updateFunction;
        this.mergeLazyFunction = mergeLazyFunction;
        this.collapseUpdateFunction = collapseUpdateFunction;
        this.defaultLazyValue = defaultLazyValue;
        this.height = minimumPowerOfTwo(n);
        this.leafs = 1 << this.height;
        this.baseOfLeaf = this.leafs - 1;
        this.size = 2 * this.leafs - 1;
        this.lazy = new long[this.size];
        this.tree = new long[this.size];
        for(int i = size - 1; i >= 0; i--) {
            if(i >= baseOfLeaf + n) {
                this.tree[i] = this.idElm;
            } else if(isLeaf(i)) {
                this.tree[i] = t[i - baseOfLeaf];
            } else{
                this.tree[i] = operator.applyAsLong(this.tree[left(i)], this.tree[right(i)]);
            }
        }
    }

    public void applyForSegment(int l, int r, long v){
        applyForSegment(new Range(l, r), 0, new Range(0, leafs), v);
    }
    private long applyForSegment(Range queryRange, int k, Range treeRange, long v){
        evaluate(k, treeRange);
        if(queryRange.crosses(treeRange)) {
            if(queryRange.contains(treeRange)) {
                lazy[k] = mergeLazyFunction.applyAsLong(lazy[k], v);
                return updateFunction.applyAsLong(tree[k], collapseUpdateFunction.apply(lazy[k], treeRange.length()));
            } else {
                long left = applyForSegment(queryRange, left(k), treeRange.leftHalf(), v);
                long right = applyForSegment(queryRange, right(k), treeRange.rightHalf(), v);
                return tree[k] = operator.applyAsLong(left, right);
            }
        } else{
            return tree[k];
        }
    }
    public void applyForPoint(int i, long v){
        tree[baseOfLeaf + i] = updateFunction.applyAsLong(tree[baseOfLeaf + i], collapseUpdateFunction.apply(v, 1));
    }

    public long query(int l, int r){
        return query(new Range(l, r), 0, new Range(0, leafs));
    }
    private long query(Range queryRange, int k, Range treeRange){
        evaluate(k, treeRange);
        if(!queryRange.crosses(treeRange)){
            return idElm;
        } else if(queryRange.contains(treeRange)){
            return tree[k];
        } else{
            long left = query(queryRange, left(k), treeRange.leftHalf());
            long right = query(queryRange, right(k), treeRange.rightHalf());
            return operator.applyAsLong(left, right);
        }
    }
    private void evaluate(int k, Range r){
        if(lazy[k] != defaultLazyValue) {
            if(!isLeaf(k)){
                lazy[left(k)] = mergeLazyFunction.applyAsLong(lazy[left(k)], lazy[k]);
                lazy[right(k)] = mergeLazyFunction.applyAsLong(lazy[right(k)], lazy[k]);
            }
            tree[k] = updateFunction.applyAsLong(tree[k], collapseUpdateFunction.apply(lazy[k], r.length()));
            lazy[k] = defaultLazyValue;
        }
    }
    private int minimumPowerOfTwo(int n){
        int i = 0;
        while(1 << ++i < n);
        return i;
    }
    private boolean isLeaf(int i){
        return i >= baseOfLeaf;
    }
    private int left(int k){
        return 2 * k + 1;
    }
    private int right(int k){
        return 2 * k + 2;
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        for(int h = 0; h <= height; h++) {
            for(int i = (1 << h) - 1; i < (1 << (h + 1)) - 1; i++) {
                sb.append(tree[i]).append(" ");
            }
            sb.append('\n');
        }
        return sb.toString();
    }

    public static enum QueryFunctions{
        SUM((u, v) -> u + v, 0),
        // PRODUCT((u, v) -> u * v, 1),
        MAX((u, v) -> u > v ? u : v, Long.MIN_VALUE),
        MIN((u, v) -> u < v ? u : v, Long.MAX_VALUE),
        // GCD((u, v) -> gcd(u, v), 0),
        // LCM((u, v) -> lcm(u, v), 1),
        ;
        private final LongBinaryOperator queryFunction;
        private final long idElm;
        private QueryFunctions(LongBinaryOperator queryFunction, long idElm){
            this.queryFunction = queryFunction;
            this.idElm = idElm;
        }
        public LongBinaryOperator getQueryFunction(){
            return queryFunction;
        }
        public long getIdElm(){
            return idElm;
        }
    }
    public static enum UpdateFunctions{
        ADD((u, v) -> u + v, (u, v) -> u + v, (u, l) -> u * l, 0),
        SUB((u, v) -> u - v, (u, v) -> u + v, (u, l) -> u * l, 0),
        // MUL((u, v) -> u * v, (u, v) -> u * v, (u, l) -> u, 1),
        REWRITE((u, v) -> v, (u, v) -> v, (u, l) -> u, Long.MIN_VALUE + 1),
        ;
        private final LongBinaryOperator updateFunction;
        private final LongBinaryOperator mergeLazyFunction;
        private final BiFunction<Long, Integer, Long> collapseUpdateFunction;
        private final long defaultLazyValue;
        private UpdateFunctions(LongBinaryOperator updateFunction, LongBinaryOperator mergeLazyFunction, BiFunction<Long, Integer, Long> collapseUpdateFunction, long defaultLazyValue){
            this.updateFunction = updateFunction;
            this.mergeLazyFunction = mergeLazyFunction;
            this.collapseUpdateFunction = collapseUpdateFunction;
            this.defaultLazyValue = defaultLazyValue;
        }
        public LongBinaryOperator getUpdateFunction(){
            return updateFunction;
        }
        public LongBinaryOperator getMergeLazyFunction(){
            return mergeLazyFunction;
        }
        public BiFunction<Long, Integer, Long> getCollapseUpdateFunction(){
            return collapseUpdateFunction;
        }
        public long getDefaultLazyValue(){
            return defaultLazyValue;
        }
    }
    public static LazySegmentTree create(long[] t, QueryFunctions queryFunctionCode, UpdateFunctions updateFunctionCode){
        LongBinaryOperator operator = queryFunctionCode.getQueryFunction();
        long idElm = queryFunctionCode.getIdElm();
        LongBinaryOperator updateFunction = updateFunctionCode.getUpdateFunction();
        LongBinaryOperator mergeLazyFunction = updateFunctionCode.getMergeLazyFunction();
        BiFunction<Long, Integer, Long> collapseUpdateFunction = updateFunctionCode.getCollapseUpdateFunction();
        long defaultLazyValue = updateFunctionCode.getDefaultLazyValue();
        return new LazySegmentTree(t, operator, idElm, updateFunction, mergeLazyFunction, collapseUpdateFunction, defaultLazyValue);
    }
}

class LongQueue {
    private long[] a;
    private int head = 0, tail = 0;

    public LongQueue(int max) {
        a=new long[max+2];
    }

    public void addLast(long x) {
        a[tail++]=x;
    }

    public long pollFirst(){
        if (tail == head) {
            try {
                throw new Exception("no elements.");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return a[head++];
    }

    public long pollLast() {
        if (tail == head) {
            try {
                throw new Exception("no elements.");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return a[tail--];
    }

    public long getFirst() {
        return a[head];
    }

    public long getLast() {
        return a[tail - 1];
    }

    public int size() {
        return tail ^ head;
    }

    public void init() {
        head = 0;
        tail = 0;
    }
}


class LongUtil {
    public static long min(long... a) {
        long ret = Const.LINF;
        for (long c : a) {
            ret = Math.min(ret, c);
        }
        return ret;
    }

    public static long max(long... a) {
        long ret = -Const.LINF;
        for (long c : a) {
            ret = Math.max(ret, c);
        }
        return ret;
    }

    /**
     * Caluculate the ceil of a/b. Returns the smallest integer greater than or
     * equal to a/b while 'a/b' rounds fractional parts to ZERO.
     * 
     * @param a
     * @param b
     * @return the smallest integer greater than or equal to a/b
     */
    public static long cld(long a, long b) {
        if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
            if (b > 0) {
                return (a + b - 1) / b;
            } else {
                return (a + b + 1) / b;
            }
        } else {
            return a / b;
        }
    }

    /**
     * Caluculate the floor of a/b. Returns the largest integer less than or equal
     * to a/b while 'a/b' rounds fractional parts to ZERO.
     * 
     * @param a
     * @param b
     * @return the largest integer less than or equal to a/b
     */
    public static long fld(long a, long b) {
        if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
            return a / b;
        } else {
            if (b > 0) {
                return (a - b + 1) / b;
            } else {
                return (a - b - 1) / b;
            }
        }
    }

    public static long fold(LongBinaryOperator func, long a, long... b) {
        long ret = a;
        for (long c : b) {
            ret = func.applyAsLong(ret, c);
        }
        return ret;
    }
}


class MathUtil{
    /**
     * Enumarate primes less than n.
     * 
     * @param n
     * @return {@code ArrayList} that holds primes.
     */
    public static ArrayList<Integer> eratosthenes(int n) {
        int[] div = eratosthenesDivisors(n);
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (div[i] == i) {
                result.add(i);
            }
        }
        return result;
    }
    /**
     * execute eratosthenes's prime-enumerate algorithm. a[i] holds the greatest
     * divisor of i. if a[i]=i, i is a prime number. This arrary enables you to
     * prime-factorize in O(log n) time. (<O(sqrt n)).
     * 
     * @param n
     * @return divisor array.
     */
    public static int[] eratosthenesDivisors(int n) {
        int[] divisors = new int[n + 1];
        if (n <= 0) {
            return null;
        }
        for (int i = 1; i <= n; i++) {
            if ((i & 1) != 0) {
                divisors[i] = i;
            } else {
                divisors[i] = 2;
            }
        }
        for (long i = 3; i <= n; i += 2) {
            if (divisors[(int) i] == (int) i) {
                for (long j = i * i; j <= n; j += (i << 1)) {
                    divisors[(int) j] = (int) i;
                }
            }
        }
        return divisors;
    }

    /**
     * Caluculate prime-factorization.
     * 
     * @param n
     * @return {@code HashMap} of {prime: index}
     */
    public static HashMap<Long, Integer> primeFactorization(long n) {
        HashMap<Long, Integer> primes = new HashMap<Long, Integer>();
        for (long p = 2; p * p <= n; p++) {
            int q = 0;
            while (n % p == 0) {
                n /= p;
                q++;
            }
            if (q > 0) {
                primes.put(p, q);
            }
        }
        if (n > 1) {
            primes.put(n, 1);
        }
        return primes;
    }

    private static HashMap<Long, Integer> lcm(HashMap<Long, Integer> amap, HashMap<Long, Integer> bmap) {
        if (amap.size() < bmap.size()) {
            return lcm(bmap, amap);
        }
        HashMap<Long, Integer> lcm = amap;
        for (Map.Entry<Long, Integer> e : bmap.entrySet()) {
            long prime = e.getKey();
            if (lcm.containsKey(prime)) {
                lcm.put(prime, Math.max(lcm.get(prime), e.getValue()));
            } else {
                lcm.put(prime, e.getValue());
            }
        }
        return lcm;
    }

    private static HashMap<Long, Integer> lcm(HashMap<Long, Integer> amap, long b) {
        HashMap<Long, Integer> bmap = primeFactorization(b);
        return lcm(amap, bmap);
    }

    public static HashMap<Long, Integer> lcm(long... a) {
        HashMap<Long, Integer> amap = new HashMap<>();
        for (long c : a) {
            amap = lcm(amap, c);
        }
        return amap;
    }
    public static long unsafeLCM(long a, long b) {
        return a * b / gcd(a, b);
    }

    /**
     * Caluculate the GCD of (a, b)/
     * 
     * @param a first value
     * @param b second value
     * @return GCD(a, b)
     */
    public static long gcd(long a, long b) {
        if (a < b) {
            return gcd(b, a);
        }
        if(b == 0) {
            return a;
        } else if(a == 0) {
            return b;
        }
        long r = a % b;
        while (r != 0) {
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }

    public static long gcd(long... a){
        long gcd = 0;
        for(long c:a){
            gcd = gcd(gcd, c);
        }
        return gcd;
    }

    /**
     * Return one of the solutions to {@code ax+by=gcd(a, b)}.
     * 
     * @return {@code x}, {@code y}, {@code gcd(a, b)}.
     * @param a a of ax+by=gcd(a, b).
     * @param b b of ax+by=gcd(a, b). class ReferenceLong is a reference type of long.
     */
    public static long[] extGCD(long a, long b) {
        ReferenceLong x = new ReferenceLong();
        ReferenceLong y = new ReferenceLong();
        long[] ret = new long[3];
        ret[2] = extGCD(a, b, x, y);
        ret[0] = x.v;
        ret[1] = y.v;
        return ret;
    }

    private static long extGCD(long a, long b, ReferenceLong x, ReferenceLong y) {
        if (b == 0) {
            x.v = 1;
            y.v = 0;
            return a;
        }
        long d = extGCD(b, a % b, y, x);
        y.v -= a / b * x.v;
        return d;
    }

    private static class ReferenceLong {
        long v = 0;
    }
}

class ModUtil{
    public static long mul(long... a) {
        long ret = 1;
        for (long c : a) {
            ret *= c;
            ret %= Const.MOD;
        }
        return ret;
    }

    public static long div(long a, long... b) {
        long ret = a;
        for (long c : b) {
            ret *= inv(c);
            ret %= Const.MOD;
        }
        return ret;
    }

    /**
     * Caluculate the value b s.t. a*b mod Const.MOD = 1.
     * 
     * @param a
     * @return inverse of a
     */
    public static long inv(long a) {
        long b = Const.MOD;
        long u = 1, v = 0;
        while (b >= 1) {
            long t = a / b;
            a -= t * b;
            long tmp1 = a;
            a = b;
            b = tmp1;
            u -= t * v;
            long tmp2 = u;
            u = v;
            v = tmp2;
        }
        u %= Const.MOD;
        return u >= 0 ? u : u + Const.MOD;
    }

    /**
     * Caluculate the combination nCr.
     * 
     * @param n left
     * @param r right
     * @return nCr
     */
    public static long comb(long n, long r) {
        if (n < r) {
            return 0;
        }
        r = Math.min(r, n - r);
        long res = 1;
        for (long d = 1; d <= r; d++) {
            res = div(mul(res, n--), d);
        }
        return res;
    }

    public static long[] fact(int n){
        long[] fact=new long[n+1];
        for(long i=0;i<=n;i++){
            if(i<=1){
                fact[(int)i]=1;
            } else{
                fact[(int)i]=mul(fact[(int)i-1], i);
            }
        }
        return fact;
    }
}


class Node{
    public int id;
    public ArrayList<Edge> edges;
    public long w;
    public int in;
    
    public Node(int id){
        this.id=id;
        this.edges = new ArrayList<Edge>();
    }
    public Node(int id, long w){
        this.id = id;
        this.w = w;
        this.edges = new ArrayList<>();
    }
    @Override public boolean equals(Object o){
        if(this == o) return true;
        if(! (o instanceof Node)) return false;
        Node n=(Node) o;
        return n.id == id;
    }
    @Override public int hashCode(){
        return id;
    }
}


@SuppressWarnings("unchecked")
class PolyLazySegmentTree<T, U>{
    private T[] tree;
    private U[] lazy;
    private T idElm;
    private U defaultLazyValue;
    private BiFunction<T, T, T> operator;
    private BiFunction<T, U, T> updateFunction;
    private BiFunction<U, U, U> mergeLazyFunction;
    private BiFunction<U, Integer, U> collapseUpdateFunction;
    private int size;
    private int leafs;
    private int height;
    private int baseOfLeaf;

    public PolyLazySegmentTree(T[] t, BiFunction<T, T, T> operator, T idElm, BiFunction<T, U, T> updateFunction, BiFunction<U, U, U> mergeLazyFunction , BiFunction<U, Integer, U> collapseUpdateFunction, U defaultLazyValue){
        int n = t.length;
        this.operator = operator;
        this.idElm = idElm;
        this.updateFunction = updateFunction;
        this.mergeLazyFunction = mergeLazyFunction;
        this.collapseUpdateFunction = collapseUpdateFunction;
        this.defaultLazyValue = defaultLazyValue;
        this.height = minimumPowerOfTwo(n);
        this.leafs = 1 << this.height;
        this.baseOfLeaf = this.leafs - 1;
        this.size = 2 * this.leafs - 1;
        this.lazy = (U[]) new Object[this.size];
        this.tree = (T[]) new Object[this.size];
        for(int i = size - 1; i >= 0; i--) {
            if(i >= baseOfLeaf + n) {
                this.tree[i] = this.idElm;
            } else if(isLeaf(i)) {
                this.tree[i] = t[i - baseOfLeaf];
            } else{
                this.tree[i] = operator.apply(this.tree[left(i)], this.tree[right(i)]);
            }
        }
    }

    public void applyForSegment(int l, int r, U v){
        applyForSegment(new Range(l, r), 0, new Range(0, leafs), v);
    }
    private T applyForSegment(Range queryRange, int k, Range treeRange, U v){
        evaluate(k, treeRange);
        if(queryRange.crosses(treeRange)) {
            if(queryRange.contains(treeRange)) {
                lazy[k] = mergeLazyFunction.apply(lazy[k], v);
                return updateFunction.apply(tree[k], collapseUpdateFunction.apply(lazy[k], treeRange.length()));
            } else {
                T left = applyForSegment(queryRange, left(k), treeRange.leftHalf(), v);
                T right = applyForSegment(queryRange, right(k), treeRange.rightHalf(), v);
                return tree[k] = operator.apply(left, right);
            }
        } else{
            return tree[k];
        }
    }
    public void applyForPoint(int i, U v){
        tree[baseOfLeaf + i] = updateFunction.apply(tree[baseOfLeaf + i], collapseUpdateFunction.apply(v, 1));
    }

    public T query(int l, int r){
        return query(new Range(l, r), 0, new Range(0, leafs));
    }
    private T query(Range queryRange, int k, Range treeRange){
        evaluate(k, treeRange);
        if(!queryRange.crosses(treeRange)){
            return idElm;
        } else if(queryRange.contains(treeRange)){
            return tree[k];
        } else{
            T left = query(queryRange, left(k), treeRange.leftHalf());
            T right = query(queryRange, right(k), treeRange.rightHalf());
            return operator.apply(left, right);
        }
    }
    private void evaluate(int k, Range r){
        if(lazy[k] != defaultLazyValue) {
            if(!isLeaf(k)){
                lazy[left(k)] = mergeLazyFunction.apply(lazy[left(k)], lazy[k]);
                lazy[right(k)] = mergeLazyFunction.apply(lazy[right(k)], lazy[k]);
            }
            tree[k] = updateFunction.apply(tree[k], collapseUpdateFunction.apply(lazy[k], r.length()));
            lazy[k] = defaultLazyValue;
        }
    }
    private int minimumPowerOfTwo(int n){
        int i = 0;
        while(1 << ++i < n);
        return i;
    }
    private boolean isLeaf(int i){
        return i >= baseOfLeaf;
    }
    private int left(int k){
        return 2 * k + 1;
    }
    private int right(int k){
        return 2 * k + 2;
    }

    private static class Range{
        private int left, right;
        Range(int left, int right){
            this.left = left;
            this.right = right;
        }
        boolean crosses(Range r){
            return this.left < r.right && r.left < this.right;
        }
        boolean contains(Range r){
            return this.left <= r.left && r.right <= this.right;
        }
        Range leftHalf(){
            return new Range(left, (left + right) / 2);
        }
        Range rightHalf(){
            return new Range((left + right) / 2, right);
        }
        int length(){
            return right - left;
        }
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        for(int h = 0; h <= height; h++) {
            for(int i = (1 << h) - 1; i < (1 << (h + 1)) - 1; i++) {
                sb.append(tree[i]).append(" ");
            }
            sb.append('\n');
        }
        return sb.toString();
    }
}


class Prim{
    public static Edge[] prim(int n, Node[] nodes){
        HashSet<Integer> connected = new HashSet<>();
        connected.add(0);
        PriorityQueue<Edge> pq = new PriorityQueue<>((u, v)->Long.compare(u.cost, v.cost));
        for(Edge e: nodes[0].edges) pq.add(e);
        Edge[] ret = new Edge[n-1];
        int index = 0; 
        while(pq.size() > 0 && connected.size() < n){
            Edge e = pq.poll();
            for(int i = 0; i < 2; i++){
                int v = i==0 ? e.from : e.to;
                if(!connected.contains(v)){
                    ret[index++] = e;
                    connected.add(v);
                    for(Edge edge: nodes[v].edges){
                        if(!connected.contains(edge.from) || !connected.contains(edge.to)) pq.add(edge);
                    }
                    break;
                }
            }
        }
        return ret;
    }
}


class Range{
    public static final int MAX = +Const.IINF;
    public static final int MIN = -Const.IINF;
    public static final Range EMPTY = new Range(MAX, MAX);
    public static final Range WHOLE = new Range(MIN, MAX);

    public int left;
    public int right;

    public Range(int left, int right){
        if(left >= right){
            this.left = EMPTY.left;
            this.right = EMPTY.right;
        } else{
            this.left = left;
            this.right = right;
        }
    }
    public boolean crosses(Range r){
        return this.left < r.right && r.left < this.right;
    }
    public boolean contains(Range r){
        if(this.isEmpty()) return false;
        if(r.isEmpty()) return true;
        return this.left <= r.left && r.right <= this.right;
    }
    public Range leftHalf(){
        if(this.isEmpty()) return EMPTY;
        return new Range(left, (left + right) >> 1);
    }
    public Range rightHalf(){
        if(this.isEmpty()) return EMPTY;
        return new Range((left + right) >> 1, right);
    }
    public int length(){
        return right - left;
    }
    public Range intersection(Range r){
        if(!this.crosses(r)) return EMPTY;
        return new Range(Math.max(this.left, r.left), Math.min(this.right, r.right));
    }
    public ArrayList<Range> union(Range r){
        ArrayList<Range> union = new ArrayList<>();
        if(this.isEmpty()){
            union.add(r); 
        } else if(r.isEmpty()){
            union.add(this);
        } else if(this.crosses(r)){
            union.add(new Range(Math.min(this.left, r.left), Math.max(this.right, r.right)));
        } else {
            if(this.left < r.left){
                union.add(this);
                union.add(r);
            } else{
                union.add(r);
                union.add(this);
            }
        }
        return union;
    }
    public boolean isEmpty(){
        return this.equals(EMPTY);
    }
    public boolean nonEmpty(){
        return !this.isEmpty();
    }

    public static boolean crosses(Range r1, Range r2){
        return r1.crosses(r2);
    }
    public static Range leftHalf(Range r){
        return r.leftHalf();
    }
    public static Range rightHalf(Range r){
        return r.rightHalf();
    }
    public static int length(Range r){
        return r.length();
    }
    public static Range interSection(Range... rs){
        Range ret = WHOLE;
        for(Range r: rs) ret = ret.intersection(r);
        return ret;
    }
    public static ArrayList<Range> union(Range... rs){
        sort(rs, (u, v) -> Integer.compare(u.left, v.left));
        ArrayList<Range> union = new ArrayList<>();
        Range now = null;
        for(Range r: rs){
            if(r.isEmpty()) break;
            if(isNull(now)){
                now = r;
            } else{
                if(r.left <= now.right){
                    now.right = r.right;
                } else{
                    union.add(now);
                    now = r;
                }
            }
        }
        if(!isNull(now) && !now.equals(EMPTY)) union.add(now);
        if(union.isEmpty()) union.add(EMPTY);
        return union;
    }
    public static boolean isEmpty(Range r){
        return r.isEmpty();
    }
    public static boolean nonEmpty(Range r){
        return r.nonEmpty();
    }

    @Override
    public boolean equals(Object o){
        if(this == o) return true;
        if(!(o instanceof Range)) return false;
        Range r = (Range) o;
        return this.left == r.left && this.right == r.right; 
    }
    @Override
    public int hashCode(){
        return hash(left, right);
    }
    @Override
    public String toString(){
        return "["+left+", "+right+")";
    }
}


class RollingHash {
    private static final long mod = (1l << 61) - 1;
    private static final long mask31 = (1l << 31) - 1;
    private static final long mask30 = (1l << 30) - 1;

    private long base;
    private long[] pow;
    private int length;

    // hash[i] is the hash of substring[0, i). (i = 0, 1, ..., length)
    private long[] hash;

    public RollingHash(char[] ch) {
        length = ch.length;
        setBase();
        pow = new long[length + 1];
        powInit();
        hash = new long[length + 1];
        for(int i = 0; i < length; i++) hash[i + 1] = mod(mult(hash[i], base) + ch[i] + 1);
    }

    public long hash(int begin, int end) {
        long ret = hash[end] - mod(mult(hash[begin], pow[end - begin]));
        if (ret < 0) ret += mod;
        return ret;
    }

    // calc a*b mod 2^61-1 without overflow.
    // use the fact that 2^61 = 1 mod 2^61-1.
    private long mult(long a, long b) {
        // au is upper 30(=61-31) bits of a.
        // ad is lower 31 bits of a.
        // bu is upper 30(=61-31) bits of b.
        // bd is lower 31 bits of b.
        long au = a >> 31;
        long ad = a & mask31;
        long bu = b >> 31;
        long bd = b & mask31;
        // a*b = (au*2^31 + ad) * (bu*2^31 + bd)
        // a*b = au*bu*2^62 + (au*bd + ad*bu)*2^31 + ad*bd.

        // au*bu*2^62 = au*bu*2 (mod 2^61-1) because of 2^61 = 1 (mod 2^61-1)
        // au*bu*2 <= 2 * (2^30 - 1) * (2^30 - 1) = 2^61 - 2^32 + 2
        // mid := au*bd + ad*bu <= 2 * (2^30-1) * (2^31-1) = 2^62 - 3*2^31 + 2 <= 61bits
        // mid = midu*2^30 + midd.
        // midu is upper 31(=61-30) bits of b.
        // midd is lower 30 bits of b.
        // mid * 2^31 = midu*2^61 + midd*2^31 = midu + midd*2^31 <= 2^61 + 2^31
        // ad*bd <= (2^31 -1) * (2^31 - 1) = 2^62 - 2^32 + 1

        // (au*bu*2) + (midu+midd*2^31) + (ad*bd) <= 2^63 - 3*2^31 + 3 <= Long.MAX_VALUE
        long mid = au * bd + ad * bu;
        long midu = mid >> 30;
        long midd = mid & mask30;

        return (au * bu * 2) + (midu + (midd << 31)) + (ad * bd);
    }

    private long mod(long l) {
        l = (l & mod) + (l >> 61);
        while (l > mod) {
            l -= mod;
        }
        return l;
    }

    private void setBase(){
        Random r = new Random(System.currentTimeMillis());
        do base = r.nextLong(); while (base >= mod - 1 || base <= 6000);
    }

    private void powInit(){
        for (int i = 0; i < length; i++) {
            if (i == 0){
                pow[i] = 1;
            } else{
                pow[i] = mod(mult(pow[i - 1], base));
            }
        }
    }
}


class Search {
    // return the distance from 's' to other vertices as an array.
    public static int[] bfs(ArrayList<Integer>[] nodes, int s) {
        IntQueue q = new IntQueue(nodes.length);
        q.addLast(s);
        int n = nodes.length;
        int[] d = new int[n];
        fill(d, -1);
        d[s] = 0;
        while(q.size() > 0){
            int now = q.pollFirst();
            for(int next: nodes[now]){
                if(d[next] < 0){
                    d[next] = d[now] + 1;
                    q.addLast(next);
                }
            }
        }
        return d;
    }

    // return the shortest path from 's' to 't' as an array.
    // [s, a1, a2, ..., ak, t] => distance = array.length-1
    // if NO path from 's' to 't' exists, returns NULL.
    public static int[] bfs(ArrayList<Integer>[] nodes, int s, int t) {
        IntQueue q = new IntQueue(nodes.length + 1);
        q.addLast(s);
        int n = nodes.length;
        int[] d = new int[n];
        int[] prev = new int[n];
        prev[t] = -1;
        fill(d, -1);
        d[s] = 0;
        while(q.size() > 0){
            int now = q.pollFirst();
            for(int next: nodes[now]){
                if(d[next] < 0){
                    d[next] = d[now] + 1;
                    prev[next] = prev[s];
                    q.addLast(next);
                }
            }
        }
        if(prev[t] < 0) return null;
        int now = t;
        int[] path = new int[d[t] + 1];
        for (int i = 0; i <= d[t]; i++) {
            path[d[t] - i] = now;
            now = prev[now];
        }
        return path;
    }

    public static int[] _01bfs(Node[] nodes, int s){
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        dq.add(s);
        int n = nodes.length;
        int[] d = new int[n];
        boolean[] visited=new boolean[n];
        fill(d, Const.IINF);
        d[s] = 0;
        while (dq.size() > 0) {
            int now = dq.pollFirst();
            if(visited[now]) continue;
            visited[now] = true;
            for (Edge e: nodes[now].edges) {
                int next = e.to;
                int cost = (int) e.cost;
                if (d[next] > d[now]) {
                    if (cost == 0) {
                        dq.addFirst(next);
                    } else {
                        dq.addLast(next);
                    }
                    d[next] = d[now] + cost;
                }
            }
        }
        return d;
    }
}


class SegmentTree{
    private long[] tree;
    private long idElm;
    private LongBinaryOperator operator;
    private int size;
    private int leafs;
    private int height;
    private int baseOfLeaf;

    public SegmentTree(long[] t, long idElm, LongBinaryOperator operator){
        int n = t.length;
        this.idElm = idElm;
        this.height = minimumPowerOfTwo(n);
        this.leafs = 1 << this.height;
        this.baseOfLeaf = this.leafs - 1;
        this.size = 2 * this.leafs - 1;
        this.tree = new long[this.size];
        for(int i = size - 1; i >= 0; i--) {
            if(i >= baseOfLeaf + n) {
                this.tree[i] = this.idElm;
            } else if(isLeaf(i)) {
                this.tree[i] = t[i - baseOfLeaf];
            } else{
                this.tree[i] = operator.applyAsLong(this.tree[left(i)], this.tree[right(i)]);
            }
        }
    }
    public void update(int i, int v){
        int index = i + baseOfLeaf;
        int parent = index;
        tree[index] = v;
        while(parent > 0){
            parent = (parent - 1) >> 1;
            tree[parent] = operator.applyAsLong(tree[left(parent)], tree[right(parent)]);
        }
    }
    // tree size=2^0+2^1+...+2^height=2^(height+1)-1
    public int size(){
        return size;
    }
    public int height(){
        return height;
    }
    public long query(int a, int b){
        return query(new Range(a, b), 0, new Range(0, leafs));
    }
    // tree[k] covers [l, r).
    private long query(Range queryRange, int k, Range treeRange){
        if(!queryRange.crosses(treeRange)){ // out of range
            return idElm;
        } else if(queryRange.contains(treeRange)){ //include range (+update)
            if(isLeaf(k)) return tree[k];
            else return tree[k] = operator.applyAsLong(tree[left(k)], tree[right(k)]);
        } else{
            long left=query(queryRange, left(k), treeRange.leftHalf());
            long right=query(queryRange, right(k), treeRange.rightHalf());
            return operator.applyAsLong(left, right);
        }
    }
    
    public String toString(){
        StringBuilder sb = new StringBuilder();
        for(int h = 0; h <= height; h++){
            for(int i = (1 << h) - 1; i < (1 << (h + 1))-1; i++){
                sb.append(tree[i]).append(" ");
            }
            sb.append('\n');
        }
        return sb.toString();
    }

    private int minimumPowerOfTwo(int n){
        int i = 0;
        while(1 << ++i < n);
        return i;
    }
    private boolean isLeaf(int i){
        return i >= baseOfLeaf;
    }
    private int left(int k){
        return 2 * k + 1;
    }
    private int right(int k){
        return 2 * k + 2;
    }
}


class SuffixArray {
    // sort suffixes of ch in O(n*log n).
    public static int[] suffixArray(char[] ch) {
        int n = ch.length;
        Integer[] order = new Integer[n];
        for (int i = 0; i < n; i++) {
            order[i] = n - i - 1;
        }
        Arrays.sort(order, (u, v) -> ch[u] - ch[v]);

        int[] suffixArray = new int[n];
        int[] classes = new int[n];

        for (int i = 0; i < n; i++) {
            suffixArray[i] = order[i];
            classes[i] = ch[i];
        }
        /*
         * suffixArray[i] is suffix on i'th position after sorting by first len
         * characters.
         */
        /*
         * classes[i] is equivalence class of the i'th suffix after sorting by first len
         * characters.
         */
        for (int len = 1; len < n; len *= 2) {
            int[] c = classes.clone();
            for (int i = 0; i < n; i++) {
                // condition that suffixArray[i-1]+len<n simulates 0-symbol at the end of the
                // string
                // a separate class is created for each suffix followed by simurated 0-symbol

                if (i == 0) {
                    classes[suffixArray[i]] = i;
                } else {
                    // judge the equivalence by deviding substring.
                    if (c[suffixArray[i - 1]] == c[suffixArray[i]] && suffixArray[i - 1] + len < n
                            && c[suffixArray[i - 1] + len / 2] == c[suffixArray[i] + len / 2]) {
                        classes[suffixArray[i]] = classes[suffixArray[i - 1]];
                    } else {
                        classes[suffixArray[i]] = i;
                    }
                }
            }
            // suffixes are already sorted by first len characters.
            // now sort suffixes by first len*2 characters.
            int[] count = new int[n];
            for (int i = 0; i < n; i++) {
                count[i] = i;
            }
            int[] s = suffixArray.clone();
            for (int i = 0; i < n; i++) {
                // s[i] is order of suffixes sorted by first len characters.
                // (s[i]-len) is order of suffixes sorted by second len characters.
                int s1 = s[i] - len;
                if (s1 >= 0) {
                    suffixArray[count[classes[s1]]++] = s1;
                }
            }
        }
        return suffixArray;
    }

    // sort rotation of S in O(n*log n).
    public static int[] rotationArray(char[] ch) {
        int n = ch.length;
        Integer[] order = new Integer[n];
        for (int i = 0; i < n; i++) {
            order[i] = i;
        }
        Arrays.sort(order, (u, v) -> ch[u] - ch[v]);

        int[] suffixArray = new int[n];
        int[] classes = new int[n];

        for (int i = 0; i < n; i++) {
            suffixArray[i] = order[i];
            classes[i] = ch[i];
        }
        /*
         * suffixArray[i] is suffix on i'th position after sorting by first len
         * characters.
         */
        /*
         * classes[i] is equivalence class of the i'th suffix after sorting by first len
         * characters.
         */
        for (int len = 1; len < n; len *= 2) {
            int[] c = classes.clone();
            for (int i = 0; i < n; i++) {
                // condition that suffixArray[i-1]+len<n simulates 0-symbol at the end of the
                // string
                // a separate class is created for each suffix followed by simurated 0-symbol

                if (i == 0) {
                    classes[suffixArray[i]] = i;
                } else {
                    // judge the equivalence by deviding substring.
                    if (c[suffixArray[i - 1]] == c[suffixArray[i]]
                            && c[(suffixArray[i - 1] + len / 2) % n] == c[(suffixArray[i] + len / 2) % n]) {
                        classes[suffixArray[i]] = classes[suffixArray[i - 1]];
                    } else {
                        classes[suffixArray[i]] = i;
                    }
                }
            }
            // suffixes are already sorted by first len characters.
            // now sort suffixes by first len*2 characters.
            int[] count = new int[n];
            for (int i = 0; i < n; i++) {
                count[i] = i;
            }
            int[] s = suffixArray.clone();
            for (int i = 0; i < n; i++) {
                // s[i] is order of suffixes sorted by first len characters.
                // (s[i]-len) is order of suffixes sorted by second len characters.
                int s1 = (s[i] - len + n) % n;
                suffixArray[count[classes[s1]]++] = s1;
            }
        }
        return suffixArray;
    }

    // longest common prefixes array in O(n)
    public static int[] lcp(int[] suffixArray, char[] ch){
        int n=suffixArray.length;
        int[] rank = new int[n];
        for(int i=0;i<n;i++){
            rank[suffixArray[i]]=i;
        }
        int[] lcp=new int[n-1];
        for(int i=0, h=0;i<n;i++){
            if(rank[i]<n-1){
                for(int j=suffixArray[rank[i]+1];Math.max(i, j)+h<ch.length&&ch[i+h]==ch[j+h];++h);
                lcp[rank[i]]=h;
                if(h>0){
                    h--;
                }
            }
        }
        return lcp;
    }
}

class TopologicalSort{
    static int[] topologicalSort(Node[] nodes){
        int n = nodes.length;
        int[] ret = new int[n];
        //for(Node node:nodes) for(Edge e:node.edges) nodes[e.id].in++;
        IntQueue zeros=new IntQueue(3*n);
        for(Node node: nodes) if(node.in == 0) zeros.addLast(node.id);
        int index = 0;
        while(zeros.size() > 0){
            int v = zeros.pollFirst();
            for(Edge e: nodes[v].edges){
                nodes[e.to].in--;
                if(nodes[e.to].in == 0) zeros.addLast(e.to);
            }
            ret[index++]=v;
        }
        if(index < n) return null;
        return ret;
    }
    
    // for example (n=9)
    // [1, 8] -> [2, 5, 6] -> [3, 7] -> [4] -> [9]
    // => length:5
    static int shortest(Node[] nodes){
        int n = nodes.length;
        int ret = 0;
        //for(Node node:nodes) for(Edge e:node.edges) nodes[e.id].in++;
        IntQueue zeros = new IntQueue(3 * n);
        for(Node node: nodes) if(node.in == 0) zeros.addLast(node.id);
        int num = zeros.size();
        while(zeros.size() > 0){
            int size = zeros.size();
            while(size > 0){
                int v = zeros.pollFirst();
                size--;
                for(Edge e: nodes[v].edges){
                    int u = e.to;
                    if(--nodes[u].in == 0){
                        zeros.addLast(u);
                        num++;
                    }
                }
            }
            ret++;
        }
        if(num < n) return -1;
        return ret;
    }
}

class TwoDimensionsBinaryIndexedTree{
    private int[][] tree;
    private int[][] originalArray;
    private int n, m;

    public TwoDimensionsBinaryIndexedTree(int[][] array){
        this.originalArray = array.clone();
        this.n = array.length;
        this.m = array[0].length;
        this.tree = new int[n+1][m+1];
        init();
    }
    public TwoDimensionsBinaryIndexedTree(int initial, int n, int m){
        this.originalArray = new int[n][m];
        this.n = n;
        this.tree = new int[n+1][m+1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                originalArray[i][j] = initial;
            }
        }
        init();
    }
    public TwoDimensionsBinaryIndexedTree(int n, int m){
        this(0, n, m);
    }
    private void init(){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                tree[i][j] += originalArray[i-1][j-1];
                int pi=i + (-i & i);
                int pj=j + (-j & j);
                if(pi <= n && pj <= m){
                    tree[pi][pj] += tree[i][j];
                } else if(pi <= n){
                    tree[pi][j] += tree[i][j];
                } else if(pj <= m){
                    tree[i][pj] += tree[i][j];
                }
            }
        }
    }

    /**
     * Calculate the sum of range (l, r] in array (1-indexed).
     * @param l left border (open)
     * @param r right border (closed)
     * @return sum of range (l, r] in array (1-indexed).
     */
    public int sum(int il, int ir, int jl, int jr){
        return sum(ir, jr) - sum(il, jl);
    }
    private int sum(int i, int j){
        int ret=0;
        for(; i > 0; i -= -i & i){
            for(; j > 0; j -= -j & j){
                ret += tree[i][j];
            }
        }
        return ret;
    }

    /**
     * add v to array[i] and update BIT.
     * @param i index of array (1-indexed)
     * @param v adding value
     */
    public void add(int i, int j, int v){
        originalArray[i-1][j-1] += v;
        for(; i <= n; i += -i & i){
            for(; j <= m; j += -j & j){
                tree[i][j] += v;
            }
        }
    }

    /**
     * update the value of array[i] to v and update BIT.
     * @param i index of array (1-indexed)
     * @param v adding value
     */
    public void update(int i, int j, int v){
        add(i, j, v - originalArray[i-1][j-1]);
        originalArray[i-1][j-1] = v;
    }
}


class UnionFindTree {
    private int[] parent;
    private int[] rank;
    private int[] size;
    private int groups;
    public UnionFindTree(int n){
        this.parent = new int[n];
        this.rank = new int[n];
        this.size = new int[n];
        this.groups = n;
        fill(this.size, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    public int root(int x){
        if(parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }
    public boolean isSame(int x, int y){
        return root(x) == root(y);
    }
    public void unite(int x, int y){
        int xr = root(x);
        int yr = root(y);
        if(xr == yr) return;
        if(rank[xr] < rank[yr]){
            parent[xr] = yr;
            size[yr] += size[xr];
        }
        else{
            parent[yr] = xr;
            size[xr] += size[yr];
            if(rank[xr] == rank[yr]) rank[xr]++;
        }
        groups--;
    }
    public int size(int x){
        return size[root(x)];
    }
    public int groups(){
        return groups;
    }
}

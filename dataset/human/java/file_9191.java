import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int hole[] = new int[m+2];
    hole[0] =-1;
    hole[m+1] = n+1;
    long L = 1000000007;
    for(int i=1;i<=m;i++){
      hole[i]=sc.nextInt();
    }
    long fib[] = new long[n+2];
    fib[0]=0;
    fib[1]=1;
    fib[2]=1;
    for(int i=3;i<n+2;i++){
      fib[i]=(fib[i-1]+fib[i-2])%L;
    }
    long answer =1;
    
    for(int i=0;i<=m;i++){
      answer = (answer*fib[hole[i+1]-hole[i]-1])%L;
    }
    System.out.println(answer);
    
    
    
  }
  
  //最大公約数・最小公倍数（セットで使う）
static int gcd (int a, int b) {return b>0?gcd(b,a%b):a;}
static int lcm (int a, int b) {return a*b/gcd(a,b);}


//素数判定
static boolean isPrime (int n) {
	if (n==2) return true;
	if (n<2 || n%2==0) return false;
	double d = Math.sqrt(n);
	for (int i=3; i<=d; i+=2) if(n%i==0){return false;}
	return true;
}


//倍数判定（10進数以外のときに有用）
static boolean isMultiple (String s, int base, int m) {
	int temp = 0;
	for (int i=0; i<s.length(); i++) {
		temp = (temp*base+Character.getNumericValue(s.charAt(i)))%m;
	}
	if (temp==0) {return true;}
	return false;
}


//階乗
static long factorial (int i) {
	if (i==1) {return 1;}
	else {return i*factorial(i-1);}
}


//進数変換
static String toNbase (String sm, int m, int n) {
	return Long.toString(Long.parseLong(sm,m),n);
}
  
}

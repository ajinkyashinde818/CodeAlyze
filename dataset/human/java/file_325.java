import java.util.Scanner;

public class Main {

     static Scanner scanner;

     public static void main(String[] args) {
         scanner = new Scanner(System.in);

         int N=gi();
         long[] a=new long[N];
         long minabs=Long.MAX_VALUE;
         long max=0;
         long mc=0;
         for(int i=0; i<N;i++) {
        	 a[i]=gi();
        	 if(a[i]<0)mc++;
        	 long abs=Math.abs(a[i]);
        	 minabs=Math.min(abs, minabs);
        	 max+=abs;
         }

         if(mc%2==0) {
        	 System.out.print(max);
         } else {
        	 System.out.print(max-minabs*2);
         }

         //System.out.print(a^b);



         //System.out.print(sb);
     }

     public static long f(long n) {
    	 if(n<=0)return 0;
    	 if(n==1)return 1;
    	 if(n==2)return 3;
    	 if(n==3)return 0;
    	 int i=2;
    	 while(i<=n) {
    		 i=i*2;
    	 }
    	 i=i/2;

    	 long ret=0;
    	 if((n-i)%2==0) {
    		 ret+=i;
    	 }
    	 ret= ret + f(n-i);
    	 return ret;
     }

     // 文字列として入力を取得
     public static String gs() {
          return scanner.next();
     }

     // intとして入力を取得
     public static int gi() {
          return Integer.parseInt(scanner.next());
     }

     // longとして入力を取得
     public static long gl() {
          return Long.parseLong(scanner.next());
     }

     // doubleとして入力を取得
     public static double gd() {
          return Double.parseDouble(scanner.next());
     }
}

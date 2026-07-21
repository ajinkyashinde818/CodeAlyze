import java.util.Scanner;

public class Main {

     static Scanner scanner;

     public static void main(String[] args) {
         scanner = new Scanner(System.in);

         int N=gi();
         long K=gl();
         long S=gl();
         long[] a=new long[N];

         for (int i=0; i<N;i++) {
        	 if(i<K) {
        		 a[i]=S;
        	 } else {
        		 long q=S+1;
        		 if(q>1000000000) q=1;
        		 a[i]=q;
        	 }
         }

         StringBuilder sb=new StringBuilder();
         for (int i=0;i<N;i++) {
        	 if(i!=0);sb.append(" ");
        	 sb.append(a[i]);
         }

         System.out.println(sb);
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

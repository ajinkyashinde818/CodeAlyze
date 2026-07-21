import java.util.Scanner;

public class Main {

     static Scanner scanner;

     public static void main(String[] args) {
         scanner = new Scanner(System.in);

         String s=gs();


         StringBuilder sb=new StringBuilder();
         int l=0;
         int r=s.length()-1;
         long ans=0;
         while(r-l>0) {
        	 char ch1=s.charAt(l);
        	 char ch2=s.charAt(r);
        	 if(ch1==ch2) {
        		 l++;
        		 r--;
        	 } else {
        		 if(ch1=='x') {
        			 ans++;
        			 l++;
        		 } else if(ch2=='x') {
        			 ans++;
        			 r--;
        		 } else {
        			 System.out.println(-1);
        			 return;
        		 }
        	 }
         }

         System.out.println(ans);
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

import java.util.Scanner;

public class Main {

     static Scanner scanner;

     public static void main(String[] args) {
         scanner = new Scanner(System.in);

         String S=gs();
         int Q=gi();
         int[] T=new int[Q];
         int[] F=new int[Q];
         String[] C=new String[Q];

         for (int i=0; i<Q;i++) {
        	 T[i]=gi();
        	 if(T[i]==2) {
        		 F[i]=gi();
        		 C[i]=gs();
        	 }
         }
         
         StringBuilder sb= new StringBuilder(S);
         boolean rev=false;
         for (int i=0; i<Q;i++) {
        	 if(T[i]==1) {
        		 rev=!rev;
        	 } else {
        		 if((rev==false && F[i]==1) || rev==true && F[i]==2) {
        			 sb.insert(0,C[i]);
        		 } else {
        			 sb.append(C[i]);
        		 }
        	 }
         }
         StringBuffer sbf=new StringBuffer(sb);
         if(rev)sbf.reverse();

         System.out.println(sbf.toString());
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

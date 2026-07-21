import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

     static Scanner scanner;

     public static void main(String[] args) {
         scanner = new Scanner(System.in);

         int N=gi();
         long K=gl();
         int[] a=new int[N+1];

         for (int i=0; i<N;i++) {
        	 a[i]=gi()-1;
         }

         int pos=0;
         int r=0;
         Map<Integer,Integer> map=new HashMap<Integer,Integer>();
         while(!map.containsKey(pos)) {
        	 map.put(pos, r);
        	 r++;
        	 pos=a[pos];

         }

         long s=(long)map.get(pos);
         if(K>s) {
             long b=r-s;
             long ri=(K-s)%b;
             for(int i=0; i<ri;i++) {
        	     pos=a[pos];
             }
         } else {
             pos=0;
             for(int i=0; i<K;i++) {
        	     pos=a[pos];
             }
         }
         

         System.out.println(pos+1);
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

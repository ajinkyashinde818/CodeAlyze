import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

     static Scanner scanner;

     public static void main(String[] args) {
         scanner = new Scanner(System.in);

         long N=gl();
         List<Long> l=insuB(N);
         Map<Long,Integer> m=new HashMap<Long,Integer>();
         for(int i=0; i<l.size();i++) {
        	 if(m.containsKey(l.get(i))) {
        		 m.put(l.get(i), m.get(l.get(i))+1);
        	 } else {
        		 m.put(l.get(i), 1);
        	 }
         }

         int ans=0;
         for(Integer v : m.values()) {
        	 int tmp=1;
        	 while(v-tmp>=0) {
        		 v-=tmp;
        		 tmp++;
        		 ans++;
        	 }
         }

         System.out.println(ans);
     }

  // 素因数分解
 	public static List<Long> insuB(long n) {
 		List<Long> l=new ArrayList<Long>();
 		long tmp=n;
 		for(long i=2; i<=Math.sqrt(n); i++) {
 			while(tmp%i==0) {
 				tmp=tmp/i;
 				l.add(i);
 			}
 		}
 		if(tmp!=1) l.add(tmp);

 		return l;
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

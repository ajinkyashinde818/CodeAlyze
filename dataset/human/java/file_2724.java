import static java.lang.Math.*;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            String s = scanner.next();
            String t = scanner.next();
            char[] sAr = s.toCharArray(); 
            char[] tAr = t.toCharArray();
            char[] sd = chsort(sAr);
            /*char[] td = chsort(tAr);*/
            
            if (Comp(sd, tAr))
                System.out.println("Yes");
            else
                System.out.println("No");
        };
        
        private static char[] chsort(char[] s){
            Arrays.sort(s);
            return s;
        }
        
        private static Boolean Comp(char[] s, char[] t ){
            int len = min(s.length, t.length);
            Boolean b;
            int judge=0;
            for (int i=0; i < len; i++){
                int j=i;
                b=false;
                while ((j < t.length) && (!b)){
                    if (s[i] < t[j]){
                        char c=t[i];
                        t[i]=t[j];
                        t[j]=c;
                        b=true;
                        judge = 1;
                    } else if ((s[i] == t[j]) && (judge ==0)){
                        judge = 0;
                    } else {
                        judge = -1;
                    }
                    j++;
                }
                if ((b)) return b;
            }
            if ((judge == 0) && (s.length < t.length)){
                return true;
            } else {
                return false;
            }
        }
}

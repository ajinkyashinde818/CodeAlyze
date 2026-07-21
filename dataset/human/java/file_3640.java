import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String a = sc.next();
        String b = sc.next();
        int aa = (int)a.charAt(0);
        int bb = (int)b.charAt(0);
        
        if(aa==bb){
            System.out.print("=");
        }else if(aa<bb){
            System.out.print("<");
        }else{
            System.out.print(">");
        }
   }
}

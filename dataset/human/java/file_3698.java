import java.util.*;
 
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str1 = sc.next();
        String str2 = sc.next();
        
        char c1 = str1.charAt(0);
        char c2 = str2.charAt(0);
        
        Character C1 = new Character(c1);
        Character C2 = new Character(c2);
        
        int a = C1.compareTo(C2);
        
        if(a<0){
            System.out.println("<");
        }else if(a>0){
            System.out.println(">");
        }else{
            System.out.println("=");
        }
        //System.out.println(a);
    }
}

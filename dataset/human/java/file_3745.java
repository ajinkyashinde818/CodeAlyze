import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String X = sc.next();
        String Y = sc.next();
        
        if(henkan(X)<henkan(Y)){
            System.out.println("<");
        }else if(henkan(X)>henkan(Y)){
            System.out.println(">");
        }else{
            System.out.println("=");
        }
    }
    
    public static int henkan(String str){
            if(str.equals("A")) return 10;
            if(str.equals("B")) return 11;
            if(str.equals("C")) return 12;
            if(str.equals("D")) return 13; 
            if(str.equals("E")) return 14;
            else return 15;
        }
}

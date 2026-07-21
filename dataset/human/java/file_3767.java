import java.util.Scanner;
import java.util.Arrays;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String X=sc.next();
        String Y=sc.next();
        
        if(X.compareTo(Y)<0){
            System.out.println("<");
        }else if(Y.compareTo(X)<0){
            System.out.println(">");
        }else{
            System.out.println("=");
        }
    }
}

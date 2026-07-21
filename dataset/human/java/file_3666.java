import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        char A = sc.next().charAt(0);
        char B = sc.next().charAt(0);

        if(A<B){
            System.out.println("<");
        }
        else if(A>B){
            System.out.println(">");
        }
        else{
            System.out.println("=");
        }
    }
}

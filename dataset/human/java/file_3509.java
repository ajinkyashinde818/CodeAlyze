import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        int X, Y;
        Scanner sc = new Scanner(System.in);
        X = sc.next().charAt(0);
        Y = sc.next().charAt(0);
        
        if(X < Y)
            System.out.println("<");
        else if(X > Y)
            System.out.println(">");
        else
            System.out.println("=");
    }
    
}

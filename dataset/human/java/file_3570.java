import java.util.*;
public class Main{

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        char z,x;
        z=input.next().charAt(0);
        x=input.next().charAt(0);
        if(z==x)
            System.out.println("=");
        else if(z>x)
            System.out.println(">");
        else System.out.println("<");
    }
    
}

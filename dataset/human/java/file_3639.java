import java.util.*;

public class Main{
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        String X = sc.next(), Y = sc.next();
        int x = check(X), y = check(Y);
        //System.out.println(x + " " + y);
        if(x>y){
            System.out.println(">");
        }else if(x<y){
            System.out.println("<");
        }else {
            System.out.println("=");
        }
    }
    
    public static int check(String str){
        int s=0;
        if(str.equals("A"))s=10;
        else if(str.equals("B"))s=11;
        else if(str.equals("C"))s=12;
        else if(str.equals("D"))s=13;
        else if(str.equals("E"))s=14;
        else if(str.equals("F"))s=15;
        return s;
    }
}

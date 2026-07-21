import java.util.*;
public class Main {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String a,b;

        a = sc.next();
        b = sc.next();
        int a2=0,b2=0;
        if(a.equals("A")) a2 = 10;
        else if(a.equals("B")) a2 =11;
        else if(a.equals("C")) a2 = 12;
        else if(a.equals("D")) a2=13;
        else if(a.equals("E")) a2=14;
        else if (a.equals("F"))a2 =15;

        if(b.equals("A")) b2 = 10;
        else if(b.equals("B")) b2 =11;
        else if(b.equals("C")) b2 = 12;
        else if(b.equals("D")) b2=13;
        else if(b.equals("E")) b2=14;
        else if(b.equals("F")) b2 =15;

        if(a2>b2) System.out.println(">");
        else if(a2<b2) System.out.println("<");
        else if(a2==b2) System.out.println("=");
    }
}

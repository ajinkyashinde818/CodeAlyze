import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner scan = new java.util.Scanner(System.in);
        int n = scan.nextInt();
        int r = scan.nextInt();
        int out;
        
        if(n >= 10){
            out = r;
            System.out.println(out);
        }else{
            out = r + 100 * (10 - n);
            System.out.println(out);
        }
    }
}

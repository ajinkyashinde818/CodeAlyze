import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int out = 2;
        if(n == out){
            System.out.println(2);
            return;
        }
        while(out <= n){
            out *= 2;
        }
        System.out.println(out / 2);
        scan.close();
    }
}

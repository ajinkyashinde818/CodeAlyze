import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        
        int res = b + (c - (a + b) <= 1 ? c : c - (c - b - a) + 1);
        
        System.out.println(res);
    }
}

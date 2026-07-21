import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());
        
        System.out.println(lcm(a, b));
    }
    
    static long gcd(long a, long b){
        
        if(b == 0){
            return a;
        }else{
            return gcd(b, a % b);
        }
    }
    
    static long lcm(long a, long b){
        
        return (a / gcd(a, b)) * b;
    }
}

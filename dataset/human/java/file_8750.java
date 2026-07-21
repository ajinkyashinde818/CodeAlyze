import java.util.Scanner;

public class Main{

    public static int eukleides(int a, int b){
        if(b % a == 0){
            return a;
        }
        int mod = b % a;

        return eukleides(mod, a);
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        // input
        int a = scan.nextInt();
        int b = scan.nextInt();
        int border = scan.nextInt();
        
        // search
        int gcd = eukleides(Math.min(a, b), Math.max(a, b));
        int count = 0;
        for(int i = gcd; i >= 1; i--){
            if(gcd % i == 0){
                count++;
            }
            if(count == border){
                System.out.println(i);
                break;
            }
        }

    }
}

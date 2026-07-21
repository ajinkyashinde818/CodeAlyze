import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);

        int n = stdIn.nextInt();
        int r = stdIn.nextInt();

        if(n >= 10){
            System.out.println(r);
        }else{
            System.out.println(r + 100 * (10 - n));
        }
    }
}

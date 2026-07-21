import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();

        if(num%10 == 9 || num/10 == 9) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        //System.out.println()

        //System.out.println(count);

    }
}

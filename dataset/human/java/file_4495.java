import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
        if(c <= a+b) {
            System.out.println(b+c);
        } else {
            System.out.println(a+b+b+1);
        }
    }
}

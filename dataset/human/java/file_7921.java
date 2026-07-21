import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = 0;

        for (int i = 0; i < 10; i++) {
            int t = scan.nextInt();
            a += t;

        }
        System.out.println(a);
    }
}

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);
        int n = Integer.parseInt(stdIn.next());
        int r = Integer.parseInt(stdIn.next());

        if (n >= 10) {
            System.out.println(r);
        } else {
            System.out.println(r + 100 * (10 - n));
        }
    }
}

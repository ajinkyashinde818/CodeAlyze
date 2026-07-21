import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int i;
        int s;
        int total = 0;
        for (i = 0; i < 10; i++) {
            s = scan.nextInt();
            total += s;

        }
        System.out.println(total);
    }
}

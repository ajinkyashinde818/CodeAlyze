import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] a = new String[]{sc.next(), sc.next()};
        int res = a[0].compareTo(a[1]);
        if (res > 0) {
            System.out.println(">");
        } else if (res < 0) {
            System.out.println("<");
        } else {
            System.out.println("=");
        }
    }
}

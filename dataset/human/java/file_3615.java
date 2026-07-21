import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        char a = sc.next().toCharArray()[0];
        char b = sc.next().toCharArray()[0];
        System.out.println(a<b?"<":a>b?">":"=");
    }
}

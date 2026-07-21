import java.util.Scanner;
import java.util.Stack;

class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        System.out.println(x < 1200 ? "ABC" : "ARC");
    }
}

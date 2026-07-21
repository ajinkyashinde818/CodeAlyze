import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int R = Integer.parseInt(sc.next());
        
        System.out.println(N < 10 ? R + (100 * (10 - N)) : R);
    }
}

import java.util.Scanner;

public class Main {
    /**
     * ABC/ARC
     * @param 1 ≦ x ≦ 3,000
     */
    public static void main(String...args) {
        try (Scanner sc = new Scanner(System.in)) {
            int x = sc.nextInt();
            if (x < 1200) {
                System.out.println("ABC");
            } else {
                System.out.println("ARC");
            }
        }
    }
}

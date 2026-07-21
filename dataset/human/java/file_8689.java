public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int a = scanner.nextInt(), b = scanner.nextInt(), k = scanner.nextInt();
        for (int i = Math.max(a, b), c = 0; i > 0; i--) {
            if (a % i == 0 && b % i == 0 && ++c == k) {
                System.out.println(i);
                return;
            }
        }
    }
}

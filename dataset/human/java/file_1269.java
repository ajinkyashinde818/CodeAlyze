public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        long fd = 0, min = -1, temp;
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            fd += a[i] = scanner.nextInt();
        for (int i = 0; i < n - 1; i++) {
            min = Math.min(temp = Math.abs(fd -= a[i] * 2), min == -1 ? temp : min);
        }

        System.out.println(min);
    }
}

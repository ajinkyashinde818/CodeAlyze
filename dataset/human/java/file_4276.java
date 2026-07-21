import java.util.Scanner;

public class Main {

    private void execute() throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        String[] a = sc.nextLine().split(" ");
        String[] b = sc.nextLine().split(" ");
        String[] c = sc.nextLine().split(" ");
        int totalScore = 0;
        for (int idx = 0; idx < n; idx++) {
            int valA = Integer.parseInt(a[idx]);
            totalScore += Integer.parseInt(b[valA - 1]);
            if (idx > 0 && ((valA - 1) == Integer.parseInt(a[idx - 1]))) {
                totalScore += Integer.parseInt(c[valA - 2]);
            }
        }
        System.out.println(totalScore);
    }

    public static void main(String[] args) {
        try {
            new Main().execute();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

}

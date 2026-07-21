import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();
        String[] nImage = new String[n];
        for (int i = 0; i < n; i++) {
            nImage[i] = sc.nextLine();
        }
        String[] mImage = new String[m];
        for (int i = 0; i < m; i++) {
            mImage[i] = sc.nextLine();
        }

        for (int i = 0; i < n - m + 1; i++) {
            int index = nImage[i].indexOf(mImage[0]);
            while (index != -1) {
                if (isMutch(nImage, mImage, index, i)) {
                    System.out.println("Yes");
                    return;
                }
                index = nImage[i].indexOf(mImage[0], index + 1);
            }
        }

        System.out.println("No");
    }

    static boolean isMutch(String[] nImage, String[] mImage, int xOffset, int yOffset) {
        for (int i = 0; i < mImage.length; i++) {
            if (nImage[yOffset + i].startsWith(mImage[i], xOffset) == false) {
                return false;
            }
        }

        return true;
    }
}

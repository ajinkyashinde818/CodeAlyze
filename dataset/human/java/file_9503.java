import java.util.Scanner;

//atcoderはScannerクラスのsc.next()で行ける
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int flagcnt = 0;
        boolean flag = false;
        for (int i = 0; i < n; i++) {
            int i1 = sc.nextInt();
            int i2 = sc.nextInt();
            if (i1 == i2) {
                flagcnt += 1;
            } else {
                flagcnt = 0;
            }
            if (flagcnt > 2) {
                flag = true;
                break;
            }
        }
        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }


    }
}

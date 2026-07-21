import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long l = sc.nextLong();
        long cnt = 0;
        sc.close();
        if (l % 2 == 1) {
            System.out.println(0);
            return;
        } else {
            long five = 10;
            while (five <= l) {
                cnt += (l / five);
                five *= 5;
            }
        }
        System.out.println(cnt);

    }
}

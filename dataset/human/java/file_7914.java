import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int s[] = new int[10];
        int a=0;
        s[0] = scanner.nextInt();
        s[1] = scanner.nextInt();
        s[2] = scanner.nextInt();
        s[3] = scanner.nextInt();
        s[4] = scanner.nextInt();
        s[5] = scanner.nextInt();
        s[6] = scanner.nextInt();
        s[7] = scanner.nextInt();
        s[8] = scanner.nextInt();
        s[9] = scanner.nextInt();
        a=s[0]+s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9];
        System.out.println(a);

    }
}

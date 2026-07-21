import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int cnt = b;
        if (c <= a + b + 1)
            cnt += c;
        else
            cnt += b + a + 1;
        
        System.out.println(cnt);
    }
}

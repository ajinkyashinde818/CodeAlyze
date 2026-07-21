import java.util.Scanner;

public class Main
{

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        int a = 0;

        for (int i = 0; i < 10; i++) {
            int s = scan.nextInt();
            a += s;
        }
        System.out.println(a);

    }
}

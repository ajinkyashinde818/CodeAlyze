import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();
        String[] str = new String[3];
        str = s.split("");
        if (str[0].equals(str[1]))
            System.out.println("No");
        else if (str[0].equals(str[2]))
            System.out.println("No");
        else if (str[1].equals(str[2]))
            System.out.println("No");
        else
            System.out.println("Yes");
    }
}

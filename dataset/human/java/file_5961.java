import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        sc.close();

        char[] split = s.toCharArray();

        if (split[0] != split[1] && split[1] != split[2] && split[2] != split[0]) {
            System.out.println("Yes");
        }
        else {
            System.out.println("No");
        }
    }
}

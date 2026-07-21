import java.util.Scanner;

class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String n = sc.next();
        if (n.contains("9")) {
            System.out.println("Yes");
        } else{
            System.out.println("No");
        }
    }
}

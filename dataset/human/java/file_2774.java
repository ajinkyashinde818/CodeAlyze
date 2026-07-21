import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        String t = scanner.next();

        boolean diff = false;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                if (s.charAt(i) < t.charAt(j)){
                    System.out.println("Yes");
                    return;
                }
                if (s.charAt(i) != t.charAt(j)) diff = true;
            }
        }

        if (s.length() < t.length() && !diff) System.out.println("Yes");
        else System.out.println("No");
    }
}

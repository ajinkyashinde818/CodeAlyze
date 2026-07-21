import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        if (scanner.hasNextLine()) {
            String line = scanner.nextLine();

            if (line.length() == 3 && line.indexOf('a') >= 0 && line.indexOf('b') >= 0  && line.indexOf('c') >= 0 ) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}

import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        String line = scan.nextLine();

        int count = 0;
        for (int i = 0; i < Integer.parseInt(line); i++) {
            String dice = scan.nextLine();
            String[] values = dice.split(" ");
            if (count >= 3) {
                System.out.println("Yes");
                return;
            } else {
                if (values[0].equals(values[1])) {
                    count++;
                } else {
                    count = 0;
                }
            }
        }
        
        if (count >= 3) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

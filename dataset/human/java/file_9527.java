import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        int num = Integer.parseInt(line);

        int count = 0;
        boolean ret = false;
        for (int i = 0; i < num; i++) {
            line = sc.nextLine();
            String[] lines = line.split(" ", 0);
            int a = Integer.parseInt(lines[0]);
            int b = Integer.parseInt(lines[1]);
            if (a == b) {
                count++;
                if (count == 3) {
                    ret = true;
                }
            } else {
                count = 0;
            }
        }

        if (ret) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

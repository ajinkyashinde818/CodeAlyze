import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.next();
        int number = 0;
        int carry = 0;
        for (int i = n.length() - 1; i >= 0; --i) {
            int current = Integer.valueOf(n.charAt(i)) - '0' + carry;
         //   System.out.print("current: " + current);
            if (current > 5) {
                carry = 1;
                number += 10 - current;
            } else if (current == 5) {
                if (i >= 1 && Integer.valueOf(n.charAt(i - 1)) - '0' >= 5) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                number += current;
            } else {
                carry = 0;
                number += current;
            }
        //    System.out.println(" number: " + number);
        }
        if (carry > 0) {
            number += carry;
        }
        System.out.println(number);
    }
}

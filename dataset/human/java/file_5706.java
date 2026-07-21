import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String word = scan.next();
        char[] data = word.toCharArray();
        int result = 0;
        for(int i = 0; i < data.length; i++) {
            if (data[i] == 'a') {
                result |= 1;
            }
            if (data[i] == 'b') {
                result |= 2;
            }
            if (data[i] == 'c') {
                result |= 4;
            }
        }
        System.out.println(result == 7 ? "Yes" : "No");
    }
}

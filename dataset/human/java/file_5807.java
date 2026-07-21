import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        int[] countChar = new int[3];

        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'a':
                    countChar[0]+=1;
                    break;
                case 'b':
                    countChar[1]+=1;
                    break;
                case 'c':
                    countChar[2]+=1;
                    break;
                 default:
                    break;
            }
        }

        if (countChar[0] > 1 || countChar[1] > 1 || countChar[2] > 1) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}

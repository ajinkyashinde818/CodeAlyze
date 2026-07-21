import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.nextLine().toCharArray();
		char[] t = sc.nextLine().toCharArray();
        Arrays.sort(s);
        Arrays.sort(t);

        StringBuilder revercseT = new StringBuilder();
		revercseT.append(t);
        revercseT.reverse();

        System.out.println(String.valueOf(s).compareTo(revercseT.toString()) < 0 ? "Yes" : "No");
    }
}

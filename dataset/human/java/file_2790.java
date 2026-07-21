import java.util.Arrays;
import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();
        Arrays.sort(t);
        String t2 = new StringBuilder(String.valueOf(t)).reverse().toString();
        Arrays.sort(s);
        String s2 = String.valueOf(s);

        System.out.println(s2.compareTo(t2) < 0 ? "Yes": "No");
    }
}

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    	public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	char[] n = sc.next().toCharArray();
    	char[] s = sc.next().toCharArray();

    	 Arrays.sort(n);
    	 Arrays.sort(s);

        String nn_last = new String(n);
        String ss_last = new String(s);
        ss_last = new StringBuilder(ss_last).reverse().toString();
        System.out.println(nn_last.compareTo(ss_last) < 0 ? "Yes" : "No");
    	}
    }

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static String newS(String [] s){
        String new_s = "";
        for (int i = 0; i < s.length; i++) new_s += s[i];
        return new_s;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String [] s = in.next().split("");
        Arrays.sort(s);
        if (newS(s).equals("abc")){
            System.out.println("Yes");
            return;
        }
        System.out.println("No");
    }

}

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String [] s = in.next().split("");
        String [] t = in.next().split("");
        Arrays.sort(s);
        Arrays.sort(t);
        String new_s = "";
        for (int i = 0; i < s.length; i++){
            new_s += s[i];
        }
        String new_t = "";
        for (int i = t.length-1; i >= 0; i--){
            new_t += t[i];
        }
        if (new_s.equals(new_t)){
            System.out.println("No");
            return;
        }
        String [] sort = {new_s, new_t};
        Arrays.sort(sort);
        if (sort[0].equals(new_s)){
            System.out.println("Yes");
            return;
        }
        System.out.println("No");
    }
}

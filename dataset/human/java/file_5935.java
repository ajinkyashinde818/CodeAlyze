import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        boolean[] b = new boolean[3];
        String s = sc.next();
        for (int i = 0;i < 3;++i){
            if(s.charAt(i) == 'a'){
                b[0] = true;
            }
            else if(s.charAt(i) == 'b'){
                b[1] = true;
            }
            else if(s.charAt(i) == 'c'){
                b[2] = true;
            }
        }
        if(b[0]&&b[1]&&b[2])System.out.println("Yes"); else System.out.println("No");
    }
}

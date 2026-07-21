import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String[] s = S.split("");
        String  ans = "No";
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    if(s[i].equals("a") && s[j].equals("b") && s[k].equals("c")) ans = "Yes";
                }
            }
        }
        System.out.println(ans);
    } 
}

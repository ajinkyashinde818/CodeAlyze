import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        if (s.replaceAll("eraser", "").replaceAll("erase", "").replaceAll("dreamer", "").replaceAll("dream", "")
                .equals("")) {
            System.out.println("YES");
        
        } 

        else {
            System.out.println("NO");
        }
        
        sc.close();
    }
}

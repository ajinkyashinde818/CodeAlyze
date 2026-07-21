import java.util.*;
 
public class Main{

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        String S = sc.next();
        sc.close();

        S = S.replace("eraser", "");
        S = S.replace("erase", "");
        S = S.replace("dreamer", "");
        S = S.replace("dream", "");
        
        if(S.equals(""))
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}

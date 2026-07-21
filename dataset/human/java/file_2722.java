import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class Main{
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        char[] c1 = s.toCharArray();
        String t = sc.next();
        char[] c2 = t.toCharArray();
        sc.close();

        Arrays.sort(c1);
        Arrays.sort(c2);

        for(int i = 0; i < Math.min(c1.length, c2.length); i++){
            if(c1[i] < c2[c2.length-i-1]){
                System.out.println("Yes");
                return;
            } else if(c1[i] > c2[c2.length-i-1]){
                System.out.println("No");
                return;
            } else
                continue;
        }
        if(c1.length < c2.length)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}

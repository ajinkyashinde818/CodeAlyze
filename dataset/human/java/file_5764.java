import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String S=sc.next();
        if (S.equals("abc") || S.equals("acb") || S.equals("bac") || S.equals("bca") || S.equals("cab") || S.equals("cba")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

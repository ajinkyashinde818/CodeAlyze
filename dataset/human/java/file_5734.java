import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        char a = s.charAt(0);
        char b = s.charAt(1);
        char c = s.charAt(2);
        if(a==b||b==c||c==a){
            System.out.println("No");
        }
        else{
            System.out.println("Yes");
        }
    }
}

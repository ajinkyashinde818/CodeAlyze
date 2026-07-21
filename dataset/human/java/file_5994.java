import java.util.*;

public class Main{
    public static void main(String[] args){


        Scanner sc = new Scanner(System.in);

        String S = sc.next();
        String a = "abc";
        String b = "acb";
        String c = "bac";
        String d = "cab";
        String e = "bca";
        String f = "cba";

        if(S .equals(a)){
            System.out.println("Yes");
        }else if(S.equals(b)){
            System.out.println("Yes");
        }else if(S.equals(c)){
            System.out.println("Yes");
        }else if(S.equals(d)){
            System.out.println("Yes");
        }else if(S.equals(e)){
            System.out.println("Yes");
        }else if(S.equals(f)){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }

    }
}

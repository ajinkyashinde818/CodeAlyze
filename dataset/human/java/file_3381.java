import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        String ans = "No";
        if(n.charAt(0) == '9' || n.charAt(1) == '9') ans = "Yes";
        System.out.println(ans);
    }
}

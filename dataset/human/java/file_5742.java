import java.util.*;

class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        char[] c = { str.charAt(0), str.charAt(1), str.charAt(2) };
        String ans = "No";

        if( c[0] != c[1] && c[1] != c[2] && c[2] != c[0] ){
            ans = "Yes";
        }
        System.out.println(ans);
    }
}

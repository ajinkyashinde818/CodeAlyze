import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        char a = sc.next().charAt(0), b = sc.next().charAt(0);
        char ans = '>';
        if(a == b) ans = '=';
        else if(a < b) ans = '<';
        System.out.println(ans);
    }
}

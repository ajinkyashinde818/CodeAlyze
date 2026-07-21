import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
        int ans = 0;
        if(c > a + b) ans = a + b * 2 + 1; 
        else ans = b + c;
        System.out.println(ans);
    }
}

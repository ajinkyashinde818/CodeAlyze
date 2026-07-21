import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        int res = 0, l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s.charAt(l) == s.charAt(r))    {
                l++;
                r--;
            } else if (s.charAt(l) != 'x' && s.charAt(r) != 'x')   {
                System.out.println(-1);
                return;
            } else if (s.charAt(l) == 'x')  {
                l++;
                res++;
            } else  {
                r--;
                res++;
            }
        }
        System.out.println(res);
    }
}

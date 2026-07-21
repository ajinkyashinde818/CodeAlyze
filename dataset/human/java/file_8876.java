import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int k = in.nextInt();
        
        for (int i = 100; i >= 1; i--)
            if (a %i == 0 && b %i == 0)
            {
                k--;
                if (k == 0)
                {
                    System.out.println(i);
                    break;
                }
            }
        
        in.close();
    }
}

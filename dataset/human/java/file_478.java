import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int R = input.nextInt();
        if(N>=10)
        {
            System.out.println(R);
        }
        else if(N>=1&&N<10)
        {
            int A = 100*(10-N);
            System.out.println(A+R);
        }
    }
}

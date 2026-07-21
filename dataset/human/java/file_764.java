import java.util.Scanner;
class Main
{
    public static void main(String []args)
    {
        Scanner scan = new Scanner(System.in);
        int N,R;
        N = scan.nextInt();
        R = scan.nextInt();
        int IR;
        if(N>=10)
        {
            IR = R;
        }
        else
        {
            IR = R + 100*(10-N);
        }
        System.out.println(IR);
    }
}

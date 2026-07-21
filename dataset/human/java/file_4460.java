import java.util.Scanner;

public class Main {
    public static int maximum_poison(int a,int b)
    {
        if(a>=(b-1))
            return b;
        return a+1;

    }
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        int a,b,c;
        a = input.nextInt();
        b = input.nextInt();
        c = input.nextInt();

        System.out.println(b+maximum_poison(a+b,c));


    }
}

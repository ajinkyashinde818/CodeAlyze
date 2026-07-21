import java.util.*;
public class Main
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        if(n>=10)
        System.out.println(k);
        else
        System.out.println(k+100*(10-n));
        
    }
}

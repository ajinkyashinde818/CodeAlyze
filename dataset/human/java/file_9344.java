import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int count=0;
        while(n!=0)
        {
            int a = scn.nextInt();
            int b = scn.nextInt();
            if(a==b)
            {
                count++;
            }
            else if(count<3)
            {
                count=0;
            }
            n--;
        }
        if(count>=3)
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
    }
}

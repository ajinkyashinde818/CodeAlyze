import java.util.*;
import java.io.*;


public class Main{

     public static void main(String []args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int s =scanner.nextInt();
        int counter=0;
       
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                 int z = s;
                 z = z-i -j;
                if(z>=0 && z<=n)
                counter++;
            }
        }
        
        System.out.println(counter);
     }
}

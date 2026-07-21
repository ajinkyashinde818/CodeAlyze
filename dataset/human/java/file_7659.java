/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
 
{
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        long k = s.nextLong();
        int tel[] = new int[n];
        for(int i=0; i<n; i++)
        {
            tel[i] = s.nextInt();
        }
        int[] ct = new int[n];
        int town = 1;
        int chk = 1;
        int sw = 0;
        int tr = 0;
        for(int i=0; i<k; i++)
        {
            ct[town-1]++;
            town = tel[town-1];
            tr++;
            if(ct[town-1]==2)
            {
                if(sw==0)
                {
                    sw=1;
                }
                else
                {
                    chk++;
                }
            }
            else if(ct[town-1]==3)
            {
                int rem = (int) ((k-tr)%chk);
                for(int j=0; j<rem; j++)
                {
                    town = tel[town-1];
                }
                break;
            }
        }
        System.out.println(town);
    }
}

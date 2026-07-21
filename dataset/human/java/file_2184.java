import java.io.*;
import java.util.*;

public class Main{
    public static void main(String [] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String temp[] = br.readLine().split(" ");
        
        long n = Long.parseLong(temp[0]);
        int count = 0;
        int ans = 0;
        if(n==1){System.out.println(0); return;}
        Set<Integer> set = new HashSet<>();
        while (n%2==0) 
        { 
            n /= 2; 
            if(!set.contains(count)){ ans+=1; set.add(count); count = 0;}
            else count+=1;
        } 
  
       
        
        for (int i = 3; i <= Math.sqrt(n); i+= 2) 
        {
            set = new HashSet<>();
            count = 0;
            while (n%i == 0) 
            { 
               
                n /= i; 
                if(!set.contains(count)){ ans+=1; set.add(count); count = 0;}
                else count+=1;
            } 

        }
         if(n>2) ans+=1;
        

        System.out.println(ans);
       

    }
}

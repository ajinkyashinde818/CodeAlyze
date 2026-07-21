import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args)throws Exception{
        Scanner sc=new Scanner(System.in);
        long a=sc.nextLong();
        long b=sc.nextLong();
        int i=1;
        while(true){
            if((long)Math.max(a,b)*i%(long)Math.min(a,b)==0){
                System.out.println((long)Math.max(a,b)*i);
                break;
            }
            i++;
        }
    }
}

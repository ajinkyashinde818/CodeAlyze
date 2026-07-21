import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args)throws Exception{
        Scanner sc=new Scanner(System.in);
        int k=sc.nextInt();
        int n=sc.nextInt();
        int[] ary=new int[n];
        int distance=0;
        ary[0]=sc.nextInt();
        for(int i=1;i<n;i++){
            ary[i]=sc.nextInt();
            distance=(int)Math.max(distance,ary[i]-ary[i-1]);
        }
        distance=(int)Math.max(distance,k-ary[n-1]+ary[0]);
        System.out.println(k-distance);
    }
}

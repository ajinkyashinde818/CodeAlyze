import java.util.*;
import java.lang.*;

public class Main {
    static class pair{
        double f,s;
        pair(double f,double s){
            this.f=f;
            this.s=s;
        }
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int c=in.nextInt();
        int A[]=new int[c+1];
        int B[]=new int[c+1];
        int C[]=new int[c];
        for(int i=1;i<=c;i++)
              A[i]=in.nextInt();
        for(int i=1;i<=c;i++)
              B[i]=in.nextInt();
        for(int i=1;i<c;i++)
              C[i]=in.nextInt();
        long sum=0;
        int h=-1;
        for(int i=1;i<=c;i++){
            sum+=B[A[i]];
            if(h+1==A[i])
                sum+=C[h];
            h=A[i];
        }
        System.out.println(sum);
        in.close();
    }
}

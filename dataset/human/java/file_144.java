import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] b=new long[n];
        long sum=0;
        long flag=0;
        long temp=Long.MAX_VALUE;
        for(int i=0;i<n;++i){
          b[i]= sc.nextInt();
          flag+=b[i]<0?1:0;
          b[i]*=b[i]<0?-1:1;
          sum+=b[i];
          temp=temp<b[i]?temp:b[i];
        }
        if(flag%2==0){
          System.out.println(sum);
        }else{
          System.out.println(sum-2*temp);
        }
    }
}

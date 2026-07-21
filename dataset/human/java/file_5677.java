import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        int n=0,k=0,s=0;
        if(scan.hasNext())
            n=scan.nextInt();
        if(scan.hasNext())
            k=scan.nextInt();
        if(scan.hasNext())
            s=scan.nextInt();

        int[] arr=new int[n];
        for(int i=0;i<k;i++){
            arr[i]=s;
        }
        for(int i=k;i<n;i++){
            if(s%2!=0){
                arr[i]=2;
                continue;
            }
            if(s!=1000000000)
            arr[i]=s+1;
            else
                arr[i]=s-1;
        }
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }

}

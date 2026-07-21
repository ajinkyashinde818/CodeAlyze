import java.util.*;

class Main {

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        int k = s.nextInt();
        int n = s.nextInt();
        int[] a=new int[n];
        int[] d=new int[n];
        for (int i = 0; i <n ; i++) {
             a[i] = s.nextInt();
             if(i==0){
             }else{
                 d[i]=a[i]-a[i-1];
             }
        }
        d[0]=k-a[n-1]+a[0];

        int max=-1;
        int sum=0;
        for (int i = 0; i <n ; i++) {
            sum+=d[i];
            if(max<d[i]){
                max=d[i];
            }
        }
        System.out.println(sum-max);
    }

}

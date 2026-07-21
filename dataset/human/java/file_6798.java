import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i =0;i<a.length;i++){
            a[i]=sc.nextInt();
        }
        int t = 0;
        int sum = 0;
        for(int i=0;i<a.length;i++){
            if(i+1-n==0){
                t = Math.max(k+a[0]-a[n-1],t);
                sum += k+a[0]-a[n-1];
            } else {
                t = Math.max(t,a[i+1]-a[i]);
                sum += a[i+1]-a[i];
            }
        }
        System.out.println(sum-t);
    }
}

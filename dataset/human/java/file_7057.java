import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int k=scanner.nextInt();
        int n=scanner.nextInt();
        int arr[]=new int[n];
        for(int j=0;j<n;j++){
            arr[j]=scanner.nextInt();
        }
        int max=Integer.MIN_VALUE;
        for(int j=1;j<n;j++){
            if(arr[j]-arr[j-1]>max){
                max=arr[j]-arr[j-1];
            }
        }
        if(k-arr[n-1]+arr[0]>max){
            max=k-arr[n-1]+arr[0];
        }
        System.out.println(k-max);
    }
}

import java.util.Scanner;
import java.util.Arrays;

public class Main{
public static void main(String[] args){
Scanner scan=new Scanner(System.in);
int k=scan.nextInt();
int n=scan.nextInt();
int[] a=new int[n];

int i=0;
for(i=0;i<n;i++){
    a[i]=scan.nextInt();
}
Arrays.sort(a);
int[] b=new int[n];
for(i=0;i<n-1;i++){
  b[i]=a[i+1]-a[i];
}
b[n-1]=k-a[n-1]+a[0];
Arrays.sort(b);

System.out.println(k-b[n-1]);


}
}

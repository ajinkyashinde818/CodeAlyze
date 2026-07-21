import java.util.*;
public class Main {

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int para = s.nextInt();
    int n = s.nextInt();
    int[] arr = new int[n];

    for(int i=0;i<n;i++) {
      arr[i]=s.nextInt();
    }
    int[] d = new int[n];

    d[0]=arr[0]+para-arr[n-1];
    for(int i=1;i<n;i++) {
      d[i] =  arr[i]-arr[i-1];
    }
    int max = 0;
    for(int i=0;i<n;i++) {
      if(d[i]>max) 
        max = d[i];
    }
    System.out.println(para-max);
  }

 }

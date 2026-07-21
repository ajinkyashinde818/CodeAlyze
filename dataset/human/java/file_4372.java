import java.util.*;


public class Main{
	public static void main(String args[]){
        int sum = 0;
        int inf = 1000;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n-1];
        for(int i = 0; i < n; i++){ //a
            a[i] = sc.nextInt();
        }
        for(int j = 0; j < n; j++){ //b
            b[j] = sc.nextInt();
        }
        for(int k = 0; k < n-1; k++){ //c
            c[k] = sc.nextInt();
        }
        for(int m = 0; m < n; m++){ //syori
            
            int index = a[m];
            sum += b[index - 1];
            if(index- inf == 1){
                sum += c[index-2];
            }
            inf = a[m];
        }
        System.out.println(sum);
    }
}

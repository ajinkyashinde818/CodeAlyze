import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        //System.out.println("n:" + n);

        int before = 0;
        int longest = 0;
        int longestIndex = 0;

        int[] a = new int[n];
        for(int i=0; i<n;i++){
            a[i] = sc.nextInt();

            int length = a[i] - before;

            if (length > longest){
                longest = length;
                longestIndex = i;
            }
            before= a[i];
        }

        int first = a[0] + (k-a[n-1]);
        if(first > longest){
            longest = first;
        }
        System.out.println(k-longest);




        //System.out.println("k:" +k + " n:" + n + " a[0]:" + a[0] + " a[n]" + a[n-1]);
    }

}

import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);
        int n = stdIn.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n-1];
        for(int i = 0;i<n;i++) {
            a[i] = stdIn.nextInt();
        }

        for(int i = 0;i<n;i++) {
            b[i] = stdIn.nextInt();
        }

        for(int i = 0;i<n-1;i++) {
            c[i] = stdIn.nextInt();
        }

        int count = 0;

        for(int i = 0;i<b.length;i++) {
            count += b[i];
        }
        //System.out.println(count);

        for(int i = 0;i<b.length-1;i++) {
            if(a[i]!=n && a[i]+1 == a[i+1]) {
                count += c[a[i]-1];
            }
        }
        System.out.println(count);
    }
}

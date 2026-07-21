import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int[] a = new int[n];
        String line = sc.nextLine();
        String[] line1 = line.split(" ");
        for(int i = 0; i < n; i++) a[i] = Integer.parseInt(line1[i]);
        int[] b = new int[n];
        String line2 = sc.nextLine();
        String[] line3 = line2.split(" ");
        for(int i = 0; i < n; i++) b[i] = Integer.parseInt(line3[i]);
        int[] c = new int[n - 1];
        String line4 = sc.nextLine();
        String[] line5 = line4.split(" ");
        for(int i = 0; i < n - 1; i++) c[i] = Integer.parseInt(line5[i]);

        int count = 0;
        for(int i = 0; i < n; i++) count += b[i];
        
        for(int i = 0; i < n - 1; i++){
            if(a[i] + 1 == a[i + 1])    count += c[a[i] - 1];
        }
        System.out.println(count);
    }
}

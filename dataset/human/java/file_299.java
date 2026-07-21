import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long first = 0;
        long last = 0;
        // long sum = 0;
        int[] original = new int[n];
        int[] a = new int[n];

        int count = 0;
        int minusCount = 0;
        //int flagInt = 0;

        int min = 1000000000;
        long sum = 0;
        List<Long> list = new ArrayList<>();
        long eee = 0;
        int[][] zeroRange = new int[n][2];
        boolean zFlag = false;
        for(int i = 0; i < n; i++) {
            int tmp = scanner.nextInt();
            original[i] = tmp;
            if(zFlag) {
                zeroRange[count][0] = i;
                zFlag = false;
            }
            if(tmp == 0) {
                //flagInt = tmp;
                zeroRange[count][1] = i;
                count++;
                list.add(sum);
                sum = 0;
                zFlag = true;
            }
            
            a[i] = Math.abs(tmp);
            sum += Math.abs(tmp);

            eee += Math.abs(tmp);
            min = Math.min(min, Math.abs(tmp));
            if(tmp < 0) minusCount++;
            if(i == 0) {
                first -= a[i];
            } else {
                first += a[i];
            }
            if(i == n-1) {
                last -= a[i];
            } else {
                last += a[i];
            }
        }


        if(count == 0) {
            if(minusCount % 2 == 0) {
                System.out.println(sum);
            } else {
                long aaaa = Math.max(first, last);
                System.out.println(Math.max(aaaa, sum-(min*2)));
            }
        } else {
            System.out.println(eee);
            
        }
        

       

    }
}

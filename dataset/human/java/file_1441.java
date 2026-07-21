import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        String[] a = new String[n];
        String[] b = new String[m];

        for (int i = 0; i < n; i++){
            a[i] = scanner.next();
        }
        for (int i = 0; i < m; i++){
            b[i] = scanner.next();
        }

        int bCounter = 0;
        int shift = -1;
        int rowFound = 0;
        for (int i = 0; i < n; i++){
            if (bCounter == 0){
                shift = a[i].indexOf(b[bCounter]);
                if (shift == -1){
                    continue;
                }
                rowFound++;
            }
            else if (bCounter < m){
                if (a[i].indexOf(b[bCounter]) == -1){
                    scanner.close();
                    System.out.println("No");
                    return;
                } else {
                    rowFound++;
                }
            }
            bCounter++;
        }
        if (rowFound == m){
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        scanner.close();
    }
}

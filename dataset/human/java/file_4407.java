import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        int index;

        Scanner scan = new Scanner(System.in);
        index = Integer.valueOf(scan.next());
        int[] a = new int[index];
        int[] b =new int[index];
        int[] c =new int[index];

        for(int i=0;i<index;i++)
            a[i] = Integer.valueOf(scan.next());
        for(int i=0;i<index;i++)
            b[i] = Integer.valueOf(scan.next());
        for(int i=0;i<index-1;i++)
            c[i] = Integer.valueOf(scan.next());

        int answer= 0;
        for(int i=0;i<index;i++){
            answer += b[a[i] - 1];
            if(i != 0){
                if(a[i] == a[i-1]+ 1)
                    answer += c[a[i-1] - 1];
            }
        }
        System.out.println(answer);

    }
}

import java.util.Scanner;

public class Main {
    static Scanner stdIn = new Scanner(System.in);
    public static void main(String[] args){
        int n = stdIn.nextInt();
        long k = stdIn.nextLong();
        int[] a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = stdIn.nextInt();
        }
        int[] visited = new int[n];
        for(int i=0; i<n; i++){
            visited[i] = -1;
        }

        int townNumber = 1;
        int counter;
        for(counter = 0; counter<k; counter++){
            if(visited[townNumber - 1] != -1){
                long res = (k - counter) % (counter - visited[townNumber - 1]);
                for(int i=0; i<res; i++){
                    townNumber = a[townNumber - 1];
                }
                System.out.println(townNumber);
                return;
            }
            visited[townNumber - 1] = counter;
            townNumber = a[townNumber - 1];
        }

        System.out.println(townNumber);
    }
}

import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] c = sc.next().toCharArray();
        int[] a = new int[26];

        for(char cc : c) {
            a[cc-'a']++;
        }

        long res = 1;
        long div = 1000000007;

        for(int i=0; i<26; i++) {
            res *= a[i] + 1;
            res %= div;
        }
        res += div - 1;
        res %= div;

        System.out.println(res);

    }

}

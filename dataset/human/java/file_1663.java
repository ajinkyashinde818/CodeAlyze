import java.util.Scanner;
public class Main{

    public static void main(String[] args){
        int MOD_NUM = (int)Math.pow(10,9)+7;
        Scanner sc = new Scanner(System.in);

        int[] abc = new int[26];
        for(int i = 0; i < 26; i++)abc[i] = 0;
        int N = sc.nextInt();
        String str = sc.next();

        for(int i = 0; i < N; i++){
            abc[(char)str.charAt(i) - 'a']++;
        }

        long ans = 1;
        for(int i = 0; i < 26; i++){
            ans = (ans  * (abc[i]+1))% MOD_NUM;
        }

        System.out.println((ans - 1));

    }
}

import java.util.Scanner;

public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while(true){
            int N =sc.nextInt();
            if(N==0)break;
            int[] key = new int[N];
            for (int i = 0; i < key.length; i++) {
                key[i]=sc.nextInt();
            }
            StringBuilder sb=new StringBuilder();
            StringBuilder ans=new StringBuilder();
            for (int i = 0; i < 26;i++){
                sb.append((char)('a'+i));
            }
            for (int i = 0; i < 26;i++){
                sb.append((char)('A'+i));
            }
            char[] s = sc.next().toCharArray();
            
            for (int i = 0; i < s.length; i++) {
                int j = i%key.length;
                int c = s[i]-'a';
                if(Character.isUpperCase(s[i])){
                    c = s[i]-'A'+26;
                }
                c = c - key[j];
                c += 52;
                ans.append(sb.charAt(c%52));
            }
            System.out.println(ans);
        }
    }

}

import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        char[] S = s.toCharArray();
        char[] T = t.toCharArray();
        Arrays.sort(S);
        Arrays.sort(T);
        for(int i=0;i<=T.length/2-1;i++){
            char temp = T[i];
            T[i] = T[T.length-1-i];
            T[T.length-1-i] = temp;
        }
        String ans = "No";
        int i=0;
        while(i<Math.min(T.length,S.length)){
            if(S[i]<T[i]){
                ans = "Yes";
                break;
            }
            if(S[i]>T[i]){
                break;
            }
            i++;
        }
        if(i==Math.min(T.length,S.length)&&S.length<T.length) ans = "Yes";
        System.out.println(ans);
    }
}

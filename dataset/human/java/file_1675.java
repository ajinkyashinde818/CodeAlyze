import java.util.*;
 
public class Main {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] chars={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        long output=1;
        long mod=1000000007;
        int n=sc.nextInt();
        String s=sc.next();
        for(int i=0;i<26;i++){
            output*=(long)(s.length()-s.replaceAll(chars[i],"").length()+1);
            output%=mod;
        }
        System.out.println(output==0?mod-1:output-1);
    }
}

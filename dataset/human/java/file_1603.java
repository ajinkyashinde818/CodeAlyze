import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    char[] s = sc.next().toCharArray();
    long sum = 1;
    long cnt = 0;
    long mod = 1000000007;
    for(char c = 'a';c<='z';c++){
      for(int i = 0;i < n;i++)if(s[i]==c)cnt++;
      sum=sum*(cnt+1);
      sum = sum%mod;
      cnt=0;
    }
    System.out.println(sum-1);
  }
}

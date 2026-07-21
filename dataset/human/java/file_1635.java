public class Main {
    public static void main(String[] args) {
        java.util.Scanner s=new java.util.Scanner(System.in);
        s.nextInt();
        long m[]=new long[26],a=1;
        for(char c:s.next().toCharArray())m[c-97]++;
        for(int i=0;i<26;i++)a=a*(m[i]+1)%1000000007;
        System.out.println(--a);
    }
}

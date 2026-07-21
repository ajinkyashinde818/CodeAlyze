import javax.swing.plaf.basic.BasicInternalFrameTitlePane;
import  java.io.*;
import  java.math.*;
import java.nio.Buffer;
import java.sql.SQLSyntaxErrorException;
import  java.util.*;
import  java.text.*;
import java.util.regex.Pattern;
import java.util.stream.Collectors;


public class Main {


    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        long k=cin.nextLong();
        int n=cin.nextInt();
        long num[]=new long[n+1];
        long num1[]=new long[n+1];
        num[1]=cin.nextLong();
        for(int i=2;i<=n;i++){
            num[i]=cin.nextLong();
            num1[i-1]=num[i]-num[i-1];
        }

        long sum=0;
        num1[n]=k+num[1]-num[n];
        long ans=0;
        for(int i=1;i<=n;i++){
            ans=Math.max(ans,num1[i]);
            sum+=num1[i];
        }
        sum=sum-ans;
        System.out.println(sum);
    }
}

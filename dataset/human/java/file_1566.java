import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

//   String nyuA=sc.nextLine();
  // String nyuB=sc.nextLine();
 
     String[] S=sc.nextLine().split(" ");

//int n=Integer.parseInt(nyu);

int N=Integer.parseInt(S[0]);
int M=Integer.parseInt(S[1]);

String[][] A=new String[N][N];
String[][] B=new String[M][M];

for(int i=0;i<N;i++){
A[i]=sc.nextLine().split("");
}
for(int i=0;i<M;i++){
B[i]=sc.nextLine().split("");
}
int count=0;

int flag=0;
for(int i=0;i<(N-M)+1;i++){
re:

for(int j=0;j<(N-M)+1;j++){

for(int k=0;k<M;k++){
for(int l=0;l<M;l++){
if(!A[i+k][j+l].equals(B[k][l]) ){
//System.out.println(i+"-"+j+"-"+k+"-"+l);
continue re;
}else{
//System.out.println(i+"-"+j+"-"+k+"-"+l+"-"+A[i+k][j+l]+"--"+B[k][l]);

}

}}
flag=1;
//System.out.println("sor");
}}

//long H=Long.parseLong(t[0]);
//long W=Long.parseLong(t[1]);
//long C=Long.parseLong(t[2]);


if(flag==0)
System.out.println("No");
else
System.out.println("Yes");


	}
}

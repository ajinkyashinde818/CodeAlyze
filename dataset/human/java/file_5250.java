import java.util.Scanner;
import java.util.ArrayList;
import java.awt.Point;
import java.lang.Math;

public class Main{

public static int tansaku(int[][]house,int n){
	int ret=0;
	int maxr=0;
	for(int j=0;j<n;j++)
	for(int i=0;i<n;i++){
		if(house[i][j]=='.' && i<n-maxr && j<n-maxr){
		int r=Math.min(n-i-1,n-j-1);
		int rd=0,sd=0;int ix=0,iy=0;
			for(rd=1;rd<=r;rd++){
			int flag=0;
				for(sd=0;sd<=rd;sd++){
					if(house[i+sd][j+rd]!='.'){ix=i+sd;iy=j+rd;flag=1;break;}
					if(house[i+rd][j+sd]!='.'){ix=i+rd;iy=j+sd;flag=1;break;}
				}
				if(flag==1){
				for(int z=i;z<=ix;z++){if(house[z][j]=='.')house[z][j]='C';}
				for(int w=j;w<=iy;w++){if(house[ix][w]=='.')house[ix][w]='C';}

				break;
				}
				if(flag==0){if(maxr<rd+1)maxr=rd+1;}
				//System.out.printf("i=%d j=%d maxr=%d\n",i,j,maxr);
			}
		}
			
		}
	
	return maxr;
}


public static void main(String []ag){
Scanner sc=new Scanner(System.in);
int n=0;
do{
	n=sc.nextInt();
	int [][]house=new int[n][n];
	for(int j=0;j<n;j++){
			String str=sc.next();for(int i=0;i<n;i++){house[i][j]=str.charAt(i);}
	}
	int ret=tansaku(house,n);
	if(n!=0)System.out.printf("%d\n",ret);
}while(n!=0);

}

}

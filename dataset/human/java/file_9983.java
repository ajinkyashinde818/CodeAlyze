import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int m=sc.nextInt();
    int x=sc.nextInt();
    int[] c=new int[n]; 
    int[][] a=new int [n][m]; 
    for(int i=0;i<n;i++){
      c[i]=sc.nextInt();
      for(int j=0;j<m;j++){
        a[i][j]=sc.nextInt();
      }
    }
    int[] aExp=new int[m];
    int cSum=0;
    List<Integer> cList=new ArrayList<>();
    boolean masterd=true;
    sc.close();
    
    for(int i=0;i< 1<<n;i++){
      for(int j=0;j<n;j++){
        if((1&i>>j)==1){
          for(int k=0;k<m;k++){
            aExp[k]+=a[j][k];
          }
          cSum+=c[j];
        }
      }
      for(int k=0;k<m;k++){
        if(aExp[k]<x){
          masterd=false;
          break;
        }
      }
      if(masterd) cList.add(cSum);
      for(int k=0;k<m;k++) aExp[k]=0;
      cSum=0;
      masterd=true;
    }
    int cMin=Integer.MAX_VALUE;
    if(cList.isEmpty()){
      cMin=-1;
    }
    else{
      for(int z:cList){
        if(cMin>z) cMin=z;
      }
    }
    System.out.println(cMin);
  }
}

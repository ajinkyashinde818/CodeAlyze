import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        char[] s=sc.next().toCharArray();
        int x=sc.nextInt(), y=sc.nextInt();
        sc.close();
        int n=s.length;
        ArrayList<Integer> xl=new ArrayList<>();
        ArrayList<Integer> yl=new ArrayList<>();
        boolean b=true;
        boolean xb=false;
        int count=0;
        int xc=0, yc=0;
        for(int i=0;i<n;i++){
            if(b){
                if(s[i]=='F'){
                    x--;
                } else{
                    b=false;
                }
            } else{
                if(s[i]=='F'){
                    count++;
                } else{
                    if(xb){
                        if(count>0){
                            xl.add(count);
                            xc+=count;
                        }
                    } else{
                        if(count>0){
                            yl.add(count);
                            yc+=count;
                        }
                    }
                    xb=!xb;
                    count=0;
                }
            }
        }
        if(count>0){
            if(xb){
                xl.add(count);
                xc+=count;
            } else{
                yl.add(count);
                yc+=count;
            }
        }
        if((xc-x)%2!=0 || (yc-y)%2!=0 || xc<x || yc<y){
            System.out.println("No");
            return;
        }
        xc=(xc-x)/2;
        yc=(yc-y)/2;
        // System.out.println("xc:"+xc+", yc:"+yc);
        int xn=xl.size(), yn=yl.size();
        boolean okx=false, oky=false;
        if(xn!=0){
            boolean[][] dpx=new boolean[xn][8001];
            for(int i=0;i<xn;i++){
                for(int j=0;j<=8000;j++){
                    if(j==0||j==xl.get(i)){
                        dpx[i][j]=true;
                    }
                    if(i>0 && dpx[i-1][j]){
                        dpx[i][j+xl.get(i)]=true;
                        dpx[i][j]=true;
                    }
                }
            }
            okx=dpx[xn-1][xc];
            // System.out.println("xl");
            // for(int i:xl){
            //     System.out.println(i);
            // }
        } else{
            okx=xc==0;
        }
        if(yn!=0){
            boolean[][] dpy=new boolean[yn][8001];
            for(int i=0;i<yn;i++){
                for(int j=0;j<=8000;j++){
                    if(j==0||j==yl.get(i)){
                        dpy[i][j]=true;
                    }
                    if(i>0 && dpy[i-1][j]){
                        dpy[i][j+yl.get(i)]=true;
                        dpy[i][j]=true;
                    }
                }
            }
            oky=dpy[yn-1][yc];
            // System.out.println("yl");
            // for(int i:yl){
            //     System.out.println(i);
            // }
        } else{
            oky=yc==0;
        }
        if(okx&&oky){
            System.out.println("Yes");
        } else{
            System.out.println("No");
        }
    }
}

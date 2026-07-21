import java.io.*;
import java.util.*;

//height 違う
public class Main{
    static int count =0;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
     
        //Prepare
        str = br.readLine();
        int n = Integer.parseInt(str);

        Nodes[] nodes = new Nodes[n];
        for(int i=0;i<n;i++){
            str = br.readLine();
            String[] tmpA = str.split("\\s");
            for(int j=0;j<n;j++){
                if(j == Integer.parseInt(tmpA[0])){
                    nodes[j] = new Nodes(Integer.parseInt(tmpA[0]),Integer.parseInt(tmpA[1]),Integer.parseInt(tmpA[2]));
                }
            }
        }

        //Looking for P 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j){
                    if(nodes[i].DL == nodes[j].N || nodes[i].DR == nodes[j].N){
                        nodes[j].P = i;
                    }
                }
            }

        }
        //Type & degree & height & depth
        int PN =0;
        for(int i=0;i<n;i++){
            if(nodes[i].P == -1){
                nodes[i].Type = "root";
                PN =i;
            }else if(nodes[i].DL ==-1 && nodes[i].DR == -1){
                nodes[i].Type = "leaf";
            }else{
                nodes[i].Type = "internal node";
            }

            int cou = 0;
            if(nodes[i].DL != -1){
                cou++;
            }
            if(nodes[i].DR !=-1){
                cou++;
            }
            nodes[i].Deg = cou;


            nodes[i].H = getHeight(nodes,nodes[i].DL,nodes[i].DR,0);
            nodes[i].Dep = getDep(nodes,i,0);

            for(int j=0;j<n;j++){
                if(i != j){
                    if(nodes[i].P == nodes[j].P){
                        nodes[i].S = nodes[j].N;
                        nodes[j].S = nodes[i].N;
                    }
                }
            }
        }
        

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++){
            sb.append("node ");
            sb.append(nodes[i].N);
            sb.append(": parent = ");
            sb.append(nodes[i].P);
            sb.append(", sibling = ");
            sb.append(nodes[i].S);
            sb.append(", degree = ");
            sb.append(nodes[i].Deg);
            sb.append(", depth = ");
            sb.append(nodes[i].Dep);
            sb.append(", height = ");
            sb.append(nodes[i].H);
            sb.append(", ");
            sb.append(nodes[i].Type);
            sb.append("\n");
        }
        System.out.print(sb.toString());

    }

    //leaf まで潜っていく。左と右それぞれに進む。　進んだ数＝height　で右と左の大きい方が答え
    public static int getHeight(Nodes[] nodes,int DL,int DR,int Height){
        int HL = 0;
        int HR = 0;

        if(DL ==-1 && DR ==-1){
            
            return Height;

        }else{
            
            if(DL != -1){
            HL = Height + 1;
            HL = getHeight(nodes,nodes[DL].DL,nodes[DL].DR,HL);
            }

            if(DR != -1){
                HR = Height + 1;
                HR = getHeight(nodes,nodes[DR].DL,nodes[DR].DR,HR);
            }
            
            return Math.max(HL,HR);
        }
    }

    public static int getDep(Nodes[] nodes,int i,int d){
        if(nodes[i].P != -1){
            d++;
            return getDep(nodes,nodes[i].P,d);
        }else{
            return d;
        }
    }

}

class Nodes{
    int N;//Node
    int P;//親ノード
    int S;//sibling
    int DL;//left child
    int DR;//右の子
    int Deg;
    int Dep;//depth
    int H;//height
    String Type;
    
    Nodes(int a,int b,int c){
        this.N =a;
        this.DL = b;
        this.DR = c;
        this.P =-1;
        this.S = -1;
        this.Deg = -1;
        this.Dep = 0;
        this.Type = "leaf";
    }
}

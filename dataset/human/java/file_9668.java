import java.util.*;
import java.io.*;

public class Main{
    static class Node{
        int nodeNumber;
        Node parent;
        Node opposite;
        Node leftChild;
        int depth;
        int height;
        ArrayList<Node> childList=new ArrayList<Node>();

        int getDepth(){
            int depth=0;
            Node that=this.parent;
            while(that!=null){
                depth++;
                that=that.parent;
            }
            this.depth=depth;
            return depth;
        }
        
        int h1=0;
        int h2=0;
        int getHeight(){
            if(childList.size()==0){return 0;}
            Node leftChild;
            Node rightChild;

            if(childList.size()>=1){
                leftChild=childList.get(0);
                h1=leftChild.getHeight()+1;
            }
            if(childList.size()==2){
                rightChild=childList.get(1);
                h2=rightChild.getHeight()+1;
            }
            height=Math.max(h1,h2);
            return height;

        }

    }
    public static void main (String args[]){

        //初期処理
        // Scanner sc=new Scanner(System.in);
        // int n=Integer.parseInt(sc.nextLine());
        // String[] sElementArray=sc.nextLine().split(" ");
        // int[] array=Arrays.stream(sElementArray).mapToInt(Integer::parseInt).toArray();
        // sc.close();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       try{
            int n= Integer.parseInt(br.readLine());

            //Node管理用の配列
            Node[] allNode=new Node[n];
            for(int s=0;s<n;s++){
                allNode[s]=new Node();
            }

            for(int i=0;i<n;i++){
                String[] sElementArray = br.readLine().split(" ");
                int[] array = Arrays.stream(sElementArray).mapToInt(Integer::parseInt).toArray();

                //番号設定
                allNode[array[0]].nodeNumber=array[0];
                
                //そのほか4つのプロパティを設定
                //array=[0,1,4]の子ノードをとる。
                if(array[1]!=-1){
                    allNode[array[1]].parent=allNode[array[0]];   //子の親を自分に設定 
                    allNode[array[0]].childList.add(allNode[array[1]]);
                }
                if(array[2]!=-1){
                    allNode[array[2]].parent=allNode[array[0]];   //子の親を自分に設定 
                    allNode[array[0]].childList.add(allNode[array[2]]);
                }
                         //   allNode[array[0]].leftChild=allNode[1];  //左の子を最初の子要素に設定
                if(array[1]!=-1&&array[2]!=-1){
                            allNode[array[1]].opposite=allNode[array[2]];  //sibling
                            allNode[array[2]].opposite=allNode[array[1]];  //sibling
                }
                            
                            
                        }
                for (int i=0;i<n;i++){

                    //depth
                    allNode[i].getDepth();
                        //height
                        //root treeのdepthはparentしか使ってないからたまたま上のfor文で使えただけで、heightは全プロパティがそろってからじゃないと求まらない
                        //実際今回もここに入れないとダメ
                        allNode[i].getHeight();
                }

            StringBuffer sb=new StringBuffer();
            for(int i=0;i<n;i++){
                Node node=allNode[i];
                //node number
                sb.append("node "+node.nodeNumber+": ");

                //親
                sb.append("parent = ");
                if(node.parent!=null){
                    sb.append(node.parent.nodeNumber);
                }else {
                    sb.append("-1");
                }
                sb.append(", ");

                //sibling
                sb.append("sibling = "+(node.opposite!=null?node.opposite.nodeNumber:-1)+", ");

                //degree
                sb.append("degree = "+node.childList.size()+", ");

                //深さ
                sb.append("depth = "+node.depth+", ");

                //高さ
                sb.append("height = "+node.height+", ");

                //Nodeの種類
                if(node.parent==null){
                    sb.append("root");
                }else if(node.childList.size()==0){
                    sb.append("leaf");
                }else {
                    sb.append("internal node");
                }
                sb.append("\n");
                //子
                // sb.append(" [");
                //     node.childList.forEach(x->sb.append(x.nodeNumber+", "));;
                //     if(node.childList.size()!=0){
                //         sb.setLength(sb.length()-2);
                //     }

                // sb.append("]\n");

            }
            System.out.print(sb);
        }catch(IOException e){e.printStackTrace();}
        }
    }

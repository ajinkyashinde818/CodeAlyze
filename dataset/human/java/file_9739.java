import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

class Main {

	static long changecount = 0;
   public static void main(String args[]) throws IOException{

	   Scanner sc = new Scanner(System.in);
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   int n = Integer.parseInt( br.readLine()  );


       Tree tree = new Tree(n);


	   for(int i = 0;i < n; i++){
		   String[] string = br.readLine().split(" ");
		   tree.Nodes[ Integer.parseInt(string[0]) ].input_nood_number( Integer.parseInt(string[0]) );
           tree.Nodes[ Integer.parseInt(string[0]) ].input_root_number(string , tree );
	   }


        tree.printtree();

	   //System.out.println("");
	   sc.close();
   }


}



class Node{

	int nood_number = 0;




    Node parent = null;
    Node right = null;
    Node left = null;



    void input_nood_number(int date){
    	nood_number = date;
    }


    void input_root_number(String[] string, Tree tree ){



       if( Integer.parseInt(string[1]) !=-1 ){
    	  right = tree.Nodes[ Integer.parseInt(string[1]) ];

          tree.Nodes[ Integer.parseInt(string[1]) ].parent = this;

        }

       if( Integer.parseInt(string[2]) !=-1 ){
     	  left = tree.Nodes[ Integer.parseInt(string[2]) ];

           tree.Nodes[ Integer.parseInt(string[2]) ].parent = this;

         }


    }


     int child_num(){

    	 if( right == null && left == null){
    		 return 0;
    	 }
    	 else if(right != null && left != null){
    		 return 2;
    	 }
    	 else{
    		 return 1;
    	 }


     }

     int node_depth(Node[] nodes , int number){
	     int depth = 0;


         for(Node tmp = this; tmp.parent != null; depth++){
        	 //System.out.println(nodes[number].parent.nood_number);
        	 tmp = tmp.parent;

         }

	     return depth;
    }

     int height_node(Node node , Node[] nodes)
     {
       if (node == null) return 0;
       if(node.left == null&& node.right == null) return 0;

       int a = height_node( node.left, nodes);
       int b = height_node( node.right, nodes);
       return 1+(a > b ? a : b);
     }


     int parent_node( )
     {
       if (parent == null) {return -1;}
       else{
    	   return parent.nood_number;
       }
     }

     String node_type(){

    	 if(parent == null ){

    		 return "root";

    	 }else if( parent != null && (right != null || left != null )    ){

    		 return "internal node";

    	 }else{

    		 return "leaf";
    	 }



     }

}

//Integer.parseInt(string[2+i])

class Tree{

	Node[] Nodes = null;
    int allnode_num = 0 ;

    Tree(int n){
    	allnode_num = n;
    	Nodes = new Node[n];
    	for(int i = 0; i < n ; i++){
    		Nodes[i] = new Node();
    	}

    }

    int brother_find(Node node , int n ){
    	int brother_number = -1;


        if(node.parent != null){

        	if( node.parent.left == node && node.parent.right != null){
        		return node.parent.right.nood_number;

        	}else if(node.parent.right == node && node.parent.left != null ){
        		//System.out.println("check");
        		return node.parent.left.nood_number;
        	}


        }



        return brother_number;
    }



   void printtree(){

	   for(int i = 0; i < allnode_num ; i++){
		   //System.out.print("nood_number="+Nodes[i].nood_number+" root_sum="+Nodes[i].root_sum+" parent_number="+Nodes[i].parent_number);
		   //System.out.println(Nodes[i].node_depth(Nodes, i));
		  // System.out.println("node "+i+": parent = "+Nodes[i].parent_number+", depth = "+ Nodes[i].node_depth(Nodes, i)+", " +Nodes[i].node_type() +", ["+Nodes[i].print_root()+"]" );
		    //System.out.println("node "+i+": parent = "+Nodes[i].parent_node() +", sibling = "+ brother_find(Nodes[i], allnode_num) );
		   System.out.println("node "+i+ ": parent = "+Nodes[i].parent_node() +", sibling = "+ brother_find(Nodes[i], allnode_num) + ", degree = "+Nodes[i].child_num() + ", depth = "+Nodes[i].node_depth(Nodes, i)+", height = "+Nodes[i].height_node(Nodes[i], Nodes) + ", "+ Nodes[i].node_type() );
          //
   	   }

   }







}

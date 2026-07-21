import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

class Main{


	public static void main(String[] args)throws NumberFormatException, IOException{
		InputStreamReader input = new InputStreamReader (System. in);
		BufferedReader buffer = new BufferedReader(input);
		String scan = buffer.readLine();
		long processStart = System.currentTimeMillis();
		Deque<Integer> stack = new ArrayDeque<Integer>();

		int nodeAmount  = Integer.parseInt(scan);
		int[] nodeID  = new int[nodeAmount];
		int[] nodeL  = new int[nodeAmount];
		int[] nodeR = new int[nodeAmount];
		int[] nodeLeft  = new int[nodeAmount];
		int[] nodeRight = new int[nodeAmount];
		int[] parent  = new int[nodeAmount];
		int[] sibling  = new int[nodeAmount];
		int[] degree  = new int[nodeAmount];
		int[] depth  = new int[nodeAmount];
		int[] height  = new int[nodeAmount];
		String[] rank = new String[nodeAmount];
		for(int i=0; i<nodeAmount; i++){
			scan = buffer.readLine();
			String[] str = scan.split(" ");
			nodeID[i] = Integer.parseInt(str[0]);
			nodeL[i] = Integer.parseInt(str[1]);
			nodeR[i] = Integer.parseInt(str[2]);
			parent[i] = -1;
			sibling[i] = -1;
		}
		
		for(int i=0; i<nodeAmount; i++){
			nodeLeft[nodeID[i]]  = nodeL[i];
			nodeRight[nodeID[i]] = nodeR[i];
//			System.out.println("node "+i+" L "+(nodeLeft[nodeID[i]])+" R "+(nodeRight[nodeID[i]]));
		}


		int isRoot = 0;
		for(int i=0; i<nodeAmount; i++){		//parent??¨degree??????????????????
			int deg = 0;
			if(nodeLeft[i] > -1){
				parent[nodeLeft[i]]   = i;
				deg += 1;
			}
			if(nodeRight[i] > -1){
				parent[nodeRight[i]]  = i;
				deg += 1;
			}

			degree[i] = deg;
		}
		for(int i=0; i<nodeAmount; i++){		//parent????????±??????sibling??????????????????????????§???parent == -1??§??????Root????????????????????????
			for(int J=0; J<nodeAmount; J++){
				if(parent[i] == parent[J] && i!=J){
					sibling[J] = i;
				}
			}

			if(parent[i] == -1){
				isRoot = i;
			}
		}

		stack.add(isRoot);
		while(!stack.isEmpty()){		//Root???????????????depth??????????????????
			
			int check = stack.pollLast();
			if(nodeLeft[check] > -1){
				depth[nodeLeft[check]] = depth[check]+1;
				stack.add(nodeLeft[check]);
			}
			if(nodeRight[check] > -1){
				depth[nodeRight[check]] = depth[check]+1;
				stack.add(nodeRight[check]);
			}
		}


		stack.clear();
		for(int i=0; i<nodeAmount; i++){		//depth????????±??????height????±??????????
			if(degree[i] == 0){
				height[i] = 0;
			}
			else{
				int maxDepth = 0;
				
				if(nodeLeft[i] != -1){
					stack.add(nodeLeft[i]);
				}
				if(nodeRight[i] != -1){
					stack.add(nodeRight[i]);
				}
				while(!stack.isEmpty()){
					
					int check = stack.pollLast();
//					System.out.println(check+" "+nodeLeft[check]+" L node R "+nodeLeft[check]);
					if(nodeLeft[check] != -1){
						stack.add(nodeLeft[check]);
					}
					if(nodeRight[check] != -1){
						stack.add(nodeRight[check]);
					}
					if(depth[check] > maxDepth){
						maxDepth = depth[check];
					}
				}
				height[i] = maxDepth - depth[i];
			}
		}

		for(int i=0; i<nodeAmount; i++){
			if (depth[i] == 0){
				rank[i] = "root";
			}
			else if(height[i] == 0){
				rank[i] = "leaf";
			}
			else{
				rank[i] = "internal node";
			}
		}
		for(int i=0; i<nodeAmount; i++){
			System.out.println("node "+i+": parent = "+parent[i]+", sibling = "+sibling[i]+", degree = "+degree[i]+", depth = "+depth[i]+", height = "+height[i]+", "+rank[i]);
		}

		long processEnd = System.currentTimeMillis();
//		System.out.println("???????????????" + (processEnd - processStart)  + "ms");
	}
}

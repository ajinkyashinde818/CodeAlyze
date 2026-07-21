#include <stdio.h>
int main(void)
{
	int h,w;
	int i,j,count=0;
    
	scanf("%d %d",&h,&w);
    
	while((h!=0)&&(w!=0)){ //データ入力が０　０だったら終了
        
		for(i=1; i<=h; i++){
            
			while(count < w){
                
                if(i%2 == 1){
                    printf("#"); count++;
                    if (count < w) {
                        printf("."); count++;
                    }
                }
                
                if(i%2 == 0){
                    printf("."); count++;
                    if (count < w){
                        printf("#"); count++;
                    }
                }
            }
            count = 0;
            printf("\n");
            
		}
		
		printf("\n");
        
		scanf("%d %d",&h,&w); //次のデータを読み込む。
	}
    
	return 0;
    
    
}

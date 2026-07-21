#include <stdio.h>

int main(void)
{
	for(;;){
		int h,w,hn,wn;
		scanf("%d%d",&h,&w);
		if(h==0&&w==0){
			break;
		}
		for(hn=1;hn<=h;hn++){
			if(hn%2==1){				//ツ行ツ青板つェツ甘ッツ青板づ個づつォ
				for(wn=1;wn<=w;wn++){
					if(wn%2==1){		//ツ療アツ青板つェツ甘ッツ青板づ個づつォ
						printf("#");
					}else{				//ツ療アツ青板つェツ凝エツ青板づ個づつォ
						printf(".");
					}
					if(wn==w){
						printf("\n");
						if(hn==h){
							printf("\n");
						}
					}
				}
			}else{						//ツ行ツ青板つェツ凝エツ青板づ個づつォ
				for(wn=1;wn<=w;wn++){
					if(wn%2==1){		//ツ療アツ青板つェツ甘ッツ青板づ個づつォ
						printf(".");
					}else{				//ツ療アツ青板つェツ凝エツ青板づ個づつォ
						printf("#");
					}
					if(wn==w){
						printf("\n");
						if(hn==h){
							printf("\n");
						}
					}
				}
			}
		}
	}
	return 0;
}

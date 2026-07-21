#include<stdio.h>

int main(){
	int perimetro,n,a[212345],l,max;
	scanf("%d%d",&perimetro,&n);

	for (int i = 0; i < n; i++)
		scanf("%d",&a[i]);

	max = perimetro - a[n - 1] + a[0]; //respeitando o movimento anti-horario.
  for (int i = 1; i < n; i++){ //o for segue um raciocinio: você vai contar a distancia entre todos os segmentos,
															 // só que o for nao conta a diferença entre o ultimo e o primeiro segmento.
    l = a[i] - a[i - 1];			 //já que o perimetro é circular, vc tbm tem a distancia entre a primeira e a ultima casa que nao
		if (l > max)							 //foi contada no for, pra isso serve a variavel max.
			max = l;
	}
  printf("%d\n",perimetro - max);
  return 0;
}

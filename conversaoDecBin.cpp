//Louvado seja o Senhor

#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declaração de variáveis
	int numDec = 0, opt, saveDec;
	int bitMax = 128;
	float numBin = 0, saveBin, multBin = 10000000;
	float sum = 0;
	
	//Laço de repetição para escolha de opções
	do{
		printf("O que deseja fazer?\n1 - Conversao Decimal -> Binario\n2 - Conversao Binario -> Decimal\n0 - Sair\nOpcao: ");
		scanf("%d", &opt);
		
		multBin = 10000000;
		bitMax = 128;
		sum = 0;
		numDec = 0;
		numBin = 0;
		
		switch(opt){
			case 1: //Conversão Decimal -> Binário
				printf("\nInsira um numero decimal menor que %d: ", bitMax*2);
				scanf("%d", &numDec); //Entrada de dados
				saveDec = numDec; //saveDec guarda o valor original digitado pelo usuário
				
				for(int i = 0; i < 7; i++){
					//printf("\nSum: %.0f, numDec: %d, multBin: %.0f, bitMax: %d\n", sum, numDec, multBin, bitMax);
					
					/*Se o número decimal (numDec) for maior ou igual ao valor binário máximo (bitMax), que neste caso é 128, a variável 'sum' receberá o valor do multiplicador binário (multBin), 
					que é a representação de 128 na base 2, e o numDec será subtraído pelo bitMax para que a próxima análise possa ser realizada.
					Após isso, sendo o número decimal maior ou igual, ou não que o bitMax, o multBin será dividido por 10, para que agora represente o valor binário da próxima casa decimal, e, para mesmo
					fim, o bitMax será dividido por 2, para que agora represente a próxima casa decimal.*/
					if(numDec >= bitMax){
						sum += multBin;
						numDec = numDec-bitMax;
					}
							
					multBin = multBin/10;
					bitMax = bitMax/2;
					
					//printf("\nSum: %.0f, numDec: %d, multBin: %.0f, bitMax: %d\n", sum, numDec, multBin, bitMax);
				}
				//Após o fim de toda a verificação, caso o numDec seja 1, sum receberá 1, para que o valor final seja ímpar, e, caso seja 0, o valor de sum se manterá o mesmo.
				sum += numDec%2;
				
				printf("\nDecimal: %d\nBinario: %.0f\n\n", saveDec, sum);
			break;
			
			case 2: //Conversão Binário -> Decimal
				printf("\nInsira um numero binario menor que 100000000 (256 na base 10): ");
				scanf("%f", &numBin); //Entrada de dados
				saveBin = numBin; //saveBin guarda o valor original digitado pelo usuário
				
				for(int i = 8; i > 0; i--){
					/*Se o número binário (numBin) for maior ou igual ao valor máximo binário (multBin), numBin será subtraído por multBin para a próxima verificação, e a variável sum será somada ao 
					valor binário daquele espaço, sendo representado pela variável bitMax.
					Após isso, sendo numBin maior ou igual, ou não a multBin, este será dividido por 10, para que represente o próximo valor binário, e o mesmo se aplica ao bitMax, que é dividido
					por 2 para representar ao próximo valor decimal.*/
					if(numBin >= multBin){
						numBin = numBin - multBin;
						sum += bitMax;
					}
					multBin = multBin/10;
					bitMax = bitMax/2;
				}
				
				printf("\nBinario: %.0f\nDecimal: %.0f\n\n", saveBin, sum);
			break;
			
			case 0:
				printf("\nAte logo!");
			break;
			
			default:
				printf("\nPor favor, insira uma opcao valida\n\n");
			break;
		}
	}while(opt != 0);
}

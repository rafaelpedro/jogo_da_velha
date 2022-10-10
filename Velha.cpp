#include <stdio.h>
#include <stdlib.h>

void imprimejogo(char jogo[3][3]){
	int l, c;
	
	printf("\n\n\t 0   1   2\n\n");
			for(l = 0; l < 3; l++){
				for(c = 0; c < 3; c++){
					if(c == 0)
						printf("\t");
					printf(" %c ", jogo[l][c]);
					if(c < 2)
						printf("|");
					if(c == 2)
						printf("   %d", l);
				}
				if(l < 2)
					printf("\n\t------------");
					printf("\n");
			}
}

int jogarnovamente(){
	int opcao;
	printf("\nDigite 1 para jogar novamente: \n");
			scanf("%d", &opcao);
return opcao; 
}

int main(){
	
	// estrutura de dados
	int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;
	char jogo[3][3];
	
	do{
		jogador = 1;
		ganhou = 0;
		jogadas = 0;
		// como inicializar nossa estrutura de dados?
		for(l = 0; l < 3; l++){
			for(c = 0; c < 3; c++){
				jogo[l][c] = ' ';
			}
		}
			do{
			// imprimir jogo
			
			imprimejogo(jogo);
			
			// ler coordenadas
			do{
				printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar: ", jogador);
				scanf("%d%d", &linha, &coluna);
		    }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');
			
			// salvar as coordenadas
			if(jogador == 1) {
				jogo[linha][coluna] = '0';
				jogador++;
		    }
		    else{
		    	jogo[linha][coluna] = 'X';
		    	jogador = 1;
			}
			jogadas++;
			
			// alguem ganhou por linha?
			
			if(jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||
			   jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0' ||
			   jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0'){
			   	imprimejogo(jogo);
			    printf("\nParabens! O Jogador 1 venceu por linha!\n");	
			  	ganhou = 1;
				opcao = jogarnovamente(); 
			   }
			if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
			   jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
			   jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
			   	imprimejogo(jogo);
			    printf("\nParabens! O Jogador 2 venceu por linha!\n");
				ganhou = 1;	
				opcao = jogarnovamente();
			   }
			
			// alguem ganhou por coluna?
			if(jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||
			   jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||
			   jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0'){
			   	imprimejogo(jogo);
			    printf("\nParabens! O Jogador 1 venceu por coluna!\n");
				ganhou = 1;	
				opcao = jogarnovamente();
			   }
			if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
			   jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
			   jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
				imprimejogo(jogo);	
			    printf("\nParabens! O Jogador 2 venceu por coluna!\n");
				ganhou = 1;
				opcao = jogarnovamente();
			   }
			// alguem ganhou por diagonal direita?
			if(jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0'){
				imprimejogo(jogo);
			    printf("\nParabens! O Jogador 1 venceu pela diagonal!\n");
				ganhou = 1;
				opcao = jogarnovamente();
			   }
			if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
				imprimejogo(jogo);
			    printf("\nParabens! O Jogador 2 venceu pela diagonal!\n");
				ganhou = 1;
				opcao = jogarnovamente();	
			   }	
			// alguem ganhou por diagonal esquerda?
			if(jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0'){
				imprimejogo(jogo);
			    printf("\nParabens! O Jogador 1 venceu pela diagonal!\n");
				ganhou = 1;
				opcao = jogarnovamente();	
			   }
			if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
				imprimejogo(jogo);	
			    printf("\nParabens! O Jogador 2 venceu pela diagonal!\n");
				ganhou = 1;
				opcao = jogarnovamente();
			   }
			   
			   
			}while(ganhou == 0 && jogadas < 9);
			
			
			
			if(ganhou == 0){
		
				imprimejogo(jogo);
				printf("\nDeu velha\n");
				
		opcao = jogarnovamente();
		}
	}while(opcao == 1);
	return 0;
}

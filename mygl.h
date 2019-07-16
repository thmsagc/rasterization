#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include "math.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

/**
* Função PutPixel:
* Como um pixel ocupa quatro posições do vetor FBptr,
* a posição de um pixel é dada por 4*x + 4*y. 
* Para a "quebra de linha" no eixo y, multiplica-se
* a respectiva coordenada pelo número de pixels na janela.
**/
void PutPixel(int coordx, int coordy, float r, float g, float b, float a){
	FBptr[coordx*4 + coordy*4*IMAGE_WIDTH + 0] = r;
	FBptr[coordx*4 + coordy*4*IMAGE_WIDTH + 1] = g;
	FBptr[coordx*4 + coordy*4*IMAGE_WIDTH + 2] = b;
	FBptr[coordx*4 + coordy*4*IMAGE_WIDTH + 3] = a;
} 


int DrawLine(int xi, int yi, int xf, int yf){
	int dx = xf - xi;
	int dy = yf - yi;

	if(dx > 0 && dy > 0){ 		//primeiro quadrante
		if(abs(dx) > abs(dy)){  //primeiro octante
		  int D = 0;
		  int y = yi;
		    for(int x = xi; x < xf; x++){	
				PutPixel(x, y, 255, 0, 0, 255);
				if(2*(D + dy) > dx){
				   y++;
				   D = D + dy-dx;
				}
				else D = D + dy;
		    }
		}
		else {					//segundo octante
		  int D = 0;
		  int x = xi;
		    for(int y = yi; y < yf; y++){
				PutPixel(x, y, 255, 0, 0, 255);
				if(2*(D + dx) > dy){
				   x++;
				   D = D + dx-dy;
				}
				else D = D + dx;
		    }
		}
	}
	if(dx < 0 && dy > 0){ 		//segundo quadrante
		if(abs(dx) > abs(dy)){	//quarto octante
		  int D = 0;
		  int y = yi;
		    for(int x = xi; x > xf; x--){
				PutPixel(x, y, 255, 0, 0, 255);
				if(2*(D + dy) > dx){
				   y++;
				   D = D + dy-abs(dx);
				}
				else D = D + dy;
		    }
		}
		else {					//terceiro octante
		  int D = 0;
		  int x = xi;
		    for(int y = yi; y < yf; y++){
				PutPixel(x, y, 255, 0, 0, 255);
				if(2*(D + abs(dx)) > dy){
				   x--;
				   D = D + abs(dx)-dy;
				}
				else D = D + abs(dx);
		    }
		}
	}
	if(dx < 0 && dy < 0){ 		//terceiro quadrante
		if(abs(dx) > abs(dy)){  //quinto octante
		  int D = 0;
		  int y = yi;
		    for(int x = xi; x > xf; x--){
				PutPixel(x, y, 255, 0, 0, 255);
				if(2*(D + dy) < dx){
				   y--;
				   D = D + dy-dx;
				}
				else D = D + dy;
		    }
		}
		else {					//sexto octante
		  int D = 0;
		  int x = xi;
		    for(int y = yi; y > yf; y--){
				PutPixel(x, y, 255, 0, 0, 255);
				if(2*(D + dx) < dy){
				   x--;
				   D = D + dx-dy;
				}
				else D = D + dx;
		    }
		}
	}
	if(dx > 0 && dy < 0){ 		//quarto quadrante
		if(abs(dx) > abs(dy)){	//oitavo octante
		  int D = 0;
		  int y = yi;
		    for(int x = xi; x < xf; x++){
				PutPixel(x, y, 255, 0, 0, 255);
				if(2*(D + dy) > dx){
				   y--;
				   D = D + dy-dx;
				}
				else D = D + abs(dy);
		    }
		}
		else {					//setimo octante
		  int D = 0;
		  int x = xi;
		    for(int y = yi; y > yf; y--){
				PutPixel(x, y, 255, 0, 0, 255);
				if(2*(D + dx) > dy){
				   x++;
				   D = D + dx-abs(dy);
				}
				else D = D + dx;
		    }
		}
	}
	if(dx == 0){
		if(dy > 0){
			for(int y = yi; y < yf; y++){
				PutPixel(xi, y, 255, 0, 0, 255);	
			}
		} else {
			for(int y = yi; y > yf; y--){
				PutPixel(xi, y, 255, 0, 0, 255);
			}
		}
	}
	if(dy == 0){
		if(dx > 0){
		
			for(int x = xi; x < xf; x++){
				PutPixel(x, yi, 255, 0, 0, 255);	
			}
		} else {
			for(int x = xi; x > xf; x--){
				PutPixel(x, yi, 255, 0, 0, 255);
			}
		}	
	}
	
}

int TemCor(int coordx, int coordy){
	if(
	(FBptr[coordx*4 + coordy*4*IMAGE_WIDTH + 0] != 0) ||
	(FBptr[coordx*4 + coordy*4*IMAGE_WIDTH + 1] != 0) ||
	(FBptr[coordx*4 + coordy*4*IMAGE_WIDTH + 2] != 0)
	)
	return 1;
	else return 0;
}

void Pintar(){
	int memx, memy, memx2, memy2;
	for(int x = 0; x < 512; x++){
		memx = 0;	
		memx2 = 0;
		memy = 0;
		memy2 = 0;	
		for(int y = 0; y < 512; y++){
			if(TemCor(x, y) && !TemCor(x,y+1)){
				memx = x;
				memy = y;
			}
			if(!TemCor(x, y) && TemCor(x,y+1)){
				memx2 = x;
				memy2 = y+1;
			}
			if((memx != 0) && (memy !=0) && (memx2 != 0) && (memy2 != 0)){
				DrawLine(memx,memy,memx2,memy2);
			}	
		}	
	}

}


void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
	DrawLine(x1, y1, x2, y2);
	DrawLine(x2, y2, x3, y3);
	DrawLine(x3, y3, x1, y1);
	
}
#endif // _MYGL_H_


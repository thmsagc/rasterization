#include "main.h"


struct Ponto {
	int x,y,r,g,b,a;
};

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

	//PutPixel(30,50,0,255,0,255);	 

	//DrawLine(200,200,400,400); 
	//DrawLine(200,200,200,400);  
	//DrawLine(200,200,0,400);     
	//DrawLine(200,200,0,200);
	//DrawLine(200,200,0,0);       
	//DrawLine(200,0,200,200);    
	//DrawLine(400,0,200,200);   
	//DrawLine(200,200,400,200);

	DrawTriangle(100,150,200,150,150,50);
	DrawTriangle(250,150,350,150,300,50);
	Pintar(); //Pinta os polígonos fechados.


}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}


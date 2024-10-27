 //============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Battleship.
//============================================================================

#ifndef Battleship_CPP_
#define Battleship_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<fstream>
using namespace std;
//------------------------Variables----------------------------------------------

int scr=0,ship=0,color=0;
int a4a=663,b4a=187,a3b=783,b3b=263,a3a=589,b3a=263,a2a=589,b2a=337,a2b=703,b2b=337,a2c=823,b2c=337,a1a=547,b1a=417,a1b=667,b1b=417,a1c=783,b1c=417,a1d=897,b1d=417;
int A101,B101,A81,B81,A91,B91,A51,B51,A61,B61,A71,B71,A11,B11,A21,B21,A31,B31,A41,B41,A102,A82,A92,A52,A62,A72;
int A1=562,A2=682,A3=802,A4=922,A5=602,A6=722,A7=842,A8=602,A9=802,A10=682;
int B1=362,B2=362,B3=362,B4=362,B5=442,B6=442,B7=442,B8=522,B9=522,B10=602;
string st="";
//-----------------------------DrawShips-----------------------------------------

void Drawships(){


if(color==1){
DrawRoundRect(A10,B10,200,50,colors[RED]); //biggest
DrawRoundRect( A8, B8 ,150 , 50, colors[RED]); //second
DrawRoundRect( A9, B9 ,150 , 50, colors[RED]); //second
DrawRoundRect( A5, B5 ,100 , 50, colors[RED]); //third
DrawRoundRect( A6, B6 ,100, 50, colors[RED]); //third
DrawRoundRect( A7, B7 ,100 , 50, colors[RED]); //third
DrawRoundRect( A1, B1 ,50 , 50, colors[RED]); //4th (1)
DrawRoundRect(A2, B2, 50, 50, colors[RED]); //4th (2)
DrawRoundRect(A3, B3 ,50, 50, colors[RED]); //4th (3)
DrawRoundRect(A4, B4, 50, 50, colors[RED]); //4th
}
if(color==2){
DrawRoundRect(A10,B10,200,50,colors[BLUE]); //biggest
DrawRoundRect( A8, B8 ,150 , 50, colors[BLUE]); //second
DrawRoundRect( A9, B9 ,150 , 50, colors[BLUE]); //second
DrawRoundRect( A5, B5 ,100 , 50, colors[BLUE]); //third
DrawRoundRect( A6, B6 ,100, 50, colors[BLUE]); //third
DrawRoundRect( A7, B7 ,100 , 50, colors[BLUE]); //third
DrawRoundRect( A1, B1 ,50 , 50, colors[BLUE]); //4th (1)
DrawRoundRect(A2, B2, 50, 50, colors[BLUE]); //4th (2)
DrawRoundRect(A3, B3 ,50, 50, colors[BLUE]); //4th (3)
DrawRoundRect(A4, B4, 50, 50, colors[BLUE]); //4th
}
if(color==3){
DrawRoundRect(A10,B10,200,50,colors[GREEN]); //biggest
DrawRoundRect( A8, B8 ,150 , 50, colors[GREEN]); //second
DrawRoundRect( A9, B9 ,150 , 50, colors[GREEN]); //second
DrawRoundRect( A5, B5 ,100 , 50, colors[GREEN]); //third
DrawRoundRect( A6, B6 ,100, 50, colors[GREEN]); //third
DrawRoundRect( A7, B7 ,100 , 50, colors[GREEN]); //third
DrawRoundRect( A1, B1 ,50 , 50, colors[GREEN]); //4th (1)
DrawRoundRect(A2, B2, 50, 50, colors[GREEN]); //4th (2)
DrawRoundRect(A3, B3 ,50, 50, colors[GREEN]); //4th (3)
DrawRoundRect(A4, B4, 50, 50, colors[GREEN]); //4th
}
}

//----------------------------GridPattern---------------------------------------------

void GridPattern(){
	       glutPostRedisplay();
DrawRoundRect(40,760,120,40,colors[GRAY]);
DrawString( 60, 770, "Score=0", colors[BLACK]);
DrawRoundRect(840,760,120,40,colors[GRAY]);
DrawString(860,770,"START",colors[BLACK]);
int x1=50,y1=150,x2=50,y2=650; // for drawline function
for(int i=1;i<=11;i++)
{
DrawLine(x1,y1,x2,y2,3, colors[GOLD]);
	x1+=50;
	x2+=50;
	}
		glutPostRedisplay();
int m1=48,n1=150,m2=551,n2=150;
for(int i=1;i<=11;i++){
DrawLine(m1,n1,m2,n2,4, colors[GOLD]);
	n1+=50;
	n2+=50;
	}
}
//--------------------------------Play------------------------------------------------

void play()
{
DrawRectangle(0,0,1020,840,colors[WHITE]);
GridPattern();
Drawships();
glutPostRedisplay();
glutSwapBuffers(); 
}

//----------------------------MainPage--------------------------------------------

void mainpage()
{
   glClear (GL_COLOR_BUFFER_BIT);
   DrawRectangle(0,0,1020,840,colors[BLACK]);
   DrawRoundRect( 340, 790 ,430 , 40, colors[FIREBRICK]);
   DrawString( 350, 800, "WELCOME TO BATTLESHIP GAME!", colors[WHITE]); //middle
   DrawRoundRect( 5, 290 ,100, 40, colors[FIREBRICK]);
   DrawString( 20, 300, "PLAY", colors[WHITE]); //1
   DrawRoundRect(5, 90 ,210, 40, colors[FIREBRICK]);
   DrawString( 20, 100, "LEADERBOARD", colors[WHITE]); //3
   DrawRoundRect( 5, 190 ,150, 40, colors[FIREBRICK]);
   DrawString( 20, 200,"OPTIONS", colors[WHITE]); //2
   DrawRoundRect( 5, 5 ,150, 40, colors[FIREBRICK]);
   DrawString( 20, 15, "BALANCE", colors[WHITE]); //4
   glutPostRedisplay();	
   glutSwapBuffers();			 
}

//------------------------------LeaderBoard-----------------------------------------

void LeaderBoard(){
glClear (GL_COLOR_BUFFER_BIT);
string tt;
int widthh=500;
fstream f("namee.txt",ios::app);
while(f>>tt){

DrawString(100,widthh,tt,colors[RED]);
widthh-=50;
}
glutSwapBuffers();
}
//-----------------------------namee--------------------------------------------------------
void namee(){
DrawRectangle(0,0,1020,840,colors[WHITE]);
DrawRoundRect(300,450,180,45,colors[RED]);
DrawString(310,460,"ENTER NAME",colors[WHITE]);
DrawLine(490,447,490,496,3,colors[RED]);
DrawLine(490,448,690,448,3,colors[RED]);
DrawString(500,455,st,colors[BLACK]);
DrawLine(690,447,690,496,3,colors[RED]);
DrawLine(490,495,690,495,3,colors[RED]);
DrawRoundRect(350,390,100,45,colors[RED]);
DrawRoundRect(500,390,100,45,colors[GREEN]);
DrawString(360,405,"BACK",colors[WHITE]);
DrawString(510,405,"START",colors[WHITE]);
glutPostRedisplay();
glutSwapBuffers();
}
//----------------------------------ShipsColor-------------------------------------------

void shipsColor(){
glClear (GL_COLOR_BUFFER_BIT);
DrawString(280,525,"SELECT THE COLOR OF YOUR SHIPS",colors[BLACK]);
DrawRoundRect(300,450,100,45,colors[RED]);
DrawRoundRect(420,450,100,45,colors[BLUE]);
DrawRoundRect(540,450,100,45,colors[GREEN]);
glutPostRedisplay();
glutSwapBuffers();
}

//------------------------------------EmenyShips------------------------------------------
void EmenyShips(){
if(color==1){
DrawRoundRect(610,320,160,40,colors[GREEN]); //biggest
DrawRoundRect(690,480,120 , 40,colors[GREEN]); //second
DrawRoundRect(730,200,120 , 40, colors[GREEN]); //second
DrawRoundRect(610, 400,80 , 40, colors[GREEN]); //third
DrawRoundRect(570,560,80, 40, colors[GREEN]); //third
DrawRoundRect( 890,400,80 , 40, colors[GREEN]); //third
DrawRoundRect(610,240,40,40, colors[GREEN]); //4th (1)
DrawRoundRect(930,560,40,40, colors[GREEN]); //4th (2)
DrawRoundRect(850,280,40,40, colors[GREEN]); //4th (3)
DrawRoundRect(770,400,40,40, colors[GREEN]); //4th
}

if(color==2){
DrawRoundRect(610,320,160,40,colors[RED]); //biggest
DrawRoundRect(690,480,120 , 40,colors[RED]); //second
DrawRoundRect(730,200,120 , 40, colors[RED]); //second
DrawRoundRect(610, 400,80 , 40, colors[RED]); //third
DrawRoundRect(570,560,80, 40, colors[RED]); //third
DrawRoundRect( 890,400,80 , 40, colors[RED]); //third
DrawRoundRect(610,240,40,40, colors[RED]); //4th (1)
DrawRoundRect(930,560,40,40, colors[RED]); //4th (2)
DrawRoundRect(850,280,40,40, colors[RED]); //4th (3)
DrawRoundRect(770,400,40,40, colors[RED]); //4th
}

if(color==3){
DrawRoundRect(610,320,160,40,colors[BLUE]); //biggest
DrawRoundRect(690,480,120 , 40,colors[BLUE]); //second
DrawRoundRect(730,200,120 , 40, colors[BLUE]); //second
DrawRoundRect(610, 400,80 , 40, colors[BLUE]); //third
DrawRoundRect(570,560,80, 40, colors[BLUE]); //third
DrawRoundRect( 890,400,80 , 40, colors[BLUE]); //third
DrawRoundRect(610,240,40,40, colors[BLUE]); //4th (1)
DrawRoundRect(930,560,40,40, colors[BLUE]); //4th (2)
DrawRoundRect(850,280,40,40, colors[BLUE]); //4th (3)
DrawRoundRect(770,400,40,40, colors[BLUE]); //4th
}
}

//-----------------------------EmenyGrid----------------------------------------------------
void EnemyGrid(){
int x1=570,y1=199;
int x2=570,y2=600;
for(int i=0;i<=10;i++){
DrawLine(x1,y1,x2,y2,4, colors[GOLD]);
   x1+=40;
   x2+=40;
}
int n1=200,n2=200,m1=569,m2=971;
for(int i=0;i<=10;i++){
DrawLine(m1,n1,m2,n2,4, colors[GOLD]);
   n1+=40;
   n2+=40;
}
EmenyShips();
}


// seed the random numbers generator B8 current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pA3els...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */


void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


int xI = 400, yI = 400;

void drawObject() {
	glutPostRedisplay();
}


bool flag = true;
void moveObject() {
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}

/*
 * Main Canvas drawing function.
 * */


void GameDisplay()/**/{



	// set the background color using function glClearColor.
	// to change the background plB10 with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim red and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	//DrawSquare(400, 20, 40, colors[RED]);
	mainpage();
	//EnemyGrid();
	//Green Square
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	//DisplB10 Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	//DrawCircle(50,670,10,colors[RED]);
	//DrawCircle(70,670,10,colors[RED]);
	//DrawCircle(90,670,10,colors[RED]);
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	//DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	//DrawRectangle(200,100,100,50,colors[BLUE],40);
	//DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	
	//drawObject();
         glutDisplayFunc(mainpage);
	//EnemyGrid();
	glutSwapBuffers(); // do not modiB7 this line..


}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */


void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_key_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_key_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_key_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_Key_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		glutDisplayFunc(mainpage); // A6it the program when escape key is pressed.
	}
if (key == 8/* delete key ASCII*/) {
		exit(0); // exit the program when escape key is pressed.
	}
	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}

	st+=key;
	if(key==13){
	fstream file;
	file.open("namee.txt",ios::in | ios::out | ios::app);
	file<<st;
	glutDisplayFunc(GridPattern);
	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects B8 varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	moveObject();

	// once again we tell the library to call our Timer function after nA6t 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	cout << x << " " << y << endl;
	
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
//----------------------------------MouseClicked---------------------------------------
void MouseClicked(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
		{
//----------------------------------PLayButton-----------------------------------------	
if((x>5)&&(x<105)&&(y>510)&&(y<550)&&(scr==0))
		{
		scr=1;
		glutDisplayFunc(namee);	
		
		}
if((x>5)&&(x<215)&&(y>710)&&(y<750)&&(scr==0))
		{
		glutDisplayFunc(LeaderBoard);	
		
		}
if((x>500)&&(x<600)&&(y>405)&&(y<450)&&(scr==1)){
		scr=2;
		glutDisplayFunc(shipsColor);
		
}
if((x>350)&&(x<450)&&(y>405)&&(y<450)&&(scr==1)){
                scr=0;
                glutSwapBuffers();
		glutDisplayFunc(mainpage);
		
}
if((x>300)&&(x<400)&&(y>345)&&(y<390)&&(scr==2)){
		scr=3;
		color=1;
		glutDisplayFunc(play);

}
if((x>420)&&(x<520)&&(y>345)&&(y<390)&&(scr==2)){
		scr=3;
		color=2;
		glutDisplayFunc(play);
		
}
if((x>540)&&(x<640)&&(y>345)&&(y<390)&&(scr==2)){
		scr=3;
		color=3;
		glutDisplayFunc(play);
}
if((x>840)&&(x<960)&&(y>40)&&(y<80)&&(scr==3)){
                scr=4;
		glutDisplayFunc(EnemyGrid);
}

//-------------------------------ShipsCooridnates--------------------------------------
if(scr==3)
{
if((x>0)&&(x<1080)&&(y>0)&&(y<820))
{
if((x>a4a)&&(x<a4a+201)&&(y>b4a)&&(y<b4a+51)){
		ship=4;

}
if((x>a3a)&&(x<a3a+151)&&(y>b3a)&&(y<b3a+51)){
		ship=31;

}
if((x>a3b)&&(x<a3b+151)&&(y>b3b)&&(y<b3b+51)){
		ship=32;
		
}
if((x>a2a)&&(x<a2a+101)&&(y>b2a)&&(y<b2a+51)){
		ship=21;

}
if((x>a2b)&&(x<a2b+101)&&(y>b2b)&&(y<b2b+51)){
		ship=22;

}
if((x>a2c)&&(x<a2c+101)&&(y>b2c)&&(y<b2c+51)){
		ship=23;
}
if((x>a1a)&&(x<a1a+51)&&(y>b1a)&&(y<b1a+51)){
		ship=11;

}
if((x>a1b)&&(x<a1b+51)&&(y>b1b)&&(y<b1b+51)){
		ship=12;

}
if((x>a1c)&&(x<a1c+51)&&(y>b1c)&&(y<b1c+51)){
		ship=13;
		
}
if((x>a1d)&&(x<a1d+51)&&(y>b1d)&&(y<b1d+51)){
		ship=14;

}
}
//---------------------------------------------------------------------------------

if((x>50)&&(x<550)&&(y>190)&&(y<690))
{
if(ship==4){
if((x>50)&&(x<100)&&(y>190)&&(y<690))
{
A102=x+100;
}
A101=(x-150+A102)/50;
A10=(A101*50);
B101=(840-y)/50;
B10=B101*50;

	glutDisplayFunc(play);
}
if(ship==31){
if((x>50)&&(x<100)&&(y>190)&&(y<690))
{
A82=x+50;
}
A81=(x-100+A82)/50;
A8=(A81*50);
B81=(840-y)/50;
B8=B81*50;


	glutDisplayFunc(play);
}
if(ship==32){
if((x>50)&&(x<100)&&(y>190)&&(y<690))
{
A92=x+50;
}
A91=(x-100+A92)/50;
A9=(A91*50);
B91=(840-y)/50;
B9=B91*50;

	glutDisplayFunc(play);
}
if(ship==21){
if((x>50)&&(x<100)&&(y>190)&&(y<690))
{
A52=x;
}
A51=(x-50+A52)/50;
A5=A51*50;
B51=(840-y)/50;
B5=B51*50;

	glutDisplayFunc(play);
}
if(ship==22){
if((x>50)&&(x<100)&&(y>190)&&(y<690))
{
A62=x;
}
A61=(x-50+A62)/50;
A6=A61*50;
B61=(840-y)/50;
B6=B61*50;


	glutDisplayFunc(play);
}
if(ship==23){
if((x>50)&&(x<100)&&(y>190)&&(y<690))
{
A72=x;
}
A71=(x-50+A72)/50;
A7=A71*50;

B71=(840-y)/50;
B7=B71*50;


	glutDisplayFunc(play);
}
if(ship==11){
A11=x/50;
A1=A11*50;
B11=(840-y)/50;
B1=B11*50;

	glutDisplayFunc(play);
}
if(ship==12){
A21=x/50;
A2=A21*50;
B21=(840-y)/50;
B2=B21*50;

	glutDisplayFunc(play);
}
if(ship==13){
A31=x/50;
A3=A31*50;
B31=(840-y)/50;
B3=B31*50;

	glutDisplayFunc(play);
}
if(ship==14){
A41=x/50;
A4=A41*50;
B41=(840-y)/50;
B4=B41*50;
glutDisplayFunc(play);
}

}
}
glutSwapBuffers();	
}
 else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{




	}
	glutPostRedisplay();
}

/*
 * our gatewB10 main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color displB10 mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Battleship Game"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pA3els...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplB10Func(displB10); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;

//--------------------------------------------------------------------
}




#endif /* Battleship_CPP_ */

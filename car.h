#include<GL/glut.h>
//#include<iostream>//for strlen
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int i,q,choice,count=0;
int score = 0;//for score counting
int screen = 0;
char convertScore[2],hs[10];
float x=0,y=0.7,z=0;
float a,b,c;
int choice=0;
bool collide = false;//check if car collide to make game over
//char buffer[10];
int windowid2,windowid3;
int vehicleX = 200, vehicleY = 70;
int ovehicleX[4], ovehicleY[4];
int divx = 250, divy = 4, movd;
int flag=0;
int sub_menu;
int hscore;
int user,loopval;
int up=5;

void drawText(char ch[],int xpos, int ypos);
void drawBitmapText(char *string,float x,float y,float z);
void drawStrokeText(char*string,int x,int y,int z);

void fill(float x,float y,float z);
void trees(int a);
//void drawText(char ch[],int xpos, int ypos);
//void drawTextNum(char ch[],int numtext,int xpos, int ypos);
void ovpos();
void drawRoad(float a,float b,float c);

void drawDivider();
void newcar();
void drawVehicle();

void drawOVehicle();

void Specialkey(int key, int x, int y);

//void Normalkey(unsigned char key, int x, int y);

void myinit();
void display();

void race();
void finish();
void modes(int id);
void Game();



void drawText(char ch[],int xpos, int ypos)//draw the text for score and game over
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <= numofchar - 1; i++)
    {
     
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);//font used here, may use other font also
    }
}


void drawBitmapText(char *string,float x,float y,float z)
{
    char *c;
    glRasterPos3f(x, y,z);

    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
    }
}

void drawStrokeText(char*string,int x,int y,int z)
{
      char *c;
      glPushMatrix();
      glTranslatef(x, y+8,z);
      glScalef(0.25f,-0.15f,z);

      for (c=string; *c != '\0'; c++)
      {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , *c);
      }
      glPopMatrix();
}

void fill(float x,float y,float z){
    glBegin(GL_QUADS);
        glColor3f(x,y,z);
        glVertex2f(0,0);
        glVertex2f(150,0);
        glVertex2f(150,500);
        glVertex2f(0,500);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(x,y,z);
        glVertex2f(350,0);
        glVertex2f(500,0);
        glVertex2f(500,500);
        glVertex2f(350,500);
    glEnd();


}
/*
void trees(int a){
    int x1=a+70,x2=a+80,y1=40,y2=70,i=1,j=1;
    int tx1=a+40,tx2=a+110,tx3=a+75,ty1=70,ty2=70,ty3=100;
    
   
    while(i<4) {
        j=1;
        glBegin(GL_QUADS);
        glColor3f(0.647059,0.164706,0.164706);
            glVertex2f(x1,y1);
            glVertex2f(x2,y1);
            glVertex2f(x2,y2);
            glVertex2f(x1,y2);
        glEnd();
        while(j<4){
            glBegin(GL_TRIANGLES);
            glColor3f(0,0.5,0);
                glVertex2f(tx1,ty1);
                glVertex2f(tx3,ty3);
                glVertex2f(tx2,ty2);
            glEnd();
            j++;
            tx1+=7; tx2-=7;
            ty1+=15;ty2+=15;ty3+=15;
        }
        tx1=a+40;tx2=a+110;tx3=a+75;
        ty1=70;ty2=70;ty3=100;
        x1=a+70;x2=a+80;
        y1=40;y2=70;
        y2+=i*130; y1+=i*130;
        ty1+=i*130;ty2+=i*130;ty3+=i*130;
        i++;

    }
}
*/
void trees(int a){
    int x1=a+70,x2=a+80,y1=40,y2=70,i=1,j=1;
    int tx1=a+40,tx2=a+110,tx3=a+75,ty1=70,ty2=70,ty3=100;
    
   
    while(i<8) {
        j=1;
        glBegin(GL_QUADS);
        glColor3f(0.647059,0.164706,0.164706);
            glVertex2f(x1,y1);
            glVertex2f(x2,y1);
            glVertex2f(x2,y2);
            glVertex2f(x1,y2);
        glEnd();
        while(j<4){
            glBegin(GL_TRIANGLES);
            glColor3f(0,0.5,0);
                glVertex2f(tx1,ty1);
                glVertex2f(tx3,ty3);
                glVertex2f(tx2,ty2);
            glEnd();
            j++;
            tx1+=7; tx2-=7;
            ty1+=15;ty2+=15;ty3+=15;
        }
        tx1=a+40;tx2=a+110;tx3=a+75;
        ty1=70;ty2=70;ty3=100;
        x1=a+70;x2=a+80;
        y1=40;y2=70;
        y2+=i*130; y1+=i*130;
        ty1+=i*130;ty2+=i*130;ty3+=i*130;
        i++;

    }
}




   // y1+=8;y2+=8;ty1+=8;ty2+=8;ty3+=8;
void ovpos(){
    glClearColor(0,0,1,0);
    for(i = 0; i < 4; i++){
        if(rand() % 2 == 0){
            ovehicleX[i] = 200;
        }
        else{
        ovehicleX[i] = 300;
        }
   
        ovehicleY[i] = 1000 - i * 160;
    }
}

void drawRoad(float a,float b,float c){
    glLoadIdentity();
    //glTranslatef(0, movd, 0);
    glBegin(GL_QUADS);
        glColor3f(a,b,c);
        glVertex2f(250 - 100, 500);
        glVertex2f(250 - 100, 0);
        glVertex2f(250 + 100, 0);
        glVertex2f(250 + 100, 500);
    glEnd();

}


void drawDivider()//black patch drawn in middle of road
{
    glLoadIdentity();
   glTranslatef(0, -movd, 0);
    for(i = 1; i <= 10; i++)
    {
    glColor3f(1,1,0);
    glBegin(GL_QUADS);
        glVertex2f(divx  - 5, divy * 15 * i + 18);
        glVertex2f(divx  - 5, divy * 15 * i - 18);
        glVertex2f(divx  + 5, divy * 15 * i - 18);
        glVertex2f(divx  + 5, divy * 15 * i + 18);
    glEnd();
    
    }
    glLoadIdentity();
    //printf("Movd val : %d/n",movd);
}

void newcar(){
glBegin(GL_QUADS);
glColor3f(0.9,0,0);
    glVertex2f(vehicleX-20,vehicleY-10);
    glVertex2f(vehicleX+10,vehicleY-10);
    glVertex2f(vehicleX+10,vehicleY+40);
    glVertex2f(vehicleX-20,vehicleY+40);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex2f(vehicleX-20,vehicleY+40);
    glVertex2f(vehicleX+10,vehicleY+40);
    glVertex2f(vehicleX,vehicleY+70);
    glVertex2f(vehicleX-10,vehicleY+70);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(vehicleX-18,vehicleY+60);
    glVertex2f(vehicleX-12,vehicleY+60);
    glVertex2f(vehicleX-12,vehicleY+65);
    glVertex2f(vehicleX-18,vehicleY+65);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(vehicleX+2,vehicleY+60);
    glVertex2f(vehicleX+8,vehicleY+60);
    glVertex2f(vehicleX+8,vehicleY+65);
    glVertex2f(vehicleX+2,vehicleY+65);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(vehicleX-23,vehicleY+55);
    glVertex2f(vehicleX-18,vehicleY+55);
    glVertex2f(vehicleX-18,vehicleY+70);
    glVertex2f(vehicleX-23,vehicleY+70);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(vehicleX+8,vehicleY+55);
    glVertex2f(vehicleX+13,vehicleY+55);
    glVertex2f(vehicleX+13,vehicleY+70);
    glVertex2f(vehicleX+8,vehicleY+70);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(vehicleX-25,vehicleY-10);
    glVertex2f(vehicleX-20,vehicleY-10);
    glVertex2f(vehicleX-20,vehicleY+4);
    glVertex2f(vehicleX-25,vehicleY+1);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(vehicleX+10,vehicleY-10);
    glVertex2f(vehicleX+15,vehicleY-10);
    glVertex2f(vehicleX+15,vehicleY+1);
    glVertex2f(vehicleX+10,vehicleY+4);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(vehicleX-30,vehicleY-7);
    glVertex2f(vehicleX-25,vehicleY-7);
    glVertex2f(vehicleX-25,vehicleY-3);
    glVertex2f(vehicleX-30,vehicleY-3);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(vehicleX+15,vehicleY-7);
    glVertex2f(vehicleX+20,vehicleY-7);
    glVertex2f(vehicleX+20,vehicleY-3);
    glVertex2f(vehicleX+15,vehicleY-3);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(vehicleX-35,vehicleY-12);
    glVertex2f(vehicleX-30,vehicleY-12);
    glVertex2f(vehicleX-30,vehicleY+5);
    glVertex2f(vehicleX-35,vehicleY+5);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(vehicleX+20,vehicleY-12);
    glVertex2f(vehicleX+25,vehicleY-12);
    glVertex2f(vehicleX+25,vehicleY+5);
    glVertex2f(vehicleX+20,vehicleY+5);
glEnd();
}

void drawVehicle()//car for racing
{
    glPointSize(10.0);
   // glLoadIdentity();
    //glTranslatef(0, 20, 0);
    glBegin(GL_POINTS);//tire
        glColor3f(0,0,0);
        glVertex2f(vehicleX - 25, vehicleY + 16);
        glVertex2f(vehicleX + 25, vehicleY + 16);
        glVertex2f(vehicleX - 25, vehicleY - 16);
        glVertex2f(vehicleX + 25, vehicleY - 16);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1,1,0);//middle body
        glVertex2f(vehicleX - 25, vehicleY + 20);
        glColor3f(0.7,0,0);
        glVertex2f(vehicleX - 25, vehicleY - 20);
        glColor3f(0.4,0,0);
        glVertex2f(vehicleX + 25, vehicleY - 20);
        glColor3f(0.8,0,0);
        glVertex2f(vehicleX + 25, vehicleY + 20);
    glEnd();

    glBegin(GL_QUADS);//up body
        glColor3f(0,1,0);
        glVertex2f(vehicleX - 23, vehicleY + 20);
        glVertex2f(vehicleX - 19, vehicleY + 40);
        glVertex2f(vehicleX + 19, vehicleY + 40);
        glVertex2f(vehicleX + 23, vehicleY + 20);
    glEnd();

    glBegin(GL_QUADS);//down body
        glColor3f(0,1,0);
        glVertex2f(vehicleX - 23, vehicleY - 20);
        glVertex2f(vehicleX - 19, vehicleY - 35);
        glVertex2f(vehicleX + 19, vehicleY - 35);
        glVertex2f(vehicleX + 23, vehicleY - 20);
    glEnd();
 }



void drawOVehicle()//other cars
{

    for(i = 0; i < 4; i++)
    {
    glPointSize(10.0);
    glBegin(GL_POINTS);//tire
        glColor3f(0,0,0);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] + 16);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] + 16);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] - 16);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] - 16);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.99609, 0.83984, 0);//middle body
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] + 20);
	glColor3f(0.5, 0.6345, 0.234);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] - 20);
	glColor3f(0.456, 0.830, 0.98);        
	glVertex2f(ovehicleX[i] + 25, ovehicleY[i] - 20);
	glColor3f(0.3456, 0.83984, 0.234);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] + 20);
    glEnd();

    glBegin(GL_QUADS);//up body
        glColor3f(0.4,0.8,0.677);
        glVertex2f(ovehicleX[i] - 23, ovehicleY[i] + 20);
        glVertex2f(ovehicleX[i] - 19, ovehicleY[i] + 40);
        glVertex2f(ovehicleX[i] + 19, ovehicleY[i] + 40);
        glVertex2f(ovehicleX[i] + 23, ovehicleY[i] + 20);
    glEnd();

    glBegin(GL_QUADS);//down body
        glColor3f(0.4,0.872,0.677);
        glVertex2f(ovehicleX[i] - 23, ovehicleY[i] - 20);
        glVertex2f(ovehicleX[i] - 19, ovehicleY[i] - 35);
        glVertex2f(ovehicleX[i] + 19, ovehicleY[i] - 35);
        glVertex2f(ovehicleX[i] + 23, ovehicleY[i] - 20);
    glEnd();

    ovehicleY[i] = ovehicleY[i] - 8;

    if(ovehicleY[i] > vehicleY - 35 - 25 && ovehicleY[i] < vehicleY + 35 + 25 && ovehicleX[i] == vehicleX)
    {
        collide = true;
    }
	
  

  //  if(ovehicleY[i]==vehicleY && ovehicleX[i]==vehicleX)
//	collide=true;  
    
    if(ovehicleY[i] < -25)
    {
        if(rand() % 2 == 0)
        {
            ovehicleX[i] = 200;
        }
        else
        {
            ovehicleX[i] = 300;
        }
        ovehicleY[i] = 600;
    }
    }
}
void Specialkey(int key, int x, int y){//allow to use navigation key for movement of car
    switch(key){
    case GLUT_KEY_UP:
                        for(i = 0; i <4; i++){
                            ovehicleY[i] = ovehicleY[i] - 10;
                        }
                        movd = movd + movd/movd;
                        break;
    case GLUT_KEY_DOWN:
                        for(i = 0; i <4; i++){
                            ovehicleY[i] = ovehicleY[i] + 10;
                        }
                        movd = movd -movd;
                        break;
    case GLUT_KEY_LEFT: vehicleX = 200;
                        break;
    case GLUT_KEY_RIGHT:vehicleX = 300;
                        break;

}
glutPostRedisplay();
}



void keycheck(unsigned char key,int x,int y){
    if(key=='r'){
        if(flag==1 || flag==0){
            glutDestroyWindow(windowid2);
            race(); 
            collide=false;
            flag=0;  
            score=0;   
        }
    }

    if(key=='a'){
        collide=false;
	count=0;
        score=0;
        glutDestroyWindow(windowid2);
        race();
    }

    if(key=='q'){
       // exit(0);
        glutDestroyWindow(windowid2);
        exit(0);
    }


}

void readFile(){
	FILE *fin;
	printf("READING FILE");
	if(user==0)
		fin=fopen("BScore.txt","r");
	else if(user==1){
		fin=fopen("Score.txt","r");
		printf("HERE in BSCORE\n");
	}

        //fout=fopen("Score.txt","w");
        if(fin==NULL){
            printf("ERROR");
        }

    	fscanf(fin,"%d",&hscore);
	printf("Val of hscore : %d\n",hscore);
	fclose(fin);        
}

void myinit(){
glClearColor(1,1,1,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 500, 0, 500);
glMatrixMode(GL_MODELVIEW);
}

void display(){
		
    up+=5;
    if(up>=525)
	up=5;
    if(collide==false){
    glClear(GL_COLOR_BUFFER_BIT);
    if(choice==0){
        x=0; y=0.6; z=0;
        a=b=c=0.5;
    }
    else {
        //x=0;y=0;z=0;
        x=0.16078;y=0.0588;z=0.3529;
        a=0.52156;b=0.34901;c=0.53333;
    }

    if(user==0)
        loopval=30000000;
    else if(user==1)
        loopval=10000000;

    fill(x,y,z);
	glTranslatef(0,-up,0);
        trees(0);
        trees(350);
	glTranslatef(0,up,0);
    drawRoad(a,b,c);
    drawDivider();
    newcar();
    drawOVehicle();
    glPushMatrix();
    glColor3f(1,0,0);
    drawText("Score : ",370,450);
    //convertScore[0]=score+ '0';
     sprintf(convertScore, "%d", score);
    drawText(convertScore,420,450);
    readFile();
    drawText("High Score :",370,400);
    sprintf(hs,"%d",hscore);

    drawText(hs,420,400);	
    glPopMatrix();
    glFlush();
    score+=1;
    }

        movd = movd - 16;
    if(movd < - 60)
    {
        movd = 0;
    }
    for(q = 0; q<= loopval; q++);
    //printf("collide =%d \n",collide);
    if(collide == true)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        myinit();
       // glClearColor(0.16078,0.0588,0.3529,0.5);
	   glClearColor(0.4,0.6,0.3,1);       
	   Game();
    }


}

void modes(int id)
{
    switch(id)
    {
        case 1: exit(0);
                break;
        case 2: choice=0;
                break;
        case 3: choice=1;
                break;
    }
    glutPostRedisplay();
}

void race()
{
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,500);
    windowid2=glutCreateWindow("Lets PLAY");
    glutSetWindow(windowid2); 
    ovpos();
    myinit();
    sub_menu=glutCreateMenu(modes);
    glutAddMenuEntry("Day Mode",2);
    glutAddMenuEntry("Night Mode",3);
    glutCreateMenu(modes);
    glutAddMenuEntry("Exit",1);
    glutAddSubMenu("Modes",sub_menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    if(flag==0)
        glutDisplayFunc(display);
    glutSpecialFunc(Specialkey);
    glutKeyboardFunc(keycheck);
    glutIdleFunc(display);
    glEnable(GL_FOG);
   glutFullScreen();
    glutMainLoop();
}

void Game(){

        count++;
        if(count==1){
        FILE *fin,*fout;
        //fout=fopen("Score.txt","w");
       /* if(fout==NULL){
            printf("ERROR");
        }
*/

	if(user==0)
		fin=fopen("BScore.txt","r");
	else if(user==1){
		fin=fopen("Score.txt","r");
		printf("HERE in BSCORE\n");
	}

        fscanf(fin,"%d",&hscore);
	printf("Val of hscore : %d\n",hscore);
	fclose(fin);        
	printf("Hscore=%d\n",hscore);
        sprintf(hs, "%d", hscore);
        printf("%s\n",hs);
        score-=1;
	if(user==0)
		fout=fopen("BScore.txt","w");        
	else if(user==1)
		fout=fopen("Score.txt","w");
	
	if(score>hscore){
            hscore=score;
            fprintf(fout,"%d\n",hscore);
	    sprintf(hs, "%d", hscore);
            printf("NewHscore=%d\n",hscore);

        }
        
        fclose(fout);
        }
	
	
	        
	//glColor3f(0.4,0.6,0.3);
        drawText("Game Over",200,350);
        drawText("Score :",200,250);
        drawText(convertScore,250,250);
        drawText("High Score :" ,200,200);
        drawText(hs,250,200);
        drawText("Press 'a' to restart",200,130);
        drawText("Press 'q' to quit",200,80);
	   flag=1;  
        glFlush();
        glutMainLoop();
}

#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>

#include "car.h"

int obj,windowid1,windowid2;
char s[]="Start";
int state=0;

void init()
{
    glClearColor(1,1,1,0.7);
}


void reshape(int w,int h)
{

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,w,h,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}


void drawButton(int xMin, int yMin, int xMax, int yMax, int state, char *s){
    glBegin(GL_POLYGON);

    glColor3f(1,0,0);
        glVertex2d(xMin, yMin);
        glVertex2d(xMax, yMin);
        glVertex2d(xMax, yMax);
        glVertex2d(xMin, yMax);
    glEnd();

    float border = 0.5;
    if(state == 0){
        border = 1;
    }
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
        glVertex2f(xMin+border, yMin+border);
        glVertex2f(xMax-border, yMin+border);
        glVertex2f(xMax-border, yMax-border);
        glVertex2f(xMin+border, yMax-border);
    glEnd();

    glColor3f(1,1,1);

    drawStrokeText(s,xMin+10,yMin+40,0);


}

void levels(){
    state=1;
    glColor3f(0,0,0);
    drawStrokeText("DIFFICULTY LEVEL ",200,200,0);
    drawButton(550,300,770,380,0,"BEGINNER");
    drawButton(550,450,770,530,0,"  PRO   ");
    drawButton(550,650,770,730,0,"  BACK  ");
    glFlush();

}

void rules(){
    state=2;
    printf("RULES Here\n");
    glColor3f(0,0,0);
    drawStrokeText("RULES :",125,150,0);
    glColor3f(0,0,0);
    drawStrokeText("1. Use left arrow key to left",180,200,0);
    drawStrokeText("2. Use right arrow key to right",180,250,0);
    drawStrokeText("3. Right Click in game screen to change mode",180,300,0);
    drawStrokeText("4. Press r to restart game",180,350,0);
    drawStrokeText("5. Press q to quit game",180,400,0);
    drawButton(575,550,725,630,0,"START");
    drawButton(575,650,725,730,0,"BACK");
    glFlush();
   // glutMainLoop();

}


void render(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0,0,0);
    drawStrokeText("COMPUTER GRAPHICS PROJECT",325,40,0);
    glColor3f(0,0,0);
    drawStrokeText("ROAD FIGHTER",500,110,0);
    glColor3f(0,0,0);
    drawStrokeText("1. AMIT NEGI            1PE15CS018",200,320,0);
    glColor3f(0,0,0);
    drawStrokeText("2. ARPIT SACHDEVA       1PE15CS030",200,390,0);
    drawButton(575,500,725,580,0,"START");
    drawButton(575,625,725,705,0,"RULES");
	glPushMatrix();  
 newcar();
 //   glTranslated(900,20,0);
glPopMatrix();  //     glutSwapBuffers();
  //      glLoadIdentity();
    glFlush();

}

void keys(unsigned char key,int x,int y){
    if(key=='s'){
        glClear(GL_COLOR_BUFFER_BIT);
      //  glutDestroyWindow(windowid1);
        state=1;
        levels();     
    }

    if(key=='q'){
       glutDestroyWindow(windowid2);
    }

    if(key=='d'){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1,1,1,1);
        render();    
    }
}



void isButtonClicked(int x, int y){
   if(state==0) {                                           //Front page
        if(x > 575 && x < 725 && y > 500 && y < 580){
            printf("\nBUTTON IS CLICKED");
            glClear(GL_COLOR_BUFFER_BIT);
            //race();
           // glutDestroyWindow(windowid1);
            //glutPostRedisplay();
            levels();
        }
        else if(x > 575 && x < 725 && y > 625 && y < 705){
            printf("\nBUTTON IS CLICKED FOR RULES");
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(1,1,1,1);
            state=1;
            rules();
        
        }
    }

    else if(state==1){                                     //Levels Page
         if(x > 550 && x < 770 && y > 300 && y < 380){
            //BEGINNER
            printf("\nBUTTON IS CLICKED");
            glClear(GL_COLOR_BUFFER_BIT);
            user=0;
            glutDestroyWindow(windowid1);
	    race();

	    
	   // glutPostRedisplay();
        }
        else if(x > 550 && x < 770 && y > 450 && y < 530){
             //PRO
            printf("\nBUTTON IS CLICKED FOR RULES");
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(1,1,1,1);
            user=1;
	    glutDestroyWindow(windowid1);
            race();
	   // glutPostRedisplay();
        
        }
        else if(x > 550 && x < 770 && y > 650 && y < 730){
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(1,1,1,1);
            state=0;
            render();    
        
        }
    }
    else if(state==2){                                  // Rules Page
        if(x > 575 && x < 725 && y > 650 && y < 730){
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(1,1,1,1);
            state=0;
            render();    
        
        }
        else if(x > 575 && x < 725 && y > 550 && y < 630){
            printf("\nBUTTON IS CLICKED");
            glClear(GL_COLOR_BUFFER_BIT);
            //race();
           // glutDestroyWindow(windowid1);
            //glutPostRedisplay();
	    state=2;
            levels();
        }

    }
}

void mouse(int btn, int state, int x, int y){
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
       // x = maxX - x/(globalWidth / maxX);
        //y = maxY - y/(globalHeight / maxY);
        printf("X is :%d and Y is : %d\n",x,y );
        isButtonClicked(x, y);

    }
}




int main(int argc, char* argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB |GLUT_SINGLE);
    glutInitWindowSize(1350,750);   
    glutInitWindowPosition(0,0);
    windowid1=glutCreateWindow("Road Fighter");
    glutSetWindow(windowid1);
    glutKeyboardFunc(keys);
    glutDisplayFunc(render);
    //glutIdleFunc(render);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    init();
    glutFullScreen();
    glutMainLoop();
    return 0;
}















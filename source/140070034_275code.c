#include<simplecpp>
#include<conio.h>




void paddlemotion(int vnewp,int &xc ,Rectangle &p , Rectangle&newp , int gamestarted ,Circle &ball , float &bcx , float &bcy)//function for ball motion
{
    if(vnewp==2) //the main code for movement of the big paddle
    {

        XEvent event;

        checkEvent(event);
        if (keyPressEvent(event))
        {
            char movep = charFromEvent(event);
            if (movep=='M'&&xc<530)
            {
                xc= xc+30;
                if(gamestarted==0)
                {
                    bcx=bcx+30;ball.moveTo(bcx,525);
                }
                p.moveTo(xc,550 );

            }

            if (movep=='K'&&xc>50)
            {
                xc= xc-30;
                if(gamestarted==0)
                {
                    bcx=bcx-30;
                    ball.moveTo(bcx,525);
                }
                p.moveTo(xc, 550);
            }

            if(movep==32 )
            {
                getch();
            }

        }



    }


    //main code for movement of the small paddle
    if(vnewp==3)
    {
        XEvent event1;
        checkEvent(event1);
        if (keyPressEvent(event1))
        {
            char movenewp = charFromEvent(event1);
            if (movenewp=='M'&&xc<530)
            {
                xc= xc+30;

                newp.moveTo(xc,550 );

            }

            if (movenewp=='K'&&xc>50)
            {
                xc= xc-30;


                newp.moveTo(xc, 550);
            }
        }
    }

}


void ballmotion(float &vx,float &vy, float &bcx,float &bcy, Circle &ball, int vnewp, int xc, int *arectanglereflect, Rectangle **b,int &score,int *xb1,int *xb2,int *yb1,int *yb2,int &bi , int &bj)
{

    bcx=bcx+vx;//increment in x-co-ordinate of the ball
    bcy=bcy+vy;//increment in y-co-ordinate of the ball

    ball.move(vx,vy);//moving the ball

    if(bcx==10||bcx==590||bcx==591||bcx==11||bcx==592||bcx==12||bcx==13||bcx==589||bcx==14||bcx==588)//reflection of the ball from the boundaries
    {
        vx=-vx;//velocity is reversed

    }

    if(bcy==20||bcy==21||bcy==22||bcy==19)
    {
        vy=-vy;
    }

    if(bcy==525||bcy==526||bcy==527||bcy==528)//reflection of the ball from the paddle
    {
        if (vnewp==2)//if the big paddle is active
        {

            if(bcx<xc+60&&bcx>xc-60)
            {
                vy=-vy;

            }
        }
        if(vnewp==3)//if the small paddle is active
        {
            if(bcx<xc+35&&bcx>xc-35)
            {
                vy=-vy;

            }
        }


    }
    int reflect=2;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(((bcy>=yb2[j+5*i]+9&&bcy<=yb2[j+5*i]+15||bcy<=yb1[j+5*i]-9&&bcy>=yb1[j+5*i]-15)&&bcx<=xb2[j+5*i]+14&&bcx>=xb1[j+5*i]-14)||((bcx>=xb2[j+5*i]+9&&bcx<=xb2[j+5*i]+15||bcx<=xb1[j+5*i]-9&&bcx>=xb1[j+5*i]-15)&&bcy<=yb2[j+5*i]+14&&bcy>=yb1[j+5*i]-14))//description of the boundary
            {


                if (((bcx>=xb2[j+5*i]+9&&bcx<=xb2[j+5*i]+15||bcx<=xb1[j+5*i]-9&&bcx>=xb1[j+5*i]-15)&&bcy<=yb2[j+5*i]+14&&bcy>=yb1[j+5*i]-14))
                {
                    reflect=3;
                }
                else
                {
                    reflect=2;
                }
                if(arectanglereflect[j+5*i]==2||arectanglereflect[j+5*i]==4)//gets reflected only when the brick is actually visible
                {
                    bi=i;
                    bj=j;

                    if(arectanglereflect[j+5*i]==2)//if the brick is a normal brick
                    {


                        if(reflect==2)
                        {
                            vy=-vy;
                        }
                        else
                        {
                            vx=-vx;
                        };
                        b[j+5*i]->hide();//the brick is hidden
                        arectanglereflect[j+5*i]=3;//the value of the reflection variable is changed so that the ball is not reflected again
                        score++;//increment in score
                    }

                    if(arectanglereflect[j+5*i]==4)//the brick is the two time reflection brick
                    {
                        if(reflect==2)
                        {
                            vy=-vy;
                        }
                        else
                        {
                            vx=-vx;
                        }
                        b[j+5*i]->setColor(COLOR("blue"));//after first reflection the brick changes to a normal brick
                        arectanglereflect[j+5*i]=2;// the value of reflection variable changed to that of a normal brick
                    }
                }
            }
        }
    }




}


main_program
{

    a:int level;
    int score=0;
    float vx=2;
    float vy=-2;
    int t=0;
    int cx[6][6];// x-coordinates of the centres of the bricks
    int cy[6][6];// y-coordinates of the centres of the bricks
    int xb1[25];// x-coordinates of the farther boundaries of the bricks
    int xb2[25];// x-coordinates of the lesser boundaries of the bricks
    int yb1[25];// y-coordinates of the nearer boundaries of the bricks
    int yb2[25];// x-coordinates of the farther of the bricks
    Rectangle *b[25];//pointer to the bricks
    int arectanglereflect[25];//variable which checks whether the ball has collided with the brick or not
    initCanvas("arena",600,600);
   b: Rectangle startscreen(300,300,580,580);
    startscreen.setFill(1);
    startscreen.setColor(COLOR("green"));
    Rectangle a(300,150,200,50);
    a.setFill();
    a.setColor(COLOR(255,255,255));
    Rectangle inst(100,40,120,50);
    inst.setFill();
    inst.setColor(COLOR(255,255,255));
    Rectangle a1(160,300,100,50);
    a1.setFill();
    a1.setColor(COLOR(255,255,255));
    Rectangle a2(440,300,100,50);
    a2.setFill();
    a2.setColor(COLOR(255,255,255));
    Rectangle a3(160,400,100,50);
    a3.setFill();
    a3.setColor(COLOR(255,255,255));
    Rectangle a4(440,400,100,50);
    a4.setFill();
    a4.setColor(COLOR(255,255,255));
    Rectangle a5(300,500,100,50);
    a5.setFill();
    a5.setColor(COLOR(255,255,255));
    Text text0(100,40,"INSTRUCTIONS");
    Text text1(300,150,"BRICK BREAKER");

    Text text2(160,300,"LEVEL 1");
    Text text3(440,300,"LEVEL 2");
    Text text4(160,400,"LEVEL 3");
    Text text5(440,400,"LEVEL 4");
    Text text6(300,500,"LEVEL 5");
    int clickpos;
    clickpos=getClick();
    if(clickpos/65536<140&&clickpos/65536>40&&clickpos%65536<65&&clickpos%65536>15){
     a1.hide();
     a2.hide();
     a3.hide();;
     a4.hide();
     a5.hide();
     text0.hide();
     inst.hide();

     Rectangle instbox(300,450,500,180);
     instbox.setFill();
     instbox.setColor(COLOR(255,255,255));
     Rectangle back(100,40,80,50);
     back.setFill();
    back.setColor(COLOR(255,255,255));
     text2.hide();
     text3.hide();
     text4.hide();
     text5.hide();
     text6.hide();
     Text text13(100,40,"BACK");
     Text text7(300,380,"THE AIM OF THE GAME IS TO BREAK ALL THE BRICKS  ");
     Text text8(300,410," WITHOUT LETTING THE BALL FALL BELOW THE PADDLE. ");
     Text text9(300,440,"FOR MOVING THE PADDLE PRESS THE LEFT AND RIGHT KEYS.");
     Text text10(300,470,"YOU CAN TAKE THE POWERS WHICH FALL DOWN FROM THE BRICKS.");
     Text text11(300,500,"BEWARE SOME POWERS MIGHT BE DESTRUCTIVE");
     Text text12(300,530,"ENJOY THE GAME .");
     int clickpos1;
    clickpos1=getClick();
    if(clickpos/65536<140&&clickpos/65536>60&&clickpos%65536<65&&clickpos%65536>15){ goto b; }

    }
    if(clickpos/65536<210&&clickpos/65536>110&&clickpos%65536<325&&clickpos%65536>275){level=1;}
    if(clickpos/65536<490&&clickpos/65536>390&&clickpos%65536<325&&clickpos%65536>275){level=2;}
    if(clickpos/65536<210&&clickpos/65536>110&&clickpos%65536<425&&clickpos%65536>375){level=3;}
    if(clickpos/65536<490&&clickpos/65536>390&&clickpos%65536<425&&clickpos%65536>375){level=4;}
    if(clickpos/65536<350&&clickpos/65536>250&&clickpos%65536<525&&clickpos%65536>475){level=5;}

    Rectangle r(300,300,580,580);
    r.setFill(1);
    r.setColor(COLOR(2,2,2));
   /* cout<<"which level ?";
    cin>>level;*/


    if (level==5 )
    {

        cx[0][0]=65;
        cx[0][1]=120;
        cx[0][2]=175;
        cx[0][3]=285;
        cx[0][4]=395;
        cx[1][0]=450;
        cx[1][1]=505;
        cx[1][2]=120;
        cx[1][3]=175;
        cx[1][4]=230;
        cx[2][0]=285;
        cx[2][1]=285;
        cx[2][2]=285;
        cx[2][3]=340;
        cx[2][4]=395;
        cx[3][0]=450;
        cx[3][1]=120;
        cx[3][2]=175;
        cx[3][3]=230;
        cx[3][4]=285;
        cx[4][0]=285;
        cx[4][1]=285;
        cx[4][2]=340;
        cx[4][3]=395;
        cx[4][4]=450;

        cy[0][0]=275;
        cy[0][1]=275;
        cy[0][2]=275;
        cy[0][3]=275;
        cy[0][4]=275;
        cy[1][0]=275;
        cy[1][1]=275;
        cy[1][2]=220;
        cy[1][3]=165;
        cy[1][4]=110;
        cy[2][0]=55;
        cy[2][1]=110;
        cy[2][2]=165;
        cy[2][3]=110;
        cy[2][4]=165;
        cy[3][0]=220;
        cy[3][1]=330;
        cy[3][2]=385;
        cy[3][3]=440;
        cy[3][4]=495;
        cy[4][0]=440;
        cy[4][1]=385;
        cy[4][2]=440;
        cy[4][3]=385;
        cy[4][4]=330;

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                xb1[j+5*i]=cx[i][j]-20;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                xb2[j+5*i]=cx[i][j]+20;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                yb1[j+5*i]=cy[i][j]-15;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                yb2[j+5*i]=cy[i][j]+15;
            }
        }

        for(int i=0; i<25; i++)
        {
            if(i>=10&&i<15)
            {
                continue;
            }
            arectanglereflect[i]=2;
        }
        for(int i=10; i<15; i++)
        {
            arectanglereflect[i]=4;
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                b[j+5*i]=new Rectangle(cx[i][j],cy[i][j],40,30);
            }
        }

        for(int i=0; i<25; i++)
        {
            if( i>=10&&i<15)
            {
                continue;
            }
            b[i]->setFill(1);
            b[i]->setColor(COLOR("blue"));
        }

        for(int i=10; i<15; i++)
        {
            b[i]->setFill(1);
            b[i]->setColor(COLOR("red"));
        }
    }



    if (level==4)// level 5 starts
    {


        cy[0][0]=40;
        cy[0][1]=40;
        cy[0][2]=80;
        cy[0][3]=80;
        cy[0][4]=80;
        cy[1][0]=80;
        cy[1][1]=80;
        cy[1][2]=80;
        cy[1][3]=120;
        cy[1][4]=120;
        cy[2][0]=130;
        cy[2][1]=170;
        cy[2][2]=210;
        cy[2][3]=210;
        cy[2][4]=210;
        cy[3][0]=220;
        cy[3][1]=260;
        cy[3][2]=300;
        cy[3][3]=340;
        cy[3][4]=340;
        cy[4][0]=340;
        cy[4][1]=300;
        cy[4][2]=260;
        cy[4][3]=220;
        cy[4][4]=380;


        cx[0][0]=100;
        cx[0][1]=480;
        cx[0][2]=50;
        cx[0][3]=100;
        cx[0][4]=150;
        cx[1][0]=430;
        cx[1][1]=480;
        cx[1][2]=530;
        cx[1][3]=100;
        cx[1][4]=480;
        cx[2][0]=290;
        cx[2][1]=290;
        cx[2][2]=240;
        cx[2][3]=290;
        cx[2][4]=340;
        cx[3][0]=90;
        cx[3][1]=140;
        cx[3][2]=190;
        cx[3][3]=240;
        cx[3][4]=290;
        cx[4][0]=340;
        cx[4][1]=390;
        cx[4][2]=440;
        cx[4][3]=490;
        cx[4][4]=290;


        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                xb1[j+5*i]=cx[i][j]-20;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                xb2[j+5*i]=cx[i][j]+20;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                yb1[j+5*i]=cy[i][j]-15;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                yb2[j+5*i]=cy[i][j]+15;
            }
        }

        for(int i=0; i<25; i++)
        {
            if(i>=10&&i<15)
            {
                continue;
            }
            arectanglereflect[i]=2;
        }
        for(int i=10; i<15; i++)
        {
            arectanglereflect[i]=4;
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                b[j+5*i]=new Rectangle(cx[i][j],cy[i][j],40,30);
            }
        }

        for(int i=0; i<25; i++)
        {
            if( i>=10&&i<15)
            {
                continue;
            }
            b[i]->setFill(1);
            b[i]->setColor(COLOR("blue"));
        }

        for(int i=10; i<15; i++)
        {
            b[i]->setFill(1);
            b[i]->setColor(COLOR("red"));
        }
    }


    if(level==3)// level 3 starts
    {


        cy[0][0]=55;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<3; j++)
            {
                cy[i][j+1]=cy[i][j];
            }
            cy[i+1][0]=cy[i][0]+55;
        }

        cy[0][3]=55;
        for(int i=0; i<2; i++)
        {
            for(int j=3; j<5; j++)
            {
                cy[i][j+1]=cy[i][j];
            }
            cy[i+1][3]=cy[i][3]+220;
        }
        cy[2][3]=55;
        for(int i=2; i<4; i++)
        {
            for(int j=3; j<5; j++)
            {
                cy[i][j+1]=cy[i][j];
            }
            cy[i+1][3]=cy[i][3]+220;
        }

        cy[4][3]=55;
        cy[4][4]=55;


        cx[0][0]=115;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<3; j++)
            {
                cx[i][j+1]=cx[i][j]+185;
            }
            cx[i+1][0]=cx[i][0];
        }

        cx[0][3]=60;
        for(int i=0; i<2; i++)
        {
            for(int j=3; j<5; j++)
            {
                cx[i][j+1]=cx[i][j]+110;
            }
            cx[i+1][3]=cx[i][3];
        }
        cx[2][3]=245;
        for(int i=2; i<4; i++)
        {
            for(int j=3; j<5; j++)
            {
                cx[i][j+1]=cx[i][j]+110;
            }
            cx[i+1][3]=cx[i][3];
        }

        cx[4][3]=430;
        cx[4][4]=540;
        cout<<cx[1][4]<<cy[1][4];
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                xb1[j+5*i]=cx[i][j]-25;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                xb2[j+5*i]=cx[i][j]+25;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                yb1[j+5*i]=cy[i][j]-25;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                yb2[j+5*i]=cy[i][j]+25;
            }
        }

        for(int i=0; i<25; i++)
        {
            if(i>=10&&i<15)
            {
                continue;
            }
            arectanglereflect[i]=2;
        }
        for(int i=10; i<15; i++)
        {
            arectanglereflect[i]=4;
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                b[j+5*i]=new Rectangle(cx[i][j],cy[i][j],50,50);
            }
        }

        for(int i=0; i<25; i++)
        {
            if( i>=10&&i<15)
            {
                continue;
            }
            b[i]->setFill(1);
            b[i]->setColor(COLOR("blue"));
        }

        for(int i=10; i<15; i++)
        {
            b[i]->setFill(1);
            b[i]->setColor(COLOR("red"));
        }




    }

    if(level==1)// level 1 starts
    {
        cx[0][0]=80;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                cx[i][j+1]=cx[i][j]+  106;
            }

            cx[i+1][0]=cx[i][0];
        }

        cy[0][0]=40;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                cy[i][j+1]=cy[i][j];
            }

            cy[i+1][0]=cy[i][0]+56;
        }





        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                xb1[j+5*i]=cx[i][j]-50;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                xb2[j+5*i]=cx[i][j]+50;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                yb1[j+5*i]=cy[i][j]-25;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                yb2[j+5*i]=cy[i][j]+25;
            }
        }

        for(int i=0; i<25; i++)
        {
            if(i>=10&&i<15)
            {
                continue;
            }
            arectanglereflect[i]=2;
        }
        for(int i=10; i<15; i++)
        {
            arectanglereflect[i]=4;
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                b[j+5*i]=new Rectangle(cx[i][j],cy[i][j],100,50);
            }
        }

        for(int i=0; i<25; i++)
        {
            if( i>=10&&i<15)
            {
                continue;
            }
            b[i]->setFill(1);
            b[i]->setColor(COLOR("blue"));
        }

        for(int i=10; i<15; i++)
        {
            b[i]->setFill(1);
            b[i]->setColor(COLOR("red"));
        }
    }

    if (level==2)// level 2 starts
    {

        cx[0][0]=90;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cx[i][j+1]=cx[i][j]+85;

            }
            cx[i+1][0]=cx[i][0];

        }

        cx[0][3]=450;
        for(int i=0; i<3; i++)
        {
            for(int j=3; j<5; j++)
            {
                cx[i][j+1]=cx[i][j]+85;

            }
            cx[i+1][3]=cx[i][3];

        }

        cx[3][0]=90 ;
        for(int i=3; i<5; i++)
        {
            for(int j=0; j<3; j++)
            {
                cx[i][j+1]=cx[i][j]+85;

            }
            cx[i+1][0]=cx[i][0];

        }
        cx[3][3]= 450;
        for(int i=3; i<5; i++)
        {
            for(int j=3; j<5; j++)
            {
                cx[i][j+1]=cx[i][j]+85;

            }
            cx[i+1][3]=cx[i][3];
        }

        cy[0][0]=75 ;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cy[i][j+1]=cy[i][j];

            }
            cy[i+1][0]=cy[i][0]+40;

        }

        cy[0][3]=75 ;
        for(int i=0; i<3; i++)
        {
            for(int j=3; j<5; j++)
            {
                cy[i][j+1]=cy[i][j];

            }
            cy[i+1][3]=cy[i][3]+40;

        }
        cy[3][0]= 225 ;
        for(int i=3; i<5; i++)
        {
            for(int j=0; j<3; j++)
            {
                cy[i][j+1]=cy[i][j];

            }
            cy[i+1][0]=cy[i][0]+40;

        }
        cy[3][3]= 225;
        for(int i=3; i<5; i++)
        {
            for(int j=3; j<5; j++)
            {
                cy[i][j+1]=cy[i][j];

            }
            cy[i+1][3]=cy[i][3]+40;
        }



        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                xb1[j+5*i]=cx[i][j]-35;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                xb2[j+5*i]=cx[i][j]+35;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                yb1[j+5*i]=cy[i][j]-12;
            }
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                yb2[j+5*i]=cy[i][j]+12;
            }
        }



        for(int i=0; i<25; i++)
        {
            if(i>=10&&i<15)
            {
                continue;
            }
            arectanglereflect[i]=2;
        }
        for(int i=10; i<15; i++)
        {
            arectanglereflect[i]=4;
        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                b[j+5*i]=new Rectangle(cx[i][j],cy[i][j],70,30);
            }
        }


        for(int i=0; i<25; i++)
        {
            b[i]->setFill(1);
            b[i]->setColor(COLOR("blue"));
        }

        for(int i=10; i<15; i++)
        {
            b[i]->setFill(1);
            b[i]->setColor(COLOR("red"));
        }
    }

    int xc=100;
    Rectangle p(xc,550,100,30); //mainpaddle
    p.setFill(1);
    p.setColor(COLOR("red"));
    Circle ball(100,525,10);//ball
    ball.setFill(1);
    ball.setColor(COLOR("green"));

    int bi,bj;
    float bcx=100;//x-co-ordinate of center of the ball
    float bcy=525;//y-co-ordinate of center of the ball
    int vnewp=2;//variable used to decide which paddle is active(small or big)
    int k;
    int powertaken=0;//variable used to check whether the power has been taken or not
    int c1,c2;//center co-ordinates of the power
    Rectangle newp(xc,550,50,30);//small paddle which comes as a result of power
    newp.setFill(1);
    newp.setColor(COLOR("red"));
    newp.hide();

    int gamestarted=0;//variable to start the game




    // the main while loop begins
    while(1)
    {

        paddlemotion(vnewp , xc, p ,newp,gamestarted, ball,bcx,bcy);


        // to start the game when space key is pressed
        if(gamestarted==0)
        {
            paddlemotion(vnewp , xc, p ,newp,gamestarted,ball,bcx,bcy);//function for paddle motion


            XEvent event3;

            nextEvent(event3);
            if (keyPressEvent(event3))
            {
                char startgame =charFromEvent(event3);
                if(startgame==32)
                {
                    gamestarted=1;
                }
            }
        }

        //the ball starts moving once the variable gamestarted becomes 1 i.e space key is pressed
        if(gamestarted==1)
        {

            if (score==25) //if all the bricks are scored the while loop breaks
            {
                break;
            }

            ballmotion(vx,vy,bcx,bcy,ball ,vnewp,xc,arectanglereflect,b,score,xb1,xb2,yb1,yb2,bi,bj);//function for ball motion


             if(bj+5*bi==6)//power to increase the speed of the block
            {
                int t=0;//variable which serves like a clock for the power to be on
                c2=cy[bi][bj];//center of the rectangle which has the power
                c1=cx[bi][bj];
                int powermoving=1;//variable which checks if the power rectangle is going down or not
                Rectangle power(c1,c2,30,30);//the rectangle which moves down
                power.setFill(1);
                power.setColor(COLOR("red"));
                power.imprint();
                vx=vx*2;//velocity doubled so as to maintain the speed of the ball as it was becoming slow due to extra part of the code running
                vy=vy*2;
                while(c2<535)//while the power is moving down
                {     if(bcy>610){break;}

                    if(powermoving==1)//if the power is moving down
                    {
                        ballmotion(vx,vy,bcx,bcy,ball ,vnewp,xc,arectanglereflect,b,score,xb1,xb2,yb1,yb2,bi,bj);

                        paddlemotion(vnewp , xc, p ,newp,gamestarted,ball,bcx,bcy);


                        power.move(0,1);//movement of the power rectangle
                        c2++;
                        if(c2==535)//finally when the power reaches the paddle
                        {
                            powermoving=0;//variable powermoving changed
                            vx=vx/2;//speed of ball reduced to bring it back to the normal level as the beginning
                            vy=vy/2;
                        }
                    }
                }
                if(c1<xc+50&&c1>xc-50)//if the power hits the paddle
                {
                    vx=vx/2;//velocity increases as a result of the power
                    vy=-vy/2;
                    t=0;// a variable which  serves as a count of when to switch the power off
                    powertaken=1;//the time variable increases only when the power is taken
                }
            }

            if(bj+5*bi==15)//power to increase the speed of the block
            {
                int t=0;//variable which serves like a clock for the power to be on
                c2=cy[bi][bj];//center of the rectangle which has the power
                c1=cx[bi][bj];
                int powermoving=1;//variable which checks if the power rectangle is going down or not
                Rectangle power(c1,c2,30,30);//the rectangle which moves down
                power.setFill(1);
                power.setColor(COLOR("green"));
                power.imprint();
                vx=vx*2;//velocity doubled so as to maintain the speed of the ball as it was becoming slow due to extra part of the code running
                vy=vy*2;
                while(c2<535)//while the power is moving down
                {    if(bcy>610){break;}

                    if(powermoving==1)//if the power is moving down
                    {
                        ballmotion(vx,vy,bcx,bcy,ball ,vnewp,xc,arectanglereflect,b,score,xb1,xb2,yb1,yb2,bi,bj);

                        paddlemotion(vnewp , xc, p ,newp,gamestarted,ball,bcx,bcy);


                        power.move(0,1);//movement of the power rectangle
                        c2++;
                        if(c2==535)//finally when the power reaches the paddle
                        {
                            powermoving=0;//variable powermoving changed
                            vx=vx/2;//speed of ball reduced to bring it back to the normal level as the beginning
                            vy=vy/2;
                        }
                    }
                }
                if(c1<xc+50&&c1>xc-50)//if the power hits the paddle
                {
                    vx=vx*2;//velocity increases as a result of the power
                    vy=vy*-2;
                    t=0;// a variable which  serves as a count of when to switch the power off
                    powertaken=1;//the time variable increases only when the power is taken
                }
            }







            if (bj+5*bi==16)//power for  reducing the size of the paddle
            {
                c2=cy[bi][bj];
                c1=cx[bi][bj];
                int powermoving=1;

                Rectangle power(c1,c2,30,30);
                power.setFill(1);
                power.setColor(COLOR("blue"));
                power.imprint();
                vx=vx*2;
                vy=vy*2;
                while(c2<535)
                {    if(bcy>610){break;}

                    if(powermoving==1)
                    {
                        ballmotion(vx,vy,bcx,bcy,ball ,vnewp,xc,arectanglereflect,b,score,xb1,xb2,yb1,yb2,bi,bj);



                        paddlemotion(vnewp , xc, p ,newp,gamestarted,ball,bcx,bcy);

                        power.move(0,1);
                        c2++;
                        if(c2==535)
                        {
                            powermoving=0;
                            vx=vx/2;
                            vy=vy/2;
                        }
                    }
                }
                if(c1<xc+60&&c1>xc-60)
                {    int k=0;
                    p.hide();
                    vnewp=3;
                    newp.show();
                    powertaken=1;
                }
            }




            if(bcy>610)
            {
                char sco;
                sco=score;
                Rectangle gameover(300,300,580,580);
                gameover.imprint();
                gameover.setFill(1);
                gameover.setColor(COLOR("red"));
                Rectangle sc(300,300,150,20);
                sc.setFill(1);
                sc.setColor(COLOR(255,255,255));
                Text text1(300,300,"YOUR SCORE IS :  ") ;Text text2(360,300,sco);
                wait(10);
                break;

            }
            if((arectanglereflect[15]==3 )&&powertaken==1)
            {
                t++;
                if (t==1000)
                {
                    vx=vx/2;
                    vy=vy/2;
                    powertaken=0;
                }
            }
            if((arectanglereflect[6]==3)&&powertaken==1)
            {
                t++;
                if (t==1000)
                {
                    vx=vx*2;
                    vy=vy*2;
                    powertaken=0;
                }
            }
         if((arectanglereflect[16]==3)&&powertaken==1)
            {
                k++;
                if (k==1000)
                {
                   vnewp=2;
                   p.show();
                    newp.hide();
                    powertaken=0;
                }
            }



        }


    }
}




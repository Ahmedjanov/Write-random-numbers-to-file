#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>

void button();
void mode(int,int,int,int,int,char *st);
void result(int x);
void printer(int tt,char st[]);
int first();
int second();
int main(void)
{

   int GrDr, GrMod, rez ;
    GrDr=DETECT ;

   initgraph(&GrDr,&GrMod," ") ; // GrDr - графический драйвер;
                                                         //GrMod -графический режим;
// третий параметр- путь до графического       //драйвера;

   rez=graphresult() ;
   if(rez != grOk)
{
    printf("\n ООError graph modeи") ;
   return(1) ;
 }
 setcolor(0);
setfillstyle(1,8);
bar(0,400,639,479);
setfillstyle(1,8);
bar(0,0,639,400);
setcolor(0);
line(0,400,639,400);

 mode(80, 170, 420, 450,4, "First");
 mode(250, 340 ,420, 450,2, "Second");
 mode(420,510,420,450 ,2,"Exit");

button();

closegraph() ;
return(0) ;
}
///////////////////////////////////////////////////////////////////////////
void mode(int x,int x1, int y,int y1, int col,char *st)
{
    setfillstyle(1,7);
    bar(x,y,x1, y1);
    setbkcolor(7);
    setcolor(col);
    outtextxy (x+15,y+5,st);
}
////////////////////////////////////////////////////////////////////////
void button()
{
    char key;
    int position=1;
    do
    {
        // mouse
        int xz,yz;
        getmouseclick(WM_LBUTTONDOWN,xz,yz);
        if((xz>80)&&(yz>420)&&(xz<170)&&(yz<450))
        {
            position=1;
                        result(position);
                        first();
        }
        else if((xz>250) && (yz>420) && (xz<340)  && (yz<450))
            {
                position=2;
            result(position);
            second();
            }
            else if((xz>420)&&(yz>420)&&(xz<510)&&(yz<450))
            {
                position=3;
                outtextxy(245,245,"Exit");
                result(position);
                key='e';
            }

        if(kbhit())
        {
                 key=getch();

         if(key==77)//right
            {
                position++;
                if(position==4) position=1;
                result(position);
            }

             if(key==75)//left
            {
                position--;
                if(position==0) position=3;
                result(position);
            }
if(key==13) //enter
{
    if(position==1)
    {

first();    }
    if(position==2)
    {

second();

    }
    if(position==3)
    {
        key='e';
        outtextxy(245,245,"Exit");
    }}
}
    }
      while(key!='e');
}
////////////////////////////////////////////////////////////////////////
void result(int x)
{
 switch (x)
        {
            case 1:
 mode(80, 170, 420, 450,4, "First");
 mode(250, 340 ,420, 450,2, "Second");
 mode(420,510,420, 450,2,"Exit");
                break;
            case 2:
 mode(80, 170, 420, 450,2, "First");
 mode(250, 340 ,420, 450,4, "Second");
 mode(420,510,420, 450,2,"Exit");
                break;
            case 3:
 mode(80, 170,420, 450,2, "First");
 mode(250, 340 ,420, 450,2, "Second");
 mode(420,510,420, 450,4,"Exit");
            break;
        }
}
//////////////////////////////////////////////////////////////////
void printer(int tt,char st[])
{
    st[0]='\0';
    char ch;
    int i=0;
    setcolor(15);
    setbkcolor(8);
            do
            {
                ch=getch();
                if(ch>='0'&&ch<='9')
                {
                   st[i]+=ch;
                   st[i+1]='\0';
                   i++;
                }
                switch(ch)
                {
                    case('.'):
                        st[i]+=ch;
                        st[i+1]='\0';
                        i++;
                        break;
                    case('-'):
                        st[i]+=ch;
                        st[i+1]='\0';
                        i++;
                        break;
                    case(8):
                        setfillstyle(1,8);
                        bar(tt,55,tt+strlen(st)*8,75);
                        st[strlen(st)-1]='\0';
   i--;
                        break;
                }
                outtextxy(tt,55,st);
            }
            while(ch!=13);
}
//////////////////////////////////////////////////////////////////
int first()
{
    setcolor(15);
    setfillstyle(1,8);
bar(0,0,639,400);
setbkcolor(8);
outtextxy(530,20,"First mode");
    srand(time(0));
char st[20];
char str1[10],str2[10];
double **A,s=0,c,a1,b1;
int k=0,i,j,a,b;
FILE *f;
outtextxy(230,25,"Enter a range of numbers");
outtextxy(125,55,"from : ");
   printer(170,st);     //scanf("%d",&a);
      a1=atof(st);
outtextxy(425,55,"to : ");
   printer(460,st);        //scanf("%d",&b);
   b1=atof(st);
a=a1/1;
b=b1/1;
A=(double **) malloc(100*sizeof(double*));

f=fopen("file1.txt","w");
if(f==NULL)
{
    printf("ERROR OPENINH FILE\n");
getch();
return 1;
}
for(i=0;i<100;i++)
{
A[i]=(double*) malloc(200*sizeof(double));
    for(j=0;j<200;j++)
    {
        A[i][j]=(rand()%(b-a+1)+a+(a1-a)+0.01*(rand()%100+1));
if(A[i][j]>b1) {A[i][j]=b1;}
 fprintf(f,"%.2f\t",A[i][j]);
 s+=A[i][j];
        k++;
    }
       fprintf(f,"\n");
}
fclose(f);
outtextxy(220,75,"first 10*10 matrix elements :\n");
int ki=0,kj=0;
for( i=0;i<10;i++)
{
    for(j=0;j<10;j++)
    {
sprintf(str1,"%.2f",A[i][j]);
outtextxy((ki+40),(kj+100),str1);

ki+=58;
    }
kj+=24;
ki=0;
}
setcolor(4);
outtextxy(180,350,"range of number in the matrix [            ;             ]");
sprintf(str2,"%.2f",a1);
outtextxy(385,350,str2);
sprintf(str2,"%.2f",b1);
outtextxy(435,350,str2);
c=s/k;
sprintf(str2,"%.4f",c);
outtextxy(425,370,str2);
outtextxy(165,370,"arithmetic mean value of all elements :");
free (*A);

}
//////////////////////////////////////////////////////////
int second()
{
setcolor(15);
    setfillstyle(1,8);
bar(0,0,639,400);
setbkcolor(8);
outtextxy(530,20,"Second mode");
        srand(time(0));
char st[10];
char str1[10],str2[10];
double **A;
int m,n,i,j,a,b;
double a1,b1;
FILE *F;
outtextxy(230,25,"Enter a range of numbers");
outtextxy(125,55,"from : ");
   printer(170,st);     //scanf("%d",&a);
      a1=atof(st);
outtextxy(425,55,"to : ");
   printer(460,st);        //scanf("%d",&b);
   b1=atof(st);
a=a1/1;
b=b1/1;
m=rand()%111+10;
//n=rand()%202+1;
F=fopen("file2.txt","w");
if(F==NULL)
{
    printf("ERROR OPENINH FILE\n");
getch();
return 1;
}
A=(double **) malloc(100*sizeof(double*));
for(i=0;i<m;i++)
{
    n=rand()%200+1;
    A[i]=(double*) malloc(200*sizeof(double));
    for(j=0;j<n;j++)
    {
       A[i][j]=(rand()%(b-a+1)+a+(a1-a)+0.01*(rand()%100));
if(A[i][j]>b1){A[i][j]=b1;}
    fprintf(F,"%.2f\t",A[i][j]);
    }
    fprintf(F,"\n");
}
fclose(F);
outtextxy(220,75,"first 10*10 matrix elements :\n");
int ki=0,kj=0;
for( i=0;i<10;i++)
{
    for(j=0;j<10;j++)
    {
sprintf(str1,"%.2f",A[i][j]);
outtextxy((ki+40),(kj+100),str1);
ki+=58;
    }
kj+=24;
ki=0;
}
setcolor(4);
outtextxy(180,345,"range of number in the matrix [            ;             ]");
sprintf(str2,"%.2f",a1);
outtextxy(385,345,str2);
sprintf(str2,"%.2f",b1);
outtextxy(435,345,str2);

free(*A);
}

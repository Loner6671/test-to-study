#include<iostream>
#include<cstring>
#include<fstream>
#include<ctime>
using namespace std;
int sort(int all_score[10][10])
{
    char name[10]={'a','b','c','d','e','f','g','h','i','j'};
    char middle[2]={};
    int summary[10]={0};
    int num1=0,sum=0;
    for(int i=0;i<10;i++)
    {
        for(int l=0;l<10;l++)
        {
            sum+=all_score[l][i];
        }
        summary[i]=sum;
        sum=0;
    }
    for(int j=0;j<10;j++)
    {
        for(int k=0;k<10;k++)
        {
           if(summary[k]<=summary[j])
           {
               num1=summary[k];
               middle[1]=name[k];
               summary[k]=summary[j];
               name[k]=name[j];
               summary[j]=num1;
               name[j]=middle[1];
           }
        }
    }
    ofstream outfile;
    outfile.open("score.txt",ios::app);
    outfile<<"排名\n";
    cout<<"排名\n";
    for(int m=0;m<10;m++)
    {
        outfile<<name[m]<<" : "<<summary[m]<<"  ";
        cout<<name[m]<<" : "<<summary[m]<<"  ";
    }
    outfile<<"\n\n";
    cout<<"\n\n";
    outfile.close();
    return 0;
}
int write_file(int all_score[10][10])
{
    char name[10]={'a','b','c','d','e','f','g','h','i','j'};
    int sum;
    ofstream outfile;
    outfile.open("score.txt",ios::app);
    for(int i=0;i<10;i++)
    {
        outfile<<"第"<<i+1<<"轮\n";
        cout<<"第"<<i+1<<"轮\n";
        for(int j=0;j<10;j++)
        {
            outfile<<name[j]<<": "<<all_score[i][j]<<"  ";
            cout<<name[j]<<": "<<all_score[i][j]<<"  ";
        }
        outfile<<"\n\n";
        cout<<"\n\n";
        outfile<<"目前总分："<<"  ";
        cout<<"目前总分："<<"  ";
        for(int k=0;k<10;k++)
        {
            for(int l=0;l<=i;l++)
            {
                sum+=all_score[l][k];
            }
            outfile<<name[k]<<" :"<<sum<<"  ";
            cout<<name[k]<<" :"<<sum<<"  ";
            sum=0;
        }
        outfile<<"\n\n";
        cout<<"\n\n";
    }
    outfile.close();
    return 0;
}
int sum()
{
    static bool seeded=false;
    if (!seeded) 
    {
        srand((unsigned int)time(NULL));
        seeded = true;
    }
    int ball[20]={0};
    int score[10]={0};
    int all_score[10][10]={0};
    int num1=0,num2=0,sum=0;
    for(int x=0;x<10;x++)
    {
        for(int i=0;i<9;i++)
        {
            num1=0+rand()%10;
            if(i==0)
            {
                ball[0]=num1;
                if(num1!=10)
                {
                    num2=0+rand()%num1;
                    ball[1]=num2;
                }
                else
                {
                    ball[1]=0;
                }
            }
            else
            {
                if(num1!=10)
                {
                    num2=0+rand()%(10-num1);
                    ball[i*2]=num1;
                    ball[i*2+1]=num2;
                }
                else
                {
                    ball[i*2]=10;
                    ball[i*2+1]=0;
                }
            }
        }
        ball[17]=0+rand()%10;
        if(ball[17]==10)
        {
            ball[18]=0;
            ball[19]=0+rand()%10;
            ball[20]=0+rand()%10;
            score[9]=ball[17]+ball[18]+ball[19]+ball[20];
        }
        else
        {
            ball[18]=0+rand()%(10-ball[17]);
            if(ball[17]+ball[18]==10)
            {
                ball[19]=0+rand()%10;
                score[9]=ball[17]+ball[18]+ball[19];
            }
            else
            {
                score[9]=ball[17]+ball[18];
            }
        }
        for(int j=0;j<9;j++)        
        {
            if(j==0)
            {
                if(ball[0]!=10 && ball[0]+ball[1]!=10)
                {
                    score[0]=ball[0]+ball[1];
                }
                else if(ball[0]!=10 && ball[0]+ball[1]==10)
                {
                    score[0]=ball[0]+ball[1]+ball[2];
                }
                else if(ball[0]==10)
                {
                    if(ball[2]!=10)
                    {
                    score[0]=ball[0]+ball[1]+ball[2]+ball[3];
                    }
                    else
                    {
                        score[0]=ball[0]+ball[1]+ball[2]+ball[3]+ball[4];
                    }
                }
            }
            else
            {
                if(ball[j*2]!=10 && ball[j*2]+ball[j*2+1]!=10)
                {
                    score[j]=ball[j*2]+ball[j*2+1];
                }
                else if(ball[j*2]!=10 && ball[j*2]+ball[j*2+1]==10)
                {
                    score[j]=ball[j*2]+ball[j*2+1]+ball[j*2+2];
                }
                else if(ball[j*2]==10)
                {
                    if(ball[j*2+2]!=10)
                    {
                        score[j]=ball[j*2]+ball[j*2+1]+ball[j*2+2]+ball[j*2+3];
                    }
                    else
                    {
                        score[j]=ball[j*2]+ball[j*2+1]+ball[j*2+2]+ball[j*2+3]+ball[j*2+4];
                    }
                }
            }
        }
        for(int l=0;l<10;l++)
        {
            all_score[l][x]=score[l];
        }
    }
    write_file(all_score);
    sort(all_score);
    return 0;
}
int main()
{
    int summary[9];
    int num1=0,num2=0;
    char name[10]={'a','b','c','d','e','f','g','h','i','j'};
    char middle[2]={};
    sum();
    system("pause");
}
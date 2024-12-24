#include<iostream>
#include<cstring>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;
int all_score[10][10]={0};
int summary[10]={0};
class Player
{
public:
    vector<pair<int,pair<string,int>>> pl;
};
int summary_score()
{
    int sum;
    for(int i=0;i<10;i++)
    {
        for(int l=0;l<10;l++)
        {
            sum+=all_score[l][i];
        }
        summary[i]=sum;
        sum=0;
    }
    return 0;
}
int sort(vector<pair<int,pair<string,int>>> pl)
{
    string mid;
    int s_summary[10]={0};
    string s_name[10];
    int num1=0,sum=0;
    for(int i=0;i<10;i++)
    {
        s_summary[i]=pl[i].second.second;
        s_name[i]=pl[i].second.first;
    }
    for(int j=0;j<10;j++)
    {
        for(int k=0;k<10;k++)
        {
           if(s_summary[k]<=s_summary[j])
           {
               num1=s_summary[k];
               mid=s_name[k];
               s_summary[k]=s_summary[j];
               s_name[k]=s_name[j];
               s_summary[j]=num1;
               s_name[j]=mid;
           }
        }
    }
    ofstream outfile;
    outfile.open("score.txt",ios::app);
    outfile<<"排名\n";
    cout<<"排名\n";
    for(int m=0;m<10;m++)
    {
        outfile<<s_name[m]<<" : "<<s_summary[m]<<"  ";
        cout<<s_name[m]<<" : "<<s_summary[m]<<"  ";
    }
    outfile<<"\n\n";
    cout<<"\n\n";
    outfile.close();
    return 0;
}
int write_file(vector<pair<int,pair<string,int>>> pl)
{
    int sum;
    string name[10];
    for(int i=0;i<10;i++)
    {
        name[i]=pl[i].second.first;
    }
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
    return 0;
}
int main()
{
    Player player;
    string player_name;
    int num1=0,num2=0,choice1;
    char name[10]={'A','B','C','D','E','F','G','H','I','J'};
    while(true)
    {
        cout<<"是否自定义运动员名字？(1:自定义/2:使用默认字母代替)\n"
            <<"请输入您的选择：";
        cin>>choice1;
        if(choice1==2)
        {
            sum();
            summary_score();
            for(int i=0;i<10;i++)
            {
                player.pl.push_back(make_pair(i,make_pair(string(1,name[i]),summary[i])));
            }
            write_file(player.pl);
            sort(player.pl);
            break;
        }
        else if(choice1==1)
        {
            sum();
            summary_score();
            for(int k=0;k<10;k++)
            {
                cout<<"请输入第"<<k+1<<"个运动员的名字：";
                cin>>player_name;
                player.pl.push_back(make_pair(k,make_pair(player_name,summary[k])));
            }
            write_file(player.pl);
            sort(player.pl);
            break;
        }
        else
        {
            cout<<"输入错误，请重新输入！\n";   
            continue;
        }
    }
    system("pause");
    return 0;
}
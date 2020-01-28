#include<bits/stdc++.h>
#define forl(i,n) for(int i=0;i<(int)n;i++)
#define pb(x) push_back(int x)
#define lld long long int
#define pii pair<int,int>
#define mem(x,y) memset(x,y,sizeof(x))
#define INF 1<<28
#define si(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define sc(a) scanf("%ch",&a)
#define print(a) printf("%d\n",a)
using namespace std;

int hashh (string word)
{
    int result = 0;
    for(int i = 0; i <word.length(); ++i) {
        result += word[i] * pow(2, i);
    }
    return result%20;
}


class symbolinfo
{
public:
    string name,type;
    symbolinfo* next;
};

class symboltable
{
public:
    symbolinfo *lst[20];
    int  lookup(symbolinfo sinfo);
    void insertt(symbolinfo sinfo);
    void dump();
};

int symboltable::lookup(symbolinfo sinfo)
{
    cout<<"lookup->"<<endl;
    string name;
    name=sinfo.name;
    int index=hashh(name);
    symbolinfo *head=lst[index];
    //cout<<index<<endl;
    while(head!=NULL)
    {
        if(name==head->name)return 1;
        else head=head->next;
    }
    return 2;
}

void symboltable::insertt(symbolinfo sinfo)
{
    cout<<"insert->"<<endl;
    string name;
    name=sinfo.name;
    int index=hashh(name);
    symbolinfo* temp=new symbolinfo;
    temp->name=sinfo.name;
    temp->type=sinfo.type;
    temp->next=lst[index];
    lst[index]=temp;
}

void symboltable::dump()
{
    cout<<"dump->"<<endl;
    forl(i,20)
    {
        cout<<i<<"->";
        symbolinfo *head=lst[i];
        while(head!=NULL)
        {
            cout<<head->name<<","<<head->type<<"->";
            head=head->next;
        }
        cout<<endl;
    }
}

int main()
{
    symboltable table;
    forl(i,20)
    {
        table.lst[i]=NULL;
    }
    forl(i,100)
    {
        string name,type,total;
        cin>>total;
        int j;
        for(j=0;j<total.length();j++)
        {
            if(total[j]==',')
            {
                break;
            }
        }
        name.append(total,0,j);
        type.append(total.begin()+j+1,total.end());
        symbolinfo sinfo;
        sinfo.name=name;
        sinfo.type=type;
        sinfo.next=NULL;

        int a=table.lookup(sinfo);
        if(a==1)
        {
            cout<<"Given symbol already exists in the symbol table!"<<endl;
        }
        else
        {
            table.insertt(sinfo);
        }
        table.dump();
    }

    return 0;
}





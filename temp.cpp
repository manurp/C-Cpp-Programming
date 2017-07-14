#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int n,q;
    vector<string> v1;
    vector<string> v2;
    vector<string> v3;
    string str;
    cin>>n>>q;

    for(int i=0;i<=n;i++)
    {
        getline(cin,str);
        v1.push_back(str);
    }

    for(int i=0;i<q;i++)
    {
        getline(cin,str);
        v2.push_back(str);
    }

    for(int i=1;i<=n;i++)
    {
        if(v1[i][1]=='t')
        {
            string s = v1[i].substr(1,4);
            int found=v1[i].find(' ');
            int f=v1[i].find(' ',found+1);
            int dq1=v1[i].find('"');
            int dq2=v1[i].find('"',dq1+1);
           // int i=1;
            while(found !=-1 && f !=-1)
            {
                s=s+"~"+v1[i].substr(found+1,f-found-1);
                v3.push_back(s);
                v3.push_back(v1[i].substr(dq1+1,dq2-dq1-1));
                found=v1[i].find(' ',f+3);
                f=v1[i].find(' ',found+1);
                dq1=v1[i].find('"',dq2+1);
                dq2=v1[i].find('"',dq1+1);
                //cout<<found<<" "<<f<<endl;
                //cout<<s<<endl;
                s=v1[i].substr(1,4);
               // i++;
            }
        }
    }
   /* cout<<endl;

      for(unsigned int i=0;i<v3.size();i++)
    {
        cout<<v3[i]<<endl;
    }
    cout<<endl;*/
vector<string> v4;
    for(int i=1;i<=n;i++)
    {
        //int j=i;
        if(v1[i][1]=='t')
        {
            string s=v1[i].substr(1,4);
           // int j=i;

            //string strm=s;
            string next=v1[++i].substr(1,4);

            while(next[0]!='/')
            {
                cout<<next<<"\n ";

                s=s+"."+next.substr(0,4);
                next=v1[++i].substr(1,6);
                if((next[0]=='/' && next[4]!=s[3])||next[5]=='0')
                {
                    v4.push_back(s);
                    s=s.substr(0,s.length()-5);
                    next=v1[++i].substr(1,6);
                }
            }
            v4.push_back(s);
              }
    }
    for(unsigned int i=0;i<v4.size();i++)
    {
        cout<<v4[i]<<endl;
    }
    for(int la =0;la<q;la++)
    {
        unsigned int i;
        string ans;
        bool status=false;
        bool status1=true;

        string querry = v2[la];
        //if(v3[la][0]!='t')
          //  continue;
        //cout<<endl<<querry<<" "<<la<<endl;
        string q1 = querry.substr(querry.find('~')-4,querry.length()+4-querry.find('~'));
        string q2 = querry.substr(0,querry.find('~'));
        //cout<<endl<<q1<<"\t"<<q2;
        for(unsigned int j=0;j<v4.size();j++)
        {

            int qf = v4[j].find(q2);
           // cout<<j<<endl;
            if(qf==-1)
                status=false;
            else{
                status=true;
                break;
            }
        }

        for(i=0;i<v3.size();i++)
        {
            if(v3[i]==q1){
                status1=true;
                break;
            }
            if(i==(v3.size()-2))
            {
                status1=false;
            }
        }



        if(status&&status1){
            cout<<v3[i+1]<<endl;
        }
        else
            cout<<"Not Found!"<<endl;
    }
   // cout<<endl<<endl;

  /*  for(int i=1;i<=n;i++)
    {
        cout<<v1[i]<<endl;
    }

    for(int i=0;i<q;i++)
    {
        cout<<v2[i]<<endl;
    }

    for(unsigned int i=0;i<v4.size();i++)
    {
        cout<<v4[i]<<endl;
    }
*/
return 0;
}

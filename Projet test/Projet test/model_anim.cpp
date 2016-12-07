#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

string end_int(string s);
string sub(string s,string s1,string text);
bool replace(string fn,string s,string s1);
void splitlast(string s,string cs,string *av,string *ap);
string get_basename(string s);

int main(int argc, char *argv[])
{
    string mtl_name="";
    char c=0;

    cout<<"Nom du mtl (sans .mtl) : ";
    while(c!=EOF&&c!='\n')
    {
        c=getchar();
        mtl_name+=c;
    }
    mtl_name=mtl_name.substr(0,mtl_name.size()-1)+string(".mtl");

    for(int i=1;i<argc;i++)
    {
        string parts[2],fn;

        splitlast(argv[i],".",&parts[0],&parts[1]);
        fn=end_int(parts[0])+string(".")+parts[1];

        replace(argv[i],get_basename(parts[0])+string(".mtl"),mtl_name);

        rename(argv[i],fn.c_str());

        cout<<get_basename(argv[i])<<string(" > ")<<get_basename(fn)<<endl;
    }
    cout<<"Modifications terminees."<<endl<<"Appuyez sur entree pour quitter...";
    getchar();
    return EXIT_SUCCESS;
}

string end_int(string s)
{
    unsigned int i;
    string name,number;
    splitlast(s,"_",&name,&number);
    name+=string("_");
    for(i=0;i<number.size();i++)
        if(number[i]!='0')
            break;
    return name+number.substr(i);
}
string sub(string s,string s1,string text)
{
    for(int i=0;i<(int)text.size();i++)
    {
        i=text.find(s,i);
        if(i==-1)
            break;
        text.replace(i,s.size(),s1);
    }
    return text;
}
bool replace(string fn,string s,string s1)
{
    string content="";
    ifstream fichier(fn.c_str(),ios::in);
    if(fichier)
    {
        string ligne;
        while(getline(fichier,ligne))
            content+=ligne+string("\n");
        fichier.close();

        ofstream fichier1(fn.c_str(),ios::out|ios::trunc);
        fichier1<<sub(s,s1,content);
        fichier1.close();
        return true;
    }
    return false;
}
void splitlast(string s,string cs,string *av,string *ap)
{
    unsigned int i;
    bool ok=false;
    for(i=s.size()-1;i>=0&&!ok;i--)
        for(unsigned int j=0;j<cs.size();j++)
            if(s[i]==cs[j])
            {
                ok=true;
                break;
            }
    if(av)
        *av=s.substr(0,i+1);
    if(ap)
        *ap=s.substr(i+2);
}
string get_basename(string s)
{
    string ret;
    splitlast(s,"\\/",NULL,&ret);
    return ret;
}

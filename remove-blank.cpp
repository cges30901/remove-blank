#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc,char* argv[])
{
    ifstream inFile(argv[1]);
    ofstream outFile(strcat(argv[1],".new"));
    while( !inFile.eof())
    {
        string str;
        getline(inFile,str);

        //remove space at the beginning of a line
        while(str.length()>0)
        {
            if(str[0]==' ')
            {
                str.erase(0,1);
            }
            else if(str.find("　")==0)
            {
                str.erase(0,3);
            }
            else break;
        }

        //remove space at the end of a line
        while(str.length()>0)
        {
            if(str[str.length()-1]==' ')
            {
                str.erase(str.length()-1,1);
            }
            else break;
        }

        //skip empty line
        if(str.length()!=0)
        {
            outFile<<str<<endl;
        }
    }
    return 0;
}

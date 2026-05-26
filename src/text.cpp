#include "text.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;


void writetext(const string& text, int speed,int mx)
{
    int i=0,start=0;
    while (i<(int) text.size())
    {
        int sfarsit=i;
        while (sfarsit<(int) text.size() && text[sfarsit]!=' ' && text[sfarsit]!='\n')
        {
            sfarsit++;
        }
        int l=sfarsit-i;
        if (start+l>mx && start>0)
        {
            cout<<"\n";
            start=0;
        }
        while (i<sfarsit)
        {
            cout<<text[i];
            start++;
            i++;
            this_thread::sleep_for(chrono::milliseconds(speed));
        }
        while (i<(int) text.size() && (text[i]==' ' || text[i]=='\n'))
        {
            cout<<text[i];
            if (text[i]=='\n')
            {
                start=0;
            }
            else
            {
                start++;
            }
            i++;
            this_thread::sleep_for(chrono::milliseconds(speed));
        }
    }
    cout<<"\n";
}
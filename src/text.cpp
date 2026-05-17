#include "text.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;


void writetext(const string& text, int speed)
{
    for (char c : text)
    {
        cout<<c;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
    cout<<"\n";
}
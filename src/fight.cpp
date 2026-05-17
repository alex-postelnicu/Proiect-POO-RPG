#include "fight.h"
#include "colors.h"
#include "text.h"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Fight& Fight::getinstance()
{
    static Fight instance;
    return instance;
}

bool Fight::battle(Player& p, Enemy& e)
{
    cout<<RED;
    writetext("You close your eyes and suddenly you find yourself in an empty void, all alone, only with your thoughts to keep you company");
    cout<<"\n";
    writetext("Your surroundings distort and a manifestation appears in front of you:");
    cout<<"\n";
    writetext(">> "+e.getname()+" <<");
    cout<<"\n";
    writetext("Your pulse races and you begin the fight.");
    cout<<"\n\n";
    cout<<WHITE;

    deque<string>message_hit={
        "Your attack lands with incredible force, leaving "+e.getname()+" visibly weakened.",
        "You lunge forward and attack "+e.getname()+".",
        "You slash at "+e.getname()+" and catch a glimpse of reality, as their form slightly destabilizes."
    };

    deque<string>message_kill={
        "Your final strike shatters the illusion completely. "+e.getname()+" breaks into a thousand shards and vanishes.",
        "With a final burst of courage and determination, you crush "+e.getname()+", leaving nothing but a faint echo of panic.",
        "A deep silence follows your final strike. "+e.getname()+" slowly disappears, as though they never never existed at all."
    };

    deque<string>message_takedmg={
        e.getname()+" whispers your deepest failures. You stand helpless and take the full impact of their attack.",
        e.getname()+" unleashes a barrage of attacks. Your vision blurs as panic takes over.",
        "Your balance breaks, as "+e.getname()+" strikes from the shadows."
    };

    int option;
    p+=p.getmaxhp();
    e+=e.getmaxhp();
    while (p.alive() && e.alive())
    {
        cout<<"+--------------+\n";
        cout<<"| [1] Check    |\n";
        cout<<"| [2] Attack   |\n";
        cout<<"| [3] Defend   |\n";
        cout<<"| [4] Backpack |\n";
        cout<<"+--------------+\n";
        cin>>option;

        p.stopdefending();
        try
        {
            random_device rd;
            mt19937 g(rd());
            switch (option)
            {
                case 1:
                    cout<<p;
                    cout<<e;
                    break;

                case 2:
                    p.dodmg(e);
                    if (e.alive())
                    {
                        //enemy survives
                        shuffle(message_hit.begin(), message_hit.end(), g);
                        writetext(message_hit.front());
                        cout<<YELLOW;
                        cout<<"("<<to_string(p.getdmg())<<" DMG)"<<"\n";
                        cout<<WHITE;

                        if (e<p && g()%2==0)
                        {
                            //special attack
                            e.special(p);
                            writetext(e.getname()+" unleashes a desperate attack.");
                            cout<<RED;
                            cout<<"(-"<<to_string(e.getdmg()*150/100)<<" HP"<<"\n";
                            cout<<WHITE;
                        }
                        else
                        {
                            //normal attack
                            e.dodmg(p);
                            mt19937 g(rd());
                            shuffle(message_takedmg.begin(), message_takedmg.end(), g);
                            writetext(message_takedmg.front());
                            cout<<RED;
                            cout<<"(-"<<to_string(e.getdmg())<<" HP"<<"\n";
                            cout<<WHITE;
                        }
                    }
                    else
                    {
                        //enemy dies
                        shuffle(message_kill.begin(), message_kill.end(), g);
                        writetext(message_kill.front());
                        cout<<YELLOW;
                        cout<<"("<<to_string(p.getdmg())<<" DMG)"<<"\n";
                        cout<<WHITE;
                    }
                    break;

                case 3:
                    p.startdefending();
                    cout<<CYAN;
                    writetext("You clear your mind and prepare for the next attack.");
                    cout<<WHITE;
                    if (e<p && g()%2==0)
                    {
                        //special attack
                        e.special(p);
                        writetext(e.getname()+" unleashes a powerful attack.");
                        cout<<RED;
                        cout<<"(-"<<to_string(e.getdmg()*150/100)<<" HP"<<"\n";
                        cout<<WHITE;
                    }
                    else
                    {
                        //normal attack
                        e.dodmg(p);
                        mt19937 g(rd());
                        shuffle(message_takedmg.begin(), message_takedmg.end(), g);
                        writetext(message_takedmg.front());
                        cout<<RED;
                        cout<<"(-"<<to_string(e.getdmg())<<" HP"<<"\n";
                        cout<<WHITE;
                    }
                    break;

                case 4:
                    p.open_inv();
                    int slot;
                    cin>>slot;
                    p.use_item(slot);
                    break;
                
                default:
                    cout<<RED;
                    cout<<"Invalid option!\n";
                    cout<<WHITE;
            }
        }
        catch (const exception& exc)
        {
            cout<<RED;
            cout<<exc.what();
            cout<<WHITE;
            cout<<"\n";
        }
    }

    if (!p.alive())
    {
        cout<<RED;
        writetext("Your mind collapses under the weight of your thoughts...");
        cout<<"\n";
        cout<<WHITE;
        return false;
    }

    cout<<GREEN;
    writetext("You defeated the manifestation of "+e.getname()+". Reality begins to stabilize as you return to the real world...");
    cout<<WHITE;
    return true;
}
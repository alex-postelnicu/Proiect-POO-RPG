#include "colors.h"
#include "consumable.h"
#include "enemy_factory.h"
#include "enemy.h"
#include "entity.h"
#include "exceptions.h"
#include "fight.h"
#include "inventory.h"
#include "item.h"
#include "player.h"
#include "text.h"
#include "weapon.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{

    Player player("You", 100, 10);
    Enemy_Factory factory;

    int option;
    bool ok,win;
    
    ok=false;
    while (!ok)
    {
        cout<<"[1] Start Game\n";
        cout<<"[2] End Game\n";
        cin>>option;
        switch (option)
        {
            case 1:
            {
                ok=true;
                //start game
                writetext("The alarm buzzes. It's 10 AM. You stare at the ceiling, feeling a sharp twist of dread in your stomach. Today isn't just another monotonous day. Afer dozens of ignored and rejected applications at other jobs, today is your interview for a post at the cinema. You need to get out of your house but the world feels judgemental and terrifying.");
                cout<<"\n";
                ok=false;
                while (!ok)
                {
                    writetext("How will you start your day?");
                    cout<<"\n";
                    cout<<"[1] Check your phone\n";
                    cout<<"[2] Lie there and gather your thoughts\n";
                    cout<<"[3] Force yourself out of bed\n";
                    cin>>option;
                    switch (option)
                    {
                        case 1:
                        {
                            ok=true;
                            writetext("Your screen is empty, no messages. You take your phone with you.");
                            cout<<"\n";
                            writetext("Obtained [Phone] (Weapon, +7 DMG)");
                            cout<<"\n";
                            player.take_item(new Weapon("Phone (+7 DMG)", 7));
                            break;
                        }

                        case 2:
                        {
                            ok=true;
                            writetext("You stare at the ceiling and think about what could possibly happen today. You decide to write your thoughts in your journal.");
                            cout<<"\n";
                            writetext("Obtained [Personal Journal] (Weapon, +5 DMG)");
                            cout<<"\n";
                            player.take_item(new Weapon("Personal Journal (+5 DMG)", 5));
                            break;
                        }

                        case 3:
                        {
                            ok=true;
                            writetext("With a slight sense of motivation, you get out of bed. You look out the window and notice it's cloudy today. You take your umbrella in case it rains. You must be prepared for anything, especially today.");
                            cout<<"\n";
                            writetext("Obtained [Umbrella] (Weapon, +10 DMG)");
                            cout<<"\n";
                            player.take_item(new Weapon("Umbrella (+10 DMG)", 10));
                            break;
                        }

                        default:
                        {
                            cout<<RED;
                            cout<<"Please input a valid number!\n";
                            cout<<WHITE;
                        }
                    }
                }

                writetext("You try your best to try your best, get ready, equip your backpack and leave the house. Others have their paths to take, and I have my own. Feeling tired, you decide to get some coffee to give you some energy. You step into a cafe. The queue seems endless. While waiting, you think to yourself: \"Did I remember to lock the door when I left?\". When you finally reach the register, you stutter while ordering. The barista sighs loudly and rolls her eyes. The noise of the coffee machines drown your thoughts completely and panic begins to set in.");
                cout<<"\n";

                //barista fight
                win=false;
                Enemy* barista=factory.create_enemy("Barista");
                while (!win)
                {
                    win=Fight::getinstance().battle(player, *barista);
                    if (!win)
                    {
                        writetext("Do you want to try again?");
                        cout<<"\n";
                        cout<<"[1] Yes\n";
                        cout<<"[2] No\n";
                        cin>>option;
                        ok=false;
                        while (!ok)
                        {
                            switch (option)
                            {
                                case 1:
                                {
                                    ok=true;
                                    writetext("You decide to not give up and prove yourself that you can achieve what set out to do.");
                                    cout<<"\n";
                                    break;
                                }

                                case 2:
                                {
                                    ok=true;
                                    cout<<RED;
                                    writetext("You let panic consume you. You turn around and flee home, not being strong enough to face the unknown...");
                                    cout<<"\n";
                                    writetext("GAME OVER");
                                    cout<<"\n";
                                    cout<<WHITE;
                                    cout<<"\n";
                                    delete barista;
                                    return 0;
                                }
                            
                                default:
                                {
                                    cout<<RED;
                                    cout<<"Please input a valid number!\n";
                                    cout<<WHITE;
                                }
                            }
                        }
                    }
                }
                delete barista;
                writetext("[Barista]: \"Sorry for the wait, our system crashed. Here is your cup of coffee. Have a nice day!\"");
                cout<<"\n";
                writetext("Obtained [Matcha Latte] (Consumable, +15 HP)");
                cout<<"\n";
                player.take_item(new Consumable("Matcha Latte (+15 HP)",15));

                writetext("With the coffee in your hand, you leave the cafe and think about the pressing matter of the interview that is in a few hours. To kill some time, you decide to go to the gym, hoping that this will get you in a better mood to be prepared for later.");
                cout<<"\n";
                writetext("The moment you open the gym door, you are met with the sound of heavy weights being dropped, loud music and a lot of fit people working out. You slowly walk to the dumbells corner, feeling incredibly small and out of place. You pick up two dumbells, but as you lift them, a familiar yet unsettling feeling rises inside of you:");
                cout<<"\n";
                writetext("\"Everyone is staring and judging you! They know you don't belong here! Just look at how bad your form is!\", your mind whispers.");
                cout<<"\n";
                writetext("Suddenly, you see the gym coach approaching you, menacingly. He's shouting something while pointing at you, but you can't quite make sense of it because of the loud music. Your vision begins to blur and panic begins to take over you.");
                cout<<"\n";

                //coach fight
                win=false;
                Enemy* coach=factory.create_enemy("Coach");
                while (!win)
                {
                    win=Fight::getinstance().battle(player, *coach);
                    if (!win)
                    {
                        writetext("Do you want to try again?");
                        cout<<"\n";
                        cout<<"[1] Yes\n";
                        cout<<"[2] No\n";
                        cin>>option;
                        ok=false;
                        while (!ok)
                        {
                            switch (option)
                            {
                                case 1:
                                {
                                    ok=true;
                                    writetext("You decide to not give up and prove yourself that you can achieve what set out to do.");
                                    cout<<"\n";
                                    break;
                                }

                                case 2:
                                {
                                    ok=true;
                                    cout<<RED;
                                    writetext("You let panic consume you. You turn around and flee home, not being strong enough to face the unknown...");
                                    cout<<"\n";
                                    writetext("GAME OVER");
                                    cout<<"\n";
                                    cout<<WHITE;
                                    cout<<"\n";
                                    delete coach;
                                    return 0;
                                }
                            
                                default:
                                {
                                    cout<<RED;
                                    cout<<"Please input a valid number!\n";
                                    cout<<WHITE;
                                }
                            }
                        }
                    }
                }
                delete coach;
                writetext("You take a deep breath and see the coach standing in front of you, but not with any bad intentions, only with genuine concern.");
                cout<<"\n";
                writetext("[Coach]: \"Hey, take it easy! I saw you lifting from across the gym. You're going to seriously injure yourself with that form. Here, let me show you...");
                cout<<"\n";
                writetext("You take his advice and you are glad he wasn't judging you, he just wanted to make sure you didn't hurt yourself. A wave of relief washes over you.");
                cout<<"\n";
                writetext("[Coach]: \"You look a bit exhausted and pale. Here, take this... It'll give you a boost of energy. Have a good workout!\"");
                cout<<"\n";
                writetext("Obtained [Energy Drink] (Consumable, +20 HP)");
                cout<<"\n";
                player.take_item(new Consumable("Energy Drink (+20 HP)",20));

                writetext("You leave the gym with a sense of accomplishment and a bit of confidence. Unfortunately, these good feelings slowly fade away as you head towards the cinema for the job interview. With every step closer, scary thoughts come forward as the unknown draws near.");
                cout<<"\n";
                writetext("\"What if I am not good enough for this job? What if I freeze after a question? What if they see right through my fake confidence and realize what a failure I am?\" you think to yourself.");
                cout<<"\n";
                writetext("After what felt like an eternity and endless scenarios played in your head, you finally arrive. You walk inside and approach the front desk at the cinema. You tell the employee working there you are here for the job interview and he points you toward the hallway leading to the manager's office.");
                cout<<"\n";
                writetext("You are standing right outside the manager's office door. You gather your courage and step inside. You see the manager sitting at a table, silently reading your resume. After what feels like forever, he looks up directly at you and the room begins to distort into a dark void. You must confront your fear of failure.");
                cout<<"\n";

                //manager fight
                win=false;
                Enemy* manager=factory.create_enemy("Manager");
                while (!win)
                {
                    win=Fight::getinstance().battle(player, *manager);
                    if (!win)
                    {
                        writetext("Do you want to try again?");
                        cout<<"\n";
                        cout<<"[1] Yes\n";
                        cout<<"[2] No\n";
                        cin>>option;
                        ok=false;
                        while (!ok)
                        {
                            switch (option)
                            {
                                case 1:
                                {
                                    ok=true;
                                    writetext("You decide to not give up and prove yourself that you can achieve what set out to do.");
                                    cout<<"\n";
                                    break;
                                }

                                case 2:
                                {
                                    ok=true;
                                    cout<<RED;
                                    writetext("You let panic consume you. You turn around and flee home, not being strong enough to face the unknown...");
                                    cout<<"\n";
                                    writetext("GAME OVER");
                                    cout<<"\n";
                                    cout<<WHITE;
                                    cout<<"\n";
                                    delete manager;
                                    return 0;
                                }
                            
                                default:
                                {
                                    cout<<RED;
                                    cout<<"Please input a valid number!\n";
                                    cout<<WHITE;
                                }
                            }
                        }
                    }
                }
                delete manager;
                writetext("You take a deep breath and see the room returning to normal. The manager's look softens and glares calmly at you.");
                cout<<"\n";
                writetext("[Manager]: \"Well, you were a little bit nervous at first, but I have to say I'm impressed. You didn't give up and you handled my tough questions really well. That's what we are looking for in people working at this cinema: focus and resilience, especially on busy weekend days. You got the job, we can start training next week. What do you say?\"");
                cout<<"\n";
                writetext("You immediately accept and feel the pressure that has been persistent all day finally lift up, replaced by a sense of accomplishment. Today you proved yourself that you are much stronger than you consider yourself to be.");
                cout<<"\n\n\n";
                writetext("You conquered your anxiety, passed the interview and got the job! But now... will you finally be happy? Will the feeling of accomplishment be enough?");
                ok=true;
                break;
            }
            case 2:
            {
                ok=true;
                return 0;
                break;
            }
            default:
            {
                cout<<RED;
                cout<<"Please input a valid number!\n";
                cout<<WHITE;
            }
        }
    }
    
    return 0;
}

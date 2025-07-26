#include <iostream>
#include <string>

using namespace std;

int Room_navigation(int currentRoom);

bool Item_pick_up(int room, int itemIndex);

void Inspect_inventory();

const int room_count = 4;
const int inventory_size = 8;

int Unlock_room(int currentRoom, int connections[][room_count]);

// 1 = connected, while 0 = inaccessible.
int connections[room_count][room_count] = {
    {0, 0, 0, 0},  // Main entrance
    {0, 0, 0, 0},  // Ruined room
    {1, 1, 0, 1},  // Flower room
    {1, 0, 0, 0}   // Mirror room
};

int Room_number;    // Important for the unlock rooms function, line (23 - 24)
int Room_door;

string roomItems[room_count][3] =
{
    {"Burning candle", "Nora", "Small notebook"},
    {"Cast iron blueprint", "Crucible", "Heavy steel cube"},
    {"Mcguffin", "", ""},
    {"", "", ""}
};

bool itemTaken[room_count][3] =
{
    {false, false, false},
    {false, false, false},
    {false, false, false},
    {false, false, false}
};

int Available_slots[inventory_size] = { 0 };
string Inventory[inventory_size];

int main() // begins both the start and the end of the game, once the player reaches room: 5, which isn't really a room.
{
    /*
        Room 1: Main entrance
        Room 2: Ruined room
        Room 3: Flower room
        Room 4: Mirror room
    */
    int currentRoom = 1;


    cout << "You find yourself overlooking a tall stone tower. With the sun beaming behind about a few hours till sunset,\n"
        << "You know that this is the place you were searching for all these year. For as long as you can remember, \n"
        << "You were searching for a place that is called the mirror dimension.\n"
        << "From what the stories told, it is said to be the gateway between the real world and the spaces beyond.\n"
        << "Some say it is the perfect training ground for fighting any opponent,\n"
        << "While others say, you can manifest any object in your hand, just by thinking about it.\n"
        << "As someone who wishes to unearth the secrets that this world holds, this mirror dimension has caught your attention the most.\n And now you are here to unearth the secrets behind this dreamlike dimension." << endl;

    cout << "You know that the only way to access this dimension is to take on the challenges this tower holds, then reach the top to enter it's portal.\n"
        << "With this in mind, you enter the tower and begin the long climb." << endl;

    while (currentRoom != 5)
    {
        currentRoom = Room_navigation(currentRoom);
    }

    int Player_input;
    int Final_ending;

    cout << "You go through the mirror just like they did, feeling slightly disoriented as your body makes it to the other side.\n"
        << "You find yourself in a vast open space, where the floor of this \"room\" are made of clear tranquil waters, still as glass itself.\n"
        << "Your footsteps are able to touch the surface without sinking inwards, instead sending small ripples from each step you take.\n"
        << "If this is the mirror dimension, the you should be able to manifest whatever your thinking about into this vast empty space that streches on forever.\n"
        << "But what should your first thought be?" << endl;

    while (Player_input != 1 && Player_input != 2 && Player_input != 3)
    {
        cout << "[1] Think about a simple object, [2] Believe you can fly, [3] Manifest large structures" << endl;
        cin >> Player_input;

        switch (Player_input)
        {


        case 1: cout << "You think about the first everyday object that comes to mind, and all of a sudden, you look down at your right hand.\n"
            << "A plain red apple, it feels like an apple, but you know for a fact that you weren't carrying an apple before.\n"
            << "You start to experiment, you make yourself believe that the apple is a spoon. Almost instantly it does in fact become a spoon.\n"
            << "You experiment even further, a broom with fire on it's end, a trident that comes back to your hands when you throw it, a weighted sandbag that floats, and many more as you continue to test the very properties that each manifested object entitles.\n"
            << "You keep thinking that the object your creating acts the way you know it usually does, or usually doesn't. It's incredible, with how many combinations you could try out with no limitations." << endl;
            break;
        case 2: cout << "With the very thought of being able to fly in this place, you hover above the ground.\n"
            << "You felt a hint of excitement and decide to fly upwards a certain amount. Then you stop think about flying, then you start to fall back to the floor.\n"
            << "Before you get the chance to land, you think yourself into not falling down, inches away from the floor.\n"
            << "As soon as the adrenaline in your vein seizes, you begin to test out different abilities that were normally impossible for you at first.\n"
            << "Element manipulation, regeneration, invisibility, no matter how abstract the ability looks like, as soon as your thinking you can do it, you are able to do it with ease." << endl;
            break;
        case 3: cout << "You decided to make a common building to start, or rather think of a common building to start.\n"
            << "You thought of a small house, and before you can blink, it's there. Right in front of you.\n"
            << "It's simplistic exterior, just as inviting as you thought about it. It's interior just as inviting, that you almost forgot that it is here because your thinking about it.\n"
            << "You close your eyes and think about being in a fighting dojo, sure enough you find yourself in one as soon as your eyes open.\n"
            << "You keep blinking to ensure your changing where you think you are. A large castle, a deep underground prison, and underwater city, a hellish fortress.\n"
            << "Each time you think you are there, it is right in front of you. Your lucky that your still remembering that you are in the mirror dimension." << endl;
            break;
        default: cout << "It is a hard decision to think about something, I mean the list goes on with how much you could be thinking about. you don't know where to start!\n"
            << "You could be thinking about an easter egg, but that would be to easy. You continue to ponder." << endl;
        }
    }

    cout << "Time begins to pass, you continue to experiment with different thoughts that come to your head.\n"
        << "It has only been a few minutes or seconds, yet you aren't able to find any limitations to what you can and cannot do. It is the best space you could be in if you want to discover what your thinking about in more detail.\n"
        << "You have never felt this much euphoria just by make your thoughts apart of this place.\n"
        << "Yet, you realize something. If someone else were to come in this dimension who isn't here for discovery, but domination, you can only imagine what horrific events would take place if they took hold of an entire dimension to leak out into the real world.\n"
        << "But what could you possibly do, considering that doomsday scenario?" << endl;

    cout << "As you continue to ponder, Nora and Mcguffin float in front of you, a good distance away from them.\n"
        << "That's right, you almost forgotten that you weren't alone in this dimension. Do they have a solution?\n"
        << "Both orbs display different holographic images as soon as your thinking this.\n"
        << "Nora is showing a scenario where the whole world forget's that the mirror dimension ever exist's, including yourself.\n"
        << "While McGuffin is showing you a scenario where the entire tower, along with the only way to the mirror dimension, is protected by a barrier where no one can leave or enter. But this barrier needs you as it's catalyst.\n"
        << "You are shocked by these solutions that were presented. You don't want to forget about this amazing place, but are you willing to trap yourself here so no one could find it?\n"
        << "You don't know. For the first time in your life, you are conflicted by what is and is the right solution. What do you do? Is there even a way to save a potential apocalypse from happening, without it affecting yourself?" << endl;

    while (Final_ending != 1 && Final_ending != 2 && Final_ending != 3)
    {
        cout << "[1] Agree with Nora's plan, [2] Agree with McGuffin's plan, [3] Leave the mirror dimension alone" << endl;
        cin >> Final_ending;

        switch (Final_ending)
        {
        case 1: cout << "You decided that it's best to delay the inevitable, by making sure everyone forgets. You think that you can do whatever you think you can do here, right?\n"
            << "All you have to do is let Nora do the rest. You wave goodbye one last time to the two orbs, then believe that they can make you forget and send you back far away from the tower, before you first discovered it.\n"
            << "Both orbs spin around you on all sides, with Nora being the most bright it's ever been.\n"
            << "A large fog starts to overcome you, slowly but surely wiping away every last memory you have of the tower and this dimension."
            << "You collapse to the floor and everything faded to black." << endl;

            cout << "You wake up in a small room, laying on a small bed. Your not too sure how you got here, but maybe that's just from the many travels you've taken.\n";
            cout << "Before you fully wake up, a voice that you don't recognize speaks up. \"Are you awake?\"" << endl;
            break;
        case 2: cout << "It would be wrong to simply forget the truth that you hold so dear, but you also seem to acknowledge the severity of the situation.\n"
            << "Maybe trapping yourself here so others won't come in here, might just potentially save the world. With this in mind, you nod at McGuffin, telling him that you are willing to be the reason why the barrier will remain around the tower.\n"
            << "McGuffin hovers above you, glowing more brighter then it's ever been here, with Nora orbiting around McGuffin.\n"
            << "It shines a purple spotlight right on you, and the once stable watery ground beneath you starts to feel less and less solid as you start to sink.\n"
            << "Soon your entire body sink's fully into the water depths, and eventually you are truly alone in a black inky abyss.\n"
            << "You don't run out of air, as you are able to breath normally, but your consciousnous fades away.\n"
            << "All you have are the sounds of your own thoughts as you plunge ever deeper, reflecting on the life that you may never return too.\n"
            << "This is for the best, this is so no one will know what's in the tower. You fully fade being alone with your thoughts about this place. Unshared to anyone for all of enternity." << endl;
            break;
        case 3: cout << "Wait a minute, you don't have to do either of these things. You thought about where you entered this place from, it suddenly appears in front of you. It's wormhole like portal still open, surprising both Nora and McGuffin.\n"
            << "You know that this is an option, because the two orbs could potentially find a different solution, still concealing this towers presense, but ensures that no one knows where to look for the mirror dimensions gateway.\n"
            << "You exchange a knowing look to both of the sentient orbs and they appear to understand what is happening, they allow you to step through the portal.\n"
            << "As you pass the threshold, the gateway closes back up again. Allowing you to leave the entire tower behind for good.\n"
            << "You never wanted to do something extrodinary, you only wanted to understand the very mysteries that this tower holds.\n"
            << "As the happiness starts to creep in as you let go of a heavy responsibility befallen on you, some questions still came to mind.\n"
            << "Why is the mirror dimension hidden inside this tower? Who were the first people to ever discover it in the first place? You realize now, that you don't have to know all of the answers in one adventure.\n"
            << "For it is not about your final destination, but rather the experiences you made along the way. Whether it is good or bad, you realized that cherishing every instant is what makes exploring parts of life that much enjoyable.\n"
            << "You look back to the tower as it carefully conceals itself, which makes it seem as if there wasn't a tower at all anymore and thus closing the door to another chapter of your life.\n"
            << "Whatever may happen in the future, you trust that you, as well as the orbs that once followed you, will do their best to do the right thing.\n"
            << "You turn around and head on towards the sunset, ready for what comes your way." << endl;
            break;
        default: cout << "..." << endl;

        }
    }
    cout << "-----------------------------------------------" << endl;
    cout << "I would like to thank you for trying out this game for my assignment." << endl;
    cout << "I hope you enjoyed may first makings of this game. Let me know how I could of improved it." << endl;
    cout << "For now, I'll be sure to be ready for my next class. Until then, good day." << endl;

    // I'm always looking for future opportunities for improving my computer science skills over the summer.

    return 0;
}

int Room_navigation(int currentRoom)  // Almost every single choice that has been made in this game, including navigating between rooms. (lines: 182 - 600)
{
    int player_input;
    int player_event;

    if (currentRoom == 1)    // Choices for the main entrance (lines: 186 - 286).
    {
        cout << "Your in a room that is dimly lit. You can just make out the rustic interior,\n"
            << "where had you not seen the exterior, you would have mistaken this as a cabin in the woods." << endl;

        if (connections[0][1] == 0)
        {
            cout << "There are only a few things of note within this room. Which includes a plain wooden table on the left centered in the left corner,\n"
                << "along with a few soft bed cushions, strangely spread out, along the right side of the room.\n";
            cout << "Looking back on the travel experience you gained,\nyou know that this simple room is not all it seemed to be." << endl;
        }
        else if (connections[0][1] == 1)
        {
            cout << "As you assess your surroundings, you instantly recognize that this is the first room that you came in as you began your ascend up the tower.\n";
            cout << "The table, the buring torch, the door leading to the second floor, as well as the cushions that appeared to cushion your fall. \"So that is what the hatch is for!\" you thought to yourself\n "
                << "Almost immediatly the hatch closes. Although you just barely heard a small tink, coming from underneath the table.\n"
                << "Did you miss something in here when you first came in?" << endl;
        }

        while (currentRoom == 1)
        {
            cout << "[1] Check your bag, [2] Go through the wooden door, [3] Gaze above the cushions,\n[4] Examine the table, [5] Inspect the unlit torch" << endl;

            cin >> player_input;

            switch (player_input)
            {
            case 1: Inspect_inventory();
                break;
            case 2: if (connections[0][1] == 0)
            {
                cout << "You try the wooden door, but it's locked." << endl;
                break;
            }
                  else if (connections[0][1] == 1)
            {
                cout << "You make your way to the 2nd floor." << endl;
                currentRoom = 2;
                break;
            }
            case 3: cout << "You look up to see an metal hatch, with no handle.\n";
                cout << "Perhaps you can open it, when your further up the tower." << endl;
                break;
            case 4: if (connections[0][1] == 0)
            {
                cout << "You walk over towards the wooden table, admiring it's simplistic features.\n";
                cout << "On top of it is a candle that appears to be the only source of light in the room. Casting small dark shadows in a room where light is less apparent.\n"
                    << "For a moment, you feel at ease as you stare at the dancing flame that continues to maintain it's almost teardrop shape." << endl;
                Item_pick_up(0, 0);
            }
                  else if (connections[0][1] = 1 && connections[1][2] == 0)
            {
                cout << "You quickly made sure you didn't miss anything near the table. Sure enough, you didn't notice anything on the tabl. \nAdmiring the furninture, you turn you back to it." << endl;
            }
                  else if (connections[1][2] == 1)
            {
                cout << "You check underneath the table that once held the candle and your suspicion was proven correct, there was something you missed, just underneath this table.\n"
                    << "You reach down to pick up a plain glass orb seemingly inanimate. It almost looks like this orb is important, but you can't shake the feeling why.\n"
                    << "But then it glows with a radiating light similar to the sun, that almost blinds you, blows out the torch that is in the room. It starts to hover off of your hands, but shows no sign of aggression.\n"
                    << "It's light is comforting, lighting up the room. Since this beacon reacts with your movements, you accept the fact that you have this object to be alongside you.\n"
                    << "Until you figure out what it is called, you decided to name it based on it's comforting light." << endl;
                Item_pick_up(0, 1);
                cout << "You also found a small notebook, under the table too. It might be helpful if it contains something useful." << endl;
                Item_pick_up(0, 2);
                cout << "Unfortunatly, you may have to relight the torch again, if you wish to proceed." << endl;
            }
                  break;
            case 5: cout << "You walk over to the burnt out torch. It's still dry.\n";
                cout << "You might be able to relight it." << endl;
                for (int i = 0; i < inventory_size; i++)
                {
                    if (Inventory[i] == "Burning candle")
                    {
                        cout << "You place the burning wick of your candle close to the torch, setting it a blaze.\n";
                        connections[0][1] = Unlock_room(currentRoom, connections);
                        cout << "As if on command the door opens up, revealing wooden stairs that lead further up the tower." << endl;
                        break;
                    }
                }
                break;
            }
        }
    }
    else if (currentRoom == 2)    // Decisions for the room with the forge (lines: 269 - 443).
    {
        player_event = 0;

        int In_claw = 0;
        cout << "As you ascend the final step, you find yourself on the 2nd floor of the tower. Unlike the 1st floor, this room felt more ruinous and dilapidated.\n";
        if (connections[1][2] == 0)
        {
            cout << "With only a few small pebbles scattered across the floor. There is a workbench right next to what looks like an inactive forge.\n"
                << "There is also the metal hatch that you saw at the bottom of the tower, lit up by sunlight seeping above the room.\n"
                << "Yet despite seeing the other side of this hatch, you still don't see anyways of opening it. \n"
                << "You catch a glimpse of what looks like a pressure plate, until suddenly,\n as you ponder on what to do next, the door behind you slams shut." << endl;
        }
        else if (connections[1][2] == 1)
        {

            cout << "Looking back on it, you realize that this room served quite a distinct purpose just moments ago. After all, now you know that the metal hatch won't open until you jumped down the hole above.\n"
                << "You wonder if this place was once inhabited by someone here long ago, before it became abandond.\n"
                << "The thought was halted as the door slams shut on you once again, blocking your way down to the lower floors, at least here.\n"
                << "You felt a little bit more comforted that you made a another small discovery that deeply affects the world around.\n"
                << "Just a moment ago you didn't know what to do in this room, but that too changed, making the mystery a discovery." << endl;
        }

        while (currentRoom == 2)
        {

            cout << "[1] Check your bag, [2] Try the door leading downstairs, [3] Sit near the workbench, \n[4] Inspect the forge, [5] approach the pressure plate, [6] Pry the metal hatch, \n[7] Open the metal door" << endl;

            cin >> player_input;

            switch (player_input)
            {
            case 1: Inspect_inventory();
                break;
            case 2: cout << "You try the door leading downstairs, it's locked from the other side." << endl;
                break;
            case 3: cout << "You lean over towards the inviting workbench next to the forge. There are a few items \non the table that appear to serve a distinct purpose for the design of this place." << endl;

                while (player_event != 3)
                {
                    cout << "[1] Inspect the blueprint, [2] Inspect the stone cup, [3] Leave the workbench" << endl;
                    cin >> player_event;
                    switch (player_event)
                    {
                    case 1: cout << "These look like the design of some ordinary steel cube. What could this be used for?\n Despite knowing what it's polished design looks like, perhaps making it would be the only way to know what to use it for." << endl;
                        Item_pick_up(1, 0);
                        break;
                    case 2: cout << "You gaze at the stone cup, but you don't think it was made for simple everyday beverages.\n There is more weight on it as you pick it up, perhaps it is able to store something more hotter than anything you could possibly imagine." << endl;
                        Item_pick_up(1, 1);
                        break;
                    case 3: cout << "You decide that it is best to see the rest of the room" << endl;
                        break;
                    default: cout << "..." << endl;
                    }
                }
                player_event = 0;
                break;
            case 4: cout << "You walk towards the unlit forge, growing more curious as you approach it.\n"
                << "You have seen many forges before, but this one looked more simple by design.\n"
                << "It only has a simple switch, as well as a metal claw that looks like it is made to carry something akin to a cylindar." << endl;

                while (player_event != 1)
                {
                    cout << "[1] Step back from the forge, [2] Flip the switch, ";

                    for (int i = 0; i < inventory_size; i++)
                    {
                        if (Inventory[i] == "Crucible")
                        {
                            cout << "[3] Place the crucible in the claw." << endl;
                        }
                        else
                        {
                            cout << "\n";    //Adds another line, due to the fact that the first two choices don't.
                        }
                    }

                    cin >> player_event;

                    switch (player_event)
                    {
                    case 1: cout << "You quickly admire the intricacy this forge holds, then checked the rest of the room" << endl;
                        if (In_claw == 1)
                        {
                            cout << "You make sure that the crucible has been cooled just enough for you to grab it. After a moment, you do so." << endl;
                        }
                        break;
                    case 2: if (In_claw == 0)
                    {
                        cout << "With a flick, the forge starts to roar to life. It's ancient engine humming as it prepares to do something. \n"
                            << "A small door opens inside the forge, revealing molten magma, going down a narrow tube, leading to the center of the forge. \n"
                            << "It slides down the center of the claw, but something feels wrong. As it goes through the center, \n"
                            << "it covers the bottom of the forge. Smoke starts to rise within it, causing it to cover each corner of the room, \n"
                            << "before escaping the hole in the ceiling. After three loud beeps, another door inside the forge quickly opens sending water crashing at the bottom. \n"
                            << "You stumble backwards, as the steam comes at you, slightly startled by the sudden gas rushing towards your body. \n"
                            << "The excess gas, leaves the room just enough to make it so you could see what just happened. The forge is now back to it's inactive state, \n"
                            << "As both doors inside it close, cleaning out the rest of the damage that has been made. Whatever you just witnessed, \n"
                            << "you believe that you just saw one of the forges safety features, if something were to go wrong with it.\n"
                            << "Either way, you seemed to miss a step when activating it. Maybe placing something in the claw can help." << endl;
                        break;
                    }
                          else if (In_claw == 1)
                    {
                        cout << "As the engine begins to whir within the forge, it once again prepares something.\n"
                            << "The first door opens, releasing the lava down the sturdy tube, only instead of going through the center of the claw, it pours into the crucible you've just placed.\n"
                            << "It fills to the brim, giving off intense heat as it sits.\n"
                            << "Then a third door, seemingly leading to the another section of the forge, opens sending down a stone cubed container, stopping just below the crucible.\n"
                            << "In a slight instant, the claw gently rotates, sending down the hot lava into the cubed container. Once it finishes, the claw rotates\n"
                            << "back to it's orginal posistion just as the crucible is now empty. The claw retracts just out of the forge along with the crucible, still burning hot as it cools.\n"
                            << "A deep rumble quickly follows. After a short pause, the top of the chamber slams down, crushing the contents inside shuddering the entire tower slightly.\n"
                            << "You can only hear the sound of grinding, boiling and reforming behind the forges metal doors. Until finally, steam hisses from it's vents, as the large press slowly rises back up. Possibly indicating that you successfully made something.\n"
                            << "A small hatch opens from a small side compartment on the forges exterior, revealing the cube that is similar to the one you saw on the blueprint. It's almost like it's beckoning you to take it.\n"
                            << "As you attempt to take the cube, you realized that it is incredibly heavy. For something quite small, it was difficult to take it at first.\n"
                            << "But then you've grown accustomed to it's weight. With a small victory on your own strength\n";
                        Item_pick_up(1, 2);
                        break;
                    }
                    case 3: In_claw = 1;
                        cout << "You place the crucible in between the claw's metal jaws. Double checking to see if the claw has a firm grip on it. I suppose it's time to see what this forge will make." << endl;
                        break;
                    default: cout << "..." << endl;
                    }
                }
                player_event = 0;
                break;
            case 5: cout << "You walk just close enough to the stone pressure plate on the floor. \"What does it do?\" you secretly thought to yourself." << endl;

                cout << "[1] Stand on the pressure plate";
                for (int i = 0; i < inventory_size; i++)
                {
                    if (Inventory[i] == "Crucible")
                    {
                        cout << ", [2] Place the crucible on the pressure plate";
                    }

                    if (Inventory[i] == "Heavy steel cube")
                    {
                        cout << ", [3] Place the heavy cube on the pressure plate";
                    }
                }

                cout << "\n";

                cin >> player_event;

                switch (player_event)
                {
                case 1: cout << "You hop on the pressure, which doesn't make it budge even a little bit. You jump a few times on it, before realizing that your body weight alone won't activate. \nYou step off, seeing what else is in the room.";
                    break;
                case 2: cout << "For experimentation purposes, you place the crucible on the pressure plate. As you suspected, not even this could activate whatever this pressure plate starts.\n"
                    << "You need something more heavier if you ever hope to activate it." << endl;
                    break;
                case 3: cout << "With a certain amount of effort you place the metal cube on the pressure plate. It budges slightly at first, until it presses down to the ground.\n";
                    cout << "The metal door, scraping along the floor, opens up the stairs leading further up the tower." << endl;
                    connections[1][2] = Unlock_room(currentRoom, connections);
                    break;
                default: cout << "..." << endl;
                }
                break;
            case 6: cout << "You do your best to pry open the metal hatch. You don't have much luck, as it feels like you aren't supposed to open the metal hatch by hand.\n"
                << "You look up to see an open hole just above the hatch, you catch just a faint glimpse of foliage at the top,\n"
                << "trying to figure out how such plant life would grow up there. You don't see the entire room, but you wonder why this hole is above the open hatch." << endl;
                break;
            case 7: if (connections[1][2] == 0)
            {
                cout << "You try to move the door, but I doesn't even have a handle. You do your best to push the door open, but you can't seem to open it." << endl;
            }
                  else if (connections[1][2] == 1)
            {
                cout << "You make your way to the next floor." << endl;
                currentRoom = 3;
            }
            }
        }
    }
    else if (currentRoom == 3)        // Choices made in the room with 5 flowers (lines: 444 - 539).
    {
        cout << "The 3rd floor is filled with bushes and small grass patches. You are able to see a large opening from the exterior walls of the tower, which would explain how the plants in here thrive.\n"
            << "There are five distinct flowers that each have their own unique colors, with also a few vines covering certain areas of the room.\n";

        cout << "Apart from the hole you saw before, the most strangest thing you saw is a mirror on the ceiling. Sending a constant stream of water, pouring inside a large wooden tub, adjacent to a glass door that remained open." << endl;

        while (currentRoom == 3)
        {
            player_event = 0;

            cout << "[1] Examine the lose vines, [2] Gaze into the hole, [3] Look outside, \n[4] Go past the glass door, [5] Take some water from the tub, [6] Head back downstairs, \n [7] Inspect the mirror" << endl;

            cin >> player_input;

            switch (player_input)
            {
            case 1: cout << "You pull some of the vines aside the wall, revealing an old rusted metal plate with engravings on the wall.\n"
                << "It reads \"The mirrors may reflect your own desire, but only if your ego is not so dire. Though they have everything to obtain what they say, it means nothing if they don't find the gateway\"\n"
                << "You thought about these words for a moment and came to the conclusion that it is describing how the mirror dimension works. Though you can't seem to wrap your head around it fully. After all, if it reflects your desire, then how could it be done?\n"
                << "Either way, you did hear the stories about the mirror dimension. So the only way to know for sure, is to experience it yourself." << endl;
                break;
            case 2: cout << "You look down the hole leading to the second floor." << endl;
                cout << "With the hatch closed, you could just as easily jump down back onto the 2nd floor again. But why would you? After all, the door never locked itself when you got here.\n"
                    << "It wouldn't make sense to jump back down, when you know for a fact that you could just take the stairs back down" << endl;

                cout << "[1] Jump down the hole, [2] Walk away from the hole" << endl;
                cin >> player_event;

                switch (player_event)
                {
                case 1: cout << "Then again, would this really be a completly meaningless choice? You might as well try to see what happens when you don't take the stairs.\n"
                    << "You drop down towards the metal hatch, expecting to land directly on top of it with the air rushing below you.\n"
                    << "Yet unexpectidly, the hatch opens swiftly. Sending you falling farther down the tower. You land on soft cushions straight on your back as you attempt to recover by the sudden height change." << endl;
                    currentRoom = 1;
                    break;
                case 2: cout << "Indeed, with this in mind, you step back from the hole." << endl;
                    break;
                default: cout << "..." << endl;
                }
                break;
            case 3: cout << "You start to take in the view from the tower. You see the vast forest below streching on for what seemed to be miles.\n"
                << "As well as the mountains that are even more higher than the tower you stand in. You have come quite far to reach this high among the tower and the only thing you can think of,\n"
                << "is how breathtaking this view looks like. You aren't done with this tower just yet, yet you still admire the upcoming sunset that will take place in a few hours, even for just a short moment."
                << "With yourself feeling more at ease, you explore the rest of the room." << endl;
                break;
            case 4: cout << "Despite knowing that the door to the top floor is open, you take a few cautious steps, \nbefore heading past the final stairs leading to what you can assume to be the gateway to the mirror dimension." << endl;
                currentRoom = 4;
                break;
            case 5: cout << "Using the crucible, you scooped up as much water as you could from the tub. If you are going to be heading to the mirror dimension, you might as well allow the plants to be watered." << endl;

                cout << "[1] Water the yellow flower, [2] Water the blue flower, [3] Water the red flower, \n[4] Water the black flower, [5] Water the purple flower, [6] Water a random bush" << endl;

                cin >> player_event;

                switch (player_event)
                {
                case 1: cout << "You poured water on the yellow flower, it's front facing the shining sun. You can imagine that this flower get's the most attention, \n" << "since it is the closest flower near the large opening on this floor. Perhaps, it feels loved even more, when the last bit of water leaves your cup." << endl;
                    break;
                case 2: cout << "You water the blue flower, knowing that it is the closest to the hole. You wonder for a moment how deep these flower roots go, especially this one.\n"
                    << "It is pretty close to the hole, yet despite that, this flower still remains rooted to the ground it's on. It's comforting to think about." << endl;
                    break;
                case 3: cout << "You start watering the red flower, noting it's large size. It seems to like being close to the wooden tub.\n"
                    << "If flowers could think, you can imagine how unbelievibly grateful it would be to be the closest to the only source of water in this room. That's probably why it grows large enough to show it, or maybe not" << endl;
                    break;
                case 4: cout << "After a carefull treck through some rough bushes, you ended up watering the black flower, obscured in occasional shadows. Unlike the other flowers in this room, this one appears to not need that much sunlight.\n"
                    << "Although you never explored the world of botany before, you can't help but gather the mystery that this flower holds. Maybe you'll discover more about it, when your done with this place." << endl;
                    break;
                case 5: cout << "Carefully going through the circle filled with greenery, you made it to the purple flower in the center of the room.\n"
                    << "Before you decide to water it, you considered the flower for a brief moment.\n"
                    << "You have seen many colors throughout your entire journey, but your favorite color among them, is purple. It signifies something about admiration and respect within flowers, including the one in front of you.\n"
                    << "Yet it also shows off some kind of mystery with it's enchanting colors. Perhaps, that mystery allows someone who has the courage to face whatever truth they find within, even if it's something as simple as the color in front of you.\n"
                    << "Perhaps that is also why you decided to go on many adventures, because you wish to hold the truth close to your heart, in hopes of seeing something extraordinary, even if it may hurt.\n"
                    << "Though it may sound a little harsh, it feel right. You did manage to get to the 3rd floor of this tower, because you did use what is true, right?\n";
                    cout << "You realize that you have been reflecting a little bit longer than you would like, perhaps it's time to water this flower.\n"
                        << "As the multiple drops of water interact with the stem of the flower, sinking down towards the earth, purple pollen seems to cover your entire surroundings.\n"
                        << "It starts to gather above the purple flower, making it seem like a ball of pollen is being made, but then it changes into something else.\n"
                        << "As it completes it's transformation, a glowing dark glass orb floats toward you, stopping just in front of you.\n"
                        << "It appears to reacted with your movements, as well as follow you wherever you go. It feels rather convinent that you gained this orb just by taking care of the plant life, you decided to name it accordingly." << endl;
                    Item_pick_up(2, 0);
                    break;
                case 6: cout << "Congradulations! You nurtured a bush." << endl;
                    break;
                default: cout << "Perhaps it's best not too, at least for now." << endl;
                }
                break;
            case 6: cout << "You turn around and make your way downstairs, standing just in behind the door that would lead to the first floor of this tower." << endl;
                currentRoom = 2;
            case 7: cout << "You walk as close as you can towards the mirror on the ceiling. You've never seen mirror like this before.\n"
                << "It is constantly pouring water, sending ripples across the mirror giving the impression that this is some sort of two way portal to a place you can't hope to reach, due to the height of the ceiling.\n"
                << "If you hope to access what is beyond that mirror, it would be impossible here." << endl;
                break;
            default: cout << "..." << endl;
            }
        }
    }
    else if (currentRoom == 4)             // The only choice you can make in the mirror dimension gateway (lines: 540 - 600).
    {
        cout << "You find yourself in a room covered with mirrors, in each corner of the room.\n";
        cout << "There is a strange aura filling the room, almost mystifying to look at each one of them." << endl;
        bool Has_Nora = false;
        bool Has_Mcguffin = false;
        for (int i = 0; i < inventory_size; i++)
        {
            if (Inventory[i] == "Nora" && Inventory[i] == "Mcguffin")
            {
                cout << "What's even more strange, is that both Nora and Mcguffin seem to resonate inside this room. Perhaps they might be the key to the mirror dimension." << endl;
            }
        }

        cout << "[1] Meditate" << endl;

        cin >> player_input;

        if (player_input == 1)
        {
            for (int i = 0; i < inventory_size; i++)
            {
                if (Inventory[i] == "Nora")
                {
                    Has_Nora = true;
                }
                if (Inventory[i] == "Mcguffin")
                {
                    Has_Mcguffin = true;
                }

            }

            if ((!Has_Nora && !Has_Mcguffin) || (Has_Nora && !Has_Mcguffin) || (!Has_Nora && Has_Mcguffin))
            {
                cout << "You sit in the center of the room, trying your best to clear your mind. As it appears to be the only way you know how to get to the mirror dimension.\n"
                    << "As you sit as still as you possibly could, the aura in this room strengthens. Not oppressing you, but making you... more aware? But aware of what? Yourself, or something you couldn't percieve before?\n"
                    << "The room eventually grows brighter and brighter and brighter, until you are teleported somewhere else. You start to stand back up." << endl;
                currentRoom = 1;
            }
            else if (Has_Nora && Has_Mcguffin)
            {
                cout << "You sit in the center of the room, doing your best to clear your mind. Nora and Mcguffin floating just in front of you.\n"
                    << "As the aura of the room strengthen's, both Nora and Mcguffins glow strengthens too. Then, they begin to orbit around each other.\n"
                    << "The light of the room glows brigther, until all of a sudden, all but one of the mirrors of this room shatters.\n"
                    << "The broken shards of broken glass appear to follow Nora's and Mcguffins vortex, as they both spin faster and faster, until every last shard succumbs to their gravity.\n";
                cout << "You remain motionless, awestruck by the intensity the both orbs bring, almost like staring into the center of a black hole.\n"
                    << "Nora and McGuffin spin faster and faster and faster, until suddenly, both of the two orbs stop, with the shards of glass staying where they are in mid air.\n"
                    << "They both gently head into the only mirror that doesn't appear to be broken, ripples run across it as they both past the threshold.\n"
                    << "Wherever they just went to, you decided that it is best to follow them." << endl;
                currentRoom = 5;   //Technincally not a room, just a way to ensure that the main program finishes.
            }
        }
        else
        {
            cout << "..." << endl;
        }
    }

    return currentRoom;
}

int Unlock_room(int currentRoom, int connections[][room_count])    // Responsible for unlocking doors when the player makes a certain decision (lines: 602 - 626).
{
    /*
    Room_number 0: starting room
    Room_number 1: ruined room
    Room_number 2: flower room
    Room_number 3: Mirror room

    All unlocked rooms have a value of 1, if it has a value of 0 it's locked.
    */
    if (currentRoom == 1)
    {
        Room_number = 0;
        Room_door = 1;
        connections[Room_number][Room_door] = 1;
    }
    else if (currentRoom == 2)
    {
        Room_number = 1;
        Room_door = 2;
        connections[Room_number][Room_door] = 1;
    }
    return connections[Room_number][Room_door];
}

bool Item_pick_up(int room, int itemIndex)        // A function responsible for indicating that a player has picked up an item (lines: 627 - 655).
{
    if (!itemTaken[room][itemIndex] && !roomItems[room][itemIndex].empty())
    {
        for (int i = 0; i < inventory_size; i++)
        {
            if (Inventory[i].empty())
            {
                Inventory[i] = roomItems[room][itemIndex];
                itemTaken[room][itemIndex] = true;
                if (Inventory[i] == "Nora" || Inventory[i] == "Mcguffin")
                {
                    cout << Inventory[i] << " joined your team." << endl;
                }
                else
                {
                    cout << "You take the " << Inventory[i] << endl;
                }
                return true;
            }
        }

        cout << "Your carrying too much!" << endl;
        return false;
    }
    cout << "There is nothing else to pick up here." << endl;
    return false;
}

void Inspect_inventory()   // A function capable of inspecting your inventory in between rooms (lines: 656 - 722).
{
    cout << "--------------------------" << endl;

    int display_Count = 0;

    for (int i = 0; i < inventory_size; i++)
    {
        if (!Inventory[i].empty())
        {
            cout << "[" << i + 1 << "] " << Inventory[i] << endl;
            display_Count++;
        }
    }

    if (display_Count == 0)
    {
        cout << "Your bag is empty." << endl;
        cout << "--------------------------" << endl;
        return;
    }

    cout << "--------------------------" << endl;

    int Item_option;
    cin >> Item_option;

    string item = Inventory[Item_option - 1];

    if (item == "Burning candle")
    {
        cout << "A small candle that has a burning wick, capable of burning objects with ease.\n"
            << "Because your bag is built to withstand high temperatures, you are able to place the candle\ninside without any risk of accidental embers from burning anything inside it." << endl;
    }
    if (item == "Cast iron blueprint")
    {
        cout << "Design plan's for a plain cube blueprint. Your hoping to understand it's design a little bit better, even if only a little.\n";
        cout << "The more you look at it, the more it doesn't appear to have any distinct purpose.\n"
            << "The only thing you do know is that it is made from steel." << endl;

    }
    if (item == "Crucible")
    {
        cout << "A small cup that lacks to much detail, save for how it is primarily made of strudy stone.\n";
        cout << "It looks like it can hold a certain amount of liquid, possibly even extremely hot liquids." << endl;
    }
    if (item == "Heavy steel cube")
    {
        cout << "An incredibly heavy cube that you are lucky to even lift in the first place.\n"
            << "You estimate that it's around 14 pounds or so, just enough to carry, but also enough to weigh something down." << endl;
    }
    if (item == "Mcguffin")
    {
        cout << "A dark glowing orb that emits a purple glow, it reacts to your movements like it's somehow a sentient living being.\n"
            << "Aside from the faint aura it emits, you can't help but wonder how this orb could be created by nothing but strange pollen." << endl;
    }
    if (item == "Nora")
    {
        cout << "A light glowing orbit that emits a yellow radiant glow, it reacts to your movement almost like it is alive.\n"
            << "Aside from it's comforting glow that it emits, your curious as to how this orb came to be here and why it was inactive when you first found it." << endl;
    }
    if (item == "Small notebook")
    {
        cout << "A notebook containing entries about the mirror dimension itself. Skimming through pages you more or less already knew, you come across a page that describes floating orbs in the mirror dimension.\n"
            << "Although they are rare to find in the mirror dimension, it is said that they know how the mirror dimension works and do their best to protect it with their own lives. But what would these orbs protect the mirror dimension from?" << endl;
    }
}
/*       // Here is some old code on the first idea I had for my game, I thought I would include it. (Lines: 723 - 942)
#include <iostream>
#include <iomanip>

using namespace std;

int loopEndHour = 8;
int loopEndMinute = 0;
const int loop_Start_Hour = 6;
const int Loop_Start_Minute = 15;

int currentRoom;
int player_memory = 0;

int loopIteration = 1;

void advance_time(int &hour, int &min, int minutes_to_add);
void end_of_loop(int &loopIteration, int &player_memory);

int Player_decision(int player_memory, int currentRoom, int &hour, int &min);  // Note, you have to figure out a way to create decision function,
                     // while still being able to update the memory variable. May need the
                     // currentRoom and player_memory variable.

int main()
{
    // Write C++ code here

    int hour = loop_Start_Hour;
    int min = Loop_Start_Minute;

    currentRoom = 0;

    while(true)
    {

        while(hour < loopEndHour || (hour == loopEndHour && min < loopEndMinute))
        {

            cout << hour << ":" << setw(2) << setfill('0') << min << "am" << endl;

            currentRoom = Player_decision(player_memory, currentRoom, hour, min);

        }

        hour = loop_Start_Hour;
        min = Loop_Start_Minute;
        currentRoom = 0;

    }
    return 0;
}

void advance_time(int &hour, int &min, int minutes_to_add)
{
    min += minutes_to_add;
    if (min == 60)
    {
        hour += 1;
        min %= 60;
    }

}

int Player_decision(int player_memory, int currentRoom, int &hour, int &min)
{
    int Player_input;
    bool Player_choice = false;


    // Room 0: Your room.
    if(currentRoom == 0)
    {
        if (player_memory == 0)      // Depending on how many loops you repeated, different choice will appear.
        {
            cout << "You wake up in your room, the lights are off and the dim sunlight is the only thing faintly illuminating the room. \n";
            cout << "Your name is Leila and this is the start of a new day. \n";
            cout << "The faster you get your viatamins, the better this day will turn out." << endl;
        }
        else if (player_memory == 1)
        {
            cout << "1, 2 and 3? \n..." << endl;
        }
        while(!Player_choice)
        {
            cout << "[1] Turn on the lamp,\n" << "[2] Leave the room,\n" << "[3] Check inventory" << endl;
            cin >> Player_input;

            switch (Player_input)
            {
                case 1: cout << "\nWith a click, the light on your nightstand                  makes the room more brighter.\n"
                             << "Your vision blurry as your eyes adjust, until you are able to see your surroundings.\n"
                             << "The inside of your room is neat and tidy, with your work computer centered on a desk beside your bed.\n"
                             << "Along with the curtains on the opposing side of your room, marking where your spare clothes are." << endl;
                        break;
                case 2: cout << "Right choice!" << endl;
                        Player_choice = true;
                        currentRoom = 1;
                        advance_time(hour, min, 5);
                        break;
                case 3: cout << "I see you done the third" << endl;
                        break;
            }
        }
    }

    // Room 1: Hallway.
    else if(currentRoom == 1)
    {
        while (!Player_choice)
        {
            cout << "3, or 4?" << endl;
            cin >> Player_input;

            switch (Player_input)
            {
                case 3: cout << "You got 3!" << endl;
                        break;
                case 4: cout << "Success!" << endl;
                        Player_choice = true;
                        currentRoom = 0;
                        advance_time(hour, min, 5);
                        break;
            }
        }
    }
    // Rooms 2 and 3 are locked, until final production.

    // Room 2: Kitchen.
    else if(currentRoom == 2)
    {
        while (!Player_choice)
        {
            cout << "5, or 6?" << endl;
            cin >> Player_input;

            switch (Player_input)
            {
                case 5: cout << "Odd number? try again." << endl;
                        break;
                case 6: cout << "Good one!" << endl;
                        Player_choice = true;
                        currentRoom = 3;
                        advance_time(hour, min, 5);
                        break;

            }
        }
    }
    // Room 3: Main entrance.
    else if(currentRoom == 3)
    {
        while (!Player_choice)
        {
            cout << "7, or 8" << endl;
            cin >> Player_input;

            switch (Player_input)
            {
                case 7: cout << "Not right..." << endl;
                        break;
                case 8: cout << "Is right!" << endl;
                        Player_choice = true;
                        currentRoom = 0;
                        advance_time(hour, min, 5);
                        break;

            }
        }
    } // Note to self, make tutorial, if this doesn't work out.
    return currentRoom;
}

void end_of_loop(int &loopIteration, int &player_memory)
{
    int journal_entry = 0;

    cout << "8:00am" << endl;

    if (loopIteration == 1)
    {
        cout << "As you begin your work, time begins to pass throughout your day.\n ";
        cout << "You only recall certain moments, like how you successfully programmed an app in the coorporation you work in.\n";
        cout << "You also recall moments where work stress may be too much for you. But, then that feeling fades. \n";
        cout << "You know that all of your efforts will not be in vain, if you wish to be the best computer scientist out there." << endl;
    }
    else if (loopIteration >= 2 && player_memory = 0`)
    {
        cout << "Time starts to pass throughout the day.\n";
        cout << "You only recall certain moments, like how your curiousity seemed to affect your day differently.\n";
        cout << "As this thought finished, you are confused by it. Why was it different?\n";
        cout << "After all, you've always lived this way. Maybe you'll have time to reflect on this at the end of your day." << endl;
    }

    cout << "10:00pm" << endl;

    if (loopIteration == 1)
    {
        cout << "Then you find yourself holding a journal. Filled with multiple entries in your handwritting of thoughts that you hold dear.\n;";
        cout << "Every night, you have logged your ambitions, struggles, and even secrets onto this very journal.\n In a way, you consider this journal as the one thing that has always been with you when you need it the most.\n";
        cout << "Each time you reflect your thoughts into this journal, you are given additional ways to improve yourself.\n"'
        cout << "But what should you reflect on this time?" << endl;

        while(journal_entry != 1 || journal_entry != 2)
        {
            cout << "[1] Hopes, [2] Life" << endl;
            cin journal_entry;

            switch(journal_entry)
            {
                case 1: cout << "You decided to reflect on your hopes for the future ahead.\n";
                        cout << "You write down what your goal is in as much detail as possible, and why you go toward this goal to begin with.\n";
                        cout << "Ever since you learned a programming language, you've always wanted to learn more about the topics present in computer science.\n";
                        cout << "Yet, where in computer science? You can't seem to recall." << endl;
                case 2: cout << ""

            }
        }
    }
}
*/
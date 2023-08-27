 _____     ______     ______     __  __    
/\  __-.  /\  __ \   /\  == \   /\ \/ /    
\ \ \/\ \ \ \  __ \  \ \  __<   \ \  _"-.  
 \ \____-  \ \_\ \_\  \ \_\ \_\  \ \_\ \_\ 
  \/____/   \/_/\/_/   \/_/ /_/   \/_/\/_/
 __    __     ______     ______     __   __    
/\ "-./  \   /\  __ \   /\  __ \   /\ "-.\ \   
\ \ \-./\ \  \ \ \/\ \  \ \ \/\ \  \ \ \-.  \  
 \ \_\ \ \_\  \ \_____\  \ \_____\  \ \_\\"\_\ 
  \/_/  \/_/   \/_____/   \/_____/   \/_/ \/_/
 ,------.              ,--.                    ,--. ,--.              
|  .---,--.  ,--.,---.|  |,---.,--.--.,--,--,-'  '-`--',---.,--,--,  
|  `--, \  `'  /| .-. |  | .-. |  .--' ,-.  '-.  .-,--| .-. |      \ 
|  `---./  /.  \| '-' |  ' '-' |  |  \ '-'  | |  | |  ' '-' |  ||  | 
`------'--'  '--|  |-'`--'`---'`--'   `--`--' `--' `--'`---'`--''--'

A moon, devoid of magnetic field, in orbit of a cold, dead planet. By trapping 
in heat and shielding the ground from radiation, the moon’s thick, vaporous 
atmosphere is the only thing standing between the alien life that evolved there 
and annihilation. But it also makes the place damned inconvenient to study. 

When the exoplanetary research grants were being handed out, your agency scraped
its way to a qualifying position and by luck of the draw beat out the 
competition for a final spot (1,345th out of 1,345). But being last-place among 
qualified agencies also came with the last-pick amongst candidate worlds, so 
you’re stuck with this one (and it’s stuck with you). 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

OVERVIEW: This is a game about blindly directing ambulatory drone explorers in 
alien terrain on behalf of a cut-rate space exploration organization. Your job 
is to give instructions, listen to the drone’s data dumps, and plan for success—
keeping track of all the data you receive in the hopes of using it to pursue an 
objective. 

PLAYING THE GAME: This is a cooperative game in which the players control two 
drones, each able to independently maneuver around the map area. Unfortunately, 
the players won’t be able to see this map. That privilege goes only to the 
Cartographer, who plays the role of “computer” giving readouts of data to reveal 
the results of the players’ instructions. 

Instead of viewing a map, the players have to track their drones’ movements 
manually.

There are additional setbacks.

You do not know where the drones are. The drones do not know where each other 
are. You do not know where the objective is. The drones have no objective 
bearings, whatsoever. They rely purely on inertial guidance, which means all 
telemetry is subjective to each drone. They designate their own “North” 
arbitrarily, and all movement (including altitude) is logged and reported only 
relative to the drone’s own internal guidance system.

Below is the reference “rose”. A copy of this can be given to players so they 
can easily visualize the directions given verbally by the cartographer, and 
compare to the label for each edge and vertex. The cartographer also has a pair 
of transparent tiles that look like this which serve as their player drone 
location markers on the board, and they can use them to easily read off precise 
and correct directional information for each drone.

          ______
         /   1  \
  ______/ north  \______
 /  6   \        /  2   \
/ north  \______/ north  \
\  west  /      \  east  /
 \______/        \______/
 /  5   \        /  3   \
/  south \______/  south \
\  west  /  4   \  west  /
 \______/        \______/
        \  south /
         \______/

If a random direction is ever needed, roll a d6. Numerically, the north 
direction is “1” and it counts up in a clockwise direction to “6” at the 
North-west. 

The six directions orthogonal to the grid are used for all navigation and 
communication. Some gameplay events result in a “rough direction” report, in 
which case the cartographer will estimate which of the 6 directions is closest 
to the straight-line direction between two locations (picking randomly if the 
straight line is right down the middle between two compass directions).

There is also a similar mechanic called “rough distance.” To report rough 
distance, the cartographer reports range in banded increments of 5 steps; i.e. 
1 to 5, 6 to 10, 11 to 15, and so on.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TAKING TURNS: 
The order in which players command their drones is up to them to decide each 
turn, and their actions can be interleaved, but each drone must perform the 
following three commands in this order:
    1: Strategic Action (Pick One)
    2: Movement (Pick One)
    3: Survey

Part 1: Strategic Action. 
Players assign a strategic action and resolve the outcomes with the help of the
Cartographer. Strategic actions have a variety of uses and outcomes, and each
drone will have different options. All drones have access to the following three
options (maybe more, who knows): 
    
    Interact - 
        when you are adjacent to or in the same hex as an identified anomaly, 
        you get the option to interact. When Interacting with certain obstacles,
        you move one step to enter the anomaly’s hex before proceeding. If such
        movement is impossible due to obstacles, another Strategic Action must 
        be chosen. Each anomaly has a different interactive feature which is 
        explained when the anomaly is identified during a survey.
    
    Inertial Guidance Check - 
        Use this to get absolute certainty on your current position relative to
        your start. This action follows these steps: 
        1:  The cartographer locates the player’s starting hex and then gives a 
            simple terrain-agnostic straight-line navigation back to the start 
            via a direct route with a maximum of two instructions 
            (e.g. X hexes North, 2 hexes Northwest).
        2:  Then the cartographer looks at the player’s current hex, and 
            compares its altitude to the starting hex which they marked for that
            player, then reports the net change in altitude. 
        3:  (If you find a discrepancy between your expected result and what the
            cartographer delivers, that’s just too bad, something made an error,
            but it's not the end of the world)
    
    Flare Beacon - 
        Sets a “Flare” Beacon, which is a short-wave remote device with limited
        range and sensor capabilities. Players choose a direction and a number 
        of steps between 0 and 5. The cartographer uses these directions to move
        an imaginary flare beacon from the player drone’s position. The flare
        beacon can bypass all obstructions other than the map edge, which causes
        it to stop short. Once it reaches its final hex, mark its position as a
        new anomaly, noting which drone launched it, and perform a Survey from
        its position. Flare beacons always use the North orientation of their
        parent drone. Each drone only gets one flare beacon per game. As an 
        anomaly the beacon has the following property: Interact: move to this 
        hex. If you have expended your beacon, collect this one, remove it from
        the board and regain use of this ability
    
    Project Management Meeting - 
        Rather than command your drone, you engage in a series of interminable 
        planning sessions in an attempt to alter an agency agenda. Tick the 
        funding timer down once. Then discard the current Mission Control 
        status.
    
In addition, at the start of the game, players draw 6 cards from the Strategic 
Action deck and assign 2 of the drawn cards to each player drone, discarding the
rest. These will provide additional actions that are only available to the 
assigned drone:

    Anomaly Radar - 
        Cartographer reports the rough direction from this drone to the nearest
        anomaly. If two (or more) anomalies are equidistant from the drone, you
        get multiple readings.
    
    Listen - 
        Open passive audio sensors which can detect anomalies nearby, but cannot
        provide directional information. Cartographer reports the rough distance
        from this drone to the nearest anomaly, and the total number of
        anomalies within that range band. 

    Flash Scan - 
        A penetrating, directional scan. Choose a direction, and optionally 
        choose an anomaly type. The Cartographer reports Yes or No as to whether
        there are any anomalies in that rough direction, limited to the chosen
        type if a type was given. 

    Behavior Study - 
        Study the activity of animal life to discern clues about their biome. 
        Choose an anomaly type. Cartographer reports either Yes or No, as to 
        whether there is any contiguous path of hexes that can connect your 
        present position to that of an anomaly of the chosen type without 
        changing biome along the way.

    Linear Tracer - 
        Choose a direction. The Cartographer traces a straight line in that 
        direction starting from this drone and ending at the map edge and 
        reports the following: the number of biome colors on the line, and the 
        value of the largest altitude deviation on the line relative to your 
        current position. 

    Transponder Ping - 
        Send an omnidirectional transponder ping out. The return ping cannot 
        discern direction, but can estimate distance based on signal delay. 
        Cartographer reports the rough distance to the other player drone. 

    Nav-Limit Bypass - 
        When you Explore after using this action, your drone will ignore Cliffs
        and Coasts. If it attempts to cross Whitewater, it instead stops and
        initiates a River Ride with instructions to cross the river; it ends its
        movement after the river ride concludes.

    Delay System - 
        After using this action, this drone can execute a second Strategic 
        Action after completing its movement and survey. 

    Sprint - Explore +1 Step this turn.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Part 2: Movement. 
It is a difficult job, planning, executing, and tracking the movement of a 
remote controlled drone that is millions of miles away in deep space, but this 
guide should make it easy-breezy. Locomotion is achieved by picking one of three
options: 

    EXPLORE
        Explore is the most basic option, used for pushing into uncharted 
        wilderness. While exploring, the drone has to think for itself on how to
        navigate and log a lot of data along the way; since the drone is not
        very smart, it goes slow. When you Explore, you declare a number of
        directional “steps” that you program into the drone in a specific order.
        Each step tells the drone to move one hex in one of the 6 possible
        directions. The drone can always perform up to 3 steps of instructions,
        though you can provide as many or few commands as you want. In any case,
        you must provide all of them up front before the drone begins executing
        the command. If your first step is downhill it costs 0, allowing the
        drone to execute a 4th step command (but subsequent downhill steps are
        counted normally). Once you have set your travel directions, the
        Cartographer will execute them and give the outcome via travel report.
        Along the way, you may run into a few kinds of obstructions—terrain 
        features that the bot can’t overcome—these obstructions will cause the
        bot to stop and discard the remainder of its movement instructions. 
    
    PLANNED TRAVEL
        Planned Travel lets you move much further distances, as long as you know
        the precise details of the terrain you are traversing. This way, the
        drone doesn’t have to think as much about navigating, so it can go very
        fast. In order to do this, declare planned travel. Then, one step at a
        time, you must tell the cartographer the direction, altitude change, and
        color of each hex you step into. If you make an error (incorrectly 
        reporting the altitude change or color) you stop short of the intended 
        hex and the drone’s movement ends. You can also stop if any instruction
        causes the bot to hit an obstruction, as normal. The players can
        voluntarily end the movement at any time. (This type of movement 
        requires no travel report, since it is redundant with the players 
        describing the hexes before they enter.)
    
    RIVER RIDE
        While drones are forbidden to swim during normal operations, they are
        permitted to do so when crossing rivers, and a loophole in their 
        programming allows you to instruct them to cross a river very, very
        slowly, and thus be swept downstream. This method of travel is not 
        endorsed by Mission Control. You can declare this movement option only 
        if your drone is in a hex with a river border. It’s a little tricky to
        explain, so here is a step-by-step guide:
    
    Player Procedure
        1: Declare a river ride
        2: Select which edge of your hex contains the river you want to ride 
            (whitewater included). 
        3: Declare whether you want to cross the river during the movement or 
            not (end on the near side or far side of the river).

    Cartographer Procedure
        Make sure the players have given a valid instruction. If there is no 
            river on the edge they target, this movement option fails, and the 
            drone doesn’t move this turn. 
            (That being said, you can clarify directions if they make an honest
            mistake and you feel generous). 
        
        Move the player drone 5 steps down the river, sliding the drone 
            alongside the river so that the drone only moves via hexes that are
            bordered by that river on one or more edge. Make a travel report for
            step. 
        
        If any of the ridden river’s edges are whitewater on a hex that the 
            drone moves into, the cartographer simply adds “whitewater” to the
            travel report, and the step costs 0. The players do not learn 
            specifically which edges of that hex are whitewater, only that at
            least one of them is. 

        Once you have expended the 5 steps of travel, then:
            If the players decided to cross the river, take a 6th step of 
            movement to move directly across the furthest downriver edge of the
            ridden river on their current hex (even if it is whitewater).
        
            If the players decided not to cross the river, take a 6th step
            downriver just like the other 5.
        
        This form of travel ignores all obstructions other than the map edge; if
            this movement tries to cross a map edge, end the movement.
        
        If the river being ridden terminates at a blue hex along the route, the
            drone gets dumped into the blue hex and ends movement there.

Travel Report: 
    On each step, and any time the bot moves into a new hex for any reason, the
    cartographer will give a travel report for the hex the drone enters, 
    reporting the change in altitude from the previous hex, the biome color of
    the new hex, and whether it crossed a river to get there. Even if the drone
    is being moved by an exterior force, it gives a travel report upon arrival,
    so that players always know its position relative to the last report.

    For example:
    As the Cartographer, if you execute a step and move the drone from a Green 5
    to a Green 6 you simply say: “Green +1” to tell the players about the
    relative increase in altitude. If the next move goes from the Green 6 to a
    Yellow 4, you say, “Yellow -2.” Never report the actual altitude numbers on
    the map, only plus X, minus X or zero (for no change). This can be tricky to
    get a hang of, but it is critical to the game!

    If the step involves crossing an edge that contains a river, you say so in
    the travel report for that step, and describe which direction the water 
    flowed—use the small headings on the inside of the reference rose (labeling
    the vertices of the hex) to indicate the flow direction of rivers (from X
    vertex to Y vertex). 

    If the drone steps into an anomaly hex, the Cartographer says “anomaly” in
    the travel report, but does not identify it. 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Part 3: Survey. 

The last, and perhaps most important phase of every turn is the Survey. The bot
extends its basic sensor equipment and tries to get the lay of the land around
it. 

First, the Drone observes its current cell; the Cartographer confirms the biome
color, and verifies that the players have been given a relative altitude value
for the hex (this information will have been given in the travel report to
arrive here). Then, it identifies any anomalies in this hex.

Next the drone observes all adjacent hexes in a clockwise pattern from current
position, starting with the drone’s north. Going around the circle, the
Cartographer quickly gives color, relative altitude (color, +1/-1 etc), presence
and identity of anomalies, and whether there is any river/whitewater on the edge
in that direction (or instead of all that, say “map edge” when they are at the
edge of the map and there are no more hexes in that direction). 

Once all the hexes are done, if there were any river edges, tell the players
which way the water is flowing.

The cartographer’s report should sound something like this: “Starting from your
north, going clockwise. Ready? Green 0 across whitewater. Green +2, Green +3,
Yellow +1 with an anomaly - a Geyser, Yellow 0, Yellow +1 across a river. The
river flows into the NW to N and away. Got it?”

And if the players were to draw that survey (with an arbitrary starting 
altitude of 2) it would look like:

                  ______
                 /      \
          ______/ Green  \______
         /      \   2    /      \
        / Yellow \wwwwww/ Green  \
        \    3   R      \   4    /
         \______R Green  \______/
         /      \   2    C      \
        / Yellow \______C Green  \
        \    2   /      \   5    /
         \______/ Yellow \______/
                \   3    /
                 \______/
        Anomaly (South) - Geyser

If the player is at the edge of the map, the cartographer just says “map edge” 
when a non-existent hex would be surveyed. 

NOTE - the good gameplay feeling relies on delivering this information QUICKLY
and ACCURATELY. Because this step is repeated so often, the above system is 
meant to streamline it so that the game doesn’t get bogged down with 
communication issues. Most hexes surveyed will only require a color and a number


To speed up the survey even further, when re-treading ground, players can 
interrupt the survey to instead ask for the survey by request only, in which 
case the players call out the direction and the cartographer gives the survey 
result for that hex, and they can skip any hexes they already have info on. 


TERRAIN: The Cartographer gets to see a big map of all the terrain, but for 
players, they need to discover everything as they go. To do this, we distill 
each hex down to a few simple variables.

Color. Each hex has a color which categorizes the land by the kind of terrain or
biome that dominates it. 
    Black - Flora density: low. Flora size: small. Regolith: rocky.
    e.g . rockslide, exposed bedrock, boulderfield
Green - Flora density: high. Flora size: large. Regolith: fine organic.
    e.g. forest, jungle
Yellow - Flora density: high. Flora size: small. Regolith: fine organic.
    e.g. grassland, scrub, heath 
Blue - Open body of water. The borders between Blue hexes and non-blue hexes are
    Coast, which is an obstruction when moving from land to water, but not the 
    reverse.  
White - Flora density: none. Flora size: n/a. Regolith: Water ice/snow.
    e.g. glacier, snowcap 
Orange - Flora density: low. Flora size: small. Regolith: fine silica.
    e.g. desert, sandbar, alluvial fan 
Purple - Flora density: high. Flora size: medium. Regolith: mud.
    e.g. wetland, floodplain

Altitude. Each hex on the grid displays a “master” altitude number. This should 
never be reported to the players. The cartographer only uses this to report 
relative values. Altitude is given in its own, unique but ambiguous unit, and 
should not be seen as equivalent to horizontal distance.
Wherever the altitude changes by +/-3 between two hexes, the edge is considered 
a cliff. Cliffs are obstructions. 

Rivers. Rivers exist on the borders of hexes. Therefore, a hex can have running 
water on any of its 6 edges. The Cartographer’s map indicates the direction of 
flow. When the Cartographer reports rivers, they simply need to specify which 
edges have rivers, and give the direction of flow. You can use the vertices of 
the player’s current hex to help identify this and use the “In/Out” method, 
where you tell the players which vertex the river flows into this hex on, and 
which it flows out from. 
Whitewater - In steep areas, some rivers are colored light-blue, indicating 
whitewater. Whitewater is an obstruction. Whitewater also has a somewhat 
beneficial interaction when using River Ride. 

Obstructions are terrain features that the drone is incapable of traversing 
according to its standard navigation procedures—that is to say, the drone may be
physically capable of falling down a cliff, for example, but its programming 
prevents it from doing so in most cases. Obstructions are found on hex edges, 
and (in most cases) a drone attempting to cross one of these will be prevented 
from doing so, and their movement ended. There are 4 kinds of obstruction, as 
described above, but for reference here they are again:
Cliff - anywhere the altitude changes by +/- 3 from one hex to its neighbor. 
    This terrain is too steep to traverse either up or down. 
Whitewater - portions of rivers marked on the map with light blue lines. When a 
    river is moving faster than the drone’s safety systems deem safe, the drone 
    will stop short of crossing such water. 
Coast - the edges between Blue hexes and non-blue hexes. The drone is not 
    authorized to swim in open water. Coast obstructions are one-way, they 
    prevent the drone from entering water, but not from leaving it.  
Map Edge - Mission Control has projected a barrier signal onto the mission area.
    If a drone encounters this signal, it is instructed to stop immediately. 
    This is the only obstruction that cannot be bypassed by any means. 

SCENARIO: 
A - Out in the wilderness, somewhere, an exploration drone has failed. Physical 
trauma to the chassis has halted its mission, and we have lost contact. We can’t
afford to write these things off without a good effort at recovery, and to that 
end we managed to diagnose the problem prior to full communication loss. Repairs
can be performed. The failed drone is now Objective A. We have two operational 
drones that we believe are in the immediate region of Objective A—each one of 
them possesses a critical spare part needed to make Objective A operational 
again. Therefore, your mission is to locate Objective A and individually 
locomote both operational drones to its location, where they must Interact to 
perform their repairs. Once both drones have visited the objective and performed
repairs, this mission is complete.

B - We have a drone with a faulty Exploration protocol. We need to get it to an 
uplink station in this region, but this drone is unable to navigate without 
precise directions. The drone is known as Objective B. Elsewhere in the region, 
you can find the Uplink Station. To complete this scenario, as a strategic 
action, attempt a Planned Travel movement on behalf of Objective B. The 
Cartographer will follow your directions as normal, however Objective B does not
actually move—if the Planned Travel encounters an error, the Cartographer does 
not report the kind of error. If there is no error and the travel connects 
Objective B to the Uplink Station, the mission is complete!

C - There is evidence of alien intelligence on this world! Somewhere in this 
region, there is a hidden alien structure. Our objective (Objective C) is a 
hidden anomaly which cannot be detected by any means. In order to uncover it, we
need to locate and interact with two Seismic Keys which were deployed in the 
region. The Seismic Keys are placed far apart along an orthogonal line of hexes.
Once both have been activated, the hidden alien ruin can be detected by normal 
means, located somewhere on the direct path between the two Seismic Keys. 

PREPARING THE MAP: It is the cartographer’s job to prep their map board before 
the game can start. To do this they need to select two map sheets that form a 
contiguous area and slot them into the board. Then, cover the maps with 
transparency sheets so you can mark anomaly locations (and other notes) with a 
dry erase pen. Anomaly placement is performed according to the cartographer’s 
best judgment, according to the guidelines below, but with a large degree of 
randomness intended. The objectives and sub-objective anomalies needed will 
depend on the scenario, described above. 

The first things to place are the player tokens. Put each one somewhere on the 
map. Anywhere you want. You can’t really go wrong. They can be close together or
far apart, near the map edge or right in the middle. Whatever. By default, you 
can refer to them as Red Drone and Blue Drone. Choose their orientation at 
random (roll a die for it, if you’d like). 

Next you will place anomalies. Some anomalies might be fixed on the map, but 
most are placed at the start of the game by the Cartographer. When placing the 
anomalies, there are certain rules required for each. Otherwise, they should be
distributed fairly evenly around the map. 

ANOMALIES: 

Below you will find the description of each kind of anomaly, which you can read
when one is identified during play. Most identification occurs as a result of a
Survey. If the objective of the scenario is a drone, you may place its flare
beacon on the map to start. 
Objective(s), and sub-objective anomalies. These are also known as scenario 
objects, any anomaly placed on the map that is unique to the scenario being
played. These objects cannot be placed within one step of the map edge, but
otherwise can be anywhere (except as specified in the scenario). It is 
recommended, but not necessarily required, that these anomalies not be the 
closest anomaly to any player at the start of the game. Interact: move to this
hex and perform the interaction according to the scenario. 

2x Mycelium tunnel -  It’s a carnivorous mushroom worm. Place two of these on 
the map sharing a perfect straight line of hexes, forming the two ends of a 
long tunnel. 
    Interact: move to this hex, then magically appear on the other end of the 
    tunnel. The cartographer reports the direction and distance traveled, then 
    gives the color and relative altitude of the ending hex, which contains an 
    identical anomaly. 

3x Geyser - Geothermal activity causes blasts of hot water to shoot into the 
sky! 
    Interact: move to this hex. Then move the player drone 2 hexes in a 
    direction of their choice, ignoring barriers. Then the Cartographer reports
    the color and relative altitude of the arrival hex. There can be more than
    one of these, but they cannot be placed within 2 steps of the map edge. 

1x Survival Cairn - This was left behind as a marker during the previous mission
    in this region. 
    Interact: Move to this hex, then the Cartographer gives the Rough Direction
    of the nearest scenario object. 

1x Radio Booster - An ancient bla bla bla
    Interact: Cartographer reports the exact distance, but not direction, of the
    nearest objective.

1x Probe Station - This device flies a high altitude sensor probe up into the
atmosphere. You can download some data from it to get a low-resolution view of 
the ground. 
    Interact: Move to this hex. Then, for all six directions starting with the
    north and proceeding clockwise, give the number of steps needed to reach a
    hex of a different biome color. Secondly, if there is an active
    Weatherstatus, the players may discard it. 

Player Drone Blue - 
    The two player drones cannot overlap position. They cannot end any movement
    sharing a hex with one another. 
Player Drone Red - 
    Both drones can Interact with the other if they are adjacent: Cartographer
    reports the direction of the non-acting drone’s North orientation according
    to the acting drone’s compass. 

Flare Beacon - These are only placed by players and do not start on the board.
    Interact: move to this hex. If you have expended your beacon, collect this
    one, remove it from the board and regain use of this ability.


TRANSMISSION DECK:

Also on the table is a deck of Transmission Cards. Beside the cards set a track
or d10—this is the funding timer. When it runs out, the program is shuttered 
and the players lose the game.

After both drones have executed their turns, the players draw one card from the
deck. There are a few types of cards. Event cards execute discrete effects, and
Status cards result in ongoing effects. Status cards come in two flavors: 
Weather and Mission Control. Any type of card can be marked with a countdown 
symbol; when a card is drawn that has this symbol, tick the funding timer down 
once. 

For all cards, when drawn, the players read the effect, then in the case of
Event cards, the Cartographer then takes over to execute the effect. For Status
cards, only one of each variety (weather and mission control) can be in play at
any time. If you draw one of these while another of the same type is already in
play, the in-play card is discarded and the new card takes its place. 

Once you’ve resolved the Transmission Card, the “round” of play is concluded,
and players can begin to execute their next turns.
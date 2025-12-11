# FreeRun

FreeRun is a personal project of mine where eventually the end product will be a polished 2D ininite platformer.
I am also using it as my oportunity to expand on my knowladge of C by writing this game in C++.

## Stage of development.

<br>
Now that procudural chunk generation and collision and even acceleraion is fully finished I have been thinking of what to actually make the game about.
A great idea i have had is an acceleration - speed based ininate runner game where you get a better score the faster you go. Alongside moer polished features like acceleration 
partials and score and more types of tiles for the game to have. This is an exciting stage of the game development because i can really make it the fun game it was always meant to be.

## screenshots

<img width="2252" height="1046" alt="image" src="https://github.com/user-attachments/assets/d91c5e59-20be-4dfb-8c0f-c7e57e5509d5" />
Game in it's current state ready for making it a release!

## If you would like to build it yourself

for linux run in the root of the directory:

```

  ./build.sh

```

This file simply compiles the code using g++ and will run the output file.

<br>

## Dependancies

This game uses **raylib** and is compiled using **g++**.

### to install

(assuming your on a debian distro of linux)

```

  sudo apt install g++
  sudo apt install libraylib-dev

```


## past stages of development
<hr>

### 4 DEC 2025

I am now at the point where i am confident in making the game proceduraly generate chunks, as of now  i have properly
pollished the movement and falling and jumping parts and the game incldudes an animation calss which are basic fundamentals of the game,
as of now i have started on the chunks being generated around the player (8 at a time) and being generated from a 3D array so it is "procedurally
generated". this is far greater than most prjects i have done and have pushed my limits which is somthing really enjoable and nice to say!

<hr>

### 26 NOV 2025

<hr>
Currently this is only on a really early build whith working out movment and classes but screenshots will be availble further into devleopment

Right now ive focused on the core features of the game. Collision, drawing tiles for a map and over all polish.
Games usually suffer from being too "Floaty" so i have spent a vast amount of time adjusting and tweaking the movment
to fell somthing more relaistic and nicer to use. Also the collision doesnt try to fake anything, it is made to work and wokr well.
With directional collision for the player for accurate stops on the map.
<hr>

# FreeRun

FreeRun is a personal project of mine where eventually the end product will be a polished 2D ininite platformer.
I am also using it as my oportunity to expand on my knowladge of C by writing this game in C++.

## Stage of development.

<br>
Now that procudural chunk generation and collision and even acceleraion is fully finished I have been thinking of what to actually make the game about.
A great idea I have had is an acceleration - speed based runner game where you get a better score the faster you go. Alongside more polished features like acceleration and score, and more types of tiles for the game to have. This is an exciting stage of the game development because I can really make it the fun game it was always meant to be.

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

(assuming your on a debian distro of linux which uses apt)

```

  sudo apt install g++
  sudo apt install libraylib-dev

```


## past stages of development
<hr>

### 4 DEC 2025

I am now at the point where I am confident in making the game proceduraly generate chunks, as of now I have properly
polished the movement and falling and jumping parts and the game includes an animation class which are basic fundamentals of the game,
as of now I have started on the chunks being generated around the player (8 at a time) and being generated from a 3D array so it is "procedurally
generated". This is far greater than most projects I have done and I have pushed my limits which is somthing really enjoyable and nice to say!

<hr>

### 26 NOV 2025

<hr>
Currently this is only on a really early build with working out movement and classes but screenshots will be available further into development.

Right now I've focused on the core features of the game. Collision, drawing tiles for a map and over all polish.
Games usually suffer from being too "floaty" so I have spent a vast amount of time adjusting and tweaking the movement
to fell somthing more realistic and nicer to use. Also the collision doesn't try to fake anything, it is made to work and work well with directional collision for the player for accurate stops on the map.
<hr>

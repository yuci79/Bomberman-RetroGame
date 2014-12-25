#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_ttf.h>
#include <iostream>
using namespace std;


int main()
{
srand ( time(NULL) );
for (int t=0;t<10;t++)
{
    int random_x;
    random_x = rand() % 25;
    cout<< "\nRandom X = "<<random_x;
} 
}

#include "dialogue.h"

void levelDlg(SDL_Surface *screen, Background *dialogue, int *dialogueCheck, int *i, int maxframe, int *inputs, int ctrlChoice)
{
    printf("Func entry\n");
    int inDialogue = 1;
    SDL_Event event;
    while (inDialogue)
    {
        SDL_WaitEvent(&event);
        afficherDialogue(*dialogue, screen, *i);
        printf("i = %d\n", *i);
        SDL_Flip(screen);
        if (*i >= maxframe) // end of dialogue
        {
            SDL_Delay(2500);
            *i = *(i) + 1;
            *dialogueCheck = 1;
            inDialogue = 0;
        }
        switch (event.type)
        {
        case SDL_QUIT:
            SDL_Quit();
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE: // skip dialogue
                *dialogueCheck = 1;
                inDialogue = 0;
                *i = maxframe + 1;
                break;
            case SDLK_DOWN:
                *i = *(i) + 1;
                break;
            }
        }
    }

    /*else if (ctrlChoice == 2)
    {
        afficherDialogue(*dialogue, screen, *i);
        printf("i = %d\n", *i);
        SDL_Flip(screen);
        if (*i >= maxframe) // end of dialogue
        {
            SDL_Delay(2500);
            *i = *(i) + 1;
            *dialogueCheck = 1;
            inDialogue = 0;
        }
        int Up = inputs[0];
        int Down = inputs[1];
        int Left = inputs[4];
        int Right = inputs[3];
        int X = inputs[2];
        int Y = inputs[6];
        int A = inputs[5];
        int B = inputs[7];
        if (Down == 1)
        {
            *i = *(i) + 1;
        }
        if (Y == 1)
        {
            *dialogueCheck = 1;
            inDialogue = 0;
            *i = maxframe + 1;
        }
    }*/
}

void afficherDialogue(Background b, SDL_Surface *screen, int i)
{
    SDL_BlitSurface(b.images[i], &b.camera_pos, screen, &b.rect);
}
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<vector>
#include<list>


using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background, *montana, *montana3, *personaje[4], *barras[6];

SDL_Rect rect_background, rect_montana, rect_montana3, rect_barra1;



void iniciar()
{

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"3.png");
//    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = 650;
    rect_background.h = 520;

    barras[0] = IMG_LoadTexture(renderer,"barra1.png");
    barras[1] = IMG_LoadTexture(renderer,"barra2.png");
    barras[2] = IMG_LoadTexture(renderer,"barra3.png");
    barras[3] = IMG_LoadTexture(renderer,"barra4.png");
    barras[4] = IMG_LoadTexture(renderer,"barra5.png");
    barras[5] = IMG_LoadTexture(renderer,"perder.png");

    montana = IMG_LoadTexture(renderer, "montana1.png");
    rect_montana.x =0;
    rect_montana.y =100;
    rect_montana.w = 650;
    rect_montana.h = 450;

    montana3 = IMG_LoadTexture(renderer, "montana3.png");
    rect_montana3.x =0;
    rect_montana3.y =180;
    rect_montana3.w = 650;
    rect_montana3.h = 300;



//    list<Personaje*> personajes;
//    personajes.push_back(new Sho(renderer,&personajes));
//    personajes.push_back(new EnemigoVerde(renderer,&personajes));
//    personajes.push_back(new EnemigoRojo(renderer,&personajes));

    //Main Loop
    int frame=0;
    int frames_montanas=0;
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }

            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return;
                }

                if(Event.key.keysym.sym == SDLK_p){
                    break;
                }
            }
        }

        if(frames_montanas%20==0){
            frames_montanas = rect_montana3.x--;
//            frames_montanas = rect_montana.x++;
        }

        if(frames_montanas%50==0){
//            frames_montanas = rect_montana3.x--;
            frames_montanas = rect_montana.x++;
        }


        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, background, NULL, &rect_background);



        cout<<frame<<endl;



        SDL_RenderCopy(renderer, montana, NULL, &rect_montana);
        SDL_Rect m_temp = rect_montana;
        m_temp.x-=650;
        SDL_RenderCopy(renderer, montana, NULL, &m_temp);

        if(rect_montana.x>650){
            rect_montana.x=0;
        }

        SDL_RenderCopy(renderer, montana3, NULL, &rect_montana3);
        SDL_Rect r_temp = rect_montana3;
        r_temp.x+=650;
        SDL_RenderCopy(renderer, montana3, NULL, &r_temp);

//        SDL_RenderCopy(renderer, barras[0], NULL, &rect_barra1);

        if(rect_montana3.x<-650)
            rect_montana3.x=0;


//        for(list<Personaje*>::iterator p=personajes.begin();
//                p!=personajes.end();
//                p++)
//            (*p)->draw(renderer);

//        for(list<Personaje*>::iterator p=personajes.begin();
//                p!=personajes.end();
//                p++)
//            if((*p)->muerto)
//            {
//                personajes.erase(p);
//                break;
//            }



        frame++;
        frames_montanas++;

        if(frame > 0 && frame < 1500){
            rect_barra1.x = 10;
            rect_barra1.y = 485;
            rect_barra1.w = 200;
            rect_barra1.h = 30;
            SDL_RenderCopy(renderer, barras[0], NULL, &rect_barra1);
        }
        else if(frame>1500 && frame < 3000){
            rect_barra1.x = 10;
            rect_barra1.y = 485;
            rect_barra1.w = 200;
            rect_barra1.h = 30;
            SDL_RenderCopy(renderer, barras[1], NULL, &rect_barra1);
        }
        else if(frame>3000 && frame < 4500){
            rect_barra1.x = 10;
            rect_barra1.y = 485;
            rect_barra1.w = 200;
            rect_barra1.h = 30;
            SDL_RenderCopy(renderer, barras[2], NULL, &rect_barra1);
        }
        else if(frame>4500 && frame < 5000){
            rect_barra1.x = 10;
            rect_barra1.y = 485;
            rect_barra1.w = 200;
            rect_barra1.h = 30;
            SDL_RenderCopy(renderer, barras[3], NULL, &rect_barra1);
        }
        else if(frame>5000 && frame < 6000){
            rect_barra1.x = 10;
            rect_barra1.y = 485;
            rect_barra1.w = 200;
            rect_barra1.h = 30;
            SDL_RenderCopy(renderer, barras[4], NULL, &rect_barra1);
        }
        else if(frame>6000){
            rect_barra1.x = 0;
            rect_barra1.y = 0;
            rect_barra1.w = 650;
            rect_barra1.h = 520;
            SDL_RenderCopy(renderer, barras[5], NULL, &rect_barra1);
        }

        if(frame>6300)
            break;

        SDL_RenderPresent(renderer);
    }
}

void menu()
{

    int opcion = 1;
    SDL_Texture *menu[3];
    menu[0] = IMG_LoadTexture(renderer,"menu1.png");
    menu[1] = IMG_LoadTexture(renderer,"menu2.png");
    menu[2] = IMG_LoadTexture(renderer,"menu3.png");

    SDL_Rect menu_rect;
//    SDL_QueryTexture(menu[0], NULL, NULL, 500, 650);
    menu_rect.x = 0;
    menu_rect.y = 0;
    menu_rect.h= 520;
    menu_rect.w = 650;

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_2)
                {
                    exit(0);
                }
                if(Event.key.keysym.sym == SDLK_1)
                {
                    iniciar();
                }
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return;
                }
                if(Event.key.keysym.sym == SDLK_DOWN)
                {
                    opcion++;
                    if(opcion > 3)
                        opcion = 3;
                }
                if(Event.key.keysym.sym == SDLK_UP)
                {
                    opcion--;
                    if(opcion < 1)
                        opcion = 1;
                }
                if(Event.key.keysym.sym == SDLK_RETURN)
                {
                    switch(opcion)
                    {
                        case 1:
//                            loopJuego();
                        break;
                        case 2:
                            iniciar();
                        break;
                        case 3:
                            exit(0);
                        break;
                    }
                }
            }
        }
        SDL_RenderCopy(renderer,menu[opcion-1],NULL,&menu_rect);

        SDL_RenderPresent(renderer);
    }
}

int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Windo
    if((window = SDL_CreateWindow("Menu Principal", 100, 100, 650/*WIDTH*/, 520/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    menu();
	return 0;
}


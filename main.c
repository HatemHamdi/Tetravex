#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>




typedef struct score score;
struct score
{
    char nom[100];
    char prenom[100];
    int best;
};


SDL_Surface* fenetre;
char nom[700];
char prenom[700];

int x=1;

inline void intialisation()
{
    SDL_Init( SDL_INIT_VIDEO );
    fenetre = SDL_SetVideoMode(1024, 668, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Test", NULL);
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF);
    TTF_Init();
}


inline void cleanup()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


inline void afficher_image( int x, int y, char *imagepath)
{
    SDL_Surface* image = IMG_Load(imagepath);
    SDL_Rect imageDestination;
    imageDestination.x = x;
    imageDestination.y = y;
    SDL_BlitSurface( image ,NULL, fenetre, &imageDestination );
    SDL_FreeSurface(image);
}


inline void afficher_texte( int x, int y, int taille, char *ch, int R, int G,int B)
{
    TTF_Font* Font = TTF_OpenFont("Fichiers/Fonts/font.ttf",taille);
    SDL_Color color = {R, G, B};
    SDL_Surface* surface = TTF_RenderText_Solid(Font,ch,color);
    SDL_Rect texteDestination;
    texteDestination.x = x;
    texteDestination.y = y;
    SDL_BlitSurface(surface,NULL,fenetre,&texteDestination);
    SDL_FreeSurface(surface);
    TTF_CloseFont(Font);
}



void affich_rank()
{
    score t[100];
    char s[200];
    int n=0;
    int a,f;

    FILE *fp=fopen("user.txt","r");
    while(!feof(fp))
    {
        fgets(s,100,fp);
        sscanf(s,"%d | %s | %s | %d | %d",&a,t[n].nom,t[n].prenom,&t[n].best,&f);
        n++;
    }
    fclose(fp);

    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(t[j].best>t[j+1].best)
            {
                score tmp=t[j];
                t[j]=t[j+1];
                t[j+1]=tmp;
            }
        }
    }

    char ch[300];
    int y=337;
    for(j=0; j<n; j++)
    {
        sprintf(ch,"%s %s %d",t[j].nom,t[j].prenom,t[j].best);
        afficher_texte(375,y,23, ch, 40,40,40);
        y+=25;
    }
}


inline void game()
{
    srand(time(NULL));
    int g=(rand()%2)+1;
    SDL_Event event;



//afficher_image(0,0,"Fichiers/Images/background.png");
    SDL_Surface *bg=IMG_Load("Fichiers/Images/background.jpg");
    SDL_Rect dbg;
    dbg.x=0;
    dbg.y=0;

    if(x==1)
    {

        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
        Mix_Music *musique; //Création du pointeur de type Mix_Music
        musique = Mix_LoadMUS("Fichiers/musique4.mp3"); //Chargement de la musique

        Mix_PlayMusic(musique, -1);

    }



    // afficher_image(0,0,"Fichiers/Images/background.png");

    int onclick1 = 0;
    int onclick2 = 0;
    int onclick3 = 0;
    int onclick4 = 0;
    int onclick5 = 0;
    int onclick6 = 0;
    int onclick7 = 0;
    int onclick8 = 0;
    int onclick9 = 0;

    int continuer = 1;

    SDL_Rect imageDestination1;
    imageDestination1.x = 569.7;
    imageDestination1.y = 92;
    SDL_Rect imageDestination2;
    imageDestination2.x = 697.2;
    imageDestination2.y = 92;
    SDL_Rect imageDestination3;
    imageDestination3.x = 825;
    imageDestination3.y = 92;
    SDL_Rect imageDestination4;
    imageDestination4.x = 569.7;
    imageDestination4.y = 262.2;
    SDL_Rect imageDestination5;
    imageDestination5.x = 697.2;
    imageDestination5.y = 262.2;
    SDL_Rect imageDestination6;
    imageDestination6.x = 825;
    imageDestination6.y = 262.2;
    SDL_Rect imageDestination7;
    imageDestination7.x = 569.7;
    imageDestination7.y = 431.8;
    SDL_Rect imageDestination8;
    imageDestination8.x = 697.2;
    imageDestination8.y = 431.8;
    SDL_Rect imageDestination9;
    imageDestination9.x = 825;
    imageDestination9.y = 431.8;
    SDL_Rect imageDestination10;
    imageDestination10.x = 42;
    imageDestination10.y = 92;
    SDL_Rect imageDestination11;
    imageDestination11.x = 166;
    imageDestination11.y = 92;
    SDL_Rect imageDestination12;
    imageDestination12.x = 290;
    imageDestination12.y = 92;
    SDL_Rect imageDestination13;
    imageDestination13.x = 42;
    imageDestination13.y = 262;
    SDL_Rect imageDestination14;
    imageDestination14.x = 166;
    imageDestination14.y = 262;
    SDL_Rect imageDestination15;
    imageDestination15.x = 290;
    imageDestination15.y = 262;
    SDL_Rect imageDestination16;
    imageDestination16.x = 42;
    imageDestination16.y = 431.8;
    SDL_Rect imageDestination17;
    imageDestination17.x = 166;
    imageDestination17.y = 431.8;
    SDL_Rect imageDestination18;
    imageDestination18.x = 290;
    imageDestination18.y = 431.8;


    SDL_Surface *image1,*image2,*image3,*image4,*image5,*image6,*image7,*image8,*image9,*image10,*image11,*image12,*image13,*image14,*image15,*image16,*image17,*image18;
   // g=3;
    switch (g)
    {
    case 1:
    {
        image1 = IMG_Load("Fichiers/Images/1.png");
        image2 = IMG_Load("Fichiers/Images/2.png");
        image3 = IMG_Load("Fichiers/Images/3.png");
        image4 = IMG_Load("Fichiers/Images/4.png");
        image5 = IMG_Load("Fichiers/Images/5.png");
        image6 = IMG_Load("Fichiers/Images/6.png");
        image7 = IMG_Load("Fichiers/Images/7.png");
        image8 = IMG_Load("Fichiers/Images/8.png");
        image9 = IMG_Load("Fichiers/Images/9.png");
        image10 = IMG_Load("Fichiers/Images/mouraba3.png");
        image11 = IMG_Load("Fichiers/Images/mouraba3.png");
        image12 = IMG_Load("Fichiers/Images/mouraba3.png");
        image13 = IMG_Load("Fichiers/Images/mouraba3.png");
        image14 = IMG_Load("Fichiers/Images/mouraba3.png");
        image15 = IMG_Load("Fichiers/Images/mouraba3.png");
        image16 = IMG_Load("Fichiers/Images/mouraba3.png");
        image17 = IMG_Load("Fichiers/Images/mouraba3.png");
        image18 = IMG_Load("Fichiers/Images/mouraba3.png");
    }
    break;

    case 2:
    {
        image1 = IMG_Load("Fichiers/Images/10.png");
        image2 = IMG_Load("Fichiers/Images/11.png");
        image3 = IMG_Load("Fichiers/Images/12.png");
        image4 = IMG_Load("Fichiers/Images/13.png");
        image5 = IMG_Load("Fichiers/Images/14.png");
        image6 = IMG_Load("Fichiers/Images/15.png");
        image7 = IMG_Load("Fichiers/Images/16.png");
        image8 = IMG_Load("Fichiers/Images/17.png");
        image9 = IMG_Load("Fichiers/Images/18.png");
        image10 = IMG_Load("Fichiers/Images/mouraba3.png");
        image11 = IMG_Load("Fichiers/Images/mouraba3.png");
        image12 = IMG_Load("Fichiers/Images/mouraba3.png");
        image13 = IMG_Load("Fichiers/Images/mouraba3.png");
        image14 = IMG_Load("Fichiers/Images/mouraba3.png");
        image15 = IMG_Load("Fichiers/Images/mouraba3.png");
        image16 = IMG_Load("Fichiers/Images/mouraba3.png");
        image17 = IMG_Load("Fichiers/Images/mouraba3.png");
        image18 = IMG_Load("Fichiers/Images/mouraba3.png");
    }
    break;

    case 3:
    {
        image1 = IMG_Load("Fichiers/Images/19.png");
        image2 = IMG_Load("Fichiers/Images/20.png");
        image3 = IMG_Load("Fichiers/Images/21.png");
        image4 = IMG_Load("Fichiers/Images/22.png");
        image5 = IMG_Load("Fichiers/Images/23.png");
        image6 = IMG_Load("Fichiers/Images/24.png");
        image7 = IMG_Load("Fichiers/Images/25.png");
        image8 = IMG_Load("Fichiers/Images/26.png");
        image9 = IMG_Load("Fichiers/Images/27.png");
        image10 = IMG_Load("Fichiers/Images/mouraba3.png");
        image11 = IMG_Load("Fichiers/Images/mouraba3.png");
        image12 = IMG_Load("Fichiers/Images/mouraba3.png");
        image13 = IMG_Load("Fichiers/Images/mouraba3.png");
        image14 = IMG_Load("Fichiers/Images/mouraba3.png");
        image15 = IMG_Load("Fichiers/Images/mouraba3.png");
        image16 = IMG_Load("Fichiers/Images/mouraba3.png");
        image17 = IMG_Load("Fichiers/Images/mouraba3.png");
        image18 = IMG_Load("Fichiers/Images/mouraba3.png");

    }
    break;

    }

    // afficher_image(0,0,"Fichiers/Images/background.png");


        SDL_BlitSurface( image1 ,NULL, fenetre, &imageDestination1 );
        SDL_BlitSurface( image2 ,NULL, fenetre, &imageDestination2 );
        SDL_BlitSurface( image3 ,NULL, fenetre, &imageDestination3 );
        SDL_BlitSurface( image4 ,NULL, fenetre, &imageDestination4 );
        SDL_BlitSurface( image5 ,NULL, fenetre, &imageDestination5 );
        SDL_BlitSurface( image9 ,NULL, fenetre, &imageDestination9 );
        SDL_BlitSurface( image6 ,NULL, fenetre, &imageDestination6 );
        SDL_BlitSurface( image7 ,NULL, fenetre, &imageDestination7 );
        SDL_BlitSurface( image8 ,NULL, fenetre, &imageDestination8 );
        SDL_BlitSurface( image10 ,NULL, fenetre, &imageDestination10 );
        SDL_BlitSurface( image11 ,NULL, fenetre, &imageDestination11 );
        SDL_BlitSurface( image12 ,NULL, fenetre, &imageDestination12 );
        SDL_BlitSurface( image13 ,NULL, fenetre, &imageDestination13 );
        SDL_BlitSurface( image14 ,NULL, fenetre, &imageDestination14 );
        SDL_BlitSurface( image15 ,NULL, fenetre, &imageDestination15 );
        SDL_BlitSurface( image16 ,NULL, fenetre, &imageDestination16 );
        SDL_BlitSurface( image17 ,NULL, fenetre, &imageDestination17 );
        SDL_BlitSurface( image18 ,NULL, fenetre, &imageDestination18 );
        SDL_BlitSurface( bg ,NULL, fenetre, &dbg );
        //afficher_image(0,0,"Fichiers/Images/background.png");


        int nb=0;
        char ch[20];
        sprintf(ch,"Le score est : %d",nb);
        afficher_texte(5, 5,40, ch,255,255,255);
        SDL_Flip(fenetre);


        while (continuer==1)
        {
            if((imageDestination6.x==imageDestination10.x)&&(imageDestination5.x==imageDestination11.x)&&(imageDestination1.x==imageDestination12.x)&&(imageDestination2.x==imageDestination13.x)&&(imageDestination3.x==imageDestination14.x)&&(imageDestination4.x==imageDestination15.x)&&(imageDestination8.x==imageDestination16.x)&&(imageDestination9.x==imageDestination17.x)&&(imageDestination7.x==imageDestination18.x)
                    &&(imageDestination6.y==imageDestination10.y)&&(imageDestination5.y==imageDestination11.y)&&(imageDestination1.y==imageDestination12.y)&&(imageDestination2.y==imageDestination13.y)&&(imageDestination3.y==imageDestination14.y)&&(imageDestination4.y==imageDestination15.y)&&(imageDestination8.y==imageDestination16.y)&&(imageDestination9.y==imageDestination17.y)&&(imageDestination7.y==imageDestination18.y))
            {

                Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
                Mix_Music *musique; //Création du pointeur de type Mix_Music
                musique = Mix_LoadMUS("Fichiers/musique.mp3"); //Chargement de la musique

                Mix_PlayMusic(musique, -1);
                int e,m;
                char n[200];
                int ab,ef,fg;
                char bc[50];
                char cd[50];


                FILE *user55=fopen("user.txt","a+");
                while(!feof(user55))
                {
                    fgets(n,100,user55);
                    sscanf(n,"%d | %s | %s | %d | %d",&ab,bc,cd,&ef,&fg);
                    if(!(( strcmp(bc,nom)==0) || (strcmp(cd,prenom)==0)))
                    {
                        m=ef;
                    }
                }
                fclose(user55);

                SDL_Surface *im;

                if(nb==9)
                {

                    char ch1[20];
                    im = IMG_Load("Fichiers/Images/fin1.png");
                    SDL_Rect im1;
                    im1.x=0;
                    im1.y=0;
                    SDL_BlitSurface( im ,NULL, fenetre, &im1 );
                    SDL_Flip(fenetre);
                    sprintf(ch,"%d",nb);
                    afficher_texte(512, 170.7,20, ch,255,255,255);
                    if(m<nb)
                    {
                        sprintf(ch1,"%d",m);
                        afficher_texte(512, 230.7,20, ch1,255,255,255);
                    }
                    else
                    {
                        afficher_texte(512, 230.7,20, ch,255,255,255);
                    }
                }
                else if((nb>9)&&(nb<=20))
                {
                        char ch1[20];
                        im = IMG_Load("Fichiers/Images/fin2.png");
                        SDL_Rect im1;
                        im1.x=0;
                        im1.y=0;
                        SDL_BlitSurface( im ,NULL, fenetre, &im1 );
                        SDL_Flip(fenetre);
                        sprintf(ch,"%d",nb);
                        afficher_texte(512, 170.7,20, ch,255,255,255);
                        if(m<nb)
                        {
                            sprintf(ch1,"%d",m);
                            afficher_texte(512, 230.7,20, ch1,255,255,255);
                        }
                        else
                        {
                            afficher_texte(512, 230.7,20, ch,255,255,255);
                        }
                    }
                    else
                    {
                        char ch1[20];
                        im = IMG_Load("Fichiers/Images/fin3.png");
                        SDL_Rect im1;
                        im1.x=0;
                        im1.y=0;
                        SDL_BlitSurface( im ,NULL, fenetre, &im1 );
                        SDL_Flip(fenetre);
                        sprintf(ch,"%d",nb);
                        afficher_texte(512, 170.7,20, ch,255,255,255);
                        if(m<nb)
                        {
                            sprintf(ch1,"%d",m);
                            afficher_texte(512, 230.7,20, ch1,255,255,255);
                        }
                        else
                        {
                            afficher_texte(512, 230.7,20, ch,255,255,255);
                        }
                    }




                int xxxxxxxxx=0;
                int a;
                char b[50];
                char c[50];
                int f;
                char s[200];
                char s1[200];

                FILE *user=fopen("user.txt","a+");
                FILE *user2=fopen("user2.txt","a+");
                while(!feof(user))
                {
                    s[0]='\0';
                    fgets(s,100,user);
                    sscanf(s,"%d | %s | %s | %d | %d",&a,b,c,&e,&f);
                    if( strcmp(b,nom)!=0 || strcmp(c,prenom)!=0 )
                    {
                        fputs(s,user2);
                    }
                    else
                    {
                        xxxxxxxxx=1;
                        if(e>nb)
                            e=nb;

                        sprintf(s1,"%d | %s | %s | %d | %d\n",a,b,c,e,f+1);
                        fputs(s1,user2);
                    }
                }

                fclose(user2);
                fclose(user);
                remove("user.txt");
                rename("user2.txt","user.txt");

                if(xxxxxxxxx==0)
                {
                    FILE *id=fopen("id.txt","a+");
                    fgets(s,100,id);
                    a=atoi(s);
                    fclose(id);

                    FILE *user=fopen("user.txt","a+");
                    sprintf(s1,"%d | %s | %s | %d | %d\n",a+1,nom,prenom,nb,1);
                    fputs(s1,user);
                    fclose(user);

                    id=fopen("id.txt","w");
                    fprintf(id,"%d",a+1);
                    fclose(id);
                }
                 affich_rank();
                SDL_Flip(fenetre);


                while(1)
                {
                    while (SDL_PollEvent(&event))
                    {
                        if (event.type == SDL_QUIT)
                        {
                            exit(0);
                        }
                        else if (event.type == SDL_KEYDOWN)
                        {
                            if (event.key.keysym.sym == SDLK_ESCAPE)
                                exit(0);
                        }


                        else if(event.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (event.button.button == SDL_BUTTON_LEFT)
                            {
                                if ( ((event.button.x >=772) && (event.button.x <=922 ))  &&  ((event.button.y >=29 ) && (event.button.y <=71  ))  )
                                {
                                    Mix_FreeMusic(musique);
                                    Mix_CloseAudio();
                                    game();
                                }
                                else

                                    if ( ((event.button.x >=84) && (event.button.x <=234 ))  &&  ((event.button.y >=29 ) && (event.button.y <=71  ))  )
                                    {
                                        Mix_FreeMusic(musique);
                                        Mix_CloseAudio();
                                        menu();

                                    }
                                     else

                                    if ( ((event.button.x >=611.7) && (event.button.x <=844 ))  &&  ((event.button.y >=142 ) && (event.button.y <=184  ))  )
                                    {
                                        system("start tetravex2.html");

                                    }



                            }
                        }
                    }
                }
            }
            else
            {
                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        continuer = 0;
                    }
                    else if (event.type == SDL_KEYDOWN)
                    {
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                            continuer = 0;
                    }
                    else if(event.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if (event.button.button == SDL_BUTTON_LEFT)
                        {
                            if ( ((event.button.x >= imageDestination1.x) && (event.button.x <= imageDestination1.x +image1->w))  &&  ((event.button.y >= imageDestination1.y) && (event.button.y <= imageDestination1.y+image1->h ))  )
                                onclick1 = 1;
                            else if ( ((event.button.x >= imageDestination2.x) && (event.button.x <= imageDestination2.x +image2->w))  &&  ((event.button.y >= imageDestination2.y) && (event.button.y <= imageDestination2.y+image2->h ))  )
                                onclick2 = 1;
                            else if ( ((event.button.x >= imageDestination3.x) && (event.button.x <= imageDestination3.x +image3->w))  &&  ((event.button.y >= imageDestination3.y) && (event.button.y <= imageDestination3.y+image3->h ))  )
                                onclick3 = 1;
                            else if ( ((event.button.x >= imageDestination4.x) && (event.button.x <= imageDestination4.x +image4->w))  &&  ((event.button.y >= imageDestination4.y) && (event.button.y <= imageDestination4.y+image4->h ))  )
                                onclick4 = 1;
                            else if ( ((event.button.x >= imageDestination5.x) && (event.button.x <= imageDestination5.x +image5->w))  &&  ((event.button.y >= imageDestination5.y) && (event.button.y <= imageDestination5.y+image5->h ))  )
                                onclick5 = 1;
                            else if ( ((event.button.x >= imageDestination6.x) && (event.button.x <= imageDestination6.x +image6->w))  &&  ((event.button.y >= imageDestination6.y) && (event.button.y <= imageDestination6.y+image6->h ))  )
                                onclick6 = 1;
                            else if ( ((event.button.x >= imageDestination7.x) && (event.button.x <= imageDestination7.x +image7->w))  &&  ((event.button.y >= imageDestination7.y) && (event.button.y <= imageDestination7.y+image7->h ))  )
                                onclick7 = 1;
                            else if ( ((event.button.x >= imageDestination8.x) && (event.button.x <= imageDestination8.x +image8->w))  &&  ((event.button.y >= imageDestination8.y) && (event.button.y <= imageDestination8.y+image8->h ))  )
                                onclick8 = 1;
                            else if ( ((event.button.x >= imageDestination9.x) && (event.button.x <= imageDestination9.x +image9->w))  &&  ((event.button.y >= imageDestination9.y) && (event.button.y <= imageDestination9.y+image9->h ))  )
                                onclick9 = 1;
                            else if ( ((event.button.x >=414) && (event.button.x <=567 ))  &&  ((event.button.y >=17.9 ) && (event.button.y <=58.2  ))  )
                                game();
                        }
                    }


                    if(event.type == SDL_MOUSEBUTTONUP)
                    {

                        if((imageDestination1.x+30 >= imageDestination10.x)&&(imageDestination1.x +image1->w -30 <=imageDestination10.x +image10->w))
                        {
                            if((imageDestination1.y+30>=imageDestination10.y)&&(imageDestination1.y +image1->h -30 <= imageDestination10.y +image10->h))
                            {
                                imageDestination1.x=imageDestination10.x;
                                imageDestination1.y=imageDestination10.y;

                            }

                        }/*else{imageDestination1.x = 569.7;
                imageDestination1.y = 92;}*/
                        if((imageDestination2.x+30 >= imageDestination10.x)&&(imageDestination2.x +image2->w -30 <=imageDestination10.x +image10->w))
                        {
                            if((imageDestination2.y+30>=imageDestination10.y)&&(imageDestination2.y +image2->h -30 <= imageDestination10.y +image10->h))
                            {
                                imageDestination2.x=imageDestination10.x;
                                imageDestination2.y=imageDestination10.y;

                            }

                        }
                        if((imageDestination3.x+30 >= imageDestination10.x)&&(imageDestination3.x +image3->w -30 <=imageDestination10.x +image10->w))
                        {
                            if((imageDestination3.y+30>=imageDestination10.y)&&(imageDestination3.y +image3->h -30 <= imageDestination10.y +image10->h))
                            {
                                imageDestination3.x=imageDestination10.x;
                                imageDestination3.y=imageDestination10.y;

                            }

                        }


                        if((imageDestination4.x+30 >= imageDestination10.x)&&(imageDestination4.x +image4->w -30 <=imageDestination10.x +image10->w))
                        {
                            if((imageDestination4.y+30>=imageDestination10.y)&&(imageDestination4.y +image4->h -30 <= imageDestination10.y +image10->h))
                            {
                                imageDestination4.x=imageDestination10.x;
                                imageDestination4.y=imageDestination10.y;

                            }

                        }

                        if((imageDestination5.x+30 >= imageDestination10.x)&&(imageDestination5.x +image5->w -30 <=imageDestination10.x +image10->w))
                        {
                            if((imageDestination5.y+30>=imageDestination10.y)&&(imageDestination5.y +image5->h -30 <= imageDestination10.y +image10->h))
                            {
                                imageDestination5.x=imageDestination10.x;
                                imageDestination5.y=imageDestination10.y;

                            }

                        }

                        if((imageDestination6.x+30 >= imageDestination10.x)&&(imageDestination6.x +image6->w -30 <=imageDestination10.x +image10->w))
                        {
                            if((imageDestination6.y+30>=imageDestination10.y)&&(imageDestination6.y +image6->h -30 <= imageDestination10.y +image10->h))
                            {
                                imageDestination6.x=imageDestination10.x;
                                imageDestination6.y=imageDestination10.y;

                            }

                        }

                        if((imageDestination7.x+30 >= imageDestination10.x)&&(imageDestination7.x +image7->w -30 <=imageDestination10.x +image10->w))
                        {
                            if((imageDestination7.y+30>=imageDestination10.y)&&(imageDestination7.y +image7->h -30 <= imageDestination10.y +image10->h))
                            {
                                imageDestination7.x=imageDestination10.x;
                                imageDestination7.y=imageDestination10.y;

                            }

                        }

                        if((imageDestination8.x+30 >= imageDestination10.x)&&(imageDestination8.x +image8->w -30 <=imageDestination10.x +image10->w))
                        {
                            if((imageDestination8.y+30>=imageDestination10.y)&&(imageDestination8.y +image8->h -30 <= imageDestination10.y +image10->h))
                            {
                                imageDestination8.x=imageDestination10.x;
                                imageDestination8.y=imageDestination10.y;

                            }

                        }

                        if((imageDestination9.x+30 >= imageDestination10.x)&&(imageDestination9.x +image9->w -30 <=imageDestination10.x +image10->w))
                        {
                            if((imageDestination9.y+30>=imageDestination10.y)&&(imageDestination9.y +image9->h -30 <= imageDestination10.y +image10->h))
                            {
                                imageDestination9.x=imageDestination10.x;
                                imageDestination9.y=imageDestination10.y;

                            }
                        }

                        if((imageDestination1.x+30 >= imageDestination11.x)&&(imageDestination1.x +image1->w -30 <=imageDestination11.x +image11->w))
                        {
                            if((imageDestination1.y+30>=imageDestination11.y)&&(imageDestination1.y +image1->h -30 <= imageDestination11.y +image11->h))
                            {
                                imageDestination1.x=imageDestination11.x;
                                imageDestination1.y=imageDestination11.y;

                            }

                        }
                        if((imageDestination2.x+30 >= imageDestination11.x)&&(imageDestination2.x +image2->w -30 <=imageDestination11.x +image11->w))
                        {
                            if((imageDestination2.y+30 >=imageDestination11.y)&&(imageDestination2.y +image2->h -30 <= imageDestination11.y +image11->h))
                            {
                                imageDestination2.x=imageDestination11.x;
                                imageDestination2.y=imageDestination11.y;

                            }

                        }
                        if((imageDestination3.x+30 >= imageDestination11.x)&&(imageDestination3.x +image3->w -30 <=imageDestination11.x +image11->w))
                        {
                            if((imageDestination3.y+30>=imageDestination11.y)&&(imageDestination3.y +image3->h -30 <= imageDestination11.y +image11->h))
                            {
                                imageDestination3.x=imageDestination11.x;
                                imageDestination3.y=imageDestination11.y;

                            }

                        }

                        if((imageDestination4.x+30 >= imageDestination11.x)&&(imageDestination4.x +image4->w -30 <=imageDestination11.x +image11->w))
                        {
                            if((imageDestination4.y+30>=imageDestination11.y)&&(imageDestination4.y +image4->h -30 <= imageDestination11.y +image11->h))
                            {
                                imageDestination4.x=imageDestination11.x;
                                imageDestination4.y=imageDestination11.y;

                            }

                        }

                        if((imageDestination5.x+30 >= imageDestination11.x)&&(imageDestination5.x +image5->w -30 <=imageDestination11.x +image11->w))
                        {
                            if((imageDestination5.y+30>=imageDestination11.y)&&(imageDestination5.y +image5->h -30 <= imageDestination11.y +image11->h))
                            {
                                imageDestination5.x=imageDestination11.x;
                                imageDestination5.y=imageDestination11.y;

                            }

                        }

                        if((imageDestination6.x+30 >= imageDestination11.x)&&(imageDestination6.x +image6->w -30 <=imageDestination11.x +image11->w))
                        {
                            if((imageDestination6.y+30>=imageDestination11.y)&&(imageDestination6.y +image6->h -30 <= imageDestination11.y +image11->h))
                            {
                                imageDestination6.x=imageDestination11.x;
                                imageDestination6.y=imageDestination11.y;

                            }

                        }

                        if((imageDestination7.x+30 >= imageDestination11.x)&&(imageDestination7.x +image7->w -30 <=imageDestination11.x +image11->w))
                        {
                            if((imageDestination7.y+30>=imageDestination11.y)&&(imageDestination7.y +image7->h -30 <= imageDestination11.y +image11->h))
                            {
                                imageDestination7.x=imageDestination11.x;
                                imageDestination7.y=imageDestination11.y;

                            }

                        }

                        if((imageDestination8.x+30 >= imageDestination11.x)&&(imageDestination8.x +image8->w -30 <=imageDestination11.x +image11->w))
                        {
                            if((imageDestination8.y+30>=imageDestination11.y)&&(imageDestination8.y +image8->h -30 <= imageDestination11.y +image11->h))
                            {
                                imageDestination8.x=imageDestination11.x;
                                imageDestination8.y=imageDestination11.y;

                            }

                        }
                        if((imageDestination9.x+30 >= imageDestination11.x)&&(imageDestination9.x +image9->w -30 <=imageDestination11.x +image11->w))
                        {
                            if((imageDestination9.y+30>=imageDestination11.y)&&(imageDestination9.y +image9->h -30 <= imageDestination11.y +image11->h))
                            {
                                imageDestination9.x=imageDestination11.x;
                                imageDestination9.y=imageDestination11.y;

                            }

                        }


                        if((imageDestination1.x+30 >= imageDestination12.x)&&(imageDestination1.x +image1->w -30 <=imageDestination12.x +image12->w))
                        {
                            if((imageDestination1.y+30>=imageDestination12.y)&&(imageDestination1.y +image1->h -30 <= imageDestination12.y +image12->h))
                            {
                                imageDestination1.x=imageDestination12.x;
                                imageDestination1.y=imageDestination12.y;

                            }

                        }
                        if((imageDestination2.x+30 >= imageDestination12.x)&&(imageDestination2.x +image2->w -30 <=imageDestination12.x +image12->w))
                        {
                            if((imageDestination2.y+30>=imageDestination12.y)&&(imageDestination2.y +image2->h -30 <= imageDestination12.y +image12->h))
                            {
                                imageDestination2.x=imageDestination12.x;
                                imageDestination2.y=imageDestination12.y;

                            }

                        }
                        if((imageDestination3.x+30 >= imageDestination12.x)&&(imageDestination3.x +image3->w -30 <=imageDestination12.x +image12->w))
                        {
                            if((imageDestination3.y+30>=imageDestination12.y)&&(imageDestination3.y +image3->h -30 <= imageDestination12.y +image12->h))
                            {
                                imageDestination3.x=imageDestination12.x;
                                imageDestination3.y=imageDestination12.y;

                            }

                        }

                        if((imageDestination4.x+30 >= imageDestination12.x)&&(imageDestination4.x +image4->w -30 <=imageDestination12.x +image12->w))
                        {
                            if((imageDestination4.y+30>=imageDestination12.y)&&(imageDestination4.y +image4->h -30 <= imageDestination12.y +image12->h))
                            {
                                imageDestination4.x=imageDestination12.x;
                                imageDestination4.y=imageDestination12.y;

                            }

                        }

                        if((imageDestination5.x+30 >= imageDestination12.x)&&(imageDestination5.x +image5->w -30 <=imageDestination12.x +image12->w))
                        {
                            if((imageDestination5.y+30>=imageDestination12.y)&&(imageDestination5.y +image5->h -30 <= imageDestination12.y +image12->h))
                            {
                                imageDestination5.x=imageDestination12.x;
                                imageDestination5.y=imageDestination12.y;

                            }

                        }

                        if((imageDestination6.x+30 >= imageDestination12.x)&&(imageDestination6.x +image6->w -30 <=imageDestination12.x +image12->w))
                        {
                            if((imageDestination6.y+30>=imageDestination12.y)&&(imageDestination6.y +image6->h -30 <= imageDestination12.y +image12->h))
                            {
                                imageDestination6.x=imageDestination12.x;
                                imageDestination6.y=imageDestination12.y;

                            }

                        }

                        if((imageDestination7.x+30 >= imageDestination12.x)&&(imageDestination7.x +image7->w -30 <=imageDestination12.x +image12->w))
                        {
                            if((imageDestination7.y+30>=imageDestination12.y)&&(imageDestination7.y +image7->h -30 <= imageDestination12.y +image12->h))
                            {
                                imageDestination7.x=imageDestination12.x;
                                imageDestination7.y=imageDestination12.y;

                            }

                        }

                        if((imageDestination8.x+30 >= imageDestination12.x)&&(imageDestination8.x +image8->w -30 <=imageDestination12.x +image12->w))
                        {
                            if((imageDestination8.y+30>=imageDestination12.y)&&(imageDestination8.y +image8->h -30 <= imageDestination12.y +image12->h))
                            {
                                imageDestination8.x=imageDestination12.x;
                                imageDestination8.y=imageDestination12.y;

                            }

                        }

                        if((imageDestination9.x+30 >= imageDestination12.x)&&(imageDestination9.x +image9->w -30 <=imageDestination12.x +image12->w))
                        {
                            if((imageDestination9.y+30>=imageDestination12.y)&&(imageDestination9.y +image9->h -30 <= imageDestination12.y +image12->h))
                            {
                                imageDestination9.x=imageDestination12.x;
                                imageDestination9.y=imageDestination12.y;

                            }
                        }


                        if((imageDestination1.x+30 >= imageDestination13.x)&&(imageDestination1.x +image1->w -30 <=imageDestination13.x +image13->w))
                        {
                            if((imageDestination1.y+30>=imageDestination13.y)&&(imageDestination1.y +image1->h -30 <= imageDestination13.y +image13->h))
                            {
                                imageDestination1.x=imageDestination13.x;
                                imageDestination1.y=imageDestination13.y;

                            }

                        }
                        if((imageDestination2.x+30 >= imageDestination13.x)&&(imageDestination2.x +image2->w -30 <=imageDestination13.x +image13->w))
                        {
                            if((imageDestination2.y+30>=imageDestination13.y)&&(imageDestination2.y +image2->h -30 <= imageDestination13.y +image13->h))
                            {
                                imageDestination2.x=imageDestination13.x;
                                imageDestination2.y=imageDestination13.y;

                            }

                        }
                        if((imageDestination3.x+30 >= imageDestination13.x)&&(imageDestination3.x +image3->w -30 <=imageDestination13.x +image13->w))
                        {
                            if((imageDestination3.y+30>=imageDestination13.y)&&(imageDestination3.y +image3->h -30 <= imageDestination13.y +image13->h))
                            {
                                imageDestination3.x=imageDestination13.x;
                                imageDestination3.y=imageDestination13.y;

                            }

                        }

                        if((imageDestination4.x+30 >= imageDestination13.x)&&(imageDestination4.x +image4->w -30 <=imageDestination13.x +image13->w))
                        {
                            if((imageDestination4.y+30>=imageDestination13.y)&&(imageDestination4.y +image4->h -30 <= imageDestination13.y +image13->h))
                            {
                                imageDestination4.x=imageDestination13.x;
                                imageDestination4.y=imageDestination13.y;

                            }

                        }

                        if((imageDestination5.x+30 >= imageDestination13.x)&&(imageDestination5.x +image5->w -30 <=imageDestination13.x +image13->w))
                        {
                            if((imageDestination5.y+30>=imageDestination13.y)&&(imageDestination5.y +image5->h -30 <= imageDestination13.y +image13->h))
                            {
                                imageDestination5.x=imageDestination13.x;
                                imageDestination5.y=imageDestination13.y;

                            }

                        }

                        if((imageDestination6.x+30 >= imageDestination13.x)&&(imageDestination6.x +image6->w -30 <=imageDestination13.x +image13->w))
                        {
                            if((imageDestination6.y+30>=imageDestination13.y)&&(imageDestination6.y +image6->h -30 <= imageDestination13.y +image13->h))
                            {
                                imageDestination6.x=imageDestination13.x;
                                imageDestination6.y=imageDestination13.y;

                            }

                        }
                        if((imageDestination7.x+30 >= imageDestination13.x)&&(imageDestination7.x +image7->w -30 <=imageDestination13.x +image13->w))
                        {
                            if((imageDestination7.y+30>=imageDestination13.y)&&(imageDestination7.y +image7->h -30 <= imageDestination13.y +image13->h))
                            {
                                imageDestination7.x=imageDestination13.x;
                                imageDestination7.y=imageDestination13.y;

                            }

                        }

                        if((imageDestination8.x+30 >= imageDestination13.x)&&(imageDestination8.x +image8->w -30 <=imageDestination13.x +image13->w))
                        {
                            if((imageDestination8.y+30>=imageDestination13.y)&&(imageDestination8.y +image8->h -30 <= imageDestination13.y +image13->h))
                            {
                                imageDestination8.x=imageDestination13.x;
                                imageDestination8.y=imageDestination13.y;

                            }

                        }

                        if((imageDestination9.x+30 >= imageDestination13.x)&&(imageDestination9.x +image9->w -30 <=imageDestination13.x +image13->w))
                        {
                            if((imageDestination9.y+30>=imageDestination13.y)&&(imageDestination9.y +image9->h -30 <= imageDestination13.y +image13->h))
                            {
                                imageDestination9.x=imageDestination13.x;
                                imageDestination9.y=imageDestination13.y;

                            }
                        }


                        if((imageDestination1.x+30 >= imageDestination14.x)&&(imageDestination1.x +image1->w -30 <=imageDestination14.x +image14->w))
                        {
                            if((imageDestination1.y+30>=imageDestination14.y)&&(imageDestination1.y +image1->h -30 <= imageDestination14.y +image14->h))
                            {
                                imageDestination1.x=imageDestination14.x;
                                imageDestination1.y=imageDestination14.y;

                            }

                        }
                        if((imageDestination2.x+30 >= imageDestination14.x)&&(imageDestination2.x +image2->w -30 <=imageDestination14.x +image14->w))
                        {
                            if((imageDestination2.y+30>=imageDestination14.y)&&(imageDestination2.y +image2->h -30 <= imageDestination14.y +image14->h))
                            {
                                imageDestination2.x=imageDestination14.x;
                                imageDestination2.y=imageDestination14.y;

                            }

                        }
                        if((imageDestination3.x+30 >= imageDestination14.x)&&(imageDestination3.x +image3->w -30 <=imageDestination14.x +image14->w))
                        {
                            if((imageDestination3.y+30>=imageDestination14.y)&&(imageDestination3.y +image3->h -30 <= imageDestination14.y +image14->h))
                            {
                                imageDestination3.x=imageDestination14.x;
                                imageDestination3.y=imageDestination14.y;

                            }

                        }

                        if((imageDestination4.x+30 >= imageDestination14.x)&&(imageDestination4.x +image4->w -30 <=imageDestination14.x +image14->w))
                        {
                            if((imageDestination4.y+30>=imageDestination14.y)&&(imageDestination4.y +image4->h -30 <= imageDestination14.y +image14->h))
                            {
                                imageDestination4.x=imageDestination14.x;
                                imageDestination4.y=imageDestination14.y;

                            }
                        }

                        if((imageDestination5.x+30 >= imageDestination14.x)&&(imageDestination5.x +image5->w -30 <=imageDestination14.x +image14->w))
                        {
                            if((imageDestination5.y+30>=imageDestination14.y)&&(imageDestination5.y +image5->h -30 <= imageDestination14.y +image14->h))
                            {
                                imageDestination5.x=imageDestination14.x;
                                imageDestination5.y=imageDestination14.y;

                            }

                        }
                        if((imageDestination6.x+30 >= imageDestination14.x)&&(imageDestination6.x +image6->w -30 <=imageDestination14.x +image14->w))
                        {
                            if((imageDestination6.y+30>=imageDestination14.y)&&(imageDestination6.y +image6->h -30 <= imageDestination14.y +image14->h))
                            {
                                imageDestination6.x=imageDestination14.x;
                                imageDestination6.y=imageDestination14.y;

                            }
                        }
                        if((imageDestination7.x+30 >= imageDestination14.x)&&(imageDestination7.x +image7->w -30 <=imageDestination14.x +image14->w))
                        {
                            if((imageDestination7.y+30>=imageDestination14.y)&&(imageDestination7.y +image7->h -30 <= imageDestination14.y +image14->h))
                            {
                                imageDestination7.x=imageDestination14.x;
                                imageDestination7.y=imageDestination14.y;

                            }
                        }
                        if((imageDestination8.x+30 >= imageDestination14.x)&&(imageDestination8.x +image8->w -30 <=imageDestination14.x +image14->w))
                        {
                            if((imageDestination8.y+30>=imageDestination14.y)&&(imageDestination8.y +image8->h -30 <= imageDestination14.y +image14->h))
                            {
                                imageDestination8.x=imageDestination14.x;
                                imageDestination8.y=imageDestination14.y;

                            }

                        }

                        if((imageDestination9.x+30 >= imageDestination14.x)&&(imageDestination9.x +image9->w -30 <=imageDestination14.x +image14->w))
                        {
                            if((imageDestination9.y+30>=imageDestination14.y)&&(imageDestination9.y +image9->h -30 <= imageDestination14.y +image14->h))
                            {
                                imageDestination9.x=imageDestination14.x;
                                imageDestination9.y=imageDestination14.y;

                            }

                        }


                        if((imageDestination1.x+30 >= imageDestination15.x)&&(imageDestination1.x +image1->w -30 <=imageDestination15.x +image15->w))
                        {
                            if((imageDestination1.y+30>=imageDestination15.y)&&(imageDestination1.y +image1->h -30 <= imageDestination15.y +image15->h))
                            {
                                imageDestination1.x=imageDestination15.x;
                                imageDestination1.y=imageDestination15.y;

                            }

                        }
                        if((imageDestination2.x+30 >= imageDestination15.x)&&(imageDestination2.x +image2->w -30 <=imageDestination15.x +image15->w))
                        {
                            if((imageDestination2.y+30>=imageDestination15.y)&&(imageDestination2.y +image2->h -30 <= imageDestination15.y +image15->h))
                            {
                                imageDestination2.x=imageDestination15.x;
                                imageDestination2.y=imageDestination15.y;

                            }

                        }
                        if((imageDestination3.x+30 >= imageDestination15.x)&&(imageDestination3.x +image3->w -30 <=imageDestination15.x +image15->w))
                        {
                            if((imageDestination3.y+30 >=imageDestination15.y)&&(imageDestination3.y +image3->h -30 <= imageDestination15.y +image15->h))
                            {
                                imageDestination3.x=imageDestination15.x;
                                imageDestination3.y=imageDestination15.y;

                            }

                        }

                        if((imageDestination4.x+30 >= imageDestination15.x)&&(imageDestination4.x +image4->w -30 <=imageDestination15.x +image15->w))
                        {
                            if((imageDestination4.y+30>=imageDestination15.y)&&(imageDestination4.y +image4->h -30 <= imageDestination15.y +image15->h))
                            {
                                imageDestination4.x=imageDestination15.x;
                                imageDestination4.y=imageDestination15.y;

                            }

                        }

                        if((imageDestination5.x+30 >= imageDestination15.x)&&(imageDestination5.x +image5->w -30 <=imageDestination15.x +image15->w))
                        {
                            if((imageDestination5.y+30>=imageDestination15.y)&&(imageDestination5.y +image5->h -30 <= imageDestination15.y +image15->h))
                            {
                                imageDestination5.x=imageDestination15.x;
                                imageDestination5.y=imageDestination15.y;

                            }

                        }
                        if((imageDestination6.x+30 >= imageDestination15.x)&&(imageDestination6.x +image6->w -30 <=imageDestination15.x +image15->w))
                        {
                            if((imageDestination6.y+30>=imageDestination15.y)&&(imageDestination6.y +image6->h -30 <= imageDestination15.y +image15->h))
                            {
                                imageDestination6.x=imageDestination15.x;
                                imageDestination6.y=imageDestination15.y;

                            }

                        }

                        if((imageDestination7.x+30 >= imageDestination15.x)&&(imageDestination7.x +image7->w -30 <=imageDestination15.x +image15->w))
                        {
                            if((imageDestination7.y+30>=imageDestination15.y)&&(imageDestination7.y +image7->h -30 <= imageDestination15.y +image15->h))
                            {
                                imageDestination7.x=imageDestination15.x;
                                imageDestination7.y=imageDestination15.y;

                            }

                        }
                        if((imageDestination8.x+30 >= imageDestination15.x)&&(imageDestination8.x +image8->w -30 <=imageDestination15.x +image15->w))
                        {
                            if((imageDestination8.y+30>=imageDestination15.y)&&(imageDestination8.y +image8->h -30 <= imageDestination15.y +image15->h))
                            {
                                imageDestination8.x=imageDestination15.x;
                                imageDestination8.y=imageDestination15.y;

                            }

                        }
                        if((imageDestination9.x+30 >= imageDestination15.x)&&(imageDestination9.x +image9->w -30 <=imageDestination15.x +image15->w))
                        {
                            if((imageDestination9.y+30>=imageDestination15.y)&&(imageDestination9.y +image9->h -30 <= imageDestination15.y +image15->h))
                            {
                                imageDestination9.x=imageDestination15.x;
                                imageDestination9.y=imageDestination15.y;

                            }

                        }

                        if((imageDestination1.x+30 >= imageDestination16.x)&&(imageDestination1.x +image1->w -30 <=imageDestination16.x +image16->w))
                        {
                            if((imageDestination1.y+30>=imageDestination16.y)&&(imageDestination1.y +image1->h -30 <= imageDestination16.y +image16->h))
                            {
                                imageDestination1.x=imageDestination16.x;
                                imageDestination1.y=imageDestination16.y;

                            }

                        }
                        if((imageDestination2.x+30>= imageDestination16.x)&&(imageDestination2.x +image2->w -30 <=imageDestination16.x +image16->w))
                        {
                            if((imageDestination2.y+30>=imageDestination16.y)&&(imageDestination2.y +image2->h -30 <= imageDestination16.y +image16->h))
                            {
                                imageDestination2.x=imageDestination16.x;
                                imageDestination2.y=imageDestination16.y;

                            }

                        }
                        if((imageDestination3.x+30 >= imageDestination16.x)&&(imageDestination3.x +image3->w -30 <=imageDestination16.x +image16->w))
                        {
                            if((imageDestination3.y+30>=imageDestination16.y)&&(imageDestination3.y +image3->h -30 <= imageDestination16.y +image16->h))
                            {
                                imageDestination3.x=imageDestination16.x;
                                imageDestination3.y=imageDestination16.y;

                            }

                        }

                        if((imageDestination4.x+30>= imageDestination16.x)&&(imageDestination4.x +image4->w -30 <=imageDestination16.x +image16->w))
                        {
                            if((imageDestination4.y+30>=imageDestination16.y)&&(imageDestination4.y +image4->h -30 <= imageDestination16.y +image16->h))
                            {
                                imageDestination4.x=imageDestination16.x;
                                imageDestination4.y=imageDestination16.y;

                            }

                        }

                        if((imageDestination5.x+30 >= imageDestination16.x)&&(imageDestination5.x +image5->w -30 <=imageDestination16.x +image16->w))
                        {
                            if((imageDestination5.y+30>=imageDestination16.y)&&(imageDestination5.y +image5->h -30 <= imageDestination16.y +image16->h))
                            {
                                imageDestination5.x=imageDestination16.x;
                                imageDestination5.y=imageDestination16.y;

                            }

                        }

                        if((imageDestination6.x+30 >= imageDestination16.x)&&(imageDestination6.x +image6->w -30 <=imageDestination16.x +image16->w))
                        {
                            if((imageDestination6.y+30>=imageDestination16.y)&&(imageDestination6.y +image6->h -30 <= imageDestination16.y +image16->h))
                            {
                                imageDestination6.x=imageDestination16.x;
                                imageDestination6.y=imageDestination16.y;

                            }

                        }

                        if((imageDestination7.x+30 >= imageDestination16.x)&&(imageDestination7.x +image7->w -30 <=imageDestination16.x +image16->w))
                        {
                            if((imageDestination7.y+30>=imageDestination16.y)&&(imageDestination7.y +image7->h -30 <= imageDestination16.y +image16->h))
                            {
                                imageDestination7.x=imageDestination16.x;
                                imageDestination7.y=imageDestination16.y;

                            }

                        }

                        if((imageDestination8.x+30 >= imageDestination16.x)&&(imageDestination8.x +image8->w -30 <=imageDestination16.x +image16->w))
                        {
                            if((imageDestination8.y+30>=imageDestination16.y)&&(imageDestination8.y +image8->h -30 <= imageDestination16.y +image16->h))
                            {
                                imageDestination8.x=imageDestination16.x;
                                imageDestination8.y=imageDestination16.y;

                            }

                        }
                        if((imageDestination9.x+30 >= imageDestination16.x)&&(imageDestination9.x +image9->w -30 <=imageDestination16.x +image16->w))
                        {
                            if((imageDestination9.y+30>=imageDestination16.y)&&(imageDestination9.y +image9->h -30 <= imageDestination16.y +image16->h))
                            {
                                imageDestination9.x=imageDestination16.x;
                                imageDestination9.y=imageDestination16.y;

                            }

                        }

                        if((imageDestination1.x+30 >= imageDestination17.x)&&(imageDestination1.x +image1->w -30 <=imageDestination17.x +image17->w))
                        {
                            if((imageDestination1.y+30>=imageDestination17.y)&&(imageDestination1.y +image1->h -30 <= imageDestination17.y +image17->h))
                            {
                                imageDestination1.x=imageDestination17.x;
                                imageDestination1.y=imageDestination17.y;

                            }

                        }
                        if((imageDestination2.x+30 >= imageDestination17.x)&&(imageDestination2.x +image2->w -30 <=imageDestination17.x +image17->w))
                        {
                            if((imageDestination2.y+30>=imageDestination17.y)&&(imageDestination2.y +image2->h -30 <= imageDestination17.y +image17->h))
                            {
                                imageDestination2.x=imageDestination17.x;
                                imageDestination2.y=imageDestination17.y;

                            }

                        }
                        if((imageDestination3.x+30 >= imageDestination17.x)&&(imageDestination3.x +image3->w -30 <=imageDestination17.x +image17->w))
                        {
                            if((imageDestination3.y+30>=imageDestination17.y)&&(imageDestination3.y +image3->h -30 <= imageDestination17.y +image17->h))
                            {
                                imageDestination3.x=imageDestination17.x;
                                imageDestination3.y=imageDestination17.y;

                            }

                        }

                        if((imageDestination4.x+30 >= imageDestination17.x)&&(imageDestination4.x +image4->w -30 <=imageDestination17.x +image17->w))
                        {
                            if((imageDestination4.y+30>=imageDestination17.y)&&(imageDestination4.y +image4->h -30 <= imageDestination17.y +image17->h))
                            {
                                imageDestination4.x=imageDestination17.x;
                                imageDestination4.y=imageDestination17.y;

                            }

                        }
                        if((imageDestination5.x+30 >= imageDestination17.x)&&(imageDestination5.x +image5->w -30 <=imageDestination17.x +image17->w))
                        {
                            if((imageDestination5.y+30>=imageDestination17.y)&&(imageDestination5.y +image5->h -30 <= imageDestination17.y +image17->h))
                            {
                                imageDestination5.x=imageDestination17.x;
                                imageDestination5.y=imageDestination17.y;

                            }

                        }
                        if((imageDestination6.x+30 >= imageDestination17.x)&&(imageDestination6.x +image6->w -30 <=imageDestination17.x +image17->w))
                        {
                            if((imageDestination6.y+30>=imageDestination17.y)&&(imageDestination6.y +image6->h -30 <= imageDestination17.y +image17->h))
                            {
                                imageDestination6.x=imageDestination17.x;
                                imageDestination6.y=imageDestination17.y;

                            }

                        }
                        if((imageDestination7.x+30 >= imageDestination17.x)&&(imageDestination7.x +image7->w -30 <=imageDestination17.x +image17->w))
                        {
                            if((imageDestination7.y+30>=imageDestination17.y)&&(imageDestination7.y +image7->h -30 <= imageDestination17.y +image17->h))
                            {
                                imageDestination7.x=imageDestination17.x;
                                imageDestination7.y=imageDestination17.y;

                            }

                        }
                        if((imageDestination8.x+30 >= imageDestination17.x)&&(imageDestination8.x +image8->w -30 <=imageDestination17.x +image17->w))
                        {
                            if((imageDestination8.y+30>=imageDestination17.y)&&(imageDestination8.y +image8->h -30 <= imageDestination17.y +image17->h))
                            {
                                imageDestination8.x=imageDestination17.x;
                                imageDestination8.y=imageDestination17.y;

                            }

                        }
                        if((imageDestination9.x+30 >= imageDestination17.x)&&(imageDestination9.x +image9->w -30 <=imageDestination17.x +image17->w))
                        {
                            if((imageDestination9.y+30>=imageDestination17.y)&&(imageDestination9.y +image9->h -30 <= imageDestination17.y +image17->h))
                            {
                                imageDestination9.x=imageDestination17.x;
                                imageDestination9.y=imageDestination17.y;

                            }

                        }



                        if((imageDestination1.x+30 >= imageDestination18.x)&&(imageDestination1.x +image1->w -30 <=imageDestination18.x +image18->w))
                        {
                            if((imageDestination1.y+30>=imageDestination18.y)&&(imageDestination1.y +image1->h -30 <= imageDestination18.y +image18->h))
                            {
                                imageDestination1.x=imageDestination18.x;
                                imageDestination1.y=imageDestination18.y;

                            }

                        }
                        if((imageDestination2.x+30 >= imageDestination18.x)&&(imageDestination2.x +image2->w -30 <=imageDestination18.x +image18->w))
                        {
                            if((imageDestination2.y+30>=imageDestination18.y)&&(imageDestination2.y +image2->h -30 <= imageDestination18.y +image18->h))
                            {
                                imageDestination2.x=imageDestination18.x;
                                imageDestination2.y=imageDestination18.y;

                            }

                        }
                        if((imageDestination3.x+30 >= imageDestination18.x)&&(imageDestination3.x +image3->w -30 <=imageDestination18.x +image18->w))
                        {
                            if((imageDestination3.y+30>=imageDestination18.y)&&(imageDestination3.y +image3->h -30 <= imageDestination18.y +image18->h))
                            {
                                imageDestination3.x=imageDestination18.x;
                                imageDestination3.y=imageDestination18.y;

                            }

                        }

                        if((imageDestination4.x+30 >= imageDestination18.x)&&(imageDestination4.x +image4->w -30 <=imageDestination18.x +image18->w))
                        {
                            if((imageDestination4.y+30>=imageDestination18.y)&&(imageDestination4.y +image4->h -30 <= imageDestination18.y +image18->h))
                            {
                                imageDestination4.x=imageDestination18.x;
                                imageDestination4.y=imageDestination18.y;

                            }

                        }

                        if((imageDestination5.x+30 >= imageDestination18.x)&&(imageDestination5.x +image5->w -30 <=imageDestination18.x +image18->w))
                        {
                            if((imageDestination5.y+30>=imageDestination18.y)&&(imageDestination5.y +image5->h -30 <= imageDestination18.y +image18->h))
                            {
                                imageDestination5.x=imageDestination18.x;
                                imageDestination5.y=imageDestination18.y;

                            }

                        }

                        if((imageDestination6.x+30 >= imageDestination18.x)&&(imageDestination6.x +image6->w -30 <=imageDestination18.x +image18->w))
                        {
                            if((imageDestination6.y+30>=imageDestination18.y)&&(imageDestination6.y +image6->h -30 <= imageDestination18.y +image18->h))
                            {
                                imageDestination6.x=imageDestination18.x;
                                imageDestination6.y=imageDestination18.y;

                            }

                        }

                        if((imageDestination7.x+30 >= imageDestination18.x)&&(imageDestination7.x +image7->w -30 <=imageDestination18.x +image18->w))
                        {
                            if((imageDestination7.y+30>=imageDestination18.y)&&(imageDestination7.y +image7->h -30 <= imageDestination18.y +image18->h))
                            {
                                imageDestination7.x=imageDestination18.x;
                                imageDestination7.y=imageDestination18.y;

                            }

                        }

                        if((imageDestination8.x+30 >= imageDestination18.x)&&(imageDestination8.x +image8->w -30 <=imageDestination18.x +image18->w))
                        {
                            if((imageDestination8.y+30>=imageDestination18.y)&&(imageDestination8.y +image8->h -30 <= imageDestination18.y +image18->h))
                            {
                                imageDestination8.x=imageDestination18.x;
                                imageDestination8.y=imageDestination18.y;

                            }

                        }

                        if((imageDestination9.x+30 >= imageDestination18.x)&&(imageDestination9.x +image9->w -30 <=imageDestination18.x +image18->w))
                        {
                            if((imageDestination9.y+30>=imageDestination18.y)&&(imageDestination9.y +image9->h -30 <= imageDestination18.y +image18->h))
                            {
                                imageDestination9.x=imageDestination18.x;
                                imageDestination9.y=imageDestination18.y;

                            }

                        }






                        if((event.motion.x >= imageDestination10.x)&&(event.motion.x <= imageDestination18.x+image18->w))
                        {
                            if((event.motion.y >= imageDestination10.y)&&(event.motion.y <= imageDestination18.y+image18->h))
                            {
                                nb++;
                            }

                        }



                        if( (imageDestination1.x < imageDestination10.x) || (imageDestination1.x > imageDestination18.x+image18->w) || (imageDestination1.y < imageDestination10.y) || (imageDestination1.y > imageDestination18.y+image18->h) )

                        {

                            imageDestination1.x = 569.7;
                            imageDestination1.y = 92;
                        }


                        if( (imageDestination2.x < imageDestination10.x) || (imageDestination2.x > imageDestination18.x+image18->w) || (imageDestination2.y < imageDestination10.y) || (imageDestination2.y > imageDestination18.y+image18->h) )

                        {

                            imageDestination2.x = 697.2;
                            imageDestination2.y = 92;
                        }

                        if( (imageDestination3.x < imageDestination10.x) || (imageDestination3.x > imageDestination18.x+image18->w) || (imageDestination3.y < imageDestination10.y) || (imageDestination3.y > imageDestination18.y+image18->h) )

                        {

                            imageDestination3.x = 825;
                            imageDestination3.y = 92;
                        }

                        if( (imageDestination4.x < imageDestination10.x) || (imageDestination4.x > imageDestination18.x+image18->w) || (imageDestination4.y < imageDestination10.y) || (imageDestination4.y > imageDestination18.y+image18->h) )

                        {

                            imageDestination4.x = 569.7;
                            imageDestination4.y = 262.2;
                        }



                        if( (imageDestination5.x < imageDestination10.x) || (imageDestination5.x > imageDestination18.x+image18->w) || (imageDestination5.y < imageDestination10.y) || (imageDestination5.y > imageDestination18.y+image18->h) )

                        {

                            imageDestination5.x = 697.2;
                            imageDestination5.y = 262.2;

                        }


                        if( (imageDestination6.x < imageDestination10.x) || (imageDestination6.x > imageDestination18.x+image18->w) || (imageDestination6.y < imageDestination10.y) || (imageDestination6.y > imageDestination18.y+image18->h) )

                        {

                            imageDestination6.x = 825;
                            imageDestination6.y = 262.2;

                        }


                        if( (imageDestination7.x < imageDestination10.x) || (imageDestination7.x > imageDestination18.x+image18->w) || (imageDestination7.y < imageDestination10.y) || (imageDestination7.y > imageDestination18.y+image18->h) )

                        {

                            imageDestination7.x = 569.7;
                            imageDestination7.y = 431.8;

                        }


                        if( (imageDestination8.x < imageDestination10.x) || (imageDestination8.x > imageDestination18.x+image18->w) || (imageDestination8.y < imageDestination10.y) || (imageDestination8.y > imageDestination18.y+image18->h) )

                        {

                            imageDestination8.x = 697.2;
                            imageDestination8.y = 431.8;

                        }


                        if( (imageDestination9.x < imageDestination10.x) || (imageDestination9.x > imageDestination18.x+image18->w) || (imageDestination9.y < imageDestination10.y) || (imageDestination9.y > imageDestination18.y+image18->h) )

                        {

                            imageDestination9.x = 825;
                            imageDestination9.y = 431.8;

                        }


                        // afficher_image(0,0,"Fichiers/Images/background.png");

                        //imageDestination8.x = 697.2;
                        //imageDestination8.y = 431.8;

                        /* SDL_BlitSurface( image1 ,NULL, fenetre, &imageDestination1 );
                           SDL_BlitSurface( image2 ,NULL, fenetre, &imageDestination2 );
                           SDL_BlitSurface( image3 ,NULL, fenetre, &imageDestination3 );
                           SDL_BlitSurface( image4 ,NULL, fenetre, &imageDestination4 );
                           SDL_BlitSurface( image5 ,NULL, fenetre, &imageDestination5 );
                           SDL_BlitSurface( image6 ,NULL, fenetre, &imageDestination6 );
                           SDL_BlitSurface( image7 ,NULL, fenetre, &imageDestination7 );
                           SDL_BlitSurface( image8 ,NULL, fenetre, &imageDestination8 );
                           SDL_BlitSurface( image9 ,NULL, fenetre, &imageDestination9 );
                           sprintf(ch,"Le score est : %d",nb);
                           afficher_texte(5, 5,40, ch,255,255,255);
                           SDL_Flip(fenetre);*/

                        onclick1 = 0;
                        onclick2 = 0;
                        onclick3 = 0;
                        onclick4 = 0;
                        onclick5 = 0;
                        onclick6 = 0;
                        onclick7 = 0;
                        onclick8 = 0;
                        onclick9 = 0;

                        break;
                    }


                    else if(event.type == SDL_MOUSEMOTION)
                    {
                        if( onclick1==1 )
                        {
                            imageDestination1.x = event.motion.x-(image1->w/2);
                            imageDestination1.y = event.motion.y-(image1->h/2);
                        }
                        else if( onclick2 )
                        {
                            imageDestination2.x = event.motion.x-(image2->w/2);
                            imageDestination2.y = event.motion.y-(image2->h/2);
                        }
                        else if( onclick3 )
                        {
                            imageDestination3.x = event.motion.x-(image3->w/2);
                            imageDestination3.y = event.motion.y-(image3->h/2);
                        }
                        else if( onclick4 )
                        {
                            imageDestination4.x = event.motion.x-(image4->w/2);
                            imageDestination4.y = event.motion.y-(image4->h/2);
                        }
                        else if( onclick5 )
                        {
                            imageDestination5.x = event.motion.x-(image5->w/2);
                            imageDestination5.y = event.motion.y-(image5->h/2);
                        }
                        else if( onclick6 )
                        {
                            imageDestination6.x = event.motion.x-(image6->w/2);
                            imageDestination6.y = event.motion.y-(image6->h/2);
                        }
                        else if( onclick7 )
                        {
                            imageDestination7.x = event.motion.x-(image7->w/2);
                            imageDestination7.y = event.motion.y-(image7->h/2);
                        }
                        else if( onclick8 )
                        {
                            imageDestination8.x = event.motion.x-(image8->w/2);
                            imageDestination8.y = event.motion.y-(image8->h/2);
                        }
                        else if( onclick9 )
                        {
                            imageDestination9.x = event.motion.x-(image9->w/2);
                            imageDestination9.y = event.motion.y-(image9->h/2);
                        }
                        /*afficher_image(0,0,"Fichiers/Images/background.png");
                        SDL_BlitSurface( image1 ,NULL, fenetre, &imageDestination1 );
                        SDL_BlitSurface( image2 ,NULL, fenetre, &imageDestination2 );
                        SDL_BlitSurface( image3 ,NULL, fenetre, &imageDestination3 );
                        SDL_BlitSurface( image4 ,NULL, fenetre, &imageDestination4 );
                        SDL_BlitSurface( image5 ,NULL, fenetre, &imageDestination5 );
                        SDL_BlitSurface( image6 ,NULL, fenetre, &imageDestination6 );
                        SDL_BlitSurface( image7 ,NULL, fenetre, &imageDestination7 );
                        SDL_BlitSurface( image8 ,NULL, fenetre, &imageDestination8 );
                        SDL_BlitSurface( image9 ,NULL, fenetre, &imageDestination9 );
                        sprintf(ch,"Le score est : %d",nb);
                        afficher_texte(5, 5,40, ch,255,255,255);
                        SDL_Flip(fenetre);
                        */
                    }

                }


            }

            SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));
            //afficher_image(0,0,"Fichiers/Images/background.png");
            SDL_BlitSurface( bg ,NULL, fenetre, &dbg );
            SDL_BlitSurface( image1 ,NULL, fenetre, &imageDestination1 );
            SDL_BlitSurface( image2 ,NULL, fenetre, &imageDestination2 );
            SDL_BlitSurface( image3 ,NULL, fenetre, &imageDestination3 );
            SDL_BlitSurface( image4 ,NULL, fenetre, &imageDestination4 );
            SDL_BlitSurface( image5 ,NULL, fenetre, &imageDestination5 );
            SDL_BlitSurface( image6 ,NULL, fenetre, &imageDestination6 );
            SDL_BlitSurface( image7 ,NULL, fenetre, &imageDestination7 );
            SDL_BlitSurface( image8 ,NULL, fenetre, &imageDestination8 );
            SDL_BlitSurface( image9 ,NULL, fenetre, &imageDestination9 );
            sprintf(ch,"Le score est : %d",nb);
            afficher_texte(5, 5,40, ch,255,255,255);
            SDL_Flip(fenetre);


        }



    SDL_FreeSurface(image1);
    SDL_FreeSurface(image2);
    SDL_FreeSurface(image3);
    SDL_FreeSurface(image4);
    SDL_FreeSurface(image5);
    SDL_FreeSurface(image6);
    SDL_FreeSurface(image7);
    SDL_FreeSurface(image8);
    SDL_FreeSurface(image9);
    SDL_FreeSurface(image10);
    SDL_FreeSurface(image11);
    SDL_FreeSurface(image12);
    SDL_FreeSurface(image13);
    SDL_FreeSurface(image14);
    SDL_FreeSurface(image15);
    SDL_FreeSurface(image16);
    SDL_FreeSurface(image17);
    SDL_FreeSurface(image18);
    cleanup();

}


inline void saisir()
{
    TTF_Font* pFont = TTF_OpenFont("Fichiers/Fonts/font.ttf",24);

    SDL_Surface* texte ;
    SDL_Rect texteDestination;
    SDL_Event event;


    afficher_image(0,0,"Fichiers/Images/back1.png");
    SDL_Flip(fenetre);



    nom[0]='\0';
    int continuer=1;
    while (continuer)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
            {
                if(event.key.keysym.sym == SDLK_SPACE)
                    strcat(nom," ");
                else if ( event.key.keysym.sym == SDLK_a)
                    strcat(nom,"q");
                else if ( event.key.keysym.sym == SDLK_b)
                    strcat(nom,"b");
                else if ( event.key.keysym.sym == SDLK_c)
                    strcat(nom,"c");
                else if ( event.key.keysym.sym == SDLK_d)
                    strcat(nom,"d");
                else if ( event.key.keysym.sym == SDLK_e)
                    strcat(nom,"e");
                else if ( event.key.keysym.sym == SDLK_f)
                    strcat(nom,"f");
                else if ( event.key.keysym.sym == SDLK_g)
                    strcat(nom,"g");
                else if ( event.key.keysym.sym == SDLK_h)
                    strcat(nom,"h");
                else if ( event.key.keysym.sym == SDLK_i)
                    strcat(nom,"i");
                else if ( event.key.keysym.sym == SDLK_j)
                    strcat(nom,"j");
                else if ( event.key.keysym.sym == SDLK_k)
                    strcat(nom,"k");
                else if ( event.key.keysym.sym == SDLK_l)
                    strcat(nom,"l");
                else if (event.key.keysym.sym == SDLK_SEMICOLON)
                    strcat(nom,"m");
                else if ( event.key.keysym.sym == SDLK_n)
                    strcat(nom,"n");
                else if ( event.key.keysym.sym == SDLK_o)
                    strcat(nom,"o");
                else if ( event.key.keysym.sym == SDLK_p)
                    strcat(nom,"p");
                else if ( event.key.keysym.sym == SDLK_q)
                    strcat(nom,"a");
                else if ( event.key.keysym.sym == SDLK_r)
                    strcat(nom,"r");
                else if ( event.key.keysym.sym == SDLK_s)
                    strcat(nom,"s");
                else if ( event.key.keysym.sym == SDLK_t)
                    strcat(nom,"t");
                else if ( event.key.keysym.sym == SDLK_u)
                    strcat(nom,"u");
                else if ( event.key.keysym.sym == SDLK_v)
                    strcat(nom,"v");
                else if ( event.key.keysym.sym == SDLK_w)
                    strcat(nom,"z");
                else if ( event.key.keysym.sym == SDLK_x)
                    strcat(nom,"x");
                else if ( event.key.keysym.sym == SDLK_y)
                    strcat(nom,"y");
                else if ( event.key.keysym.sym == SDLK_z)
                    strcat(nom,"w");
                else if ( event.key.keysym.sym == SDLK_BACKSPACE)
                    nom[strlen(nom)-1]='\0';
                else if (((event.key.keysym.sym == SDLK_KP_ENTER)||(event.key.keysym.sym == SDLK_RETURN)))
                {

                    if (strcmp(nom,"")!=0)
                    {
                        continuer=0;
                    }


                }
                break;
            }
            }

        }



        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 0, 0, 0));
        //texteDestination.x = 20;
        // texteDestination.y = 30;
        afficher_image(0,0,"Fichiers/Images/back1.png");
        SDL_Flip(fenetre);
        //texte = TTF_RenderText_Solid(pFont,"Saisir votre nom :", {255, 14, 22});
        SDL_BlitSurface(texte, 0, fenetre, &texteDestination);
        texteDestination.x = 422;
        texteDestination.y = 278.6;
        SDL_Color couleur= {140, 135, 135};
        texte = TTF_RenderText_Solid(pFont,nom, couleur);
        SDL_BlitSurface(texte, 0, fenetre, &texteDestination);


        SDL_Flip(fenetre);




    }


    afficher_image(0,0,"Fichiers/Images/back2.png");
    SDL_Flip(fenetre);

    prenom[0]='\0';
    int continuer2=1;
    while (continuer2)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
            {
                if(event.key.keysym.sym == SDLK_SPACE)
                    strcat(prenom," ");
                else if ( event.key.keysym.sym == SDLK_a)
                    strcat(prenom,"q");
                else if ( event.key.keysym.sym == SDLK_b)
                    strcat(prenom,"b");
                else if ( event.key.keysym.sym == SDLK_c)
                    strcat(prenom,"c");
                else if ( event.key.keysym.sym == SDLK_d)
                    strcat(prenom,"d");
                else if ( event.key.keysym.sym == SDLK_e)
                    strcat(prenom,"e");
                else if ( event.key.keysym.sym == SDLK_f)
                    strcat(prenom,"f");
                else if ( event.key.keysym.sym == SDLK_g)
                    strcat(prenom,"g");
                else if ( event.key.keysym.sym == SDLK_h)
                    strcat(prenom,"h");
                else if ( event.key.keysym.sym == SDLK_i)
                    strcat(prenom,"i");
                else if ( event.key.keysym.sym == SDLK_j)
                    strcat(prenom,"j");
                else if ( event.key.keysym.sym == SDLK_k)
                    strcat(prenom,"k");
                else if ( event.key.keysym.sym == SDLK_l)
                    strcat(prenom,"l");
                else if (event.key.keysym.sym == SDLK_SEMICOLON)
                    strcat(prenom,"m");
                else if ( event.key.keysym.sym == SDLK_n)
                    strcat(prenom,"n");
                else if ( event.key.keysym.sym == SDLK_o)
                    strcat(prenom,"o");
                else if ( event.key.keysym.sym == SDLK_p)
                    strcat(prenom,"p");
                else if ( event.key.keysym.sym == SDLK_q)
                    strcat(prenom,"a");
                else if ( event.key.keysym.sym == SDLK_r)
                    strcat(prenom,"r");
                else if ( event.key.keysym.sym == SDLK_s)
                    strcat(prenom,"s");
                else if ( event.key.keysym.sym == SDLK_t)
                    strcat(prenom,"t");
                else if ( event.key.keysym.sym == SDLK_u)
                    strcat(prenom,"u");
                else if ( event.key.keysym.sym == SDLK_v)
                    strcat(prenom,"v");
                else if ( event.key.keysym.sym == SDLK_w)
                    strcat(prenom,"z");
                else if ( event.key.keysym.sym == SDLK_x)
                    strcat(prenom,"x");
                else if ( event.key.keysym.sym == SDLK_y)
                    strcat(prenom,"y");
                else if ( event.key.keysym.sym == SDLK_z)
                    strcat(prenom,"w");
                else if ( event.key.keysym.sym == SDLK_BACKSPACE)
                    prenom[strlen(prenom)-1]='\0';
                else if (((event.key.keysym.sym == SDLK_KP_ENTER)||(event.key.keysym.sym == SDLK_RETURN)))
                {
                    if (strcmp(prenom,"")!=0)
                    {
                        continuer2=0;
                    }
                }
                break;
            }
            }
        }

        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 0, 0, 0));

        // texteDestination.x = 20;
        //texteDestination.y = 30;

        afficher_image(0,0,"Fichiers/Images/back2.png");
        SDL_Flip(fenetre);

        //texte = TTF_RenderText_Solid(pFont,"Saisir votre nom :", {255, 14, 22});
        SDL_BlitSurface(texte, 0, fenetre, &texteDestination);
        texteDestination.x = 422;
        texteDestination.y = 278.6;
        SDL_Color couleur= {140, 135, 135};
        texte = TTF_RenderText_Solid(pFont,nom, couleur);
        SDL_BlitSurface(texte, 0, fenetre, &texteDestination);

        // texteDestination.x = 20;
        //texteDestination.y = 90;
        //texte = TTF_RenderText_Solid(pFont,"Saisir votre prenom :", {255, 14, 22});
        SDL_BlitSurface(texte, 0, fenetre, &texteDestination);
        texteDestination.x = 422;
        texteDestination.y = 376;
        texte = TTF_RenderText_Solid(pFont,prenom, couleur);
        SDL_BlitSurface(texte, 0, fenetre, &texteDestination);

        SDL_Flip(fenetre);

    }


    SDL_FreeSurface(texte);
}

inline void menu()
{
    SDL_Event event;

    SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 0, 0, 0));
    afficher_image(0,0,"Fichiers/Images/menu.png");
    char ch[100]="Fichiers/Images/sonon.png";
    afficher_image(818,65,ch);
    afficher_image(750,68,"Fichiers/Images/sound.png");
    SDL_Flip(fenetre);





    int continuer=1;
    int continuer2=1;
    while (continuer)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    exit(0);
                break;

            case SDL_MOUSEMOTION :
            {
                if ( ((event.button.x >=422) && (event.button.x <=611.5 ))  &&  ((event.button.y >=184 ) && (event.button.y <=223 ))  )
                {

                    afficher_image(0,0,"Fichiers/Images/menu1.png");
                    afficher_image(750,68,"Fichiers/Images/sound.png");

                    afficher_image(818,65,ch);

                    SDL_Flip(fenetre);
                }


                else if ( ((event.button.x >=422) && (event.button.x <=611.5 ))  &&  ((event.button.y >=267.5 ) && (event.button.y <=307  ))  )
                {

                    afficher_image(0,0,"Fichiers/Images/menu2.png");
                    afficher_image(750,68,"Fichiers/Images/sound.png");

                    afficher_image(818,65,ch);

                    SDL_Flip(fenetre);


                }
                else if ( ((event.button.x >=422) && (event.button.x <=611.5 ))  &&  ((event.button.y >=356 ) && (event.button.y <=398.8  ))  )
                {

                    afficher_image(0,0,"Fichiers/Images/menu3.png");
                    afficher_image(750,68,"Fichiers/Images/sound.png");

                    afficher_image(818,65,ch);

                    SDL_Flip(fenetre);


                }
                else if ( ((event.button.x >=422) && (event.button.x <=611.5 ))  &&  ((event.button.y >=440.5 ) && (event.button.y <=480  ))  )
                {
                    afficher_image(0,0,"Fichiers/Images/menu4.png");
                    afficher_image(750,68,"Fichiers/Images/sound.png");

                    afficher_image(818,65,ch);

                    SDL_Flip(fenetre);
                }



                else
                {
                    afficher_image(0,0,"Fichiers/Images/menu.png");
                    afficher_image(750,68,"Fichiers/Images/sound.png");

                    afficher_image(818,65,ch);

                    SDL_Flip(fenetre);

                }
            }

            case SDL_MOUSEBUTTONDOWN:
            {
                //start
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if ( ((event.button.x >=422) && (event.button.x <=611.5 ))  &&  ((event.button.y >=184 ) && (event.button.y <=223 ))  )
                    {

                        continuer=0;
                    }
                    else if ( ((event.button.x >=422) && (event.button.x <=611.5 ))  &&  ((event.button.y >=267.5 ) && (event.button.y <=307  ))  )
                        //instruction
                    {
                        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 0, 0, 0));
                        afficher_image(0,0,"Fichiers/Images/instruction.png");
                        SDL_Flip(fenetre);

                        while (continuer2)
                        {
                            while (SDL_PollEvent(&event))
                            {
                                switch (event.type)
                                {
                                case SDL_QUIT:
                                    exit(0);
                                    break;
                                case SDL_KEYDOWN:
                                    if (event.key.keysym.sym == SDLK_ESCAPE)
                                        continuer2=0;
                                    break;
                                     case SDL_MOUSEBUTTONDOWN:




                         if ( ((event.button.x >=84) && (event.button.x <=234 ))  &&  ((event.button.y >=29 ) && (event.button.y <=71  ))  )
                                    {

                                        menu();

                                    }
                            break;
                                }



                            }

                        }


                    }
                    else if ( ((event.button.x >=422) && (event.button.x <=611.5 ))  &&  ((event.button.y >=440.5 ) && (event.button.y <=480  ))  )
                        //quit
                    {

                        exit(0);

                    }

                    else if ( ((event.button.x >=422) && (event.button.x <=611.5 ))  &&  ((event.button.y >=356 ) && (event.button.y <=398.8  ))  )
                        //credit
                    {


                        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 0, 0, 0));
                        afficher_image(0,0,"Fichiers/Images/credit.png");
                        SDL_Flip(fenetre);
                        while (continuer2)
                        {
                            while (SDL_PollEvent(&event))
                            {
                                switch (event.type)
                                {
                                case SDL_QUIT:
                                    exit(0);
                                    break;
                                case SDL_KEYDOWN:
                                    if (event.key.keysym.sym == SDLK_ESCAPE)
                                        continuer2=0;
                                    break;
                                         case SDL_MOUSEBUTTONDOWN:




                         if ( ((event.button.x >=84) && (event.button.x <=234 ))  &&  ((event.button.y >=29 ) && (event.button.y <=71  ))  )
                                    {

                                        menu();

                                    }
                            break;
                                }
                            }


                        }
                    }

                    else if ( ((event.button.x >=817) && (event.button.x <=877 ))  &&  ((event.button.y >=65 ) && (event.button.y <=89  ))  )
                    {
                        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 0, 0, 0));
                        afficher_image(0,0,"Fichiers/Images/menu.png");
                        afficher_image(750,68,"Fichiers/Images/sound.png");

                        if(x==1)
                        {
                            x=2;

                            strcpy(ch,"Fichiers/Images/sonoff.png");

                        }
                        else
                        {

                            x=1;

                            strcpy(ch,"Fichiers/Images/sonon.png");
                        }
                        afficher_image(818,65,ch);


                        SDL_Flip(fenetre);
                    }




                    break;
                }


            }
            }


        }
    }
}


int main ( int argc, char** argv )
{
//    video();


    intialisation();
    menu();
    saisir();
    game();
    return 0;
}


/*
    SDL_Rect dstrect,dstrect1;
    dstrect.x = 0;
    dstrect.y = 0;
    dstrect1.x = 500;
    dstrect1.y = 250;

    char s1[1000];
    int k=1;
    int i=0;
    int done = 0;
    double zoom=0;


        sprintf(s1,"Ressourses/Images/Menu/Video/1 (%d).jpg",k);
        SDL_Surface*    image=IMG_Load(s1);
        k++;
        if (k==554)
        {
            k=1;
        }
        SDL_BlitSurface(image, NULL, screen, &dstrect);

        SDL_Flip(screen);
        SDL_FreeSurface(image);
    }
    return 0;
}

*/


#include "raylib.h"
#include <cstring>
#include <vector>
#include <iostream>

typedef enum GameScreen
{
    LOGO = 0,
    MENU,
    CONV,
    STRATEGY,
    READ,
    BASE,
    ATTACK
} GameScreen;

class BaseItem : public Rectangle
{
public:
    bool isDraggable;
    bool isBeingDragged = false;
    Texture2D texture;
    bool isObstacle;
    bool isButton;
    bool isClickable;
    // bool isHovered;
    void draw()
    {
        if (isButton)
        {
            // DrawRectangle(x, y, this->width, this->height, WHITE);
            DrawTexture(texture, x, y, WHITE);
        }
        else
        {
            DrawTexture(texture, x, y, WHITE);
        }
    }
    void drag(int a, int b)
    {
        if (isDraggable || isButton)
        {
            x = a;
            y = b;
        }
    }
    bool operator!=(BaseItem item)
    {
        if (x != item.x || y != item.y || isDraggable != item.isDraggable)
            return true;
        else
            return false;
    }
};

class Tile : public BaseItem
{
};

class Base
{
public:
    Base()
    {
        int height = GetScreenHeight();
        int width = GetScreenWidth();

        // we will always start with tiles and castle so add them to the vector initally

        // add tiles to the vector
        for (int i = -30; i <= height; i += 45)
        {
            for (int j = -60; j <= width; j += 40)
            {
                Tile tile;
                tile.texture = LoadTexture("./resources/images/diagonal-grass.png");
                tile.x = j;
                tile.y = i;
                tile.isDraggable = false;
                tile.isObstacle = false;
                tile.isButton = false;
                items.emplace_back(tile);
            }
        }
        // we will add a castle at the center of the the base
        BaseItem attackButton;
        attackButton.texture = LoadTexture("./resources/ButtonImages/NewGameBefore.png");
        attackButton.x = GetScreenWidth() / 2 + 400;
        attackButton.y = -40;
        attackButton.isDraggable = false;
        attackButton.isObstacle = false;
        attackButton.isButton = false;
        attackButton.isClickable = true;
        attackButton.width = attackButton.texture.width;
        attackButton.height = attackButton.texture.height;
        items.emplace_back(attackButton);

        BaseItem campButton;
        campButton.texture = LoadTexture("./resources/army-camp.png");
        campButton.x = 50;
        campButton.y = 630;
        campButton.isDraggable = false;
        campButton.isObstacle = false;
        campButton.isButton = true;
        campButton.width = campButton.texture.width;
        campButton.height = campButton.texture.height;
        items.emplace_back(campButton);

        BaseItem treeButton;
        treeButton.texture = LoadTexture("./resources/images/medum-tree.png");
        treeButton.x = 270;
        treeButton.y = 660;
        treeButton.isDraggable = false;
        treeButton.isObstacle = false;
        treeButton.isButton = true;
        treeButton.width = treeButton.texture.width;
        treeButton.height = treeButton.texture.height;
        items.emplace_back(treeButton);

        BaseItem horseButton;
        horseButton.texture = LoadTexture("./resources/horse.png");
        horseButton.x = 420;
        horseButton.y = 690;
        horseButton.isDraggable = false;
        horseButton.isObstacle = false;
        horseButton.isButton = true;
        horseButton.width = horseButton.texture.width;
        horseButton.height = horseButton.texture.height;
        items.emplace_back(horseButton);

        BaseItem dhungaButton;
        dhungaButton.texture = LoadTexture("./resources/dhunga.png");
        dhungaButton.x = 600;
        dhungaButton.y = 670;
        dhungaButton.isDraggable = false;
        dhungaButton.isObstacle = false;
        dhungaButton.isButton = true;
        dhungaButton.width = dhungaButton.texture.width;
        dhungaButton.height = dhungaButton.texture.height;
        items.emplace_back(dhungaButton);

        BaseItem obDhungaButton;
        obDhungaButton.texture = LoadTexture("./resources/obdhunga.png");
        obDhungaButton.x = 800;
        obDhungaButton.y = 690;
        obDhungaButton.isDraggable = false;
        obDhungaButton.isObstacle = false;
        obDhungaButton.isButton = true;
        obDhungaButton.width = obDhungaButton.texture.width;
        obDhungaButton.height = obDhungaButton.texture.height;
        items.emplace_back(obDhungaButton);

        BaseItem woodButton;
        woodButton.texture = LoadTexture("./resources/fallen-wood.png");
        woodButton.x = 1000;
        woodButton.y = 690;
        woodButton.isDraggable = false;
        woodButton.isObstacle = false;
        woodButton.isButton = true;
        woodButton.width = woodButton.texture.width;
        woodButton.height = woodButton.texture.height;
        items.emplace_back(woodButton);

        BaseItem troopsButton;
        troopsButton.texture = LoadTexture("./resources/troops.png");
        troopsButton.x = 1200;
        troopsButton.y = 620;
        troopsButton.isDraggable = false;
        troopsButton.isObstacle = false;
        troopsButton.isButton = true;
        troopsButton.width = troopsButton.texture.width;
        troopsButton.height = troopsButton.texture.height;
        items.emplace_back(troopsButton);

        BaseItem castle;
        castle.texture = LoadTexture("./resources/images/GorkhaMuseum1.png");
        castle.x = (int)GetScreenWidth() / 2;
        castle.y = (int)GetScreenHeight() / 2 - 150;
        castle.isDraggable = true;
        castle.isObstacle = true;
        castle.isButton = false;
        items.emplace_back(castle);
        castle.width = castle.texture.width;
        castle.height = castle.texture.height;

        BaseItem camp;
        camp.texture = LoadTexture("./resources/army-camp.png");
        camp.x = 400;
        camp.y = 50;
        camp.isDraggable = true;
        camp.isObstacle = true;
        camp.isButton = false;
        items.emplace_back(camp);
        /*
        for(int i = 200 ; i <= height / 2 + 50 ; i += 20){
          for(int j = 630 ; j <= width / 2 + 200 ; j += 20){
            BaseItem walls;
      walls.texture = LoadTexture("./resources/wooden-wall.png");
      walls.x = j;
      walls.y = i;
      walls.isDraggable = false;
      walls.isObstacle = true;
      items.emplace_back(walls);
          }
        }
        */

        BaseItem mediumTree;
        mediumTree.texture = LoadTexture("./resources/images/medum-tree.png");
        mediumTree.x = 200;
        mediumTree.y = 300;
        mediumTree.isDraggable = true;
        mediumTree.isObstacle = true;
        mediumTree.isButton = false;
        mediumTree.width = mediumTree.texture.width;
        mediumTree.height = mediumTree.texture.height;
        items.emplace_back(mediumTree);

        BaseItem horse;
        horse.texture = LoadTexture("./resources/horse.png");
        horse.x = 300;
        horse.y = 300;
        horse.isDraggable = true;
        horse.isObstacle = true;
        horse.isButton = false;
        items.emplace_back(horse);

        BaseItem dhunga;
        dhunga.texture = LoadTexture("./resources/dhunga.png");
        dhunga.x = 50;
        dhunga.y = 60;
        dhunga.isDraggable = true;
        dhunga.isObstacle = true;
        dhunga.isButton = false;
        items.emplace_back(dhunga);

        BaseItem fallenWood;
        fallenWood.texture = LoadTexture("./resources/fallen-wood.png");
        fallenWood.x = 490;
        fallenWood.y = 300;
        fallenWood.isDraggable = true;
        fallenWood.isBeingDragged = true;
        fallenWood.isButton = false;
        items.emplace_back(fallenWood);

        BaseItem obDhunga;
        obDhunga.texture = LoadTexture("./resources/obdhunga.png");
        obDhunga.x = 340;
        obDhunga.y = 450;
        obDhunga.isDraggable = true;
        obDhunga.isObstacle = true;
        obDhunga.isButton = false;
        items.emplace_back(obDhunga);

        BaseItem army;
        army.texture = LoadTexture("./resources/troops.png");
        army.x = 100;
        army.y = 100;
        army.isDraggable = true;
        army.isObstacle = true;
        army.isButton = false;
        items.emplace_back(army);
        /*
            BaseItem test;
            test.texture = LoadTexture("./resources/images/test.png");
            test.isObstacle = true;
            test.isDraggable = true;
            test.posX = 200;
            test.posY = 350;
            items.emplace_back(test);
            */
    }
    std::vector<BaseItem> items;
    void draw()
    {
        for (auto &elt : items)
        {
            elt.draw();
        }
    }

    bool detect_collision(BaseItem &e)
    {
        /*for(auto& elt: items){
             if(e != elt &&  elt.isObstacle &&  e.posX >= elt.posX && e.posX <= (elt.posX + elt.texture.width) && e.posY >= elt.posY && e.posY <= (elt.posY + elt.texture.height) ){
           return true;
             } // collision detected don't draw
        }
        return false;
         */
        // bool collided = false;
        for (auto elt : items)
        {
            // if(elt.isObstacle && CheckCollisionRecs(e, elt)) return true;

            if (((e.x < (elt.x + elt.width) && e.x > elt.x) && (e.y < (elt.y + elt.height) && e.y > elt.y)) ||
                ((e.x < (elt.x + elt.width) && e.x > elt.x) && (e.y + e.height < (elt.y + elt.height) && e.y + e.height > elt.y)))
            // e.x + e.width >= elt.x &&
            // e.x <= elt.x + elt.width &&
            // e.y + e.height >= elt.y &&
            // e.y <= elt.y + elt.height
            //   (!(e.x + e.width < elt.x || elt.x + elt.width < e.x) ||
            //   (e.y + e.height < elt.y || elt.y + elt.height < e.y))
            // )
            {
                return true;
            }
        }
        return false;
    }

    void poll_drag()
    {
        for (auto &e : items)
        {

            auto textureWidth = e.texture.width;
            auto textureHeight = e.texture.height;

            // check for mouse drag
            if (e.isDraggable && GetMouseX() >= e.x && GetMouseX() <= (e.x + textureWidth) && GetMouseY() >= e.y && GetMouseY() <= (e.y + textureHeight) && IsMouseButtonDown(0))
            {
                if (!detect_collision(e))
                {
                    e.drag(GetMouseX() - textureWidth / 2, GetMouseY() - textureHeight / 2);
                    // DrawText("No Collision", 50, 100, 23, RED);
                }
                else
                {
                    // DrawText("Collision", 50, 100, 23, RED);
                }
            }
        }
    }
    void poll_release()
    {
        if (IsMouseButtonReleased(0))
        {
            for (auto &e : items)
            {
                if (e.isBeingDragged)
                {
                    e.isBeingDragged = false;
                }
            }
        }
    }

    BaseItem lastDraggedItem;
    void button_clicked()
    {
        for (auto &e : items)
        {
            // isHovered = CheckCollisionPointRec(GetMousePosition(), {e.x, e.y, e.x + e.width, e.y + e.height});
            if (e.isButton && GetMouseX() >= e.x && GetMouseX() <= (e.x + e.texture.width) && GetMouseY() >= e.y && GetMouseY() <= (e.y + e.texture.height) && IsMouseButtonDown(0))
            {
                e.isBeingDragged = true;
                lastDraggedItem = e;
                e.drag(GetMouseX() - e.texture.width / 2, GetMouseY() - e.texture.height / 2);
            }
        }
        if (IsMouseButtonReleased(0))
        {
            BaseItem newItem;
            newItem = lastDraggedItem; // Set your desired width
            newItem.drag(lastDraggedItem.x, lastDraggedItem.y);
            items.emplace_back(newItem);
        }
    }

    /*
     BaseItem *lastDraggedItem = nullptr;
     void button_clicked()
     {
       for (auto &e : items)
       {
         if (e.isBeingDragged)
         {
           DrawText("Dragging", 100, 100, 23, RED);
           // e.drag(GetMouseX() - e.width / 2, GetMouseY() - e.height / 2);
           lastDraggedItem = &e;
         }
         else
         {
           e.isBeingDragged = false; // Stop dragging when the mouse button is released
         }

         if (GetMouseX() >= e.x && GetMouseX() <= (e.x + e.width) && GetMouseY() >= e.y && GetMouseY() <= (e.y + e.height) && IsMouseButtonDown(0))
         {
           e.isBeingDragged = true; // Start dragging if the mouse is over the item and the button is pressed
           DrawText("Collision", 100, 100, 23, RED);
           e.drag(GetMouseX() - e.width / 2, GetMouseY() - e.height / 2);
           lastDraggedItem = &e;
         }
         if (IsMouseButtonReleased(0))
         {
           BaseItem newItem;
           newItem.width = 100;  // Set your desired width
           newItem.height = 100; // Set your desired height
           if (lastDraggedItem)
           {
             newItem.x = lastDraggedItem->x;
             newItem.y = lastDraggedItem->y;
             newItem.texture = lastDraggedItem->texture; // Use the texture of the last dragged item
             newItem.drag(GetMouseX() - newItem.width / 2, GetMouseY() - newItem.height / 2);
             items.emplace_back(newItem);
           }
         }
       }
     }
     */
};

class RivalBase{
 public:
   RivalBase(){
    int height = GetScreenHeight();
    int width =  GetScreenWidth();

    // we will always start with tiles and castle so add them to the vector initally

    // add tiles to the vector
     for(int i = -30 ; i <= height ; i += 64){
        for(int j = -60; j <= width ; j += 64){
	   Tile tile;
	   tile.texture = LoadTexture("./resources/images/diagonal-grass.png");
	   tile.x = j;
	   tile.y = i;
	   tile.isDraggable = false;
	   tile.isObstacle = false;
           items.emplace_back(tile);
        }	    
     }
    // we will add a castle at the center of the the base 



    BaseItem castle;
    castle.texture= LoadTexture("./resources/images/Nuwakot.png");
    castle.x = (int)GetScreenWidth() / 2;
    castle.y = (int)GetScreenHeight() / 2 - 150;
    castle.isDraggable = true;
    castle.isObstacle = true;
    items.emplace_back(castle);
    castle.width = castle.texture.width;
    castle.height = castle.texture.height;
   
    BaseItem camp;
    camp.texture = LoadTexture("./resources/army-camp.png");
    camp.x = 700;
    camp.y = 50;
    camp.isDraggable = true;
    camp.isObstacle = true;
    items.emplace_back(camp);
    /*
    for(int i = 200 ; i <= height / 2 + 50 ; i += 20){
      for(int j = 630 ; j <= width / 2 + 200 ; j += 20){
        BaseItem walls;
	walls.texture = LoadTexture("./resources/wooden-wall.png");
	walls.x = j;
	walls.y = i;
	walls.isDraggable = false;
	walls.isObstacle = true;
	items.emplace_back(walls);
      }	    
    }
    */
    

    BaseItem mediumTree;
    mediumTree.texture = LoadTexture("./resources/images/medum-tree.png");
    mediumTree.x = 200;
    mediumTree.y = 300;
    mediumTree.isDraggable = true;  
    mediumTree.isObstacle = true;
    mediumTree.width = mediumTree.texture.width;
    mediumTree.height = mediumTree.texture.height;
    items.emplace_back(mediumTree);


    BaseItem horse;
    horse.texture = LoadTexture("./resources/horse-opponent.png");
    horse.x = 300;
    horse.y = 300;
    horse.isDraggable = true;
    horse.isObstacle = true;
    items.emplace_back(horse);

    BaseItem dhunga;
    dhunga.texture = LoadTexture("./resources/large-stone.png");
    dhunga.x = 50;
    dhunga.y = 60;
    dhunga.isDraggable = true;
    dhunga.isObstacle = true;
    items.emplace_back(dhunga);

    BaseItem fallenWood;
    fallenWood.texture = LoadTexture("./resources/large-trunk.png");
    fallenWood.x = 490;
    fallenWood.y = 300;
    fallenWood.isDraggable = true;
    fallenWood.isBeingDragged = true;
    items.emplace_back(fallenWood);

    BaseItem obDhunga;
    obDhunga.texture = LoadTexture("./resources/obdhunga.png");
    obDhunga.x = 340;
    obDhunga.y = 650;
    obDhunga.isDraggable = true;
    obDhunga.isObstacle = true;
    items.emplace_back(obDhunga);

    BaseItem army;
    army.texture = LoadTexture("./resources/troops.png");
    army.x = 300;
    army.y = 100;
    army.isDraggable = true;
    army.isObstacle = true;
    items.emplace_back(army);
/*
    BaseItem test;
    test.texture = LoadTexture("./resources/images/test.png");
    test.isObstacle = true;
    test.isDraggable = true;
    test.posX = 200;
    test.posY = 350;
    items.emplace_back(test);
    */
   }
   std::vector<BaseItem> items;	 
   void draw(){
     for(auto& elt: items){
	      elt.draw();
    }
   }

   bool detect_collision(BaseItem& e){
	/*for(auto& elt: items){
	     if(e != elt &&  elt.isObstacle &&  e.posX >= elt.posX && e.posX <= (elt.posX + elt.texture.width) && e.posY >= elt.posY && e.posY <= (elt.posY + elt.texture.height) ){
		 return true;
	     } // collision detected don't draw	   
	}    
	return false;
   */
    // bool collided = false;
    for(auto elt : items){
      // if(elt.isObstacle && CheckCollisionRecs(e, elt)) return true;

      if 
        (((e.x < (elt.x + elt.width) && e.x>elt.x ) && (e.y < (elt.y + elt.height) && e.y>elt.y)) ||
        ((e.x < (elt.x + elt.width) && e.x>elt.x ) && (e.y + e.height < (elt.y + elt.height) && e.y + e.height>elt.y)))
        // e.x + e.width >= elt.x && 
        // e.x <= elt.x + elt.width &&
        // e.y + e.height >= elt.y &&
        // e.y <= elt.y + elt.height 
      //   (!(e.x + e.width < elt.x || elt.x + elt.width < e.x) ||
      //   (e.y + e.height < elt.y || elt.y + elt.height < e.y))
      // )
        {
          return true;
        }
    
    }	   
    return false;
   }
   
   void poll_drag(){
      for(auto& e: items){

        auto textureWidth = e.texture.width;
	      auto textureHeight = e.texture.height;

	// check for mouse drag
	if(e.isDraggable && GetMouseX()>= e.x && GetMouseX()<= (e.x + textureWidth) && GetMouseY()>= e.y && GetMouseY() <= (e.y + textureHeight) && IsMouseButtonDown(0)){
	   if(!detect_collision(e)){
	     e.drag(GetMouseX()  - textureWidth/2 , GetMouseY() - textureHeight/2);
        DrawText("No Collision", 50, 100, 23, RED);
        }
	   else {
	    DrawText("Collision", 50, 100, 23, RED);	   
	   }
	 } 
       }
    }
   void poll_release(){
     if(IsMouseButtonReleased(0)){
	for(auto& e: items){
	  e.isBeingDragged = false;	
	}     
     }	   
   }
};

int main(void)
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "Ekikaran");
    ToggleFullscreen();

    GameScreen currentScreen = LOGO;

    int framesCounter = 0; // Useful to count frames
    int framesCounter1 = 0;

    // Base Declare
    Base my_base;
    RivalBase rival_base;

    SetTargetFPS(60);

    // initialization for menu
    bool exitWindow = false;
    bool exitWindowRequested = false;
    float transAlpha = 1.0f;
    bool IsHoveredNew = false;
    bool IsHoveredSetting = false;
    bool IsHoveredQuit = false;
    bool IsHoveredAttack = false;
    auto BackgroundMusic = LoadMusicStream("resources/music/WarMusic.mp3");

    // Background Load
    // auto FirstBackgroundImage = LoadImage("resources/images/first_background-transformed.png");
    // ImageResize(&FirstBackgroundImage, GetScreenWidth(), GetScreenHeight());
    auto FirstBackgroundTexture = LoadTexture("resources/images/first_background.png");
    // UnloadImage(FirstBackgroundImage);

    // Button Load
    auto NewBefore = LoadTexture("resources/ButtonImages/NewGameBefore.png");
    auto SettingBefore = LoadTexture("resources/ButtonImages/SettingBefore.png");
    auto QuitBefore = LoadTexture("resources/ButtonImages/QuitBefore.png");

    auto NewAfter = LoadTexture("resources/ButtonImages/NewGameAfter.png");
    auto SettingAfter = LoadTexture("resources/ButtonImages/SettingAfter.png");
    auto QuitAfter = LoadTexture("resources/ButtonImages/QuitAfter.png");

    // initialization for conv

    InitAudioDevice(); // initalize audio device
    auto bgmMusic = LoadMusicStream("resources/music/FirstBackgroundMusic.mp3");
    auto skyTexture = LoadTexture("resources/images/sky.png");
    auto houseImage = LoadImage("resources/images/villagehouse(1).png");
    ImageResize(&houseImage, GetScreenWidth(), GetScreenHeight());
    auto houseTexture = LoadTextureFromImage(houseImage);
    auto fatherImage = LoadImage("resources/characters/father(1).png");
    ImageFlipHorizontal(&fatherImage);
    ImageResize(&fatherImage, 600, GetScreenHeight());
    auto fatherTexture = LoadTextureFromImage(fatherImage);
    auto daughterTexture = LoadTexture("resources/characters/daughter(1).png");
    Font font = LoadFont("resources/preeti.otf");
    auto speechTextureForFather = LoadTexture("resources/images/speechbox.png");

    auto speechImageForDaughter = LoadImage("resources/images/speechbox.png");
    ImageFlipHorizontal(&speechImageForDaughter);
    auto speechTextureForDaughter = LoadTextureFromImage(speechImageForDaughter);
    auto textCounter = 0;
    auto convText1 = "s] ul//sf] 5f]/L <";

    auto convText2 = "u]d v]ln/sf] afaf .";

    auto convText3 = "s'g v]n v]ln/Psf] gfgL <";

    auto convText41 = ";fxl;s v]n v]ln/Psf]";
    auto convText42 = "afaf d laleGg dlg; / PlnPg";
    auto convText43 = ";Fu o'w nl8/x]sL 5' .";

    auto convText51 = "t];f] xf] eg] d ;Fu lg";
    auto convText52 = "Pp6f v]n 5 gfgL";
    auto convText53 = "ltdLnfO{ dg k5{ xf]nf .";

    auto convText6 = "s'g v]n afaf <";

    auto convText71 = "Plssf/0f , Pltxl;s v]nsf]";
    auto convText72 = "d}bfg xf] gfgL .";
    auto convText73 = "of] v]n Plss[T /";
    auto convText74 = "/0fflglts n8fO{+ xf] .";

    auto convText81 = "cf]xf]! d t xh'/sf]";
    auto convText82 = "s'/f ;'g]/ pT;lxt eP .";
    auto convText83 = "clg of] v]n s;/L";
    auto convText84 = "v]n\\g] t <";

    auto convText91 = "nf} of] lstfa!";
    auto convText92 = "k9]/ P;s} cfwf/df";
    auto convText93 = "v]n\b} hfg] xf] gfgL";
    SetMusicVolume(bgmMusic, 1.0f);
    PlayMusicStream(bgmMusic);

    bool BaseEntered = false;
    bool MenuEntered = false;
    bool ConvEntered = false;
    bool transition = false;

    bool Entered = false;

    // initialization for strategy
    auto KPImage = LoadImage("resources/images/characters/kalupandey.png");
    ImageResize(&KPImage, 1500, 750);
    auto KPTexture = LoadTextureFromImage(KPImage);
    auto PNSImage = LoadImage("resources/images/characters/PNSedited.png");
    ImageFlipHorizontal(&PNSImage);
    ImageResize(&PNSImage, GetScreenWidth(), GetScreenHeight() - 100);
    auto PNSTexture = LoadTextureFromImage(PNSImage);
    auto speechTextureForPNS = LoadTexture("resources/images/speechbox.png");
    auto speechImageForKP = LoadImage("resources/images/speechbox.png");
    ImageFlipHorizontal(&speechImageForKP);
    auto speechTextureForKP = LoadTextureFromImage(speechImageForKP);
    auto strategyText11 = "sfn' kfG8],";
    auto strategyText12 = "d tldnfO d'n\\sfhL";
    auto strategyText13 = "agfpg] ;f]Rof .";

    auto strategyText21 = "xh',{ ca lrGtf";
    auto strategyText22 = "gdflgalS;of]; a8fdx/fh .";
    auto strategyText23 = "d xh'nfO{ g}/f; agf}b}g";

    auto strategyText31 = "xdL k}nf xfg{' sf] /x:o";
    auto strategyText32 = "xd|f] ;]gf ;';lHht gx'g' xf],";
    auto strategyText33 = "/ l5d]sL d'n'ssf]";
    auto strategyText34 = ";fy gfx'g' xf] .";

    auto strategyText41 = "r]tgf eof dnfO{ a9fdxf/h .";
    auto strategyText42 = "d ;]gf tof/ uGo{f 5'";
    auto strategyText43 = "/ l5d]sL d'n's ;Ë";
    auto strategyText44 = "aft{nfa klg uGo{f  5'";

    // initialization for read
    bool isFather = false;
    // Load text File
    //  const char *text = LoadFileText("resources/conversation.txt");
    // const char text[] = "This sample illustrates a text writing\nanimation effect! Check it out!";
    const char text[] = R"(#)) aif{ klxnf g]kfn eg]/ sf7df8f}+ pkTosnfO{ lrGg] ul/GYof] c? ;a} 8f]6L,s}nfnL ,g'jfsf]6 h:tf 7'nf 7'nf /fHo lyP eg] c? ;-;fgf /fHo P. t]; k5L uf]v{f Ps ;gf] /fHo df Ps dxg of]w sf] hGd x'G5 h:nfO{ xfdL k[lyjL gf/fo0ff ifx eg]/ lrGg] ur{f} . pgsf] a'af g/e'kfn zfxsf] d[To' !&&( @% r}tdf  ePkl5 pgL uf]/vfsf /fhf eP .k[YjLgf/fo0f lgs} dxTjfsf+IfL /fhf lyP. uf]v{f cfqmd0f;Fu} uf]v{f ;]gfaf6 hf]ufpg rfxGy], To;}n] ;fgf ;fgf /fHox¿nfO{ PsLs/0f u/]/ Pp6} b]z agfpg yfn] . /fhf ag]sf] Ps jif{kl5 ;G 
 !&$$ df pgn] g'jfsf]6df cfqmd0f u/] t/ uf]/vf ;]gf /fd|f];Fu ;';lHht gePsf] sf/0fn] kl5 x6\of] .To;kl5 zfxn] sfn' kf08]nfO{ cfkm\gf] /fHosf] “d'nsfhL” 
 agfP / o;/L cfkm\gf] 3/]n' /fhgLlts l:ylt alnof] agfP./fhf cfqmd0f cleofgdf uPsf a]nf l5d]sL /fhfx¿n] uf]/vfdf cfqmd0f ug{ ;S5G eGg] 8/ lyof] . 
 o;/L k[YjLn] sfn' kf08]nfO{ ndh'ªsf /fhf;Fu jft{f ug{ k7fP . sfn' kf08]n] ndh'ªsf /fhf;Fu r]k] gbLsf] a]l;gdf ;f}xfb{k"0f{ s'/fsfgL u/]sf lyP . 
 b'O{ k/Dk/fut zT? uf]/vf / ndh'ªaLr u7aGwg agfpg sfn' kf08]sf] s"6gLlt ;kmn eof] . To;kl5 uf]/vfn] sf:sL, tgx'F / kfn\kf;Fu u7aGwg u/] . 
 nueu Ps jif{ kl5, @ cS6f]a/ !&$$ df, pgn] g'jfsf]6nfO{ km]l/ cfqmd0f u/] / lht]/ cfkm\gf] uf]/vf /fHosf] l;dfgf lj:tf/ u/].)";
    // const char text[] = MyString;
    // auto textLength = TextLength(text);
    // const char *line = strtok((char *)text, "\n");

    // initialization for base
    auto baseTexture = LoadTexture("resources/images/villagehouse.png");

    // Main game loop
    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {
        // textCounter += 3;
        if (IsKeyDown(KEY_SPACE))
            framesCounter += 8;
        else
            framesCounter++;

        if (IsKeyPressed(KEY_ENTER))
            framesCounter = 0;
        textCounter++;

        BeginDrawing();

        ClearBackground(WHITE);

        switch (currentScreen)
        {
        case LOGO:
        {
            framesCounter++;

            DrawTextPro(font, "Plsqmg ", {(int)GetScreenWidth() / 2 - 75, (int)GetScreenHeight() / 2 - 75}, {0, 0}, 0, 100, 1.0, BLACK);

            if (framesCounter > 160)
            {
                currentScreen = MENU;
            }
        }
        break;
        case MENU:
        {
            // if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;
            if (exitWindowRequested)
            {
                if (IsKeyPressed(KEY_Y))
                    exitWindow = true;
                else if (IsKeyPressed(KEY_N))
                    exitWindowRequested = false;
            }
            UpdateMusicStream(bgmMusic);
            IsHoveredNew = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 - 165), 220, 85});
            IsHoveredSetting = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 - 15), 220, 85});
            IsHoveredQuit = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 + 135), 220, 85});
            IsHoveredAttack = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(GetScreenWidth()/1.0- 390.0), 15.0, GetScreenWidth()/1.0-15.0,80});
            // LoadMenu(FirstBackgroundImage);
            DrawTexture(FirstBackgroundTexture, 0, 0, WHITE); // Draw Background
            if (exitWindowRequested)
            {
                DrawRectangle(50, 150, GetScreenWidth() - 100.0, 80.0, Fade(BLACK, 0.8));
                DrawText("Are you sure you want to exit program? [Y/N]", 65, 160, 50, WHITE);
            }
            if (IsHoveredNew)
            {
                DrawTexture(NewAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 - 240), WHITE);
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    Entered = true;
                    transAlpha = 0.0f;
                }
            }
            else
            {
                DrawTexture(NewBefore, (GetScreenWidth() / 2 - 100), (GetScreenHeight() / 2 - 200), WHITE);
            }
            if (IsHoveredSetting)
            {
                DrawTexture(SettingAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 - 105), WHITE);
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    currentScreen = GameScreen::CONV;
                }
            }
            else
            {
                DrawTexture(SettingBefore, (GetScreenWidth() / 2 - 100), (GetScreenHeight() / 2 - 65), WHITE);
            }
            if (IsHoveredQuit)
            {
                DrawTexture(QuitAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 + 45), WHITE);
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    exitWindowRequested = true;
                }
            }
            else
            {
                DrawTexture(QuitBefore, (GetScreenWidth() / 2 - 100), (GetScreenHeight() / 2 + 85), WHITE);
            }
            if (Entered)
            {
                transAlpha += 0.005f;
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
                framesCounter1++; // Count frames
                if (framesCounter1 > 105)
                {
                    Entered = false;
                    framesCounter1 = 0;
                    transAlpha = 0.0f;
                    textCounter = 0;
                    currentScreen = CONV;
                }
            }
        }
        break;

        case CONV:
        {
            if (IsKeyPressed(KEY_ENTER))
                Entered = true;
            UpdateMusicStream(bgmMusic);
            DrawTexture(skyTexture, 0, 0, WHITE);
            DrawTexture(houseTexture, 0, 0, WHITE);
            DrawTexture(fatherTexture, -150, 150, WHITE);
            DrawTexture(daughterTexture, 1000, 400, WHITE);
            DrawTexture(speechTextureForFather, 140, 130, WHITE);
            DrawTexture(speechTextureForDaughter, 740, 350, WHITE);
            if (textCounter < 400)
            {
                DrawTextPro(font, convText1, {250, 200}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 400 && textCounter < 800)
            {
                DrawTextPro(font, convText2, {850, 425}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 800 && textCounter < 1200)
            {
                // DrawTextPro(font, TextSubtext(text3, 0, framesCounter / 10), {250, 200}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText3, {250, 200}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 1200 && textCounter < 1800)
            {
                DrawTextPro(font, convText41, {850, 400}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText42, {850, 425}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText43, {850, 450}, {0, 0}, 0, 25, 1.0, BLACK);
            }
            else if (textCounter > 1800 && textCounter < 2400)
            {
                DrawTextPro(font, convText51, {250, 175}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText52, {250, 200}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText53, {250, 225}, {0, 0}, 0, 25, 1.0, BLACK);
            }
            else if (textCounter > 2400 && textCounter < 2800)
            {
                DrawTextPro(font, convText6, {850, 425}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 2800 && textCounter < 3200)
            {
                DrawTextPro(font, convText71, {250, 185}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText72, {250, 210}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 3200 && textCounter < 3600)
            {
                DrawTextPro(font, convText73, {250, 185}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText74, {250, 210}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 3600 && textCounter < 4000)
            {
                DrawTextPro(font, convText81, {850, 415}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText82, {850, 440}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 4000 && textCounter < 4400)
            {
                DrawTextPro(font, convText83, {850, 415}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText84, {850, 440}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else
            {
                DrawTextPro(font, convText91, {250, 175}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText92, {250, 200}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText93, {250, 225}, {0, 0}, 0, 25, 1.0, BLACK);
            }

            if (Entered)
            {
                transAlpha += 0.005f;
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
                framesCounter1++; // Count frames
                if (framesCounter1 > 105)
                {
                    Entered = false;
                    framesCounter1 = 0;
                    transAlpha = 0.0f;
                    currentScreen = READ;
                }
            }
        }
        break;

        case READ:
        {

            // DrawText(TextSubtext(text, 0, framesCounter / 10), 210, 190, 20, BLACK);

            // DrawText(TextSubtext(text, 0, framesCounter/30), 210, 2200, 20, BLACK);
            // DrawText(TextSubtext(text, 0, framesCounter/40), 210, 250, 20, BLACK);

            if (IsKeyPressed(KEY_ENTER))
            {
                Entered = true;
                transAlpha = 0.0f;
            }else{
                DrawTexture(skyTexture, 0, 0, WHITE);
                DrawTextPro(font, TextSubtext(text, 0, framesCounter / 10), {10, 190}, {0, 0}, 0, 25, 1.0, BLACK);

            }
            if (Entered)
            {
                transAlpha += 0.005f;
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
                framesCounter1++; // Count frames
                if (framesCounter1 > 105)
                {
                    Entered = false;
                    framesCounter1 = 0;
                    transAlpha = 0.0f;
                    textCounter = 0;
                    currentScreen = STRATEGY;
                }
            }
        }

        break;

        case STRATEGY:
        {
            if (IsKeyDown(KEY_SPACE))
                framesCounter += 8;
            else
                framesCounter++;

            if (IsKeyPressed(KEY_ENTER))
                Entered = true;
            // if (IsKeyPressed(KEY_SPACE))
            //     framesCounter = 0;

            // if (IsKeyPressed(KEY_ENTER))
            // {
            //     Entered = false;
            // }
            UpdateMusicStream(bgmMusic);
            BeginDrawing();
            ClearBackground(WHITE);
            DrawTexture(skyTexture, 0, 0, WHITE);
            DrawTexture(PNSTexture, -500, 200, WHITE);
            DrawTexture(KPTexture, 170, 200, WHITE);
            DrawTexture(speechTextureForPNS, 130, 190, WHITE);
            DrawTexture(speechTextureForKP, 650, 230, WHITE);
            if (textCounter < 300)
            {
                DrawTextPro(font, strategyText11, {270, 250}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 300 && textCounter < 800)
            {
                DrawTextPro(font, strategyText12, {250, 240}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, strategyText13, {250, 280}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 800 && textCounter < 1700)
            {
                DrawTextPro(font, strategyText21, {750, 270}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, strategyText22, {750, 300}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, strategyText23, {750, 330}, {0, 0}, 0, 25, 1.0, BLACK);
            }
            else if (textCounter > 1700 && textCounter < 3000)
            {
                DrawTextPro(font, strategyText31, {250, 240}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, strategyText32, {250, 280}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 3000 && textCounter < 4200)
            {
                DrawTextPro(font, strategyText33, {250, 240}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, strategyText34, {250, 280}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 4200 && textCounter < 4700)
            {
                DrawTextPro(font, strategyText41, {750, 300}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 4700 && textCounter < 6200)
            {
                DrawTextPro(font, strategyText42, {750, 270}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, strategyText43, {750, 300}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, strategyText44, {750, 330}, {0, 0}, 0, 25, 1.0, BLACK);
            }
            if (Entered)
            {
                transAlpha += 0.005f;
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
                framesCounter1++; // Count frames
                if (framesCounter1 > 105)
                {
                    Entered = false;
                    framesCounter1 = 0;
                    transAlpha = 0.0f;
                    currentScreen = BASE;
                }
            }
        }
        break;

        case BASE:
        {
            my_base.draw();
            my_base.poll_drag();
            my_base.button_clicked();
            if (IsKeyPressed(KEY_ENTER))
            {
                Entered = true;
                transAlpha = 0.0f;
            }
            if (Entered)
            {
                transAlpha += 0.005f;
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
                framesCounter1++; // Count frames
                if (framesCounter1 > 105)
                {
                    Entered = false;
                    framesCounter1 = 0;
                    transAlpha = 0.0f;
                    currentScreen = ATTACK;
                }
            }
        }
        break;
        case ATTACK:
        {
            rival_base.draw();
            rival_base.poll_drag();
            if (IsHoveredAttack)
            {
                DrawTexture(NewAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 - 240), WHITE);
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    Entered = true;
                    transAlpha = 0.0f;
                }
            }
            else
            {
                DrawTexture(NewBefore, (GetScreenWidth()/1.0- 390.0), (GetScreenWidth()/1.0-15.0), WHITE);
            }
            if (IsKeyPressed(KEY_ENTER))
            {
                Entered = true;
                transAlpha = 0.0f;
            }
            if (Entered)
            {
                transAlpha += 0.005f;
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
                framesCounter1++; // Count frames
                if (framesCounter1 > 105)
                {
                    Entered = false;
                    framesCounter1 = 0;
                    transAlpha = 0.0f;
                    currentScreen = MENU;
                }
            }
        }
        break;
        default:
            break;
        }

        EndDrawing();
    }
    UnloadMusicStream(bgmMusic);
    UnloadTexture(FirstBackgroundTexture);
    UnloadTexture(NewBefore);
    UnloadTexture(SettingBefore);
    UnloadTexture(QuitBefore);
    UnloadTexture(NewAfter);
    UnloadTexture(SettingAfter);
    UnloadTexture(QuitBefore);

    UnloadTexture(skyTexture);
    UnloadImage(houseImage);
    UnloadTexture(houseTexture);
    UnloadImage(fatherImage);
    UnloadTexture(fatherTexture);
    UnloadTexture(daughterTexture);
    UnloadFont(font);
    UnloadTexture(speechTextureForFather);
    UnloadImage(speechImageForDaughter);
    UnloadTexture(speechTextureForDaughter);

    UnloadTexture(baseTexture);

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

#include <raylib.h>
#include <vector>
#include <iostream>
#include <cstring>

class BaseItem: public Rectangle{
  public:
    bool isDraggable;
    bool isBeingDragged;
    Texture2D texture;
    bool isObstacle;
    void draw(){
      DrawTexture(texture, x, y, WHITE);	    
    }
    void drag(int a, int b){
     if(isDraggable){
      x = a;
      y = b;
     }
    }
    bool operator !=(BaseItem item){
       if(x != item.x ||  y != item.y || isDraggable != item.isDraggable) return true;
       else return false;
    }
};

class Tile : public BaseItem{};

class Base{
 public:
   Base(){
    int height = GetScreenHeight();
    int width =  GetScreenWidth();

    // we will always start with tiles and castle so add them to the vector initally

    // add tiles to the vector
     for(int i = -30 ; i <= height ; i += 45){
        for(int j = -60; j <= width ; j += 40){
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
    castle.texture= LoadTexture("./resources/images/GorkhaMuseum1.png");
    castle.x = (int)GetScreenWidth() / 2;
    castle.y = (int)GetScreenHeight() / 2 - 150;
    castle.isDraggable = true;
    castle.isObstacle = true;
    items.emplace_back(castle);
    castle.width = castle.texture.width;
    castle.height = castle.texture.height;
   
    BaseItem camp;
    camp.texture = LoadTexture("./resources/army-camp.png");
    camp.x = 400;
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
    horse.texture = LoadTexture("./resources/horse.png");
    horse.x = 300;
    horse.y = 300;
    horse.isDraggable = true;
    horse.isObstacle = true;
    items.emplace_back(horse);

    BaseItem dhunga;
    dhunga.texture = LoadTexture("./resources/dhunga.png");
    dhunga.x = 50;
    dhunga.y = 60;
    dhunga.isDraggable = true;
    dhunga.isObstacle = true;
    items.emplace_back(dhunga);

    BaseItem fallenWood;
    fallenWood.texture = LoadTexture("./resources/fallen-wood.png");
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
    army.x = 100;
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
   void update(){}
   void refresh(){}
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

int main(){
  InitWindow(GetScreenWidth(),GetScreenHeight(),"Test");	
  ToggleFullscreen();
  Base my_base;
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
     ClearBackground(WHITE);
     my_base.draw();
     my_base.poll_drag();
    EndDrawing();
  }
}


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
       for(int j = -60; j <= width ; j += 60){
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
    castle.texture= LoadTexture("./resources/images/townhall.png");
    castle.x = (int)GetScreenWidth() / 2;
    castle.y = (int)GetScreenHeight() / 2 - 150;
    castle.isDraggable = true;
    castle.isObstacle = true;
    items.emplace_back(castle);
    castle.width = castle.texture.width;
    castle.height = castle.texture.height;

    BaseItem mediumTree;
    mediumTree.texture = LoadTexture("./resources/images/medum-tree.png");
    mediumTree.x = 200;
    mediumTree.y = 300;
    mediumTree.isDraggable = true;  
    mediumTree.isObstacle = true;
    mediumTree.width = mediumTree.texture.width;
    mediumTree.height = mediumTree.texture.height;
    items.emplace_back(mediumTree);
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


#include <raylib.h>
#include <vector>
#include <iostream>
#include <cstring>

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
    if (this->isButton)
    {
      DrawRectangle(x, y, this->width, this->height, WHITE);
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
    attackButton.x = GetScreenWidth()/2 + 400;
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
  void update() {}
  void refresh() {}
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

    BaseItem *lastDraggedItem = nullptr;
    void button_clicked()
    {
      for (auto &e : items)
      {
        // isHovered = CheckCollisionPointRec(GetMousePosition(), {e.x, e.y, e.x + e.width, e.y + e.height});
        if (e.isButton && GetMouseX() >= e.x && GetMouseX() <= (e.x + e.texture.width) && GetMouseY() >= e.y && GetMouseY() <= (e.y + e.texture.height) && IsMouseButtonDown(0))
        {
          e.isBeingDragged = true;
          lastDraggedItem = &e;
          DrawText("Collision", 100, 100, 23, RED);
          e.drag(GetMouseX() - e.texture.width / 2, GetMouseY() - e.texture.height / 2);
        }
      }
      if (IsMouseButtonReleased(0))
      {
        BaseItem newItem;
        newItem.width = lastDraggedItem->width;         // Set your desired width
        newItem.height = lastDraggedItem->height;        // Set your desired height
        newItem.texture = lastDraggedItem->texture; // Load your item's texture
        newItem.drag(lastDraggedItem->x, lastDraggedItem->y);
        // items.emplace_back(newItem);
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
}

;

int main()
{
  InitWindow(GetScreenWidth(), GetScreenHeight(), "Test");
  ToggleFullscreen();
  Base my_base;
  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);
    my_base.draw();
    my_base.poll_drag();
    my_base.button_clicked();
    // DrawLineEx({0, 620}, {GetScreenWidth(), 620}, 2, BLACK);
    EndDrawing();
  }
}

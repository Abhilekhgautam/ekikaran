#include <raylib.h>

enum GameScreen{MENU, CONV, BASE};

// int LoadMenu(Image &image){
//   ImageResize(&image,GetScreenWidth(),GetScreenHeight());
//   auto BackgroundTexture = LoadTextureFromImage(image);
//   DrawTexture(BackgroundTexture,0,0,WHITE);
//   return 0;
// }

int main(){

GameScreen currentScreen = GameScreen::MENU;

 int screenwidth = GetScreenWidth();
 int screenHeight = GetScreenHeight();

 SetExitKey(KEY_NULL);

 bool exitWindow = false;
 bool exitWindowRequested = false;

 SetTargetFPS(60);


 InitWindow(screenwidth, screenHeight, "Ekikaran");\

 bool IsHoveredNew = false;
 bool IsHoveredSetting = false;
 bool IsHoveredQuit = false;

// ToggleFullscreen();
 InitAudioDevice(); // initalize audio device

 auto BackgroundMusic = LoadMusicStream("resources/music/WarMusic.mp3");

 //Background Load
 auto FirstBackgroundTexture= LoadTexture("resources/images/first_background.png");
 //Button Load
 auto NewBefore = LoadTexture("resources/ButtonImages/NewGameBefore.png");
 auto SettingBefore = LoadTexture("resources/ButtonImages/SettingBefore.png");
 auto QuitBefore = LoadTexture("resources/ButtonImages/QuitBefore.png");
 auto NewAfter = LoadTexture("resources/ButtonImages/NewGameAfter.png");
 auto SettingAfter = LoadTexture("resources/ButtonImages/SettingAfter.png");
 auto QuitAfter = LoadTexture("resources/ButtonImages/QuitAfter.png");

 


 SetMusicVolume(BackgroundMusic,1.0f);
 PlayMusicStream(BackgroundMusic);

 while(!exitWindow && !WindowShouldClose() ){

  // if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;
  if (exitWindowRequested){
    if (IsKeyPressed(KEY_Y)) exitWindow = true;
    else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
  }
   UpdateMusicStream(BackgroundMusic);
   IsHoveredNew = CheckCollisionPointRec(GetMousePosition(),(Rectangle){(float)(GetScreenWidth()/2-65),(float)(GetScreenHeight()/2-165),220,85});
   IsHoveredSetting = CheckCollisionPointRec(GetMousePosition(),(Rectangle){(float)(GetScreenWidth()/2-65),(float)(GetScreenHeight()/2-15),220,85});
   IsHoveredQuit = CheckCollisionPointRec(GetMousePosition(),(Rectangle){(float)(GetScreenWidth()/2-65),(float)(GetScreenHeight()/2+135),220,85});
   
   
   BeginDrawing();
    ClearBackground(WHITE);
    // LoadMenu(FirstBackgroundImage);
    DrawTexture(FirstBackgroundTexture,0,0,WHITE); //Draw Background
    if (exitWindowRequested){
      DrawRectangle(100, 100, screenwidth, 20, BLACK);
      DrawText("Are you sure you want to exit program? [Y/N]", 100, 450, 30, WHITE);
    }
    if(IsHoveredNew){
      DrawTexture(NewAfter,(GetScreenWidth()/2-120),(GetScreenHeight()/2-240),WHITE);
      if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        currentScreen = GameScreen::CONV;
      }
    }else{
      DrawTexture(NewBefore,(GetScreenWidth()/2-100),(GetScreenHeight()/2-200),WHITE);
    }
    if(IsHoveredSetting){
      DrawTexture(SettingAfter,(GetScreenWidth()/2-120),(GetScreenHeight()/2-105),WHITE);
      if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        currentScreen = GameScreen::CONV;
      }
    }else{
      DrawTexture(SettingBefore,(GetScreenWidth()/2-100),(GetScreenHeight()/2-65),WHITE);
    }
    if(IsHoveredQuit){
      DrawTexture(QuitAfter,(GetScreenWidth()/2-120),(GetScreenHeight()/2+45),WHITE);
      if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        exitWindowRequested = true;
      }
    }else{
      DrawTexture(QuitBefore,(GetScreenWidth()/2-100),(GetScreenHeight()/2+85),WHITE);
    }
    

   EndDrawing();
  //  if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
  //   vector2 MousePosition = GetMouse
  //  }
 }
 //UnloadMusicStream(bgmMusic);
 UnloadMusicStream(BackgroundMusic);
 UnloadTexture(FirstBackgroundTexture);
 UnloadTexture(NewBefore);
 UnloadTexture(SettingBefore);
 UnloadTexture(QuitBefore);
 UnloadTexture(NewAfter);
 UnloadTexture(SettingAfter);
 UnloadTexture(QuitBefore);

 CloseAudioDevice();     // Close audio context
 CloseWindow();

 return 0;	
}

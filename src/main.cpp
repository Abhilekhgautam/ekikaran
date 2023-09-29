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

 InitWindow(screenwidth, screenHeight, "Ekikaran");
 
// ToggleFullscreen();
 InitAudioDevice(); // initalize audio device
 auto  bgmMusic = LoadMusicStream("resources/coin.wav");
 auto BackgroundMusic = LoadMusicStream("resources/music/WarMusic.mp3");
 

 //Background Load
 auto FirstBackgroundTexture= LoadTexture("resources/images/first_background.png");
//  auto FirstBackgroundImage = LoadImage("resources/images/first_background.png");
 
 //Button Load
 auto NewGameButton = LoadTexture("resources/BottomImages/newgame.png");
 auto SettingButton = LoadTexture("resources/BottomImages/setting.png");
 auto QuitButton = LoadTexture("resources/BottomImages/quit.png");


 SetMusicVolume(BackgroundMusic,1.0f);
 PlayMusicStream(BackgroundMusic);

 //SetMusicVolume(bgmMusic, 1.0f);
//  PlayMusicStream(bgmMusic);
 currentScreen = GameScreen::MENU;
 while(!WindowShouldClose()){
  // UpdateMusicStream(bgmMusic);
   UpdateMusicStream(BackgroundMusic);
   BeginDrawing();
    ClearBackground(WHITE);
    // LoadMenu(FirstBackgroundImage);
    DrawTexture(FirstBackgroundTexture,0,0,WHITE); //Draw Background
    DrawTexture(NewGameButton,(GetScreenWidth()/2-100),(GetScreenHeight()/2-200),WHITE);
    // DrawTexture(SettingButton,(GetScreenWidth()/2-100),(GetScreenHeight()/2-50),WHITE);
    DrawTexture(QuitButton,(GetScreenWidth()/2-100),(GetScreenHeight()/2+100),WHITE);

   EndDrawing();
 }
 //UnloadMusicStream(bgmMusic);
 UnloadMusicStream(BackgroundMusic);
 UnloadTexture(FirstBackgroundTexture);
 UnloadTexture(NewGameButton);
//  UnloadTexture(SettingButton);
 UnloadTexture(QuitButton);

 CloseAudioDevice();     // Close audio context
 CloseWindow();

 return 0;	
}

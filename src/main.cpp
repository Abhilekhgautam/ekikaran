#include <raylib.h>

enum GameScreen{MENU, CONV, BASE};

int main(){

GameScreen currentScreen = GameScreen::MENU;
 int screenwidth = 850;
 int screenHeight = 450;
 InitWindow(screenwidth, screenHeight, "Ekikaran");

 InitAudioDevice(); // initalize audio device
 auto  bgmMusic = LoadMusicStream("resources/coin.wav");

 SetMusicVolume(bgmMusic, 1.0f);
 PlayMusicStream(bgmMusic);
 currentScreen = GameScreen::MENU;
 while(!WindowShouldClose()){
   UpdateMusicStream(bgmMusic);	 
   BeginDrawing();
    ClearBackground(WHITE);
   EndDrawing();
 }
 UnloadMusicStream(bgmMusic);
 CloseAudioDevice();     // Close audio context
 CloseWindow();

 return 0;	
}

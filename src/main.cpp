#include <raylib.h>

enum GameScreen{MENU, CONV, BASE};

int main(){

GameScreen currentScreen = GameScreen::MENU;
 int screenwidth = 850;
 int screenHeight = 450;
 InitWindow(screenwidth, screenHeight, "Ekikaran");
 
 ToggleFullscreen();
 InitAudioDevice(); // initalize audio device
 auto  bgmMusic = LoadMusicStream("resources/coin.wav");
 
 //Image first_background = LoadImage('resources/images/first_background.png');

 auto first_background = LoadTexture("resources/images/first_background.png");
 

 SetMusicVolume(bgmMusic, 1.0f);
 PlayMusicStream(bgmMusic);
 currentScreen = GameScreen::MENU;
 while(!WindowShouldClose()){
   UpdateMusicStream(bgmMusic);	 
   BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(first_background,0,0,WHITE);
   EndDrawing();
 }
 UnloadMusicStream(bgmMusic);
 UnloadTexture(first_background);
 CloseAudioDevice();     // Close audio context
 CloseWindow();

 return 0;	
}

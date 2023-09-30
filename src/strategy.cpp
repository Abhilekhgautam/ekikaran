#include <raylib.h>
#include <iostream>
#include <string.h>

int main()
{

  int screenwidth = GetScreenWidth();
  int screenHeight = GetScreenHeight();

  int framesCounter = 0;

  InitWindow(screenwidth, screenHeight, "Ekikaran");

  Font font = LoadFont("resources/preeti.otf");

  InitAudioDevice(); // initalize audio device
  auto bgmMusic = LoadMusicStream("resources/music/scott-buckley-i-walk-with-ghosts(chosic.com).mp3");
  auto skyTexture = LoadTexture("resources/images/sky.png");
  auto KPImage = LoadImage("resources/images/characters/kalupandey.png");
  ImageResize(&KPImage, 1500, 750);
  auto KPTexture = LoadTextureFromImage(KPImage);
  auto PNSImage = LoadImage("resources/images/characters/PNSedited.png");
  ImageFlipHorizontal(&PNSImage);
  ImageResize(&PNSImage, GetScreenWidth(), GetScreenHeight()-100);
  auto PNSTexture = LoadTextureFromImage(PNSImage);
//   auto houseImage = LoadImage("resources/images/villagehouse.png");
//   ImageResize(&houseImage, GetScreenWidth(), GetScreenHeight());
//   auto houseTexture = LoadTextureFromImage(houseImage);
//   auto fatherImage = LoadImage("resources/characters/father.png");
//   ImageFlipHorizontal(&fatherImage);
//   ImageResize(&fatherImage, 600, GetScreenHeight());
//   auto fatherTexture = LoadTextureFromImage(fatherImage);
//   auto sonTexture = LoadTexture("resources/characters/son.png");
  auto speechTextureForPNS = LoadTexture("resources/images/speechbox.png");
  auto speechImageForKP = LoadImage("resources/images/speechbox.png");
  ImageFlipHorizontal(&speechImageForKP);
  auto speechTextureForKP = LoadTextureFromImage(speechImageForKP);
//   auto frames = 0;
//   auto isFather = true;
//   int n = 2;

  auto text11 = "sfn' kfG8],";
  auto text12 = "d tldnfO d'n\\sfhL";
  auto text13 = "agfpg] ;f]Rof .";

  auto text21 = "xh',{ ca lrGtf";
  auto text22 = "gdflgalS;of]; a8fdx/fh .";
  auto text23 = "d xh'nfO{ g}/f; agf}b}g";

  auto text31 = "xdL k}nf xfg{' sf] /x:o";
  auto text32 = ";]gf ;';lHht gfx'g' xf] .";
  auto text33 = "/ lrd]sL d'n'ssf]";
  auto text34 = ";fy gfx'g' xf] .";

  auto text41 = "r]tgf eof dnfO{ a9fdxf/h .";
  auto text42 = "d ;]gf tof/ uGo{f 5'";
  auto text43 = "/ lrd]sL d'n's ;Ë";
  auto text44 = "aft{nfa klg uGo{f  5'";

  SetMusicVolume(bgmMusic, 1.0f);
  PlayMusicStream(bgmMusic);
  float transAlpha = 0.0f;
  auto textCounter = 0;
  float fadeCounter = 0.0f;

  // currentScreen = GameScreen::CONV;
  while (!WindowShouldClose())
  {
    fadeCounter += 1;
    textCounter += 1;
    transAlpha += 0.005f;
    if (IsKeyDown(KEY_SPACE))
      framesCounter += 8;
    else
      framesCounter++;

    if (IsKeyPressed(KEY_ENTER))
      framesCounter = 0;

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
      DrawTextPro(font, text11, {270, 250}, {0, 0}, 0, 30, 1.0, BLACK);
    }
    else if (textCounter > 300 && textCounter < 800)
    {
      DrawTextPro(font, text12, {250, 240}, {0, 0}, 0, 30, 1.0, BLACK);
      DrawTextPro(font, text13, {250, 280}, {0, 0}, 0, 30, 1.0, BLACK);
    }
    else if (textCounter > 800 && textCounter < 1700)
    {
      DrawTextPro(font, text21, {750, 270}, {0, 0}, 0, 25, 1.0, BLACK);
      DrawTextPro(font, text22, {750, 300}, {0, 0}, 0, 25, 1.0, BLACK);
      DrawTextPro(font, text23, {750, 330}, {0, 0}, 0, 25, 1.0, BLACK);
    }
    else if(textCounter > 1700 && textCounter < 3000){
        DrawTextPro(font, text31, {250,240}, {0,0}, 0, 30, 1.0, BLACK);
        DrawTextPro(font, text32, {250,280}, {0,0}, 0, 30, 1.0, BLACK);
    }
    else if(textCounter > 3000 && textCounter < 4200){
        DrawTextPro(font, text33, {250,240}, {0,0}, 0, 30, 1.0, BLACK);
        DrawTextPro(font, text34, {250,280}, {0,0}, 0, 30, 1.0, BLACK);
    }
    else if(textCounter > 4200 && textCounter < 4700){
        DrawTextPro(font, text41, {750,300}, {0,0}, 0, 30, 1.0, BLACK);
    }
    else if(textCounter > 4700 && textCounter < 6200){
        DrawTextPro(font, text42, {750,270}, {0,0}, 0, 25, 1.0, BLACK);
        DrawTextPro(font, text43, {750,300}, {0,0}, 0, 25, 1.0, BLACK);
        DrawTextPro(font, text44, {750,330}, {0,0}, 0, 25, 1.0, BLACK);
    }
    if (IsKeyPressed(KEY_ENTER))
    {
      DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
    }
    EndDrawing();
  }

  UnloadMusicStream(bgmMusic);
  UnloadTexture(skyTexture);
  UnloadImage(KPImage);
  UnloadImage(PNSImage);
  UnloadTexture(PNSTexture);
  UnloadTexture(KPTexture);
  UnloadImage(speechImageForKP);
  UnloadTexture(speechTextureForKP);
  UnloadTexture(speechTextureForPNS);
//   UnloadImage(houseImage);
//   UnloadTexture(houseTexture);
  CloseAudioDevice(); // Close audio context
  CloseWindow();

  return 0;
}

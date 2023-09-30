#include <raylib.h>
#include <iostream>
#include <string.h>

int main()
{

  // GameScreen currentScreen = GameScreen::MENU;
  int screenwidth = GetScreenWidth();
  int screenHeight = GetScreenHeight();

  int framesCounter = 0;

  InitWindow(screenwidth, screenHeight, "Ekikaran");

  Font font = LoadFont("resources/preeti.otf");
  auto *text = LoadFileText("resources/conversation.txt");

  InitAudioDevice(); // initalize audio device
  auto bgmMusic = LoadMusicStream("resources/music/scott-buckley-i-walk-with-ghosts(chosic.com).mp3");

  auto skyTexture = LoadTexture("resources/images/sky.png");
  auto houseImage = LoadImage("resources/images/villagehouse.png");
  ImageResize(&houseImage, GetScreenWidth(), GetScreenHeight());
  auto houseTexture = LoadTextureFromImage(houseImage);
  auto fatherImage = LoadImage("resources/characters/father.png");
  ImageFlipHorizontal(&fatherImage);
  ImageResize(&fatherImage, 600, GetScreenHeight());
  auto fatherTexture = LoadTextureFromImage(fatherImage);
  auto sonTexture = LoadTexture("resources/characters/son.png");
  auto speechTextureForFather = LoadTexture("resources/images/speechbox.png");
  auto speechImageForSon = LoadImage("resources/images/speechbox.png");
  ImageFlipHorizontal(&speechImageForSon);
  auto speechTextureForSon = LoadTextureFromImage(speechImageForSon);
  auto frames = 0;
  auto isFather = true;
  int n = 2;

  auto text1 = "asdfg asdjf asfiuw  we9rw wow";
  auto text2 = "qweeryy askdf asdfuw fjskad fas";
  auto text3 = "sdfasdfh dfg sdfe asdfja";
  auto text4 = "asuiwe jasdufai f asdfk as";
  auto text5 = "asdf; asdfsow] aslkdfj saf";
  auto text6 = "asd ]sdf asdf askdfj asf";
  auto text7 = "sfmnnbcuw jse ea sldfjaf";
  int numText = 7;

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
    DrawTexture(houseTexture, 0, 0, WHITE);
    DrawTexture(fatherTexture, -150, 150, WHITE);
    DrawTexture(sonTexture, 1000, 350, WHITE);
    DrawTexture(speechTextureForFather, 140, 130, WHITE);
    DrawTexture(speechTextureForSon, 650, 350, WHITE);
    if (textCounter < 1000 * n)
    {
      DrawTextPro(font, TextSubtext(text1, 0, framesCounter / 50), {250, 200}, {0, 0}, 0, 30, 2.0, BLACK);
    }
    if (textCounter > 1000 * n && textCounter < 2000 * n)
    {
      DrawTextPro(font, TextSubtext(text2, 0, framesCounter / 50), {740, 425}, {0, 0}, 0, 30, 2.0, BLACK);
    }
    if (textCounter > 2000 * n && textCounter < 3000 * n)
    {
      DrawTextPro(font, TextSubtext(text3, 0, framesCounter / 50), {250, 200}, {0, 0}, 0, 30, 2.0, BLACK);
    }
    if (textCounter > 3000 * n && textCounter < 4000 * n)
    {
      DrawTextPro(font, TextSubtext(text4, 0, framesCounter / 50), {740, 425}, {0, 0}, 0, 30, 2.0, BLACK);
    }
    if (textCounter > 4000 * n && textCounter < 5000 * n)
    {
      DrawTextPro(font, TextSubtext(text5, 0, framesCounter / 50), {250, 200}, {0, 0}, 0, 30, 2.0, BLACK);
    }
    if (textCounter > 6000 * n && textCounter < 7000 * n)
    {
      DrawTextPro(font, TextSubtext(text6, 0, framesCounter / 50), {740, 425}, {0, 0}, 0, 30, 2.0, BLACK);
    }
    if (textCounter > 7000 * n && textCounter < 8000 * n)
    {
      DrawTextPro(font, TextSubtext(text7, 0, framesCounter / 50), {250, 200}, {0, 0}, 0, 30, 2.0, BLACK);
    }
    if (IsKeyPressed(KEY_ENTER))
    {
      DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
    }
    EndDrawing();
  }

  UnloadMusicStream(bgmMusic);
  UnloadTexture(skyTexture);
  UnloadTexture(fatherTexture);
  UnloadTexture(sonTexture);
  UnloadImage(houseImage);
  UnloadTexture(houseTexture);
  CloseAudioDevice(); // Close audio context
  CloseWindow();

  return 0;
}

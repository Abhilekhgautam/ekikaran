#include <raylib.h>

int main()
{

  // GameScreen currentScreen = GameScreen::MENU;
  int screenwidth = GetScreenWidth();
  int screenHeight = GetScreenHeight();

  int framesCounter = 0;

  InitWindow(screenwidth, screenHeight, "Ekikaran");

  Font font = LoadFont("resources/preeti.otf");

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

  auto fatherText = "d/f] gfd /Lof xf] ";
  auto sonText = "d/f] gfd /Lof xf] ";

  SetMusicVolume(bgmMusic, 1.0f);
  PlayMusicStream(bgmMusic);
  float transAlpha = 0.0f;

  // currentScreen = GameScreen::CONV;
  while (!WindowShouldClose())
  {
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
      DrawTextPro(font, TextSubtext(fatherText, 0, framesCounter / 10), {250, 200}, {0, 0}, 0, 20, 2.0, BLACK);
      DrawTextPro(font, TextSubtext(sonText, 0, framesCounter / 10), {740, 425}, {0, 0}, 0, 20, 2.0, BLACK);
      DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
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

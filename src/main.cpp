
#include "raylib.h"

typedef enum GameScreen
{
	MENU = 0,
	CONV,
	BASE
} GameScreen;

int main(void)
{
	const int screenWidth = GetScreenWidth();
	const int screenHeight = GetScreenHeight();

	InitWindow(screenWidth, screenHeight, "Ekikaran");

	GameScreen currentScreen = MENU;

	int framesCounter = 0; // Useful to count frames

	SetTargetFPS(60);

	// initialization for menu
	float transAlpha = 0.0f;
	auto backgroundTexture = LoadTexture("resources/images/first_background.png");

	// initialization for conv

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
	Font font = LoadFont("resources/preeti.otf");
	auto speechTextureForFather = LoadTexture("resources/images/speechbox.png");
	auto speechImageForSon = LoadImage("resources/images/speechbox.png");
	ImageFlipHorizontal(&speechImageForSon);
	auto speechTextureForSon = LoadTextureFromImage(speechImageForSon);
	auto fatherText = "d/f] gfd /Lof xf] ";
	auto sonText = "d/f] gfd /Lof xf] ";
	SetMusicVolume(bgmMusic, 1.0f);
	PlayMusicStream(bgmMusic);

	// initialization for base
	auto baseTexture = LoadTexture("resources/images/villagehouse.png");

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		switch (currentScreen)
		{
		case MENU:
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
				currentScreen = CONV;
			}
		}
		break;
		case CONV:
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
				currentScreen = BASE;
			}
		}
		break;
		case BASE:
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
				currentScreen = MENU;
			}
		}
		break;
		default:
			break;
		}
		BeginDrawing();

		ClearBackground(WHITE);

		switch (currentScreen)
		{
		case MENU:
		{
			transAlpha += 0.005f;
			DrawTexture(backgroundTexture, 0, 0, WHITE);
		}
		break;
		case CONV:
		{
			UpdateMusicStream(bgmMusic);
			DrawTexture(skyTexture, 0, 0, WHITE);
			DrawTexture(houseTexture, 0, 0, WHITE);
			DrawTexture(fatherTexture, -150, 150, WHITE);
			DrawTexture(sonTexture, 1000, 350, WHITE);
			DrawTexture(speechTextureForFather, 140, 130, WHITE);
			DrawTexture(speechTextureForSon, 650, 350, WHITE);
			DrawTextPro(font, TextSubtext(fatherText, 0, framesCounter / 10), {250, 200}, {0, 0}, 0, 20, 2.0, BLACK);
			DrawTextPro(font, TextSubtext(sonText, 0, framesCounter / 10), {740, 425}, {0, 0}, 0, 20, 2.0, BLACK);
		}
		break;
		case BASE:
		{
			DrawTexture(baseTexture, 0, 0, WHITE);
		}
		break;
		default:
			break;
		}

		EndDrawing();
	}
	CloseWindow();
	return 0;
}

/*

#include <raylib.h>

enum GameScreen{MENU, CONV, BASE};

int loadMenu(auto bgTexture){
	int width = 906;
	int height = 768;
	auto bgImage = LoadImageFromTexture(bgTexture);
	ImageResize(&bgImage, width, height);
	auto background = LoadTextureFromImage(bgImage);
	DrawTexture(background,0,0,WHITE);
	 return 0;
}

int main(){

GameScreen currentScreen = GameScreen::MENU;
 int screenwidth = GetScreenWidth();
 int screenHeight = GetScreenHeight();

 InitWindow(screenwidth, screenHeight, "Ekikaran");

 ToggleFullscreen();
 InitAudioDevice(); // initalize audio device
 auto  bgmMusic = LoadMusicStream("resources/coin.wav");

 auto backgroundTexture = LoadTexture("resources/images/first_background.png");


 SetMusicVolume(bgmMusic, 1.0f);
 PlayMusicStream(bgmMusic);
 currentScreen = GameScreen::MENU;
 while(!WindowShouldClose()){
   UpdateMusicStream(bgmMusic);
   BeginDrawing();
	ClearBackground(WHITE);
	DrawTexture(backgroundTexture,0,0,WHITE);
   // loadMenu(backgroundTexture);
   EndDrawing();
 }
 UnloadMusicStream(bgmMusic);
 UnloadTexture(backgroundTexture);
 CloseAudioDevice();     // Close audio context
 CloseWindow();

 return 0;
}
*/

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
    bool exitWindow = false;
    bool exitWindowRequested = false;
    float transAlpha = 0.0f;
     bool IsHoveredNew = false;
    bool IsHoveredSetting = false;
    bool IsHoveredQuit = false;
    auto BackgroundMusic = LoadMusicStream("resources/music/WarMusic.mp3");

    // Background Load
    auto FirstBackgroundTexture = LoadTexture("resources/images/FirstPage.png");
    //  auto FirstBackgroundImage = LoadImage("resources/images/first_background.png");

    // Button Load
    auto NewBefore = LoadTexture("resources/ButtonImages/NewGameBefore.png");
    auto SettingBefore = LoadTexture("resources/ButtonImages/SettingBefore.png");
    auto QuitBefore = LoadTexture("resources/ButtonImages/QuitBefore.png");

    auto NewAfter = LoadTexture("resources/ButtonImages/NewGameAfter.png");
    auto SettingAfter = LoadTexture("resources/ButtonImages/SettingAfter.png");
    auto QuitAfter = LoadTexture("resources/ButtonImages/QuitAfter.png");

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
    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
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
            // if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;
        if (exitWindowRequested)
        {
            if (IsKeyPressed(KEY_Y))
                exitWindow = true;
            else if (IsKeyPressed(KEY_N))
                exitWindowRequested = false;
        }
        UpdateMusicStream(BackgroundMusic);
        IsHoveredNew = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 - 165), 220, 85});
        IsHoveredSetting = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 - 15), 220, 85});
        IsHoveredQuit = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 + 135), 220, 85});

        BeginDrawing();
        ClearBackground(WHITE);
        // LoadMenu(FirstBackgroundImage);
        DrawTexture(FirstBackgroundTexture, 0, 0, WHITE); // Draw Background
        if (exitWindowRequested)
        {
            DrawRectangle(100, 100, screenWidth, 20, BLACK);
            DrawText("Are you sure you want to exit program? [Y/N]", 100, 450, 30, WHITE);
        }
        if (IsHoveredNew)
        {
            DrawTexture(NewAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 - 240), WHITE);
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                currentScreen = GameScreen::CONV;
            }
        }
        else
        {
            DrawTexture(NewBefore, (GetScreenWidth() / 2 - 100), (GetScreenHeight() / 2 - 200), WHITE);
        }
        if (IsHoveredSetting)
        {
            DrawTexture(SettingAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 - 105), WHITE);
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                currentScreen = GameScreen::CONV;
            }
        }
        else
        {
            DrawTexture(SettingBefore, (GetScreenWidth() / 2 - 100), (GetScreenHeight() / 2 - 65), WHITE);
        }
        if (IsHoveredQuit)
        {
            DrawTexture(QuitAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 + 45), WHITE);
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                exitWindowRequested = true;
            }
        }
        else
        {
            DrawTexture(QuitBefore, (GetScreenWidth() / 2 - 100), (GetScreenHeight() / 2 + 85), WHITE);
        }
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

enum GameScreen
{
    MENU,
    CONV,
    BASE
};

int main()
{

    GameScreen currentScreen = GameScreen::MENU;
    int screenwidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    SetExitKey(KEY_NULL);

    bool exitWindow = false;
    bool exitWindowRequested = false;

    SetTargetFPS(60);

    InitWindow(screenwidth, screenHeight, "Ekikaran");

    bool IsHoveredNew = false;
    bool IsHoveredSetting = false;
    bool IsHoveredQuit = false;

    // ToggleFullscreen();
    InitAudioDevice(); // initalize audio device
                       //  auto  bgmMusic = LoadMusicStream("resources/coin.wav");
    auto BackgroundMusic = LoadMusicStream("resources/music/WarMusic.mp3");

    // Background Load
    auto FirstBackgroundTexture = LoadTexture("resources/images/FirstPage.png");
    //  auto FirstBackgroundImage = LoadImage("resources/images/first_background.png");

    // Button Load
    auto NewBefore = LoadTexture("resources/ButtonImages/NewGameBefore.png");
    auto SettingBefore = LoadTexture("resources/ButtonImages/SettingBefore.png");
    auto QuitBefore = LoadTexture("resources/ButtonImages/QuitBefore.png");

    auto NewAfter = LoadTexture("resources/ButtonImages/NewGameAfter.png");
    auto SettingAfter = LoadTexture("resources/ButtonImages/SettingAfter.png");
    auto QuitAfter = LoadTexture("resources/ButtonImages/QuitAfter.png");

    SetMusicVolume(BackgroundMusic, 1.0f);
    PlayMusicStream(BackgroundMusic);

    // SetMusicVolume(bgmMusic, 1.0f);
    //  PlayMusicStream(bgmMusic);
    // UpdateMusicStream(bgmMusic);
    //  currentScreen = GameScreen::MENU;
    while (!exitWindow && !WindowShouldClose())
    {

        // if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;
        if (exitWindowRequested)
        {
            if (IsKeyPressed(KEY_Y))
                exitWindow = true;
            else if (IsKeyPressed(KEY_N))
                exitWindowRequested = false;
        }
        UpdateMusicStream(BackgroundMusic);
        IsHoveredNew = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 - 165), 220, 85});
        IsHoveredSetting = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 - 15), 220, 85});
        IsHoveredQuit = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 + 135), 220, 85});

        BeginDrawing();
        ClearBackground(WHITE);
        // LoadMenu(FirstBackgroundImage);
        DrawTexture(FirstBackgroundTexture, 0, 0, WHITE); // Draw Background
        if (exitWindowRequested)
        {
            DrawRectangle(100, 100, screenwidth, 20, BLACK);
            DrawText("Are you sure you want to exit program? [Y/N]", 100, 450, 30, WHITE);
        }
        if (IsHoveredNew)
        {
            DrawTexture(NewAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 - 240), WHITE);
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                currentScreen = GameScreen::CONV;
            }
        }
        else
        {
            DrawTexture(NewBefore, (GetScreenWidth() / 2 - 100), (GetScreenHeight() / 2 - 200), WHITE);
        }
        if (IsHoveredSetting)
        {
            DrawTexture(SettingAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 - 105), WHITE);
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                currentScreen = GameScreen::CONV;
            }
        }
        else
        {
            DrawTexture(SettingBefore, (GetScreenWidth() / 2 - 100), (GetScreenHeight() / 2 - 65), WHITE);
        }
        if (IsHoveredQuit)
        {
            DrawTexture(QuitAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 + 45), WHITE);
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                exitWindowRequested = true;
            }
        }
        else
        {
            DrawTexture(QuitBefore, (GetScreenWidth() / 2 - 100), (GetScreenHeight() / 2 + 85), WHITE);
        }

        EndDrawing();
        //  if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        //   vector2 MousePosition = GetMouse
        //  }
    }
    // UnloadMusicStream(bgmMusic);
    UnloadMusicStream(BackgroundMusic);
    UnloadTexture(FirstBackgroundTexture);
    UnloadTexture(NewBefore);
    UnloadTexture(SettingBefore);
    UnloadTexture(QuitBefore);
    UnloadTexture(NewAfter);
    UnloadTexture(SettingAfter);
    UnloadTexture(QuitBefore);

    CloseAudioDevice(); // Close audio context
    CloseWindow();

    return 0;
}
*/

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
    int framesCounter1 = 0;

    SetTargetFPS(60);

    // initialization for menu
    bool exitWindow = false;
    bool exitWindowRequested = false;
    float transAlpha = 1.0f;
    bool IsHoveredNew = false;
    bool IsHoveredSetting = false;
    bool IsHoveredQuit = false;
    auto BackgroundMusic = LoadMusicStream("resources/music/WarMusic.mp3");

    // Background Load
    auto FirstBackgroundImage = LoadImage("resources/images/first_background-transformed.png");
    ImageResize(&FirstBackgroundImage, GetScreenWidth(), GetScreenHeight());
    auto FirstBackgroundTexture = LoadTextureFromImage(FirstBackgroundImage);
    // auto FirstBackgroundTexture = LoadTexture("resources/images/first_background_clipdrop-enhance.png");
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
    auto bgmMusic = LoadMusicStream("resources/music/FirstBackgroundMusic.mp3");
    auto skyTexture = LoadTexture("resources/images/sky.png");
    auto houseImage = LoadImage("resources/images/villagehouse(1).png");
    ImageResize(&houseImage, GetScreenWidth(), GetScreenHeight());
    auto houseTexture = LoadTextureFromImage(houseImage);
    auto fatherImage = LoadImage("resources/characters/father(1).png");
    ImageFlipHorizontal(&fatherImage);
    ImageResize(&fatherImage, 600, GetScreenHeight());
    auto fatherTexture = LoadTextureFromImage(fatherImage);
    auto daughterTexture = LoadTexture("resources/characters/daughter(1).png");
    Font font = LoadFont("resources/preeti.otf");
    auto speechTextureForFather = LoadTexture("resources/images/speechbox.png");

    auto speechImageForDaughter = LoadImage("resources/images/speechbox.png");
    ImageFlipHorizontal(&speechImageForDaughter);
    auto speechTextureForDaughter = LoadTextureFromImage(speechImageForDaughter);
    auto textCounter = 0;
    auto text1 = "s] ul//sf] 5f]/L <";

    auto text2 = "u]d v]ln/sf] afaf .";

    auto text3 = "s'g v]n v]ln/Psf] gfgL <";

    auto text41 = ";fxl;s v]n v]ln/Psf]";
    auto text42 = "afaf d laleGg dlg; / PlnPg";
    auto text43 = ";Fu o'w nl8/x]sL 5' .";

    auto text51 = "t];f] xf] eg] d ;Fu lg";
    auto text52 = "Pp6f v]n 5 gfgL";
    auto text53 = "ltdLnfO{ dg k5{ xf]nf .";

    auto text6 = "s'g v]n afaf <";

    auto text71 = "Plssf/0f , Pltxl;s v]nsf]";
    auto text72 = "d}bfg xf] gfgL .";
    auto text73 = "of] v]n Plss[T /";
    auto text74 = "/0fflglts n8fO{+ xf] .";

    auto text81 = "cf]xf]! d t xh'/sf]";
    auto text82 = "s'/f ;'g]/ pT;lxt eP .";
    auto text83 = "clg of] v]n s;/L";
    auto text84 = "v]n\\g] t <";

    auto text91 = "nf} of] lstfa!";
    auto text92 = "k9]/ P;s} cfwf/df";
    auto text93 = "v]n\b} hfg] xf] gfgL";
    SetMusicVolume(bgmMusic, 1.0f);
    PlayMusicStream(bgmMusic);

    bool BaseEntered = false;
    bool MenuEntered = false;
    bool ConvEntered = false;
    bool transition = false;

    bool Entered = false;

    // initialization for base
    auto baseTexture = LoadTexture("resources/images/villagehouse.png");

    // Main game loop
    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {
        textCounter++;
        // switch (currentScreen)
        // {
        //     case MENU:
        //     {
        //         if(Entered)
        //         {
        //             transAlpha+=0.005f;
        //             DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
        //             framesCounter1++;    // Count frames
        //             if (framesCounter1 > 90)
        //             {
        //                 Entered = false;
        //                 framesCounter1 = 0;
        //                 transAlpha = 0.0f;
        //                 currentScreen = CONV;
        //             }
        //         }
        //         if (IsKeyPressed(KEY_ENTER))
        //         {
        //             Entered = true;
        //         }
        //     }
        //     break;
        //     case CONV:
        //     {
        //         if(Entered)
        //         {
        //             transAlpha+=0.005f;
        //             DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
        //             framesCounter1++;    // Count frames
        //             if (framesCounter1 > 90)
        //             {
        //                 Entered = false;
        //                 framesCounter1 = 0;
        //                 transAlpha = 0.0f;
        //                 currentScreen = BASE;
        //             }
        //         }
        //         if (IsKeyPressed(KEY_ENTER))
        //         {
        //             Entered = true;
        //         }
        //     }
        //     break;
        //     case BASE:
        //     {
        //         if(Entered)
        //         {
        //             transAlpha+=0.005f;
        //             DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
        //             framesCounter1++;    // Count frames
        //             if (framesCounter1 > 90)
        //             {
        //                 Entered = false;
        //                 framesCounter1 = 0;
        //                 transAlpha = 0.0f;
        //                 currentScreen = MENU;
        //             }
        //         }
        //         if (IsKeyPressed(KEY_ENTER))
        //         {
        //             Entered = true;
        //         }
        //     }
        //     break;
        //     default:
        //         break;
        // }

        BeginDrawing();

        ClearBackground(WHITE);

        switch (currentScreen)
        {
        case MENU:
        {
            if (exitWindowRequested)
            {
                if (IsKeyPressed(KEY_Y))
                    exitWindow = true;
                else if (IsKeyPressed(KEY_N))
                    exitWindowRequested = false;
            }
            UpdateMusicStream(bgmMusic);
            IsHoveredNew = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 - 165), 220, 85});
            IsHoveredSetting = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 - 15), 220, 85});
            IsHoveredQuit = CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)(GetScreenWidth() / 2 - 65), (float)(GetScreenHeight() / 2 + 135), 220, 85});

            // LoadMenu(FirstBackgroundImage);
            DrawTexture(FirstBackgroundTexture, 0, 0, WHITE); // Draw Background
            if (exitWindowRequested)
            {
                DrawRectangle(50, 150, GetScreenWidth() - 100.0, 80.0, Fade(BLACK, 0.8));
                DrawText("Are you sure you want to exit program? [Y/N]", 65, 160, 50, WHITE);
            }
            if (IsHoveredNew)
            {
                DrawTexture(NewAfter, (GetScreenWidth() / 2 - 120), (GetScreenHeight() / 2 - 240), WHITE);
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    Entered = true;
                    transAlpha = 0.0f;
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

            if (Entered)
            {
                transAlpha += 0.005f;
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
                framesCounter1++; // Count frames
                if (framesCounter1 > 105)
                {
                    Entered = false;
                    framesCounter1 = 0;
                    transAlpha = 0.0f;
                    currentScreen = CONV;
                }
            }
        }
        break;

        case CONV:
        {
            if (IsKeyDown(KEY_SPACE))
                framesCounter += 8;
            else
                framesCounter++;

            if (IsKeyPressed(KEY_ENTER))
                Entered = true;
            // if (IsKeyPressed(KEY_SPACE))
            //     framesCounter = 0;
            
            // if (IsKeyPressed(KEY_ENTER))
            // {
            //     Entered = false;
            // }
            UpdateMusicStream(bgmMusic);
            DrawTexture(skyTexture, 0, 0, WHITE);
            DrawTexture(houseTexture, 0, 0, WHITE);
            DrawTexture(fatherTexture, -150, 150, WHITE);
            DrawTexture(daughterTexture, 1000, 400, WHITE);
            DrawTexture(speechTextureForFather, 140, 130, WHITE);
            DrawTexture(speechTextureForDaughter, 740, 350, WHITE);
            if (textCounter < 400)
            {
                // DrawTextPro(font, TextSubtext(text1, 0, framesCounter / 10), {250, 200}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, text1, {250, 200}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 400 && textCounter < 800)
            {
                // DrawTextPro(font, TextSubtext(text2, 0, framesCounter / 40), {850, 425}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, text2, {850, 425}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 800 && textCounter < 1200)
            {
                // DrawTextPro(font, TextSubtext(text3, 0, framesCounter / 80), {250, 200}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, text3, {250, 200}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 1200 && textCounter < 1800)
            {
                // DrawTextPro(font, TextSubtext(text41, 0, framesCounter / 60), {850, 400}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text42, 0, framesCounter / 60), {850, 425}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text43, 0, framesCounter / 60), {850, 450}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, text41, {850, 400}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, text42, {850, 425}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, text43, {850, 450}, {0, 0}, 0, 25, 1.0, BLACK);
            }
            else if (textCounter > 1800 && textCounter < 2400)
            {
                DrawTextPro(font, text51, {250, 175}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, text52, {250, 200}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, text53, {250, 225}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text51, 0, framesCounter / 10), {250, 175}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text52, 0, framesCounter / 10), {250, 200}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text53, 0, framesCounter / 10), {250, 225}, {0, 0}, 0, 25, 1.0, BLACK);
            }
            else if (textCounter > 2400 && textCounter < 2800)
            {
                DrawTextPro(font, text6, {850, 425}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text6, 0, framesCounter / 10), {850, 425}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 2800 && textCounter < 3200)
            {
                DrawTextPro(font, text71, {250, 185}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, text72, {250, 210}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text71, 0, framesCounter / 10), {250, 185}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text72, 0, framesCounter / 10), {250, 210}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 3200 && textCounter < 3600)
            {
                DrawTextPro(font, text73, {250, 185}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, text74, {250, 210}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text73, 0, framesCounter / 10), {250, 185}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text74, 0, framesCounter / 10), {250, 210}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 3600 && textCounter < 4000)
            {
                DrawTextPro(font, text81, {850, 415}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, text82, {850, 440}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text81, 0, framesCounter / 10), {850, 415}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text82, 0, framesCounter / 10), {850, 440}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 4000 && textCounter < 4400)
            {
                DrawTextPro(font, text83, {850, 415}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, text84, {850, 440}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text83, 0, framesCounter / 10), {850, 415}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text84, 0, framesCounter / 10), {850, 440}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else
            {
                DrawTextPro(font, text91, {250, 175}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, text92, {250, 200}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, text93, {250, 225}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text91, 0, framesCounter / 10), {250, 175}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text92, 0, framesCounter / 10), {250, 200}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text93, 0, framesCounter / 10), {250, 225}, {0, 0}, 0, 25, 1.0, BLACK);
            }
            
            if (Entered)
            {
                transAlpha += 0.005f;
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
                framesCounter1++; // Count frames
                if (framesCounter1 > 105)
                {
                    Entered = false;
                    framesCounter1 = 0;
                    transAlpha = 0.0f;
                    currentScreen = BASE;
                }
            }
        }

        break;

        case BASE:
        {
            DrawTexture(baseTexture, 0, 0, WHITE);
            if (IsKeyPressed(KEY_ENTER))
            {
                Entered = true;
                transAlpha = 0.0f;
            }
            if (Entered)
            {
                transAlpha += 0.005f;
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
                framesCounter1++; // Count frames
                if (framesCounter1 > 105)
                {
                    Entered = false;
                    framesCounter1 = 0;
                    transAlpha = 0.0f;
                    currentScreen = MENU;
                }
            }
        }
        break;
        default:
            break;
        }

        EndDrawing();
    }
    UnloadMusicStream(bgmMusic);
    UnloadTexture(FirstBackgroundTexture);
    UnloadTexture(NewBefore);
    UnloadTexture(SettingBefore);
    UnloadTexture(QuitBefore);
    UnloadTexture(NewAfter);
    UnloadTexture(SettingAfter);
    UnloadTexture(QuitBefore);

    UnloadTexture(skyTexture);
    UnloadImage(houseImage);
    UnloadTexture(houseTexture);
    UnloadImage(fatherImage);
    UnloadTexture(fatherTexture);
    UnloadTexture(daughterTexture);
    UnloadFont(font);
    UnloadTexture(speechTextureForFather);
    UnloadImage(speechImageForDaughter);
    UnloadTexture(speechTextureForDaughter);

    UnloadTexture(baseTexture);

    CloseAudioDevice();
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

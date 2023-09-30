
#include "raylib.h"

typedef enum GameScreen
{
    MENU = 0,
    CONV,
    STRATEGY,
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
    auto convText1 = "s] ul//sf] 5f]/L <";

    auto convText2 = "u]d v]ln/sf] afaf .";

    auto convText3 = "s'g v]n v]ln/Psf] gfgL <";

    auto convText41 = ";fxl;s v]n v]ln/Psf]";
    auto convText42 = "afaf d laleGg dlg; / PlnPg";
    auto convText43 = ";Fu o'w nl8/x]sL 5' .";

    auto convText51 = "t];f] xf] eg] d ;Fu lg";
    auto convText52 = "Pp6f v]n 5 gfgL";
    auto convText53 = "ltdLnfO{ dg k5{ xf]nf .";

    auto convText6 = "s'g v]n afaf <";

    auto convText71 = "Plssf/0f , Pltxl;s v]nsf]";
    auto convText72 = "d}bfg xf] gfgL .";
    auto convText73 = "of] v]n Plss[T /";
    auto convText74 = "/0fflglts n8fO{+ xf] .";

    auto convText81 = "cf]xf]! d t xh'/sf]";
    auto convText82 = "s'/f ;'g]/ pT;lxt eP .";
    auto convText83 = "clg of] v]n s;/L";
    auto convText84 = "v]n\\g] t <";

    auto convText91 = "nf} of] lstfa!";
    auto convText92 = "k9]/ P;s} cfwf/df";
    auto convText93 = "v]n\b} hfg] xf] gfgL";
    SetMusicVolume(bgmMusic, 1.0f);
    PlayMusicStream(bgmMusic);

    bool BaseEntered = false;
    bool MenuEntered = false;
    bool ConvEntered = false;
    bool transition = false;

    bool Entered = false;

    // initialization for strategy
    auto KPImage = LoadImage("resources/images/characters/kalupandey.png");
    ImageResize(&KPImage, 1500, 750);
    auto KPTexture = LoadTextureFromImage(KPImage);
    auto PNSImage = LoadImage("resources/images/characters/PNSedited.png");
    ImageFlipHorizontal(&PNSImage);
    ImageResize(&PNSImage, GetScreenWidth(), GetScreenHeight() - 100);
    auto PNSTexture = LoadTextureFromImage(PNSImage);
    auto speechTextureForPNS = LoadTexture("resources/images/speechbox.png");
    auto speechImageForKP = LoadImage("resources/images/speechbox.png");
    ImageFlipHorizontal(&speechImageForKP);
    auto speechTextureForKP = LoadTextureFromImage(speechImageForKP);
    auto strategyText11 = "sfn' kfG8],";
    auto strategyText12 = "d tldnfO d'n\\sfhL";
    auto strategyText13 = "agfpg] ;f]Rof .";

    auto strategyText21 = "xh',{ ca lrGtf";
    auto strategyText22 = "gdflgalS;of]; a8fdx/fh .";
    auto strategyText23 = "d xh'nfO{ g}/f; agf}b}g";

    auto strategyText31 = "xdL k}nf xfg{' sf] /x:o";
    auto strategyText32 = ";]gf ;';lHht gfx'g' xf] .";
    auto strategyText33 = "/ lrd]sL d'n'ssf]";
    auto strategyText34 = ";fy gfx'g' xf] .";

    auto strategyText41 = "r]tgf eof dnfO{ a9fdxf/h .";
    auto strategyText42 = "d ;]gf tof/ uGo{f 5'";
    auto strategyText43 = "/ lrd]sL d'n's ;Ë";
    auto strategyText44 = "aft{nfa klg uGo{f  5'";

    // initialization for base
    auto baseTexture = LoadTexture("resources/images/villagehouse.png");

    // Main game loop
    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {
        textCounter +=3 ;
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
            if (exitWindowRequested)0
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
                    textCounter = 0;
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
                DrawTextPro(font, convText1, {250, 200}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 400 && textCounter < 800)
            {
                // DrawTextPro(font, TextSubtext(text2, 0, framesCounter / 40), {850, 425}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText2, {850, 425}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 800 && textCounter < 1200)
            {
                // DrawTextPro(font, TextSubtext(text3, 0, framesCounter / 80), {250, 200}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText3, {250, 200}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 1200 && textCounter < 1800)
            {
                // DrawTextPro(font, TextSubtext(text41, 0, framesCounter / 60), {850, 400}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text42, 0, framesCounter / 60), {850, 425}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text43, 0, framesCounter / 60), {850, 450}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText41, {850, 400}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText42, {850, 425}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText43, {850, 450}, {0, 0}, 0, 25, 1.0, BLACK);
            }
            else if (textCounter > 1800 && textCounter < 2400)
            {
                DrawTextPro(font, convText51, {250, 175}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText52, {250, 200}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText53, {250, 225}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text51, 0, framesCounter / 10), {250, 175}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text52, 0, framesCounter / 10), {250, 200}, {0, 0}, 0, 25, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text53, 0, framesCounter / 10), {250, 225}, {0, 0}, 0, 25, 1.0, BLACK);
            }
            else if (textCounter > 2400 && textCounter < 2800)
            {
                DrawTextPro(font, convText6, {850, 425}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text6, 0, framesCounter / 10), {850, 425}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 2800 && textCounter < 3200)
            {
                DrawTextPro(font, convText71, {250, 185}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText72, {250, 210}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text71, 0, framesCounter / 10), {250, 185}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text72, 0, framesCounter / 10), {250, 210}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 3200 && textCounter < 3600)
            {
                DrawTextPro(font, convText73, {250, 185}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText74, {250, 210}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text73, 0, framesCounter / 10), {250, 185}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text74, 0, framesCounter / 10), {250, 210}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 3600 && textCounter < 4000)
            {
                DrawTextPro(font, convText81, {850, 415}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText82, {850, 440}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text81, 0, framesCounter / 10), {850, 415}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text82, 0, framesCounter / 10), {850, 440}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 4000 && textCounter < 4400)
            {
                DrawTextPro(font, convText83, {850, 415}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, convText84, {850, 440}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text83, 0, framesCounter / 10), {850, 415}, {0, 0}, 0, 30, 1.0, BLACK);
                // DrawTextPro(font, TextSubtext(text84, 0, framesCounter / 10), {850, 440}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else
            {
                DrawTextPro(font, convText91, {250, 175}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText92, {250, 200}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, convText93, {250, 225}, {0, 0}, 0, 25, 1.0, BLACK);
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
                    textCounter = 0;
                    currentScreen = STRATEGY;
                }
            }
        }

        break;

        case STRATEGY:
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
            BeginDrawing();
            ClearBackground(WHITE);
            DrawTexture(skyTexture, 0, 0, WHITE);
            DrawTexture(PNSTexture, -500, 200, WHITE);
            DrawTexture(KPTexture, 170, 200, WHITE);
            DrawTexture(speechTextureForPNS, 130, 190, WHITE);
            DrawTexture(speechTextureForKP, 650, 230, WHITE);
            if (textCounter < 300)
            {
                DrawTextPro(font, strategyText11, {270, 250}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 300 && textCounter < 800)
            {
                DrawTextPro(font, strategyText12, {250, 240}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, strategyText13, {250, 280}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 800 && textCounter < 1700)
            {
                DrawTextPro(font, strategyText21, {750, 270}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, strategyText22, {750, 300}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, strategyText23, {750, 330}, {0, 0}, 0, 25, 1.0, BLACK);
            }
            else if (textCounter > 1700 && textCounter < 3000)
            {
                DrawTextPro(font, strategyText31, {250, 240}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, strategyText32, {250, 280}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 3000 && textCounter < 4200)
            {
                DrawTextPro(font, strategyText33, {250, 240}, {0, 0}, 0, 30, 1.0, BLACK);
                DrawTextPro(font, strategyText34, {250, 280}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 4200 && textCounter < 4700)
            {
                DrawTextPro(font, strategyText41, {750, 300}, {0, 0}, 0, 30, 1.0, BLACK);
            }
            else if (textCounter > 4700 && textCounter < 6200)
            {
                DrawTextPro(font, strategyText42, {750, 270}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, strategyText43, {750, 300}, {0, 0}, 0, 25, 1.0, BLACK);
                DrawTextPro(font, strategyText44, {750, 330}, {0, 0}, 0, 25, 1.0, BLACK);
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

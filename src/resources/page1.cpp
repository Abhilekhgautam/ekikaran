#include <raylib.h>
#include <string>
#include <vector>

int main()
{
    // Initialize Raylib and create a window
    int screenWidth = 800;  // Set your desired screen width
    int screenHeight = 600; // Set your desired screen height
    InitWindow(screenWidth, screenHeight, "Ekikaran");

    // Load the background image
    Image backgroundImage = LoadImage("resources/images/sky.png");
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);

    // Set the frames-per-second
    SetTargetFPS(60);

    int rectWidth = 700;
    int rectHeight = 300;

    // Rectangle position
    int rectX = (screenWidth - rectWidth) / 2;
    int rectY = (screenHeight - rectHeight) / 2;

    // Text to display
    std::string text = "#)) aif{ klxnf g]kfn eg]/ sf7df8f}+ pkTosnfO{ lrGg] ul/GYof] c? ;a} 8f]6L,s}nfnL ,g'jfsf]6 h:tf 7'nf 7'nf /fHo lyP eg] c? ;-;fgf /fHo lyP .t]; k5L uf]v{f Ps ;gf] /fHo df Ps dxg of]w sf] hGd x'G5 h:nfO{ xfdL k[lyjL gf/fo0ff ifx eg]/ lrGg] ur{f} .pgsf] a'af g/e'kfn zfxsf] d[To' !&&( @% r}tdf  ePkl5 pgL uf]/vfsf /fhf eP .k[YjLgf/fo0f lgs} dxTjfsf+IfL /fhf lyP . uf]v{f cfqmd0f;Fu} uf]v{f ;]gfaf6 hf]ufpg rfxGy], To;}n] ;fgf ;fgf /fHox¿nfO{ PsLs/0f u/]/ Pp6} b]z agfpg yfn] .";
    // Split the text into lines
    std::vector<std::string> textLines;
    std::string currentLine = "";
    for (char c : text)
    {
        if (c == ' ' && MeasureText(currentLine.c_str(), 20) > rectWidth - 20)
        {
            textLines.push_back(currentLine);
            currentLine = "";
        }
        currentLine += c;
    }
    textLines.push_back(currentLine); // Add the last line

    int textSize = 20;
    int lineSpacing = 30;
    int maxLines = (rectHeight - 20) / (textSize + lineSpacing);

    while (!WindowShouldClose())
    {
        // Clear the screen
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the background image
        DrawTexture(backgroundTexture, 0, 0, WHITE);

        // Draw the rectangle with a border
        DrawRectangleLines(rectX, rectY, rectWidth, rectHeight, BLACK);
        DrawRectangle(rectX, rectY, rectWidth, rectHeight, Fade(BLACK, 0.5f)); // Rectangle background

        
        int numLines = std::min(maxLines, static_cast<int>(textLines.size()));
        for (int i = 0; i < numLines; ++i)
        {
            int lineY = rectY + 10 + i * (textSize + lineSpacing);
            DrawTextPro(font, textLines[i].c_str(), rectX + 10, lineY, textSize, WHITE);
        }

        EndDrawing();
    }

    
    UnloadTexture(backgroundTexture);
    CloseWindow();

    return 0;
}

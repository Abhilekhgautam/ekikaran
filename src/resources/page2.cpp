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

    int rectWidth = 800;
    int rectHeight = 400;

    // Rectangle position
    int rectX = (screenWidth - rectWidth) / 2;
    int rectY = (screenHeight - rectHeight) / 2;

    // Text to display
    std::string text = "/fhf ag]sf] Ps jif{kl5 ;G !&$$ df pgn] g'jfsf]6df cfqmd0f u/] t/ uf]/vf ;]gf /fd|f];Fu ;';lHht gePsf] sf/0fn] kl5 x6\of] .To;kl5 zfxn] sfn' kf08]nfO{ cfkm\gf] /fHosf] /“d'nsfhL” agfP / o;/L cfkm\gf] 3/]n' /fhgLlts l:ylt alnof] agfP./fhf cfqmd0f cleofgdf uPsf a]nf l5d]sL /fhfx¿n] uf]/vfdf cfqmd0f ug{ ;S5G eGg] 8/ lyof] . o;/L k[YjLn] sfn' kf08]nfO{ ndh'ªsf /fhf;Fu jft{f ug{ k7fP . sfn' kf08]n] ndh'ªsf /fhf;Fu r]k] gbLsf] a]l;gdf ;f}xfb{k \"0f{ s'/fsfgL u/]sf lyP ";
    

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
            DrawText(textLines[i].c_str(), rectX + 10, lineY, textSize, WHITE);
        }

        EndDrawing();
    }

    
    UnloadTexture(backgroundTexture);
    CloseWindow();

    return 0;
}

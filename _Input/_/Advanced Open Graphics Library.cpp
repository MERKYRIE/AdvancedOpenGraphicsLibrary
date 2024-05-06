#pragma comment(lib , "..\\OpenAssetImportLibrary\\assimp-vc143-mt.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2main.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Image\\sdl2_image.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Mixer\\sdl2_mixer.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\TrueTypeFont\\sdl2_ttf.lib")

#define GLAD_GL_IMPLEMENTATION

#include"Advanced Open Graphics Library.hpp"

#include"Audio.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Space.hpp"
#include"Time.hpp"
#include"Video.hpp"

std::int32_t main(std::int32_t , char**)
{
    new NAdvancedOpenGraphicsLibrary::CDebug;
    NAdvancedOpenGraphicsLibrary::GDebug->AAssertSimpleDirectMediaLayerCode(SDL_Init(SDL_INIT_EVERYTHING));
    new NAdvancedOpenGraphicsLibrary::CAudio;
    new NAdvancedOpenGraphicsLibrary::CInput;
    new NAdvancedOpenGraphicsLibrary::CVideo;
    new NAdvancedOpenGraphicsLibrary::CTime;
    new NAdvancedOpenGraphicsLibrary::CSpace;
    while(!NAdvancedOpenGraphicsLibrary::GInput->AIsKeyHeld(SDL_SCANCODE_ESCAPE))
    {
        NAdvancedOpenGraphicsLibrary::GInput->AUpdate();
        NAdvancedOpenGraphicsLibrary::GTime->AUpdate();
        NAdvancedOpenGraphicsLibrary::GVideo->APreupdate();
        NAdvancedOpenGraphicsLibrary::GSpace->AUpdate();
        NAdvancedOpenGraphicsLibrary::GVideo->APostupdate();
    };
    delete NAdvancedOpenGraphicsLibrary::GSpace;
    delete NAdvancedOpenGraphicsLibrary::GTime;
    delete NAdvancedOpenGraphicsLibrary::GVideo;
    delete NAdvancedOpenGraphicsLibrary::GInput;
    delete NAdvancedOpenGraphicsLibrary::GAudio;
    SDL_Quit();
    delete NAdvancedOpenGraphicsLibrary::GDebug;
    return(0);
}
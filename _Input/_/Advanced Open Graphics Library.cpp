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
    NAdvancedOpenGraphicsLibrary::GDebug.OSimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    NAdvancedOpenGraphicsLibrary::GAudio.BInitialize();
    NAdvancedOpenGraphicsLibrary::GVideo.BInitialize();
    NAdvancedOpenGraphicsLibrary::GSpace.BInitialize();
    while(!NAdvancedOpenGraphicsLibrary::GInput.OIsKeyHeld(SDL_SCANCODE_ESCAPE))
    {
        NAdvancedOpenGraphicsLibrary::GInput.BUpdate();
        NAdvancedOpenGraphicsLibrary::GTime.BUpdate();
        NAdvancedOpenGraphicsLibrary::GVideo.BPreupdate();
        NAdvancedOpenGraphicsLibrary::GSpace.BUpdate();
        NAdvancedOpenGraphicsLibrary::GVideo.BPostupdate();
    };
    NAdvancedOpenGraphicsLibrary::GSpace.BDeinitialize();
    NAdvancedOpenGraphicsLibrary::GVideo.BDeinitialize();
    NAdvancedOpenGraphicsLibrary::GAudio.BDeinitialize();
    SDL_Quit();
    return(0);
}
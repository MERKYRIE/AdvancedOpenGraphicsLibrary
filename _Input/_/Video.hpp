#pragma once

#include"Advanced Open Graphics Library.hpp"

namespace NAdvancedOpenGraphicsLibrary
{
    inline class CVideo
    {
        private : SDL_Window* FWindow;
        private : SDL_GLContext FContext;
        private : float FRatio;
        private : float FRatioInversed;
        private : std::vector<std::shared_ptr<NVideo::CFont>> FFonts;
        private : std::vector<std::shared_ptr<NVideo::CTexture>> FTextures;

        public : CVideo();
        public : void APreupdate();
        public : float ARatio();
        public : float ARatioInversed();
        public : NVideo::CFont* AAccessFont(const std::string& PPath);
        public : NVideo::CTexture* AAccessSpecificTexture(const std::string& PPath);
        public : NVideo::CTexture* AAccessRandomTexture();
        public : void APostupdate();
        public : ~CVideo();
    }
    *GVideo;
}
#pragma once

#include"Advanced Open Graphics Library.hpp"

namespace NAdvancedOpenGraphicsLibrary::NAudio
{
    class CSound
    {
        private : std::string FPath;
        private : Mix_Chunk* FHandle;
        private : std::int32_t FChannel;

        public : CSound(const std::string& PPath);
        public : std::string APath();
        public : bool AIs(const std::string& PPath);
        public : CSound* APlay();
        public : bool AIsPlaying();
        public : ~CSound();
    };
}
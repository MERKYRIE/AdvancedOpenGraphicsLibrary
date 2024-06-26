#pragma once

#include"Advanced Open Graphics Library.hpp"

namespace NAdvancedOpenGraphicsLibrary::NVideo
{
    class CTexture
    {
        private : std::string FPath;
        private : std::uint32_t FIdentifier;

        public : CTexture(const std::string& PPath);
        public : std::string APath();
        public : bool AIs(const std::string& PPath);
        public : std::uint32_t AIdentifier();
        public : CTexture* ABind();
        public : ~CTexture();
    };
}
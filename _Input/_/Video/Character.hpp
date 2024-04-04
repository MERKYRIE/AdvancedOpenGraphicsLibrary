#pragma once

#include"Advanced Open Graphics Library.hpp"

namespace NAdvancedOpenGraphicsLibrary::NVideo
{
    class CCharacter
    {
        friend class CFont;
        
        private : std::uint32_t FIdentifier;

        private : CCharacter(TTF_Font* PFont , char PCode);

        public : std::uint32_t OIdentifier() const;
        public : ~CCharacter();
    };
}
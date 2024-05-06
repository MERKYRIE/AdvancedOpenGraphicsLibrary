#pragma once

#include"Advanced Open Graphics Library.hpp"

namespace NAdvancedOpenGraphicsLibrary::NVideo
{
    class CElementBufferObject
    {
        private : std::uint32_t FIdentifier;

        public : CElementBufferObject(const std::array<std::uint32_t , 24>& PElements);
        public : ~CElementBufferObject();
    };
}
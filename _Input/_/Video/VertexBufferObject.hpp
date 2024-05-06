#pragma once

#include"Advanced Open Graphics Library.hpp"

namespace NAdvancedOpenGraphicsLibrary::NVideo
{
    class CVertexBufferObject
    {
        private : std::uint32_t FIdentifier;

        public : CVertexBufferObject(const std::array<float , 18>& PVertices);
        public : ~CVertexBufferObject();
    };
}
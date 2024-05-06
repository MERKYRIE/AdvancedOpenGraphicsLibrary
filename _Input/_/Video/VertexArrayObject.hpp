#pragma once

#include"Advanced Open Graphics Library.hpp"

namespace NAdvancedOpenGraphicsLibrary::NVideo
{
    class CVertexArrayObject
    {
        private : std::uint32_t FIdentifier;
        private : std::shared_ptr<CVertexBufferObject> FVertexBufferObject;
        private : std::shared_ptr<CElementBufferObject> FElementBufferObject;

        public : CVertexArrayObject(const std::array<float , 18>& PVertices , const std::array<std::uint32_t , 24>& PElements);
        public : std::uint32_t AIdentifier();
        public : CVertexArrayObject* ABind();
        public : ~CVertexArrayObject();
    };
}
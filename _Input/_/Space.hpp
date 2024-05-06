#pragma once

#include"Advanced Open Graphics Library.hpp"

namespace NAdvancedOpenGraphicsLibrary
{
    inline class CSpace
    {
        private : std::shared_ptr<NVideo::CProgram> FProgram;
        private : std::shared_ptr<NVideo::CProgram> FProgramForNormal;
        private : std::shared_ptr<NVideo::CVertexArrayObject> FVertexArrayObject;
        
        public : CSpace();
        public : void AUpdate();
    }
    *GSpace;
}
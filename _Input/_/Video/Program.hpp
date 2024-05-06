#pragma once

#include"Advanced Open Graphics Library.hpp"

namespace NAdvancedOpenGraphicsLibrary::NVideo
{
    class CProgram
    {
        private : std::uint32_t FIdentifier;
        private : std::shared_ptr<CShader> FShaderVertex;
        private : std::shared_ptr<CShader> FShaderControl;
        private : std::shared_ptr<CShader> FShaderEvaluation;
        private : std::shared_ptr<CShader> FShaderGeometry;
        private : std::shared_ptr<CShader> FShaderFragment;

        public : CProgram(const std::string& PVertex , const std::string& PControl , const std::string& PEvaluation , const std::string& PGeometry , const std::string& PFragment);
        public : std::uint32_t AIdentifier();
        public : CProgram* AUse();
        public : ~CProgram();
    };
}
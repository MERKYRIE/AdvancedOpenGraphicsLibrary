#include"Program.hpp"

#include"Shader.hpp"

#include"Debug.hpp"

namespace NAdvancedOpenGraphicsLibrary::NVideo
{
    CProgram::CProgram(const std::string& PVertex , const std::string& PControl , const std::string& PEvaluation , const std::string& PGeometry , const std::string& PFragment)
    {
        FIdentifier = glCreateProgram();
        if(!PVertex.empty())
        {
            FShaderVertex = std::make_shared<CShader>(PVertex , GL_VERTEX_SHADER);
            FShaderVertex->AAttach(this);
        }
        if(!PControl.empty())
        {
            FShaderControl = std::make_shared<CShader>(PControl , GL_TESS_CONTROL_SHADER);
            FShaderControl->AAttach(this);
        }
        if(!PEvaluation.empty())
        {
            FShaderEvaluation = std::make_shared<CShader>(PEvaluation , GL_TESS_EVALUATION_SHADER);
            FShaderEvaluation->AAttach(this);
        }
        if(!PGeometry.empty())
        {
            FShaderGeometry = std::make_shared<CShader>(PGeometry , GL_GEOMETRY_SHADER);
            FShaderGeometry->AAttach(this);
        }
        if(!PFragment.empty())
        {
            FShaderFragment = std::make_shared<CShader>(PFragment , GL_FRAGMENT_SHADER);
            FShaderFragment->AAttach(this);
        }
        glLinkProgram(FIdentifier);
        std::int32_t LSuccess;
        glGetProgramiv(FIdentifier , GL_LINK_STATUS , &LSuccess);
        std::int32_t LLength;
        glGetProgramiv(FIdentifier , GL_INFO_LOG_LENGTH , &LLength);
        std::string LLog;
        LLog.resize(LLength);
        glGetProgramInfoLog(FIdentifier , LLength , nullptr , LLog.data());
        GDebug->AAssert(!LSuccess , "Open Graphics Library - " + LLog);
        glUseProgram(FIdentifier);
        GDebug->AAssertOpenGraphicsLibrary();
    }
    std::uint32_t CProgram::AIdentifier()
    {
        return(FIdentifier);
    }
    CProgram* CProgram::AUse()
    {
        glUseProgram(FIdentifier);
        return this;
    }
    CProgram::~CProgram()
    {
        FShaderFragment.reset();
        FShaderGeometry.reset();
        FShaderEvaluation.reset();
        FShaderControl.reset();
        FShaderVertex.reset();
        glDeleteProgram(FIdentifier);
        GDebug->AAssertOpenGraphicsLibrary();
    }
}
#include"Space.hpp"

#include"Debug.hpp"
#include"Time.hpp"
#include"Video.hpp"
#include"Video\\Program.hpp"
#include"Video\\Texture.hpp"
#include"Video\\VertexArrayObject.hpp"

namespace NAdvancedOpenGraphicsLibrary
{
    CSpace::CSpace()
    {
        GSpace = this;
        glEnable(GL_DEPTH_TEST);
        glPolygonMode(GL_FRONT_AND_BACK , GL_FILL);
        glActiveTexture(GL_TEXTURE0);
        GVideo->AAccessSpecificTexture("\\A.png")->ABind();
        glActiveTexture(GL_TEXTURE1);
        GVideo->AAccessSpecificTexture("\\B.png")->ABind();
        glm::mat4 LProjection{glm::perspective(glm::radians(90.0F) , GVideo->ARatio() , 0.25F , 5.0F)};
        glm::mat4 LView{1.0F};
        LView = glm::rotate(LView , glm::radians(-90.0F) , glm::vec3{1.0F , 0.0F , 0.0F});
        LView = glm::translate(LView , glm::vec3{0.0F , 1.0F , 0.0F});
        FProgram = std::make_shared<NVideo::CProgram>("\\Vertex.ogl" , "\\Control.ogl" , "\\Evaluation.ogl" , "\\Geometry.ogl" , "\\Fragment.ogl");
        FProgram->AUse();
        glUniformMatrix4fv(0 , 1 , GL_FALSE , &LProjection[0][0]);
        glUniformMatrix4fv(1 , 1 , GL_FALSE , &LView[0][0]);
        glUniform1i(3 , 0);
        glUniform1i(4 , 1);
        FProgramForNormal = std::make_shared<NVideo::CProgram>("\\Vertex.ogl" , "\\Control.ogl" , "\\Evaluation.ogl" , "\\GeometryForNormal.ogl" , "\\Fragment.ogl");
        FProgramForNormal->AUse();
        glUniformMatrix4fv(0 , 1 , GL_FALSE , &LProjection[0][0]);
        glUniformMatrix4fv(1 , 1 , GL_FALSE , &LView[0][0]);
        glUniform1i(3 , 0);
        glUniform1i(4 , 1);
        FVertexArrayObject = std::make_shared<NVideo::CVertexArrayObject>
        (
            std::array<float , 18>
            {
                0.0F  , 0.0F  , -0.5F ,
                0.0F  , -0.5F , 0.0F  ,
                +0.5F , 0.0F  , 0.0F  ,
                0.0F  , +0.5F , 0.0F  ,
                -0.5F , 0.0F  , 0.0F  ,
                0.0F  , 0.0F  , +0.5F
            }
            ,
            std::array<std::uint32_t , 24>
            {
                 0 , 1 , 2 ,
                 0 , 2 , 3 ,
                 0 , 3 , 4 ,
                 0 , 4 , 1 ,
                 5 , 2 , 1 ,
                 5 , 3 , 2 ,
                 5 , 4 , 3 ,
                 5 , 1 , 4
            }
        );
    }
    void CSpace::AUpdate()
    {
        FProgram->AUse();
        glUniform1f(2 , static_cast<float>(GTime->AAbsolute()) / 1000.0F);
        glDrawElements(GL_PATCHES , 24 , GL_UNSIGNED_INT , nullptr);
        FProgramForNormal->AUse();
        glUniform1f(2 , static_cast<float>(GTime->AAbsolute()) / 1000.0F);
        glDrawElements(GL_PATCHES , 24 , GL_UNSIGNED_INT , nullptr);
    }
}
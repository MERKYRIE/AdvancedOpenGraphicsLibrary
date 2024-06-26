#include"Audio.hpp"

#include"Audio\\Sound.hpp"
#include"Audio\\Track.hpp"

#include"Debug.hpp"

namespace NAdvancedOpenGraphicsLibrary
{
    CAudio::CAudio()
    {
        GAudio = this;
        GDebug->AAssertSimpleDirectMediaLayerMask(Mix_Init(MIX_INIT_MP3));
        GDebug->AAssertSimpleDirectMediaLayerCode(Mix_OpenAudioDevice(MIX_DEFAULT_FREQUENCY , MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS , 2048 , nullptr , 0));
        std::int32_t LFrequency;
        std::uint16_t LFormat;
        std::int32_t LChannels;
        GDebug->AAssert(!Mix_QuerySpec(&LFrequency , &LFormat , &LChannels));
        GDebug->AAssert(LFrequency != MIX_DEFAULT_FREQUENCY || LFormat != MIX_DEFAULT_FORMAT || LChannels != MIX_DEFAULT_CHANNELS);
        GDebug->AAssert(Mix_AllocateChannels(0));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Sounds"})
        {
            if(LEntry.path().extension() == ".wav")
            {
                FSounds.emplace_back(new NAudio::CSound{LEntry.path().string()});
            }
        }
        FSounds.shrink_to_fit();
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Tracks"})
        {
            if(LEntry.path().extension() == ".mp3")
            {
                FTracks.emplace_back(new NAudio::CTrack{LEntry.path().string()});
            }
        }
        FTracks.shrink_to_fit();
    }
    NAudio::CSound* CAudio::AAccessSound(const std::string& PPath)
    {
        std::vector<std::shared_ptr<NAudio::CSound>>::iterator LIterator
        {
            std::find_if(FSounds.begin() , FSounds.end() , [&](std::shared_ptr<NAudio::CSound>& LPointer){return(LPointer->AIs(PPath));})
        };
        return(LIterator->get());
    }
    NAudio::CTrack* CAudio::AAccessTrack(const std::string& PPath)
    {
        std::vector<std::shared_ptr<NAudio::CTrack>>::iterator LIterator
        {
            std::find_if(FTracks.begin() , FTracks.end() , [&](std::shared_ptr<NAudio::CTrack>& LPointer){return(LPointer->AIs(PPath));})
        };
        return(LIterator->get());
    }
    CAudio::~CAudio()
    {
        FTracks.clear();
        FSounds.clear();
        Mix_CloseAudio();
        Mix_Quit();
    }
}
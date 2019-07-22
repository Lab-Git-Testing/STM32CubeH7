/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef ROOMINFO_BASE_HPP
#define ROOMINFO_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>
class RoomInfoBase : public touchgfx::Container
{
public:
    RoomInfoBase();
    virtual ~RoomInfoBase() {}

    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::FadeAnimator< touchgfx::Image > swipeBG;
    touchgfx::FadeAnimator< touchgfx::Image > imageAirHumidty;
    touchgfx::FadeAnimator< touchgfx::TextArea > textAreaAirHum;
    touchgfx::Container containerLarge;
    touchgfx::FadeAnimator< touchgfx::TextArea > textAreaBottomlineLarge;
    touchgfx::FadeAnimator< touchgfx::TextAreaWithOneWildcard > textAreaDevicesLarge;
    touchgfx::FadeAnimator< touchgfx::TextArea > textAreaRoomLarge;
    touchgfx::FadeAnimator< touchgfx::Image > imageSliderLarge;
    touchgfx::FadeAnimator< touchgfx::TextArea > textAreaDegreeLarge;

    touchgfx::FadeAnimator< touchgfx::Image > imageSchedule;
    touchgfx::FadeAnimator< touchgfx::TextAreaWithOneWildcard > textAreaTemperature;
    touchgfx::FadeAnimator< touchgfx::TextAreaWithOneWildcard > textAreaHumidty;
    touchgfx::FadeAnimator< touchgfx::TextArea > textAreaSchedule;
    touchgfx::FadeAnimator< touchgfx::TextArea > textAreaScheduleDays;
    touchgfx::FadeAnimator< touchgfx::TextArea > textAreaScheduleTime;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREADEVICESLARGE_SIZE = 3;
    touchgfx::Unicode::UnicodeChar textAreaDevicesLargeBuffer[TEXTAREADEVICESLARGE_SIZE];
    static const uint16_t TEXTAREATEMPERATURE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTemperatureBuffer[TEXTAREATEMPERATURE_SIZE];
    static const uint16_t TEXTAREAHUMIDTY_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaHumidtyBuffer[TEXTAREAHUMIDTY_SIZE];

private:

};

#endif // ROOMINFO_BASE_HPP

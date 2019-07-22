/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/OvenSplashScreenBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

OvenSplashScreenBase::OvenSplashScreenBase() :
    buttonCallback(this, &OvenSplashScreenBase::buttonCallbackHandler),
    flexButtonCallback(this, &OvenSplashScreenBase::flexButtonCallbackHandler)
{
    setWidth(480);
    setHeight(272);

    background.setXY(0, 0);
    background.setBitmap(Bitmap(BITMAP_OVEN_POWER_BG_CLEAN_ID));

    textAreaHour.setPosition(129, 156, 100, 96);
    textAreaHour.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textAreaHour.setLinespacing(0);
    Unicode::snprintf(textAreaHourBuffer, TEXTAREAHOUR_SIZE, "%s", TypedText(T_SINGLEUSEID113).getText());
    textAreaHour.setWildcard(textAreaHourBuffer);
    textAreaHour.setTypedText(TypedText(T_SINGLEUSEID112));

    textAreaMinute.setPosition(251, 156, 100, 96);
    textAreaMinute.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textAreaMinute.setLinespacing(0);
    Unicode::snprintf(textAreaMinuteBuffer, TEXTAREAMINUTE_SIZE, "%s", TypedText(T_SINGLEUSEID115).getText());
    textAreaMinute.setWildcard(textAreaMinuteBuffer);
    textAreaMinute.setTypedText(TypedText(T_SINGLEUSEID114));

    textAreaDivider.setPosition(229, 156, 22, 96);
    textAreaDivider.setColor(touchgfx::Color::getColorFrom24BitRGB(167, 228, 246));
    textAreaDivider.setLinespacing(0);
    textAreaDivider.setTypedText(TypedText(T_SINGLEUSEID116));

    textAreaAmPm.setPosition(333, 212, 40, 29);
    textAreaAmPm.setColor(touchgfx::Color::getColorFrom24BitRGB(167, 228, 246));
    textAreaAmPm.setLinespacing(0);
    Unicode::snprintf(textAreaAmPmBuffer, TEXTAREAAMPM_SIZE, "%s", TypedText(T_SINGLEUSEID118).getText());
    textAreaAmPm.setWildcard(textAreaAmPmBuffer);
    textAreaAmPm.setTypedText(TypedText(T_SINGLEUSEID117));

    button1.setXY(0, 0);
    button1.setVisible(false);
    button1.setBitmaps(Bitmap(BITMAP_BTN_BG_ID), Bitmap(BITMAP_BTN_BG_ID));

    powerButton.setIconBitmaps(Bitmap(BITMAP_POWER_BUTTON_BIG_ID), Bitmap(BITMAP_POWER_BUTTON_PRESSED_BIG_ID));
    powerButton.setIconXY(170, 40);
    powerButton.setBitmaps(Bitmap(BITMAP_BTN_BG_ID), Bitmap(BITMAP_BTN_BG_ID));
    powerButton.setBitmapXY(0, 0);
    powerButton.setPosition(0, 0, 480, 272);
    powerButton.setAction(flexButtonCallback);

    add(background);
    add(textAreaHour);
    add(textAreaMinute);
    add(textAreaDivider);
    add(textAreaAmPm);
    add(button1);
    add(powerButton);
}

void OvenSplashScreenBase::initialize()
{
	
}

void OvenSplashScreenBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button1)
    {

    }
}

void OvenSplashScreenBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &powerButton)
    {
        //screenPressed
        //When powerButton clicked call virtual function
        //Call screenIsPressed
        screenIsPressed();
    }
}
